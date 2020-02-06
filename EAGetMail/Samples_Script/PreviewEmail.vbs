'  ===============================================================================
' |    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF      |
' |    ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO    |
' |    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A         |
' |    PARTICULAR PURPOSE.                                                    |
' |    Copyright (c)2010  AdminSystem Software Limited                         |
' |
' |    Project: It demonstrates how to use EAGetMailObj to retrieve email summary in VBScript
' |
' |    Author: Ivan Lui ( ivan@emailarchitect.net )
'  ===============================================================================

Sub DisplayHeaders(oHeaders)
	Dim headerString, i
	
	headerString = ""
	For i = 0 To oHeaders.Count - 1
		Dim oHeader
		Set oHeader = oHeaders.Item(i)
		headerString = headerString & oHeader.HeaderKey & ":" & oHeader.HeaderValue & Chr(13) & Chr(10)
	Next
	WScript.Echo headerString
End Sub

Const MailServerConnectType_ConnectSSLAuto = 0
Const MailServerConnectType_ConnectSSL = 1
Const MailServerConnectType_ConnectTLS = 2

Const ProxyType_Socks4 = 0
Const ProxyType_Socks5 = 1
Const ProxyType_Http = 2

Const MailServerAuthLogin = 0
Const MailServerAuthCRAM5 = 1
Const MailServerAuthNTLM = 2

Const MailServerPop3 = 0
Const MailServerImap4 = 1
Const MailServerEWS = 2 ' Exchange Web Service
Const MailServerDAV = 3 ' Exchange WebDAV

Dim args, info
Set args = WScript.Arguments
If args.Count < 3 Then
	info =  "Usage: cscript PreviewEmail.vbs [server] [user] [password] [pop|imap|ews|dav]" & Chr(13) & Chr(10)
	info = info & "   eg: cscript PreviewEmail.vbs mail.adminsystem.net test@adminsystem.net test imap" & Chr(13) & Chr(10)
	WScript.Echo info
	WScript.Quit
End If

Dim oServer, oClient
Set oServer = CreateObject("EAGetMailObj.MailServer")
Set oClient = CreateObject("EAGetMailObj.MailClient")

'for evaluation usage, please use "TryIt", for licensed user, please use your license code here
oClient.LicenseCode = "TryIt"

oServer.Server = args(0)
oServer.User = args(1)
oServer.Password = args(2)

' If your server doesn't require SSL, please remove this line
oServer.SSLConnection = True

If args.Count >= 4 Then
	Dim protocol 
	protocol = LCase(args(3))
End If

If protocol = "imap" Then
	oServer.Protocol = MailServerImap4
ElseIf protocol = "ews" Then
	oServer.Protocol = MailServerEWS
ElseIf protocol = "dav" Then
	oServer.Protocol = MailServerDAV
Else
	oServer.Protocol = MailServerPop3
End If

If oServer.Protocol = MailServerImap4 Then
	If oServer.SSLConnection Then
		oServer.Port = 993 'SSL IMAP4
	Else
		oServer.Port = 143 'IMAP4 normal
	End If
ElseIf oServer.Protocol = MailServerPop3 Then 
	If oServer.SSLConnection Then
		oServer.Port = 995 'SSL POP3
	Else
		oServer.Port = 110 'POP3 normal
	End If
End If

WScript.Echo "Connecting " & args(0) & " ..."

oClient.Connect oServer

Dim mailInfoList, i
Set mailInfoList = oClient.GetMailInfoList()

WScript.Echo "Total " & mailInfoList.Count & " email(s)" & Chr(13) & Chr(10)

For i = 0 To mailInfoList.Count - 1

	Dim mailInfo
	Set mailInfo = mailInfoList.Item(i)

	WScript.Echo "retrieving headers of uidl: " & mailInfo.UIDL &", index: " & i + 1 & " email ..." & Chr(13) & Chr(10)

	Dim oMail
	Set oMail = CreateObject("EAGetMailObj.Mail")
	' For evaluation usage, please use "TryIt", for licensed user, please use your license code here
	oMail.LicenseCode = "TryIt"

	' Get email headers only, then you dont have to download entire email
	' but if you want to get email body/attachments, you should use 
	' Set oMail = oClient.GetMail(mailInfoList(i))

	oMail.Load(oClient.GetMailHeader(mailInfo))
	
	Dim oHeaders
	Set oHeaders = oMail.Headers
	DisplayHeaders oHeaders
	
Next

oClient.Quit

