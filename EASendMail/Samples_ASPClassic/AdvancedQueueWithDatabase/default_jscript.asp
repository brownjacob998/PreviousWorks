<%@  codepage="65001" language="JScript" %>
<%
    // ===============================================================================
    // |    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF      |
    // |    ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO    |
    // |    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A         |
    // |    PARTICULAR PURPOSE.                                                    |
    // |    Copyright (c)2010 - 2019  ADMINSYSTEM SOFTWARE LIMITED                         |
    // |
    // | FILE: SAMPLE.ASP
    // | SYNOPSIS: SAMPLE FILE FOR EASendMail ActiveX Object (JScript)
    // | IVON LUI (ivan@emailarchitect.net)
    // |        CREATED MAY 2001
    // |
    // =================================================================================*/
    Response.CharSet = "utf-8";
    function getFromName(src) {
        var pos = src.indexOf("<");
        if (pos != -1) {
            return fnTrim(src.substr(0, pos), ",<\"> \t")
        }
        else {
            return "";
        }
    }

    function getFromAddr(src) {
        var pos = src.indexOf("<");
        if (pos != -1) {
            return fnTrim(src.substr(pos), ",<\"> \t")
        }
        else {
            return fnTrim(src, ",<\"> \t")
        }
    }

    function fnTrim(src, trimer) {
        var len = src.length;
        var i = 0;
        if (len > 0) {
            for (i = 0; i < len; i++) {
                var ch = src.charAt(i);
                if (trimer.indexOf(ch) == -1) {
                    break;
                }
            }
            src = src.substr(i);
        }

        len = src.length
        if (len > 0) {
            for (i = len - 1; i >= 0; i--) {
                var ch = src.charAt(i);
                if (trimer.indexOf(ch) == -1) {
                    break;
                }
            }

            src = src.substr(0, i + 1);
        }
        return src;
    }
    function fnShowProtocol(protocol) {

        if (isNaN(protocol)) {
            protocol = 0;
        }

        Response.write('/' + protocol + '/')

        var arProtocol = new Array("SMTP Protocol - Recommended:0",
						"Exchange Web Service - Exchange 2007/2010:1",
						"Exchange WebDav - Exchange 2000/2003:2"
							);

        var nCount = arProtocol.length;
        var s = "";

        for (var i = 0; i < nCount; i++) {
            var buf = arProtocol[i];
            var pos = buf.indexOf(":");
            if (pos < 0) {
                continue;
            }

            var s1 = buf.substr(0, pos);
            var s2 = buf.substr(pos + 1);
            s = s + "<option value=\"" + s2 + "\"";
            if (s2 * 1 == protocol * 1) {
                s += " selected";
            }
            s = s + ">" + s1 + "</option>\r\n";
        }
        Response.Write(s);
    }

    function fnShowComposeCharset() {
        var arCharset = new Array("Arabic(Windows):windows-1256",
						"Baltic(ISO):iso-8859-4",
						"Baltic(Windows):windows-1257",
						"Central Euporean(ISO):iso-8859-2",
						"Central Euporean(ISO):windows-1250",
						"Chinese Simplified(GB18030):GB18030",
						"Chinese Simplified(GB2312):gb2312",
						"Chinese Simplified(HZ):hz-gb-2312",
						"Chinese Traditional(Big5):big5",
						"Cyrillic(ISO):iso-8859-5",
						"Cyrillic(KOI8-R):koi8-r",
						"Cyrillic(KOI8-U):koi8-u",
						"Cyrillic(Windows):windows-1251",
						"Greek(ISO):iso-8859-7",
						"Greek(Windows):windows-1253",
						"Hebrew(Windows):windows-1255",
						"Japanese(JIS):iso-2022-jp",
						"Korean:ks_c_5601-1987",
						"Korean(EUC):euc-kr",
						"Latin 9(ISO):iso-8859-15",
						"Thai(Windows):windows-874",
						"Turkish(ISO):iso-8859-9",
						"Turkish(Windows):windows-1254",
						"Unicode(UTF-7):utf-7",
						"Unicode(UTF-8):utf-8",
						"Vietnames(Windows):windows-1258",
						"Western European(ISO):iso-8859-1",
						"Western European(Windows):Windows-1252"
							);

        var nCount = arCharset.length;
        var s = "";
        var charset = "utf-8";

        for (var i = 0; i < nCount; i++) {
            var buf = arCharset[i];
            var pos = buf.indexOf(":");
            if (pos < 0) {
                continue;
            }

            var s1 = buf.substr(0, pos);
            var s2 = buf.substr(pos + 1);
            s = s + "<option value=\"" + s2 + "\"";
            if (s2 == charset) {
                s += " selected";
            }
            s = s + ">" + s1 + "</option>\r\n";
        }
        Response.Write(s);
    }

    function SendMail() {
        var from, recipients
        from = new String(Request.Form("from"))
        recipients = new String(Request.Form("recipients"))

        if (from.length == 0 || recipients.length == 0) {
            Response.Write("<font color=red>Please input From, To</font>");
            return;
        }

        var oSmtp = Server.CreateObject("EASendMailObj.Mail");
        //The license code for EASendMail ActiveX Object,
        //for evaluation usage, please use "TryIt" as the license code.
        oSmtp.LicenseCode = "TryIt";

        var serveraddr = new String(Request.Form("serveraddr"));
        oSmtp.ServerAddr = serveraddr;
        oSmtp.Protocol = Request.Form("protocol") * 1;

        // Using TryTLS,
        // If smtp server supports TLS, then TLS connection is used; otherwise, normal TCP connection is used.
        // https://www.emailarchitect.net/easendmail/sdk/?ct=connecttype
        oSmtp.ConnectType = 4;

        oSmtp.Charset = Request.Form("charset");

        //Using ESMTP authentication
        if (serveraddr.length > 0) {
            if (Request.Form("authrequired") == "on") {
                oSmtp.UserName = Request.Form("user");
                oSmtp.Password = Request.Form("password");
            }

            if (Request.Form("SSL") == "on") {
                // use SSL/TLS based on server port
                oSmtp.ConnectType = 1;
            }
        }

        oSmtp.From = getFromName(from);
        oSmtp.FromAddr = getFromAddr(from);

        //Using this email to be replied to another address 
        //oSmtp.ReplyTo = "ReplyAddress: 

        //Using this email to be replied to another address 
        //oSmtp.ReplyTo = ReplyAddress 

        //pick "name" field as the recipient name and "address" field as the recipient address.
        //you can also use {$var_srecord:fieldname} to pick any field in X-Sql-Select statement
        // and put it to subject, bodytext, then EASendMail will replace it automatially.

        oSmtp.DisplayTo = "\"{$var_srecord:name}\" <{$var_srecord:address}>";
        oSmtp.AddHeader("X-Rcpt-To", "{$var_srecord:address}");

        // For more connection string
        // MS SQL server
        //"Driver={SQL Server};Server=localhost;Database=pubs;Uid=sa;Pwd=asdasd;" 
        // MS Access
        //"Driver={Microsoft Access Driver (*.mdb)};Dbq=C:\mydatabase.mdb;Uid=Admin;Pwd=;"
        // ORACLE
        //"Driver={Microsoft ODBC for Oracle};Server=OracleServer.world;Uid=Username;Pwd=asdasd;" 
        // MySQL
        //"DRIVER={MySQL ODBC 3.51 Driver};SERVER=localhost;DATABASE=myDatabase;USER=myUsername;PASSWORD=myPassword;OPTION=3;" 
        // other connection string
        // please refer to: http://www.connectionstrings.com/

        // To check the database error, please use EASendMail Service Manager->Journal->System Error

        oSmtp.AddHeader("X-Data-Connection", Request.Form("DataConnection"));
        oSmtp.AddHeader("X-Sql-Select", recipients);
        oSmtp.AddHeader("X-Sql-OnSentSuccess", Request.Form("OnSuccess"));
        oSmtp.AddHeader("X-Sql-OnSentError", Request.Form("OnError"));

        //Attachs file to this email 
        //oSmtp.AddAttachment("c:\\test.txt");

        var bodytext = new String(Request.Form("bodytext"));
        var subject = new String(Request.Form("subject"));

        bodytext = bodytext.replace("[$from]", from);
        bodytext = bodytext.replace("[$subject]", subject);
        oSmtp.Subject = subject;
        oSmtp.BodyText = bodytext;

        if (Request.Form("htmlformat") == "on")
            oSmtp.BodyFormat = 1; // Using HTML FORMAT to send mail

        var hres = oSmtp.SendMailToQueue();
        //Sending email 
        if (hres == 0)
            Response.Write("Message was sent to EASendMail service successfully!");
        else
            Response.Write("<font color=red>Error: " + oSmtp.GetLastErrDescription() + "<br>Please make sure you installed EASendMail Service on the server!</font>");  //Get last error description 
    }



%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>ASP, JScript + Queue Database Sample For EASendMail ActiveX Object</title>
    <meta http-equiv="Content-Type" content="text-html; charset=utf-8" />
    <link rel="stylesheet" type="text/css" href="sample.css" />
</head>
<body>
    <div id="s_title">
        ASP, JScript + Queue Database Sample For EASendMail ActiveX Object</div>
    <form name="thisForm" method="post" action="default_jscript.asp">
    <div id="div_main">
        <%
            var authrequired, SSL, htmlformat;
            authrequired = "";
            SSL = "";
            htmlformat = "";

            if (Request.ServerVariables("REQUEST_METHOD") == "POST") {
                Response.Write("<div id=\"s_info\">");
                SendMail();
                if (Request.Form("authrequired") == "on") {
                    authrequired = "checked=\"checked\"";
                }

                if (Request.Form("SSL") == "on") {
                    SSL = "checked=\"checked\"";
                }


                if (Request.Form("htmlformat") == "on") {
                    htmlformat = "checked=\"checked\"";
                }

                Response.Write("</div>");
            }

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
                    <input type="text" name="serveraddr" style="width: 95%;" value="<%=Request.Form("serveraddr")%>" />
                </td>
            </tr>
            <tr>
                <td>
                    &nbsp;
                </td>
                <td>
                    <input type="checkbox" name="authrequired" <%=authrequired%> />My server requires
                    user authentication
                </td>
            </tr>
            <tr>
                <td>
                    User
                </td>
                <td>
                    <input type="text" name="user" style="width: 50%;" value="<%=Request.Form("user")%>" />
                </td>
            </tr>
            <tr>
                <td>
                    Password
                </td>
                <td>
                    <input type="password" name="password" style="width: 50%;" value="<%=Request.Form("password")%>" />
                </td>
            </tr>
            <tr>
                <td>
                    &nbsp;
                </td>
                <td>
                    <input type="checkbox" name="SSL" <%=SSL%> />My server requires secure connection
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
                            fnShowProtocol(Request.Form("protocol"));
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
                            fnShowComposeCharset();
                        %>
                    </select>
                </td>
            </tr>
            <tr>
                <td>
                    Subject
                </td>
                <td>
                    <input type="text" name="subject" value="Classic Asp test from advanced queue with database" style="width: 95%;" />
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
                    - <a href="default_jscript.asp">Reset</a>
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
