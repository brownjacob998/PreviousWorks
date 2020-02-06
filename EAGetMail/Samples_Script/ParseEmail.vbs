'  ===============================================================================
' |    THIS CODE AND usageInformationRMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF      |
' |    ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO    |
' |    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A         |
' |    PARTICULAR PURPOSE.                                                    |
' |    Copyright (c)2010 - 2019  AdminSystem Software Limited                         |
' |
' |    Project: It demonstrates how to use EAGetMailObj to parse email summary in VBScript
' |
' |    Author: Ivan Lui (ivan@emailarchitect.net)
'  ===============================================================================

Dim args, usageInformation
Set args = WScript.Arguments
If args.Count < 1 Then
	usageInformation =  "Usage: cscript ParseEmail.vbs [email file path]" & Chr(13) & Chr(10)
	usageInformation = usageInformation & "   eg: cscript ParseEmail.vbs ""d:\1.eml"""
	WScript.Echo usageInformation
	WScript.Quit
End If

Dim oMail
Set oMail = CreateObject("EAGetMailObj.Mail")

' For evaluation usage, please use "TryIt", for licensed user, please use your license code here
oMail.LicenseCode = "TryIt"

' If email file is *.msg (outlook msg file), please change it to
' oMail.LoadOMSGFile args(0)
oMail.LoadFile args(0), False

' If email has winmail.dat, decode it automatically.
oMail.DecodeTNEF

' Decrypt email
If oMail.IsEncrypted  Then
	Set oMail = oMail.Decrypt(Nothing)
End If

' Verify digital signature
Dim oSignerCert
If oMail.IsSigned Then
	Set oSignerCert = oMail.VerifySignature()
End If

' Parse from and reply-to
Dim header
header = "From: " & oMail.From.Name & "<" & oMail.From.Address & ">" & Chr(13) & Chr(10)
header = header & "Reply-To: " & oMail.ReplyTo.Name & "<" & oMail.ReplyTo.Address & ">" & Chr(13) & Chr(10)

' Parse To
Dim i, address, addressList

header = header & "To: "

Set addressList = oMail.ToList
For i = 0 To addressList.Count - 1
	Set address = addressList.Item(i)
	header = header & address.Name & "<" & address.Address & ">; " 
Next

header = header & Chr(13) & Chr(10)

' Parse Cc
Set addressList = oMail.CcList
If addressList.Count > 0 Then
	header = header & "Cc: "

	For i = 0 To addressList.Count - 1
		Set address = addressList.Item(i)
		header = header & address.Name & "<" & address.Address & ">; " 
	Next
	
	header = header & Chr(13) & Chr(10)
End If

' Parse subject and date
header = header & "Subject: " & oMail.Subject & Chr(13) & Chr(10)
header = header & "Date: " & oMail.ReceivedDate & Chr(13) & Chr(10)

' Parse attachments
Dim att, attachmentList
Set attachmentList = oMail.AttachmentList

If attachmentList.Count > 0 Then
	header = header & "Attachments: "

	For i = 0 To attachmentList.Count - 1
		Set att = attachmentList.Item(i)
		header = header & att.ContentType & ":" & att.Name & "; " 

		' You can save attachment like this
		' att.SaveAs "d:\tempdata\" & att.Name, True
	Next

	header = header & Chr(13) & Chr(10)
End If

' Parse body text
WScript.Echo header
WScript.Echo ""
WScript.Echo oMail.TextBody

' Display the htmlbody
'WScript.Echo oMail.HtmlBody
