<%@  language="VBScript" codepage="65001" %>
<%
'  ===============================================================================
' |    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF      |
' |    ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO    |
' |    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A         |
' |    PARTICULAR PURPOSE.                                                    |
' |    Copyright (c) 2019 ADMINSYSTEM.NET                         |
' |
' |    File: Default.asp
' |    Project: This project demonstrates how to use EAGetMailObj to retrieve email from POP3 server and save it as an email file.
' |    Author: Ivan Lui (ivan@emailarchitect.net)
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

Dim serverAddress, user, password, isSsl, isLeaveCopy, authIndex, protocolIndex, rangeIndex, status
serverAddress = ""
user = ""
password = ""
isSsl = True
isLeaveCopy = True
authIndex = 0
protocolIndex = 0
rangeIndex = 0
status = ""

If Request.QueryString("act") = "get" Then

    serveraddress = Request.Form("Server")
    user = Request.Form("User")
    password = Request.Form("Password")
    isSsl = (Request.Form("chkSSL") <> "")
    isLeaveCopy = (Request.Form("chkLeaveCopy") <> "")
    authIndex = Request.Form("lstAuthType")
    protocolIndex = Request.Form("lstProtocol")
    rangeIndex = Request.Form("lstRange")

  On Error Resume Next
    Dim oUidlManager, isUidlLoaded
    isUidlLoaded = False
    Set oUidlManager = Server.CreateObject("EAGetMailObj.UIDLManager")

    DownloadEmail
    
    If Err.number <> 0 Then
        status = Err.Description
    End If

    If isUidlLoaded Then
        oUidlManager.Update
    End If

End If

Const MailServerPop3 = 0
Const MailServerImap4 = 1
Const MailServerEWS = 2
Const MailServerDAV = 3

Function GetMaxCountToDownload(mailCount)
    Dim count
    Select Case rangeIndex
        Case 0
            count = 10
        Case 1
            count = 30
        Case 2
            count = 100
        Case Else
            count = mailCount
    End Select

    If count > mailCount Then
        count = mailCount
    End If

    GetMaxCountToDownload = count
End Function

Sub DownloadEmail()

    Dim oClient, oServer
    isUidlLoaded = False

    Set oClient = Server.CreateObject("EAGetMailObj.MailClient")
    ' For evaluation usage, please use "TryIt" as the license code, otherwise the
    ' "Invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
    ' "Trial version expired" exception will be thrown.
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
       
    oClient.Connect oServer
   
    ' uidl is the identifier of every email on POP3/IMAP4 server, to avoid retrieve
    ' the same email from server more than once, we record the email uidl retrieved every time
    ' if you delete the email from server every time and not to leave a copy of email on
    ' the server, then please remove all the function about uidl.
    oUidlManager.Load localInbox & "\uidl.txt"
    isUidlLoaded = True
    
    Dim mailInfos
    Set mailInfos = oClient.GetMailInfoList()

    Dim countToDownload
    countToDownload = GetMaxCountToDownload(mailInfos.Count)

    oUIDLManager.SyncUIDLEX oServer, mailInfos
    ' Update result back to uidl file
    oUIDLManager.Update
    
    Dim i, downloaded, remain
    downloaded = 0
    remain = mailInfos.Count
    For i = 0 To mailInfos.Count - 1
        Dim oInfo
        Set oInfo = mailInfos.Item(i)
        remain = remain - 1    
        ' If this email has not retrieved before, then get it
        If oUidlManager.FindUIDL(oServer, oInfo.UIDL) Is Nothing Then
            Dim oMail
            Set oMail = oClient.GetMail(oInfo)

            Dim fileName
            fileName = oTools.GenFileName(i) & ".eml"
            ' generate a random file name by current local datetime,
            ' you can use your method to generate the filename if you do not like it
            oMail.SaveAs localInbox & "\" & fileName, True

            If isLeaveCopy Then
                ' Add the email uidl to uidl file to avoid we retrieve it next time.
                oUidlManager.AddUIDL oServer, oInfo.UIDL, fileName
            Else
                oClient.Delete oInfo
                oUidlManager.RemoveUIDL oServer, oInfo.UIDL
            End If
                
            downloaded = downloaded + 1
            If downloaded >=  countToDownload Then
                Exit For
            End If
        End If
    Next
        
    ' Delete method just mark the email as deleted,
    ' Quit method pure the emails from server exactly.
    oClient.Quit
    Set oClient = Nothing

    status = "Total " & mailInfos.Count & " email(s) on server, " & downloaded & " email(s) downloaded this time, " & remain & " email(s) unchecked on server, please click ""Retrieve"" again to download unchecked emails."
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
    <title>EAGetMailObj ASP Sample</title>
    <link href="sample.css" rel="stylesheet" />
</head>
<body>
    <div id="s_title">
        ASP, VBScript Sample For EAGetMail ActiveX Object</div>
    <div id="div_main">
        <%If status <> "" Then
            Response.Write("<div class=""information"">" & status & "</div>")
        End If
        %>
        <form action="default.asp?act=get" name="thisForm" method="post">
        <table style="width: 560px">
            <tr>
                <td style="width:100px">
                    Server
                </td>
                <td>
                    <input type="text" name="server" id="server" value="<%=serverAddress%>" style="width: 400px;" />
                </td>
            </tr>
            <tr>
                <td>
                    User
                </td>
                <td>
                    <input type="text" name="user" id="user" value="<%=user%>" style="width: 400px;" />
                </td>
            </tr>
            <tr>
                <td>
                    Password
                </td>
                <td>
                    <input type="password" name="password" id="password" value="<%=password%>" style="width: 400px;" />
                </td>
            </tr>
            <tr>
                <td>
                    &nbsp;
                </td>
                <td>
                    <input type="checkbox" name="chkSSL" id="chkSSL" value="1" checked="checked" />
                    SSL/TLS Connection
                </td>
            </tr>
            <tr>
                <td>
                    Auth Type
                </td>
                <td>
                    <select name="lstAuthType" id="lstAuthType" style="width: 400px;">
                        <option value="0">USER/LOGIN</option>
                        <option value="1">APOP(CRAM-MD5)</option>
                        <option value="2">NTLM</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td>
                    Protocol
                </td>
                <td>
                    <select name="lstProtocol" id="lstProtocol" style="width: 400px;">
                        <option value="0">POP3</option>
                        <option value="1">IMAP4</option>
                        <option value="2">Exchange Web Service - 2007-2019/Office 365</option>
                        <option value="3">Exchange WebDAV- 2000/2003</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td>
                    &nbsp;
                </td>
                <td>
                    <input type="checkbox" name="chkLeaveCopy" id="chkLeaveCopy" value="1" checked="checked" />Leave a
                    copy of messsage on Server.
                </td>
            </tr>
            <tr>
                <td>
                </td>
                <td>
                    <div class="comments">
                        Warning: If "leave a copy of message on server" is unchecked, the email will be
                        deleted after it has been downloaded</div>
                    <div class="comments">
                        If there are too many emails in your mailbox, it may cause ASP timeout</div>
                </td>
            </tr>
            <tr>
                <td>
                </td>
                <td>
                    <select name="lstRange" id="lstRange" style="width: 400px;">
                     <option value="0">Download 10 emails each time</option>
                        <option value="1">Download 30 emails each time</option>
                        <option value="2">Download 100 emails each time</option>
                        <option value="3">Download all emails</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td>
                </td>
                <td>
                    <input type="button" name="btnRetrieve" id="btnRetrieve" value="Retrieve" onclick="fnSubmit()" />
                    <a href="default.asp" style="margin-left: 30px;">Reset</a>
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
        Technical Support: <a href="mailto:support@emailarchitect.net">support@emailarchitect.net</a>
        <br>
        <br>
        <a href="http://www.emailarchitect.net" target="_blank">2006 - 2019 Copyright © AdminSystem
            Software Limited. All rights reserved.</a>
    </div>

    <script type="text/jscript">
        function fnDisplay(v) {
            window.open(v,
				"",
				"height=640,width=800,menubar=no,resizable=yes,scrollbars=yes,status=yes",
				false);
        }

        // Verifying input
        function fnSubmit() {
            if (document.thisForm.server.value == "" ||
		        document.thisForm.user.value == "" ||
			    document.thisForm.password.value == "") {
                alert("Please input server address, username and password!")
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
        setOpt("lstRange", <%=rangeIndex %>);

        setChecked("chkLeaveCopy", <%=LCase(isLeaveCopy)%>);
        setChecked("chkSSL", <%=LCase(isSsl)%>);

    </script>
</body>
</html>
