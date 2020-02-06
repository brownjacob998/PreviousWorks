// ===============================================================================
// |    THIS CODE AND usageInfoRMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF      |
// |    ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO    |
// |    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A         |
// |    PARTICULAR PURPOSE.                                                    |
// |    Copyright (c)2010 - 2019  AdminSystem Software Limited                       |
// |
// |    Project: It demonstrates how to use EAGetMailObj to parse email summary in JScript
// |
// |    Author: Ivan Lui (ivan@emailarchitect.net)
//  ===============================================================================
var usageInfo = "";
var args = WScript.Arguments;
if(args.Length < 1)
{
	usageInfo =  "Usage: cscript ParseEmail.js [email file path]\r\n";
	usageInfo = usageInfo + "   eg: cscript ParseEmail.js \"d:\\1.eml\"";
	WScript.Echo(usageInfo);
	WScript.Quit();
}

var oMail = new ActiveXObject("EAGetMailObj.Mail");

// For evaluation usage, please use "TryIt", for licensed user, please use your license code here
oMail.LicenseCode = "TryIt";

// If email file is *.msg (outlook msg file), please change it to
// oMail.LoadOMSGFile(args(0));
oMail.LoadFile(args(0), false);

// If email has winmail.dat, decode it automatically.
oMail.DecodeTNEF();

// Decrypt email
if(oMail.IsEncrypted)
{
	oMail = oMail.Decrypt(null);
}

// Verify digital signature
if(oMail.IsSigned)
{	
	var oSignerCert = oMail.VerifySignature();
}

// Parse From and Reply-To
var header = "";
header = "From: " + oMail.From.Name + "<" + oMail.From.Address + ">\r\n";
header += "Reply-To: " + oMail.ReplyTo.Name + "<" + oMail.ReplyTo.Address + ">\r\n"; 

// Parse To
header += "To: ";
var addressList = oMail.ToList;

for(var i = 0; i < addressList.Count; i++)
{
	var address = addressList.Item(i);
	header += address.Name + "<" + address.Address + ">; ";
}
header += "\r\n";

// Parse Cc
var addressList = oMail.CcList;
if(addressList.Count > 0)
{
	header += "CC: ";
	for(var i = 0; i < addressList.Count; i++)
	{
		var address = addressList.Item(i);
		header += address.Name + "<" + address.Address + ">; ";
	}
	header += "\r\n";
}

// Parse Subject and date
header +=  "Subject: " + oMail.Subject + "\r\n";
header +=  "Date: " + oMail.ReceivedDate + "\r\n";

var attachmentList = oMail.AttachmentList;
if( attachmentList.Count > 0)
{
	header += "Attachments: ";
	for(var i = 0; i < attachmentList.Count; i++)
	{
		var att = attachmentList.Item(i);
		header += att.ContentType + ":" + att.Name + "; ";

		// You can save attachment like this
		// att.SaveAs("d:\\tempdata\\" + att.Name, true);
	}
	header += "\r\n";
}

WScript.Echo(header);
WScript.Echo("");
WScript.Echo(oMail.TextBody);

// display the htmlbody
// WScript.Echo(oMail.HtmlBody)
