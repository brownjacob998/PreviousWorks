<%@  language="VBScript" codepage="65001" %>
<%
'  ===============================================================================
' |    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF      |
' |    ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO    |
' |    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A         |
' |    PARTICULAR PURPOSE.                                                    |
' |    Copyright (c)2010 ADMINSYSTEM.NET                         |
' |
' |    File: Default.asp
' |    Project: This project demonstrates how to use EAGetMailObj to retrieve email from POP3 server and save it as an email file.
' |    Author: Ivan Lui ( ivan@emailarchitect.net )
'  ===============================================================================
Function FormatHtmlTag( src ) 
    src = Replace(src, ">", "&gt;")
    src = Replace(src, "<", "&lt;")
    FormatHtmlTag = src
End Function

Dim filename
filename = Request.QueryString("name")

Dim oMail
Set oMail = Server.CreateObject("EAGetMailObj.Mail")

' For evaluation usage, please use "TryIt" as the license code, otherwise the
' "invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
' "Trial version expired" exception will be thrown.
oMail.LicenseCode = "TryIt"
oMail.LoadFile filename, False
    
Dim html
html = oMail.HtmlBody

Dim hdr
hdr = hdr & "<font face=""Courier New,Arial"" size=2>"
hdr = hdr & "<b>From:</b> " + FormatHtmlTag(oMail.From.Name & "<" & oMail.From.Address & ">") + "<br>"
    
Dim i, address, addrs

Set addrs = oMail.ToList
If addrs.Count > 0 Then
    hdr = hdr & "<b>To:</b> "
    
    For i = 0 To addrs.Count - 1
        Set address = addrs.Item(i)
        hdr = hdr & FormatHtmlTag(address.Name & "<" & address.Address & ">") & "; "
    Next

    hdr = hdr & "<br>"
End If
    
Set addrs = oMail.CcList
If addrs.Count > 0 Then
    hdr = hdr & "<b>Cc:</b> "
    
    For i = 0 To addrs.Count - 1
        Set address = addrs.Item(i)
        hdr = hdr & FormatHtmlTag(address.Name & "<" & address.Address & ">") & "; "
    Next

    hdr = hdr & "<br>"
End If
        
hdr = hdr & "<b>Subject:</b>" & FormatHtmlTag(oMail.Subject) & "<br>" & vbCrLf
Dim atts
Set atts = oMail.AttachmentList

If (atts.Count > 0) Then
       
    hdr = hdr & "<b>Attachments:</b> "
    For i = 0 To atts.Count - 1
        Dim att
        Set att = atts.Item(i)

        Dim attname
        attname = "attachment.asp?name=" & Server.URLEncode(filename) & "&index=" & i
            
        hdr = hdr & "<a href=""" & attname & """ target=""_blank"">" & att.Name & "</a>; "
        If Len(att.ContentID) > 0 Then
            ' show embedded image.
            html = Replace(html, "cid:" + att.ContentID, attname)
        ElseIf InStr(1, att.ContentType, "image/", vbTextCompare) = 1 Then
            ' show attached image.
            html = html & "<hr><img src=""" & attname & """>"
        End If

    Next
End If
    
hdr = "<meta HTTP-EQUIV=""Content-Type"" Content=""text/html; charset=utf-8"">" & hdr
html = hdr & "<hr>" & html
   
Response.Write( html )
%>