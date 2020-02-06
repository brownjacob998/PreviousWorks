<%@ Page Language="c#" AutoEventWireup="true" ValidateRequest="false" CodePage="65001" %>

<%@ Import Namespace="System.IO" %>
<%@ Import Namespace="System.Globalization" %>
<%@ Import Namespace="EAGetMail" %>

<script language="c#" runat="server">
    private string statusText = "";
    private void Page_Load(object sender, System.EventArgs e)
    {
        try
        {
            ListMail();
        }
        catch (Exception ep)
        {
            statusText = ep.Message;
        }
    }

    private void btnCheck_Click(object sender, System.EventArgs e)
    {
        if (textServer.Text.Length == 0 ||
            textUser.Text.Length == 0 ||
            textPassword.Text.Length == 0)
        {
            statusText = "Please input server, user and password!";
            return;
        }

        try
        {
            RetrieveEmail();
            ListMail();
        }
        catch (Exception ep)
        {
            statusText = ep.Message;
        }
    }

    private void ListMail()
    {
        string localInbox = String.Format("{0}\\inbox", Server.MapPath(""));
        if (!System.IO.Directory.Exists(localInbox))
            Directory.CreateDirectory(localInbox);

        tbMail.Rows.Clear();

        TableRow row = new TableRow();
        TableCell cel = new TableCell();
        cel.Text = "<b>From</b>";
        row.Cells.Add(cel);

        cel = new TableCell();
        cel.Text = "<b>Subject</b>";
        row.Cells.Add(cel);

        cel = new TableCell();
        cel.Text = "<b>Date</b>";
        row.Cells.Add(cel);

        cel = new TableCell();
        cel.Text = "<b>&nbsp;</b>";
        row.Cells.Add(cel);

        tbMail.Rows.Add(row);

        string[] files = Directory.GetFiles(localInbox, "*.eml");
        int count = files.Length;
        for (int i = 0; i < count; i++)
        {
            string fullname = files[i];

            // For evaluation usage, please use "TryIt" as the license code, otherwise the 
            // "Invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
            // "Trial version expired" exception will be thrown.

            Mail mail = new Mail("TryIt");
            mail.Load(fullname, true);
            row = new TableRow();
            cel = new TableCell();
            string s = Server.HtmlEncode(mail.From.ToString());
            if (s.Length == 0)
                s = "[no sender]";

            s = String.Format("<a href=\"display.aspx?name={0}\" onclick=\"javascript:fnDisplay( this.href );return false;\">{1}</a>",
                Server.UrlEncode(fullname), s);

            cel.Text = s;
            row.Cells.Add(cel);

            cel = new TableCell();
            cel.Text = Server.HtmlEncode(mail.Subject);
            row.Cells.Add(cel);

            cel = new TableCell();
            cel.Text = mail.ReceivedDate.ToString("yyyy-MM-dd HH:mm:ss");
            row.Cells.Add(cel);

            s = String.Format("<a href=\"delete.aspx?name={0}\">Delete</a>",
                Server.UrlEncode(fullname));

            cel = new TableCell();
            cel.Text = s;
            row.Cells.Add(cel);

            tbMail.Rows.Add(row);
        }
    }

    private string GenerateFileName(int sequence)
    {
        DateTime currentDateTime = DateTime.Now;
        string sdate = currentDateTime.ToString("yyyyMMddHHmmss", new CultureInfo("en-US"));
        return string.Format("{0}-{1:000}-{2:000}.eml",
            currentDateTime.ToString("yyyyMMddHHmmss", new CultureInfo("en-US")),
            currentDateTime.Millisecond,
            sequence);
    }

    private int GetMaxCountToDownload(int mailCount)
    {
        int downloadCount = mailCount;
        switch (lstRange.SelectedIndex)
        {
            case 0:
                downloadCount = 10;
                break;
            case 1:
                downloadCount = 30;
                break;
            case 2:
                downloadCount = 100;
                break;
            default:
                break;
        }

        if (downloadCount > mailCount)
        {
            downloadCount = mailCount;
        }

        return downloadCount;
    }


    private void RetrieveEmail()
    {
        MailServer server = new MailServer(textServer.Text,
            textUser.Text, textPassword.Text, chkSSL.Checked,
            (ServerAuthType)lstAuthType.SelectedIndex, (ServerProtocol)lstProtocol.SelectedIndex);

        if (server.Protocol == ServerProtocol.Pop3)
        {
            server.Port = (chkSSL.Checked) ? 995 : 110;
        }
        else if (server.Protocol == ServerProtocol.Imap4)
        {
            server.Port = (chkSSL.Checked) ? 993 : 143;
        }
        
        MailClient client = new MailClient("TryIt");
        bool bLeaveCopy = chkLeaveCopy.Checked;

        // UIDL is the identifier of every email on POP3/IMAP4/Exchange server, to avoid retrieve
        // the same email from server more than once, we record the email UIDL retrieved every time
        // if you delete the email from server every time and not to leave a copy of email on
        // the server, then please remove all the function about uidl.
        // UIDLManager wraps the function to write/read uidl record from a text file.

        UIDLManager uidlManager = new UIDLManager();
        bool isUidlLoaded = false;
        try
        {
            string localInbox = String.Format("{0}\\inbox", Server.MapPath(""));
            if (!System.IO.Directory.Exists(localInbox))
                Directory.CreateDirectory(localInbox);

            // load existed uidl records to UIDLManager
            string uidlfile = String.Format("{0}\\uidl.txt", localInbox);
            uidlManager.Load(uidlfile);
            isUidlLoaded = true;

            client.Connect(server);
            MailInfo[] infos = client.GetMailInfos();

            // Remove the local uidl which is not existed on the server.
            uidlManager.SyncUIDL(server, infos);
            uidlManager.Update();

            int remain = infos.Length;
            int countToDownload = GetMaxCountToDownload(infos.Length);
            int downloaded = 0;
            for (int i = 0; i < infos.Length; i++)
            {
                remain--;
                MailInfo info = infos[i];
                if (uidlManager.FindUIDL(server, info.UIDL) != null)
                {
                    continue;
                }

                Mail mail = client.GetMail(info);
                string fileName = GenerateFileName(i);
                mail.SaveAs(string.Format("{0}\\{1}", localInbox, fileName), true);

                if (bLeaveCopy)
                {
                    // Add the email uidl to uidl file to avoid we retrieve it next time. 
                    uidlManager.AddUIDL(server, info.UIDL, fileName);
                }
                else
                {
                    client.Delete(info);
                    // Remove UIDL from local uidl file.
                    uidlManager.RemoveUIDL(server, info.UIDL);
                }

                downloaded++;
                if (downloaded >= countToDownload)
                {
                    break;
                }
            }

            // Delete method just mark the email as deleted, 
            // Quit method expunge the emails from server exactly.
            client.Quit();

            statusText = string.Format("Total {0} email(s) on server, {1} email(s) downloaded this time, {2} email(s) unchecked on server, please click \"Retrieve\" again to download unchecked emails.",
                infos.Length,
                downloaded,
                remain);
        }
        finally
        {
            if (isUidlLoaded)
            {
                // Update the uidl list to local uidl file and then we can load it next time.
                uidlManager.Update();
            }
        }
    }
</script>
<!DOCTYPE html>
<html>
<head>
    <title>EAGetMail ASP.NET Sample</title>
    <meta http-equiv="Content-Type" content="text-html; charset=utf-8" />
    <meta name="CODE_LANGUAGE" content="C#" />
    <meta name="vs_defaultClientScript" content="JavaScript" />
    <link href="sample.css" rel="stylesheet" />
</head>
<body>
    <div id="s_title">
        ASP.NET Sample For EAGetMail Component
    </div>
    <div id="div_main">
        <form id="Form1" method="post" runat="server">

            <%
                if (statusText.Length > 0)
                {
                    Response.Write("<div class=\"information\">" + Server.HtmlEncode(statusText) + "</div>");
                }
            %>

            <table style="width: 640px;">
                <tr>
                    <td style="width: 100px;">
                        <asp:Label ID="Label1" runat="server" Width="73px" Height="24px">Server:</asp:Label></td>
                    <td>
                        <asp:TextBox ID="textServer" runat="server" Width="248px"></asp:TextBox></td>
                </tr>
                <tr>
                    <td>
                        <asp:Label ID="Label2" runat="server" Width="48px">User:</asp:Label></td>
                    <td>
                        <asp:TextBox ID="textUser" runat="server" Width="248px"></asp:TextBox></td>
                </tr>
                <tr>
                    <td>
                        <asp:Label ID="Label3" runat="server" Height="24px" Width="56px">Password:</asp:Label></td>
                    <td>
                        <asp:TextBox ID="textPassword" runat="server" Width="248px"></asp:TextBox></td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <asp:CheckBox ID="chkSSL" Checked="true" runat="server" Height="24px" Width="328px" Text="My server requires SSL connection"></asp:CheckBox></td>
                </tr>
                <tr>
                    <td>Auth Type</td>
                    <td>
                        <asp:DropDownList ID="lstAuthType" runat="server" Height="24px" Width="248px">
                            <asp:ListItem Value="0" Selected="True">User Login</asp:ListItem>
                            <asp:ListItem Value="1">APOP/CRAM-MD5</asp:ListItem>
                            <asp:ListItem Value="2">NTLM</asp:ListItem>
                        </asp:DropDownList>
                    </td>
                </tr>
                <tr>
                    <td>Protocol</td>
                    <td>
                        <asp:DropDownList ID="lstProtocol" runat="server" Height="24px" Width="248px">
                            <asp:ListItem Value="0" Selected="True">POP3 Server</asp:ListItem>
                            <asp:ListItem Value="1">IMAP4 Server</asp:ListItem>
                            <asp:ListItem Value="2">Exchange Web Service - 2007-2019/Office 365</asp:ListItem>
                            <asp:ListItem Value="3">Exchange WebDAV - 2000/2003</asp:ListItem>
                        </asp:DropDownList>
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <asp:CheckBox ID="chkLeaveCopy" Checked="true" runat="server" Height="16px" Width="336px" Text="Leave a copy of message on Server"></asp:CheckBox>
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <div class="comments">
                            Warning: If "leave a copy of message on server" is unchecked, the email will be
                        deleted after it has been downloaded
                        </div>
                        <div class="comments">
                            If there are too many emails in your mailbox, it may cause ASP.NET timeout
                        </div>
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <asp:DropDownList ID="lstRange" runat="server" Height="24px" Width="248px">
                            <asp:ListItem Value="0" Selected="True">Download 10 emails each time</asp:ListItem>
                            <asp:ListItem Value="1">Download 30 emails each time</asp:ListItem>
                            <asp:ListItem Value="2">Download 100 emails each time</asp:ListItem>
                            <asp:ListItem Value="3">Download all emails</asp:ListItem>
                        </asp:DropDownList>
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <asp:Button ID="btnCheck" runat="server" Height="32px" Width="180px" Text="Retrieve Email" OnClick="btnCheck_Click"></asp:Button>
                        <a href="default.aspx" style="margin-left: 20px;">Reset</a>
                    </td>
                </tr>
            </table>
            <hr />
            <asp:Table ID="tbMail" runat="server" Height="56px" Width="640px"></asp:Table>
        </form>
    </div>
    <script type="text/jscript">
        function fnDisplay(v) {
            window.open(v,
                "",
                "height=640,width=800,menubar=no,resizable=yes,scrollbars=yes,status=yes",
                false);
        }

        function DisableButton() {
          
            document.getElementById("btnCheck").disabled = true;
        }
        window.onbeforeunload = DisableButton;
    </script>
</body>
</html>
