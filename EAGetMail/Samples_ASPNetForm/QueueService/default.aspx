<%@ Page Language="c#" AutoEventWireup="true" ValidateRequest="false" CodePage="65001" %>

<%@ Import Namespace="System.IO" %>
<%@ Import Namespace="EAGetMail" %>

<script language="c#" runat="server">
    private string statusText = "";

    private void Page_Load(object sender, System.EventArgs e)
    {
        // Put user code to initialize the page here
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
            statusText = ep.Message + ", please make sure you have installed EAGetMail Service.";
        }
    }

    private void btnRefresh_Click(object sender, System.EventArgs e)
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
            // "invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
            // "trial version expired" exception will be thrown.
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

        string localInbox = String.Format("{0}\\inbox", Server.MapPath(""));
        if (!System.IO.Directory.Exists(localInbox))
            Directory.CreateDirectory(localInbox);

        //send request to EAGetMail Service, then EAGetMail Service retrieves email
        //in background and 'this method returns immediately
        client.GetMailsByQueue(server, localInbox, bLeaveCopy);
        statusText = "Task has been submitted to EAGetMail Service successfully, EAGetMail will retrieve emails in background, please click \"Refresh local emails\" later to check retrieved email.";
    }

</script>

<!DOCTYPE html>
<html>
<head>
    <title>EAGetMail ASP_NET + SERVICE SAMPLE</title>
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
        <p>
            To run this sample, you should download <a href="http://www.emailarchitect.net/webapp/download/eagetmailservice.exe">EAGetMail Service</a> and install it on the server.
        </p>
        <%
                if (statusText.Length > 0)
                {
                    Response.Write("<div class=\"information\">" + Server.HtmlEncode(statusText) + "</div>");
                }
            %>
        <form id="Form1" method="post" runat="server">
            <table style="width: 640px;">
                <tr>
                    <td>
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
                            <asp:ListItem Value="2">Exchange Web Service - 2007/2010</asp:ListItem>
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
                        <asp:Button ID="btnCheck" runat="server" Height="32px" Width="336px" Text="Retrieve email by EAGetMail Service in background" OnClick="btnCheck_Click"></asp:Button>
                    </td>
                </tr>
                <tr>
                    <td></td>
                    <td>
                        <asp:Button ID="btnRefresh" runat="server" Height="32px" Width="336px" Text="Refresh local emails" OnClick="btnRefresh_Click"></asp:Button>
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
    </script>
</body>
</html>
