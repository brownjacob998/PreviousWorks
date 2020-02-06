// ===============================================================================
// |    THIS CODE AND usageInfoRMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF      |
// |    ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO    |
// |    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A         |
// |    PARTICULAR PURPOSE.                                                    |
// |    Copyright (c)2010 - 2019 AdminSystem Software Limited                       |
// |
// |    Project: It demonstrates how to use EAGetMailObj to retrieve email summary in JScript
// |
// |    Author: Ivan Lui (ivan@emailarchitect.net)
//  ===============================================================================
var MailServerConnectType_ConnectSSLAuto = 0;
var MailServerConnectType_ConnectSSL = 1;
var MailServerConnectType_ConnectTLS = 2;

var ProxyType_Socks4 = 0;
var ProxyType_Socks5 = 1;
var ProxyType_Http = 2;

var MailServerAuthLogin = 0;
var MailServerAuthCRAM5 = 1;
var MailServerAuthNTLM = 2;

var MailServerPop3 = 0;
var MailServerImap4 = 1;
var MailServerEWS = 2; // Exchange Web Service
var MailServerDAV = 3; // Exchange WebDAV

var usageInfo = "";
var args = WScript.Arguments;
if (args.Length < 3) {
	usageInfo = "Usage: cscript PreviewEmail.js [pop3server] [user] [password] [pop|imap|ews|dav]\r\n";
	usageInfo = usageInfo + "   eg: cscript PreviewEmail.js mail.adminsystem.net test@adminsystem.net test pop\r\n";
	WScript.Echo(usageInfo);
	WScript.Quit();
}

var oServer = new ActiveXObject("EAGetMailObj.MailServer");
var oClient = new ActiveXObject("EAGetMailObj.MailClient");

// For evaluation usage, please use "TryIt", for licensed user, please use your license code here
oClient.LicenseCode = "TryIt";

oServer.Server = args(0);
oServer.User = args(1);
oServer.Password = args(2);

// If your server doesn't require SSL, please remove this line
oServer.SSLConnection = true;

var protocol;
if (args.Length >= 4) {
	protocol = args(3).toLowerCase();
}

if (protocol == "imap") {
	oServer.Protocol = MailServerImap4;
}
else if (protocol == "ews") {
	oServer.Protocol = MailServerEWS;
}
else if (protocol == "dav") {
	oServer.Protocol = MailServerDAV;
}
else {
	oServer.Protocol = MailServerPop3;
}

if (oServer.Protocol == MailServerImap4) {
	oServer.Port = oServer.SSLConnection ? 993 : 143; // 993 is ssl port, 143 is plain TCP port.
}
else if (oServer.Protocol == MailServerPop3) {
	oServer.Port = oServer.SSLConnection ? 996 : 110; // 995 is ssl port, 110 is plain TCP port.
}

WScript.Echo("Connecting " + args(0) + " ...");
oClient.Connect(oServer)

var mailInfos = oClient.GetMailInfoList();
WScript.Echo("Total " + mailInfos.Count + " email(s)\r\n");

for (var i = 0; i < mailInfos.Count; i++) {
	
	var mailInfo = mailInfos.Item(i);
	WScript.Echo("retrieving header data of uidl: " + mailInfo.UIDL + ", index: " + (i + 1) + " email ...");


	var oMail = new ActiveXObject("EAGetMailObj.Mail");
	// For evaluation usage, please use "TryIt", for licensed user, please use your license code here
	oMail.LicenseCode = "TryIt";

	// Get email headers only, then you dont have to download entire email
	// but if you want to get email body/attachments, you should use 
	// oMail = oClient.GetMail(mailInfo);
	oMail.Load(oClient.GetMailHeader(mailInfo));

	var oHeaders = oMail.Headers;
	var headerString = ""
	var x = 0;
	for (x = 0; x < oHeaders.Count; x++) {
		var oHeader = oHeaders.Item(x);
		headerString += oHeader.HeaderKey + ":" + oHeader.HeaderValue + "\r\n";
	}

	WScript.Echo(headerString)
}

oClient.Quit();