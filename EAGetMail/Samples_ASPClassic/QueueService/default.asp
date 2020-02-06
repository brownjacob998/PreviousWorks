<%@  language="VBScript" codepage="65001" %>
<%
'  ===============================================================================
' |    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF      |
' |    ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO    |
' |    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A         |
' |    PARTICULAR PURPOSE.                                                    |
' |    Copyright (c)2010 ADMINSYSTEM SOFTWARE LIMITED                         |
' |
' |    File: Default.asp
' |    Project: This project demonstrates how to use EAGetMailObj to retrieve email by EAGetMail Service
' |    Author: Ivan Lui ( ivan@emailarchitect.net )
'  ===============================================================================
Option Explicit
Response.Charset = "utf-8"

Function FormatHtmlTag(src) 
    src = Replace(src, ">", "&gt;")
    src = Replace(src, "<", "&lt;")
    FormatHtmlTag = src
End Function

Dim oTools
Set oTools = Server.CreateObject("EAGetMailObj.Tools")

Function CreateLocalFolder()
    Dim mailFolder, pos
    mailFolder = Server.MapPath(Request.ServerVariables("PATH_INFO"))
    pos = InStrRev(mailFolder, "\")
    If pos > 0 Then
	    mailFolder = Mid(mailFolder, 1, pos-1)
    End If

    mailFolder = mailFolder & "\inbox" 
    If Not oTools.ExistFile(mailFolder) Then
        oTools.CreateFolder mailFolder
    End If

    CreateLocalFolder = mailFolder
End Function

Dim localInbox
localInbox = CreateLocalFolder()

Dim serverAddress, user, password, isSsl, isLeaveCopy, authIndex, protocolIndex, status
serverAddress = ""
user = ""
password = ""
isSsl = True
isLeaveCopy = True
authIndex = 0
protocolIndex = 0
status = ""

If Request.QueryString("act") = "get" Then

    serveraddress = Request.Form("Server")
    user = Request.Form("User")
    password = Request.Form("Password")
    isSsl = (Request.Form("chkSSL") <> "")
    isLeaveCopy = (Request.Form("chkLeaveCopy") <> "")
    authIndex = Request.Form("lstAuthType")
    protocolIndex = Request.Form("lstProtocol")

    GetMail
End If

Const MailServerPop3 = 0
Const MailServerImap4 = 1
Const MailServerEWS = 2
Const MailServerDAV = 3

Sub GetMail()
    Dim oClient, oServer
    Set oClient = Server.CreateObject("EAGetMailObj.MailClient")
    'For evaluation usage, please use "TryIt" as the license code, otherwise the
    '"invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
    '"trial version expired" exception will be thrown.
    oClient.LicenseCode = "TryIt"
        
    Set oServer = Server.CreateObject("EAGetMailObj.MailServer")
    'oClient.LogFileName = mailFolder & "\pop3.txt" 'generate a log file
        
    oServer.Server = serverAddress
    oServer.User = user
    oServer.Password = password
    oServer.SSLConnection = isSsl

    oServer.AuthType = authIndex
    oServer.Protocol = protocolIndex

    If oServer.Protocol = MailServerImap4 Then
        If oServer.SSLConnection Then
            oServer.Port = 993 'SSL IMAP4
        Else
            oServer.Port = 143 'IMAP4 normal
        End If
    Else
        If oServer.SSLConnection Then
            oServer.Port = 995 'SSL POP3
        Else
            oServer.Port = 110 'POP3 normal
        End If
    End If
        
       
On Error Resume Next
    ' Send request to EAGetMail Service, then EAGetMail Service retrieves email
    ' In background and 'this method returns immediately
    oClient.GetMailsByQueue oServer, localInbox, isLeaveCopy
        
    If Err.Number <> 0 Then
        status =  "Error: " & Err.Description & " please make sure you installed EAGetMail Service!"
        On Error Goto 0
        Exit Sub
    End If
        
    status = "Task has been submitted to EAGetMail Service successfully, EAGetMail will retrieve emails in background, please click <b>Refresh local emails</b> later to check retrieved email."
End Sub

Sub DisplayLocalMail()
    Dim files, oMail, i
    files = oTools.GetFiles(localInbox & "\*.eml")

    Set oMail = Server.CreateObject("EAGetMailObj.Mail")
    oMail.LicenseCode = "TryIt"

    Dim s
    For i = LBound(files) To UBound(files)
        oMail.LoadFile files(i), True

        s = "<tr>"
        s = s & "<td><a href=""display.asp?name=" & Server.URLEncode(files(i)) & """ onclick=""javascript:fnDisplay(this.href);return false;"">" 
        s = s & FormatHtmlTag(oMail.From.Name & "<" & oMail.From.Address & ">") & "</a></td>"
        s = s & "<td>" & FormatHtmlTag(oMail.Subject) & "&nbsp;</td>"
        s = s & "<td>" & oMail.ReceivedDate & "</td>"
        s = s & "<td><a href=""delete.asp?name=" & Server.URLEncode(files(i)) & """>Delete</a></td>"
    
        Response.Write(s)
    Next
End Sub
%>
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <title>EAGetMailObj ASP + EAGetMail Service Sample</title>
    <link href="sample.css" rel="stylesheet" />

</head>
<body>
    <div id="s_title">
        EAGetMailObj ASP + EAGetMail Service Sample
    </div>
    <div id="div_main">
         <%If status <> "" Then
            Response.Write("<div class=""information"">" & status & "</div>")
        End If
        %>
        <form action="default.asp?act=get" name="thisForm" method="post">
            <p>
                To run this sample, you should download <a href="http://www.emailarchitect.net/webapp/download/eagetmailservice.exe">EAGetMail Service</a> and install it on the server.
            </p>
            <table style="width: 560px">
                <tr>
                    <td style="width:100px">Server
                    </td>
                    <td>
                        <input type="text" name="server" id="server" value="<%=serverAddress%>" style="width: 240px;" />
                    </td>
                </tr>
                <tr>
                    <td>User
                    </td>
                    <td>
                        <input type="text" name="user" id="user" value="<%=user%>" style="width: 240px;" />
                    </td>
                </tr>
                <tr>
                    <td>Password
                    </td>
                    <td>
                        <input type="password" name="password" id="password" value="<%=password%>" style="width: 240px;" />
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;
                    </td>
                    <td>
                        <input type="checkbox" name="chkSSL" id="chkSSL" value="1" checked="checked" />
                        SSL/TLS Connection
                    </td>
                </tr>
                <tr>
                    <td>Auth Type
                    </td>
                    <td>
                        <select name="lstAuthType" id="lstAuthType">
                            <option value="0">USER/LOGIN</option>
                            <option value="1">APOP(CRAM-MD5)</option>
                            <option value="2">NTLM</option>
                        </select>
                    </td>
                </tr>
                <tr>
                    <td>Protocol
                    </td>
                    <td>
                        <select name="lstProtocol" id="lstProtocol">
                            <option value="0">POP3</option>
                            <option value="1">IMAP4</option>
                            <option value="2">Exchange Web Service - 2007-2019/Office 365</option>
                            <option value="3">Exchange WebDAV- 2000/2003</option>

                        </select>
                    </td>
                </tr>
                <tr>
                    <td>&nbsp;
                    </td>
                    <td>
                        <input type="checkbox" name="chkLeaveCopy" id="chkLeaveCopy" value="1" checked="checked" />Leave a copy of messsage
                on Server.
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <div class="comments">
                            Warning: If "leave a copy of message on server" is unchecked, the email will be
                        deleted after it has been downloaded
                        </div>
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <input type="button" name="btnRetrieve" id="btnRetrieve" value="Retrieve by EAGetMail Service in background" onclick="fnSubmit()" />
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <a href="default.asp">Refresh local emails.</a>
                    </td>
                </tr>
            </table>
        </form>
        <hr />
        <table>
            <tr>
                <td>
                    <b>From</b>
                </td>
                <td>
                    <b>Subject</b>
                </td>
                <td style="width:150px">
                    <b>Date</b>
                </td>
                <td>
                    <b>&nbsp;</b>
                </td>
            </tr>
            <%
DisplayLocalMail
            %>
        </table>
    </div>
    <div id="tailer">
        <p>
            Technical Support<br />
            <br />
            Email: <a href="mailto:support@emailarchitect.net">support@emailarchitect.net</a>
        </p>
        <p>
            <a href="http://www.emailarchitect.net" target="_blank">2019 Copyright &copy; AdminSystem
            Software Limited. All rights reserved.</a>
        </p>

    </div>
    <script type="text/jscript">
        function fnDisplay(v) {
            window.open(v,
                "",
                "height=640,width=800,menubar=no,resizable=yes,scrollbars=yes,status=yes",
                false);
        }

        //Verifying input
        function fnSubmit() {
            if (document.thisForm.server.value == "" ||
                document.thisForm.user.value == "" ||
                document.thisForm.password.value == ""
            ) {
                alert("Please input server address, username and password!");
                return;
            }

            document.getElementById("btnRetrieve").disabled = true;
            document.thisForm.submit();
            return;
        }

        function setOpt(id, value) {
            var obj = document.getElementById(id);
            var opts = obj.options;
            for (i = 0; i < opts.length; i++) {
                console.log(opts[i].value);
                if (opts[i].value == value) {
                    opts[i].selected = true;
                    return;
                }
            }
        }

        function setChecked(id, value) {
            document.getElementById(id).checked = value;
        }

        setOpt("lstAuthType", <%=authIndex %>);
        setOpt("lstProtocol", <%=protocolIndex%>);

        setChecked("chkLeaveCopy", <%=LCase(isLeaveCopy)%>);
        setChecked("chkSSL", <%=LCase(isSsl)%>);
    </script>

</body>
</html>
