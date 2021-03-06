<%@  codepage="65001" language="VBScript" %>
<%
' ===============================================================================
' |    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF      |
' |    ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO    |
' |    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A         |
' |    PARTICULAR PURPOSE.                                                    |
' |    Copyright (c)2010  ADMINSYSTEM SOFTWARE LIMITED                         |
' |
' | FILE: Default.ASP
' | SYNOPSIS: SAMPLE FILE FOR EASendMail ActiveX Object(VBScript)
' |
' =================================================================================*/
Response.CharSet = "utf-8" 

Const ConnectNormal = 0
Const ConnectSSLAuto = 1
Const ConnectSTARTTLS = 2
Const ConnectDirectSSL = 3
Const ConnectTryTLS = 4

'========================================================
' fnParseAddr
'========================================================
Function fnParseAddr(src, Byref name, Byref addr)
	Dim nIndex
	nIndex = InStr(1, src, "<")
	If nIndex > 0 Then
		name = Mid(src, 1, nIndex - 1)
		addr = Mid(src, nIndex)
	Else
		name = ""
		addr = src
	End If
	
	Call fnTrim(name, " ,;<>""'")
	Call fnTrim(addr, " ,;<>""'")
End Function
'========================================================
' fnTrim
'========================================================
Function fnTrim(Byref src, trimer)
	Dim i, nCount, ch
	nCount = Len(src)
	For i = 1 To nCount
		ch = Mid(src, i, 1)
		If InStr(1, trimer, ch) < 1 Then
			Exit For
		End If
	Next
	
	src = Mid(src, i)
	nCount = Len(src)
	For i = nCount To 1 Step -1
		ch = Mid(src, i, 1)
		If InStr(1, trimer, ch) < 1 Then
			Exit For
		End If	
	Next
	src = Mid(src, 1, i)
End Function

'===================================================================
' fnShowProtocol
'===================================================================
Sub fnShowProtocol(protocol)

   Dim arProtocol, i, nCount, s
   arProtocol = Array("SMTP Protocol - Recommended:0", _
						"Exchange Web Service - Exchange 2007/2010:1", _
						"Exchange WebDav - Exchange 2007/2010:2") 

   nCount = UBound(arProtocol)
   
   Dim p
   p = CInt(protocol)
   Dim buf, s1, s2, pos
   
   For i = LBound(arProtocol) To nCount
		buf = arProtocol(i)
		pos = InStr(1, buf, ":")
		If pos > 0 Then
			s1 = Mid(buf, 1, pos-1)
			s2 = Mid(buf, pos+1)
		End If
		s = s & "<option value=""" & s2 & """"	
		If CInt(s2) = CInt(p) Then
			s = s & " selected"
		End If
		s = s & ">" & s1 & "</option>"
	Next
	Response.Write(s)	
End Sub

'===================================================================
' fnShowComposeCharset
'===================================================================
Sub fnShowComposeCharset()
	Dim arCharset, i, nCount, s, charset
	arCharset = Array("Arabic(Windows):windows-1256", _
						"Baltic(ISO):iso-8859-4", _
						"Baltic(Windows):windows-1257", _
						"Central Euporean(ISO):iso-8859-2", _
						"Central Euporean(ISO):windows-1250", _
						"Chinese Simplified(GB18030):GB18030", _
						"Chinese Simplified(GB2312):gb2312", _
						"Chinese Simplified(HZ):hz-gb-2312", _
						"Chinese Traditional(Big5):big5", _
						"Cyrillic(ISO):iso-8859-5", _
						"Cyrillic(KOI8-R):koi8-r", _
						"Cyrillic(KOI8-U):koi8-u", _
						"Cyrillic(Windows):windows-1251", _
						"Greek(ISO):iso-8859-7", _
						"Greek(Windows):windows-1253", _
						"Hebrew(Windows):windows-1255", _
						"Japanese(JIS):iso-2022-jp", _
						"Korean:ks_c_5601-1987", _
						"Korean(EUC):euc-kr", _
						"Latin 9(ISO):iso-8859-15", _
						"Thai(Windows):windows-874", _
						"Turkish(ISO):iso-8859-9", _
						"Turkish(Windows):windows-1254", _
						"Unicode(UTF-7):utf-7", _
						"Unicode(UTF-8):utf-8", _
						"Vietnames(Windows):windows-1258", _
						"Western European(ISO):iso-8859-1", _
						"Western European(Windows):Windows-1252" _
							)
						
	nCount = UBound(arCharset)
	s = ""
	charset = "utf-8"

	Dim buf, s1, s2, pos
	For i = LBound(arCharset) To nCount
		buf = arCharset(i)
		pos = InStr(1, buf, ":")
		If pos > 0 Then
			s1 = Mid(buf, 1, pos-1)
			s2 = Mid(buf, pos+1)
		End If
		s = s & "<option value=""" & s2 & """"	
		If LCase(s2) = charset Then
			s = s & " selected"
		End If
		s = s & ">" & s1 & "</option>"
	Next
	Response.Write(s)	
End Sub


Sub SendMail()
	Dim from, recipients
	from = Request.Form("from")
	recipients = Request.Form("recipients")
	
	If from = "" Or recipients = "" Then
		Response.Write("<font color=red>Please input from, to</font>")
		Exit Sub
	End If
	
	Dim oSmtp
	Set oSmtp = Server.CreateObject("EASendMailObj.Mail")
    'The license code for EASendMail ActiveX Object,
    'for evaluation usage, please use "TryIt" as the license code.
    oSmtp.LicenseCode = "TryIt"
	
	oSmtp.Charset = Request.Form("charset")
	
	Dim serveraddr, serverport
	
	serveraddr = Request.Form("serveraddr")
	serverport = CLng(Request.Form("serverport"))
	oSmtp.ServerAddr = serveraddr
    oSmtp.Protocol = CInt(Request.Form("protocol"))
    
    ' Most mordern SMTP servers require SSL/TLS connection now
    ' ConnectTryTLS means if server supports SSL/TLS connection, SSL/TLS is used automatically
    oSmtp.ConnectType = ConnectTryTLS

	' Using ESMTP authentication
	If serveraddr <> "" Then
	    oSmtp.ServerPort = serverport
		If Request.Form("authrequired") <> "" Then
			oSmtp.UserName = Request.Form("user")
			oSmtp.Password = Request.Form("password")
		End If
		
		If Request.Form("SSL") <> "" Then
            ' Use SSL/TLS based on server port.
            oSmtp.ConnectType = ConnectSSLAuto
		End If		
	End If

	Dim name, addr
	fnParseAddr from, name, addr

	oSmtp.From		= name
	oSmtp.FromAddr	= addr
	
	'Using this email to be replied to another address 
	'oSmtp.ReplyTo = ReplyAddress 

	'if you want to EASendMail service send the email after 10 minutes, please use the following code.
	'oSmtp.Date = DateAdd("n", 10, Now())
	
	'pick "name" field as the recipient name and "address" field as the recipient address.
	'you can also use {$var_srecord:fieldname} to pick any field in X-Sql-Select statement
	' and put it to subject, bodytext, then EASendMail will replace it automatially.
	
	oSmtp.DisplayTo = """{$var_srecord:name}"" <{$var_srecord:address}>"
	oSmtp.AddHeader "X-Rcpt-To", "{$var_srecord:address}"
	
	' For more connection string
	' MS SQL server
	'"Driver={SQL Server};Server=localhost;Database=pubs;Uid=sa;Pwd=asdasd;" 
	' MS Access
	'"Driver={Microsoft Access Driver (*.mdb)};Dbq=C:\mydatabase.mdb;Uid=Admin;Pwd=;"
	' ORACLE
	'"Driver={Microsoft ODBC for Oracle};Server=OracleServer.world;Uid=Username;Pwd=asdasd;" 
	' MySQL
	'"DRIVER={MySQL ODBC 3.51 Driver};SERVER=localhost;DATABASE=myDatabase;USER=myUsername;PASSWORD=myPassword;OPTION=3;" 
	' other connection string
	' please refer to: http://www.connectionstrings.com/
	
	' To check the database error, please use EASendMail Service Manager->Journal->System Error
	
	oSmtp.AddHeader "X-Data-Connection", Request.Form("DataConnection")
	oSmtp.AddHeader "X-Sql-Select", recipients 
	oSmtp.AddHeader "X-Sql-OnSentSuccess", Request.Form("OnSuccess")
	oSmtp.AddHeader "X-Sql-OnSentError", Request.Form("OnError")

	'Attachs file to this email 
	'oSmtp.AddAttachment "c:\test.txt"
	
	Dim subject, bodytext
	subject = Request.Form("subject")
	bodytext = Request.Form("bodytext") 
	bodytext = Replace(bodytext, "[$from]", from)
	bodytext = Replace(bodytext, "[$subject]", subject)
	
	oSmtp.Subject	= subject
	oSmtp.BodyText	= bodytext 
	
	If Request.Form("htmlformat") <> "" Then
		oSmtp.BodyFormat = 1	' Using HTML FORMAT to send mail
	End If
	
	Dim hres
	hres = oSmtp.SendMailToQueue()

	If hres = 0 Then
		Response.Write "Message was sent to EASendMail service successfully!" 
	Else 
		Response.Write "<font color=red>Error:" & oSmtp.GetLastErrDescription() & "<br>Please make sure you installed EASendMail Service on the server!</font>" 'Get last error description 
	End If
End Sub

%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>ASP, VBScript + Queue Database Sample For EASendMail ActiveX Object</title>
    <meta http-equiv="Content-Type" content="text-html; charset=utf-8" />
    <link rel="stylesheet" type="text/css" href="sample.css" />
   <script type="text/javascript">

       if (window.attachEvent) {
           window.attachEvent('onload', init_gui);
       } else {
           if (window.onload) {
               var curronload = window.onload;
               var newonload = function(e) {
                   curronload(e);
                   init_gui();
               };
               window.onload = newonload;
           } else {
               window.onload = init_gui;
           }
       }
       function init_gui() {
           var server = document.getElementById("serveraddr");
           server.onkeyup = (function(e) {
               changesettingbyserver(server.value.toLowerCase());
           });

           var auth = document.getElementById("authrequired");
           auth.onclick = (function(e) {
               enableuserpassword(auth.checked);
           });

           enableuserpassword(auth.checked);
       }

       function enableuserpassword(enabled) {
           document.getElementById("user").disabled = !enabled;
           document.getElementById("password").disabled = !enabled;
       }

       function changesettingbyserver(server) {
           if (server == "smtp.live.com" || server == "smtp.office365.com" ||
                server == "smtp.gmail.com" || server == "smtp.mail.yahoo.com" ||
                server == "smtp.aol.com") {

               document.getElementById("authrequired").checked = true;
               document.getElementById("SSL").checked = true;
               enableuserpassword(true);

               document.getElementById("serverport").options.selectedIndex = 1;
           }
       }
        
    </script>    
</head>
<body>
    <div id="s_title">
        ASP, VBScript + Queue Database Sample For EASendMail ActiveX Object</div>
    <form name="thisForm" method="post" action="default.asp">
    <div id="div_main">
        <%
    Dim authrequired, SSL, htmlformat
    authrequired = ""
    SSL = ""
    htmlformat = ""

    If Request.ServerVariables("REQUEST_METHOD") = "POST" Then
	    Response.Write("<div id=""s_info"">")
	    SendMail 
        If Request.Form("authrequired") <> "" Then
            authrequired = "checked=""checked"""
        End If
        
        If Request.Form("SSL") <> "" Then
            SSL = "checked=""checked"""
        End If
        
        If Request.Form("htmlformat") <> "" Then
            htmlformat = "checked=""checked"""
        End If

	    Response.Write("</div>")
    End If 
        %>
        <div class="comments">
            To run this sample, you should download <a href="http://www.emailarchitect.net/webapp/download/easendmailservice.exe">
                EASendMail Service</a> and install it on the server. If you don't specify a
            smtp server, EASendMail will send email by the setting in EASendMail Service.<br />
            <br />
            <b>easendmail_demo.mdb</b> is a demo database in EASendMail service(c:\program files\EASendMailService),
            this sample will send email to all the recipients in recipients table, before run
            the sample, we suggest that you edit the recipients table at first.
            <br />
            <br />
            If the email couldn't be delivered to the recipient, a delivery report will be sent
            to the sender email address.
        </div>
        <table cellpadding="0" cellspacing="0">
            <tr>
                <td width="150">
                    SMTP Server
                </td>
                <td>
                    <input type="text" name="serveraddr" id="serveraddr" style="width:400px;" value="<%=Request.Form("serveraddr")%>" />
                     <select name="serverport" id="serverport">
                        <option value="25">25</option>
                        <option value="587">587</option>
                        <option value="465">465</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td>
                    &nbsp;
                </td>
                <td>
                    <input type="checkbox" name="authrequired" id="authrequired" <%=authrequired%> />My server requires
                    user authentication
                </td>
            </tr>
            <tr>
                <td>
                    User
                </td>
                <td>
                    <input type="text" name="user" id="user" style="width: 50%;" value="<%=Request.Form("user")%>" />
                </td>
            </tr>
            <tr>
                <td>
                    Password
                </td>
                <td>
                    <input type="password" name="password" id="password" style="width: 50%;" value="<%=Request.Form("password")%>" />
                </td>
            </tr>
            <tr>
                <td>
                    &nbsp;
                </td>
                <td>
                    <input type="checkbox" name="SSL" id="SSL" <%=SSL%> />My server requires secure connection
                    (SSL)
                </td>
            </tr>
            <tr>
                <td>
                    Server Protocl:
                </td>
                <td>
                    <select name="protocol">
                        <%
			fnShowProtocol Request.Form("protocol")
                        %>
                    </select>
                </td>
            </tr>
            <tr>
                <td>
                    From:
                </td>
                <td>
                    <input type="text" name="from" style="width: 95%;" value="<%=Server.HTMLEncode(Request.Form("from"))%>" />
                </td>
            </tr>
            <tr>
                <td>
                    To(X-Sql-Select):
                </td>
                <td>
                    <div class="comments">
                        X-Sql-Select:EASendMail will select the fields by the following sql statement before
                        sending email, then pick the recipient address from specified field(please refer
                        to the source code).
                    </div>
                    <input type="text" name="recipients" size="80" value="SELECT id, name, address FROM Recipients" />
                </td>
            </tr>
            <tr>
                <td>
                    X-Data-Connection:
                </td>
                <td>
                    <div class="comments">
                        X-Data-Connection:<br>
                        EASendMail will use the following connection to connect to the database, the syntax
                        is same as ADO connection object.
                    </div>
                    <div class="comments">
                        {$var_easendmailpath}\easendmail_demo.mdb is a demo database in EASendMail service,
                        {$var_easendmailpath} will be replace by EASendMail with current path automatically.
                    </div>
                    <div>
                                            <b>x64: If your windows is x64 bit.
                        Please change the connection string to the following value.
                            You also need to download x64 MS Access driver and install it on your machine.
</b>
                    </div>
                                        <p><b>MS Access Database Driver Download</b></p>
                <p>
                <a href="http://www.microsoft.com/en-us/download/details.aspx?id=13255" target="_blank">Microsoft Access Database Engine 2010 Redistributable</a>
                    </p>

                    <p>
<b>
 Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq={$var_easendmailpath}\easendmail_demo.mdb;Uid=;Pwd=;</b>
                    </p>
                    <input type="text" name="DataConnection" style="width: 95%;" value="Driver={Microsoft Access Driver (*.mdb)};Dbq={$var_easendmailpath}\easendmail_demo.mdb;Uid=;Pwd=;" />
                </td>
            </tr>
            <tr>
                <td>
                    X-Sql-OnSentSuccess:
                </td>
                <td>
                    <div class="comments">
                        X-Sql-OnSentSuccess:EASendMail service will execute the following sql statement
                        on every email was sent successfully.
                    </div>
                    <input type="text" name="OnSuccess" style="width: 95%;" value="INSERT INTO sentlog (server, email) VALUES('{$var_server}', '{$var_rcptaddr}')" />
                </td>
            </tr>
            <tr>
                <td>
                    X-Sql-OnSentError:
                </td>
                <td>
                    <div class="comments">
                        X-Sql-OnSentError:EASendMail service will execute the following sql statement on
                        every email could not be delivered.
                    </div>
                    <input type="text" name="OnError" style="width: 95%;" value="INSERT INTO errorlog(email, server, errorcode, errordescription) VALUES('{$var_rcptaddr}', '{$var_server}', '{$var_errcode}', '{$var_errdesc}')" />
                </td>
            </tr>
            <tr>
                <td width="150">
                    Encoding
                </td>
                <td>
                    <select name="charset">
                        <%
			fnShowComposeCharset
                        %>
                    </select>
                </td>
            </tr>
            <tr>
                <td>
                    Subject
                </td>
                <td>
                    <input type="text" name="subject" value="Classic ASP from advanced queue with database test" style="width: 95%;" />
                </td>
            </tr>
            <tr>
                <td>
                    Html Format
                </td>
                <td>
                    <input type="checkbox" name="htmlformat" <%=htmlformat%> />
                </td>
            </tr>
            <tr>
                <td valign="top">
                    Message Body
                </td>
                <td>
                    <textarea name="bodytext" cols="80" rows="20" style="width: 95%;">
Hi {$var_srecord:name}, 
this sample demonstrates how to send email in asp.net with EASendMail service.

From:[$from]
To:{$var_srecord:address} 
Subject:[$subject]

recipient email address and name variable will be replaced by EASendMail service automatically
If no server address was specified, the email will be delivered to the recipient's server by the setting in EASendMail Service.
Your id in database is {$var_srecord:id}.
No matter how many recipients there are, EASendMail 
service will send the email in background.
	
Database connection string reference:
MS SQL server
"Driver={SQL Server};Server=localhost;Database=pubs;Uid=sa;Pwd=asdasd;" 
MS Access
"Driver={Microsoft Access Driver (*.mdb)};Dbq=C:\\mydatabase.mdb;Uid=Admin;Pwd=;"
ORACLE
"Driver={Microsoft ODBC for Oracle};Server=OracleServer.world;Uid=Username;Pwd=asdasd;" 
MySQL
"DRIVER={MySQL ODBC 3.51 Driver};SERVER=localhost;DATABASE=myDatabase;USER=myUsername;PASSWORD=myPassword;OPTION=3;"
	
						</textarea>
                </td>
            </tr>
            <tr>
                <td>
                </td>
                <td>
                    <input type="submit" name="submit1" value=" Send Mail ">
                    - <a href="default.asp">Reset</a>
                </td>
            </tr>
        </table>
    </div>
    </form>
    <div id="tailer">
        Technical Support: <a href="mailto:support@emailarchitect.net">support@emailarchitect.net</a>
        <br />
        <br />
        <a href="http://www.emailarchitect.net" target="_blank">2006 - 2019 Copyright &copy;
            AdminSystem Software Limited. All rights reserved.</a>
    </div>
</body>
</html>
