﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using EAGetMail;
using System.Collections;
using EAGetMail.Oauth;
using System.Globalization;

namespace AppProject1
{
    public partial class Form1 : Form
    {
        private bool _isCancelOperation = false;
        private string _uidlFile = "uidl.txt";
        private string _currentPath = "";

        public Form1()
        {
            InitializeComponent();
        }

        #region Resize Control Automatically

        bool _isFormLoaded = false;
        int _listViewMailWidthOffset = 0;
        int _webMailHeightOffset = 0;
        int _buttonDeleteLeftOffset = 0;

        private void _initControlOffset()
        {
            // No smaller than design time size
            this.MinimumSize = new System.Drawing.Size(this.Width, this.Height);
            _isFormLoaded = true;

            _listViewMailWidthOffset = this.Width - ListViewMail.Width;
            _webMailHeightOffset = this.Height - WebMail.Height;
            _buttonDeleteLeftOffset = this.Width - ButtonDelete.Left;
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            if (!_isFormLoaded)
            {
                return;
            }

            ListViewMail.Width = this.Width - _listViewMailWidthOffset;
            WebMail.Width = ListViewMail.Width;
            WebMail.Height = this.Height - _webMailHeightOffset;

            ButtonDelete.Left = this.Width - _buttonDeleteLeftOffset;
        }

        #endregion

        #region Initialize Controls

        private void _initCurrentPath()
        {
            string path = Application.ExecutablePath;
            int pos = path.LastIndexOfAny("\\/".ToCharArray());
            if (pos != -1)
            {
                path = path.Substring(0, pos);
            }

            _currentPath = path;
        }

        private void Form1_Load(object sender, System.EventArgs e)
        {
            _initCurrentPath();
            _initControlOffset();
            _initOauthWrapper();

            WebMail.Navigate("about:blank");

            // initialize authentication type
            ComboBoxAuthType.Items.Add("USER/LOGIN");
            ComboBoxAuthType.Items.Add("APOP");
            ComboBoxAuthType.Items.Add("NTLM");
            ComboBoxAuthType.Items.Add("Gmail XOAUTH2");

            ComboBoxAuthType.SelectedIndex = 0;

            // initialize mail date range
            ComboBoxDateRange.Items.Add("All emails");
            ComboBoxDateRange.Items.Add("Last 7 days");
            ComboBoxDateRange.Items.Add("Last 30 days");
            ComboBoxDateRange.Items.Add("Last 60 days");
            ComboBoxDateRange.Items.Add("Last 90 days");

            ComboBoxDateRange.SelectedIndex = 0;

            // initialize protocols.
            ComboBoxProtocol.Items.Add("POP3");
            ComboBoxProtocol.Items.Add("IMAP4");
            ComboBoxProtocol.Items.Add("EWS - Exchange 2007-2019/Office365");
            ComboBoxProtocol.Items.Add("WebDAV - Exchange 2000/2003");

            ComboBoxProtocol.SelectedIndex = 0;


            ListViewMail.Sorting = SortOrder.Descending;
            ListViewMail.ListViewItemSorter = new ListMailItemCompare();

            _loadLocalMails();
            LabelTotal.Text = string.Format("Total {0} email(s)", ListViewMail.Items.Count);
        }


        private void ComboBoxAuthType_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (ComboBoxAuthType.SelectedIndex == (int)ServerAuthType.AuthXOAUTH2)
            {
                ComboBoxProtocol.SelectedIndex = (int)ServerProtocol.Imap4;
                textServer.Text = "imap.gmail.com";
                chkSSL.Checked = true;

                textUser.Enabled = false;
                textPassword.Enabled = false;
                textStatus.Text = "Please click \"Start\" to login Gmail by Web OAUTH.";
            }
            else
            {
                textUser.Enabled = true;
                textPassword.Enabled = true;

                textStatus.Text = "";

                _oauthWrapper.OauthProvider.ClearToken();
                _oauthWrapper.AuthorizationCode = "";
            }
        }

        private void ComboBoxProtocol_SelectedIndexChanged(object sender, EventArgs e)
        {
            // By default, Exchange Web Service requires SSL connection.
            // For other protocol, please set SSL connection based on your server setting manually
            if (ComboBoxProtocol.SelectedIndex == (int)ServerProtocol.Pop3)
            {
                chkNewOnly.Checked = false;
                chkNewOnly.Enabled = false;

                ComboBoxDateRange.SelectedIndex = 0;
                ComboBoxDateRange.Enabled = false;
            }
            else
            {
                chkNewOnly.Enabled = true;
                ComboBoxDateRange.Enabled = true;
            }

            if (ComboBoxProtocol.SelectedIndex == (int)ServerProtocol.ExchangeEWS)
            {
                chkSSL.Checked = true; // By default, Exchange Web Service requires SSL
            }
        }

        OauthDesktopWrapper _oauthWrapper = null;
        void _initOauthWrapper()
        {
            /*
             To use Google OAUTH in your application, you must create a project in Google Developers Console.

            - Create your project at https://console.developers.google.com/project.
            - Select your project -> APIs & Services -> Dashboard -> Credentials;
            - Credentials -> Create Credentials -> OAuth client ID -> Web application or Other (Desktop Application). 
                It depends on your application type.

            - Input a name for your application, input your current ASP/ASP.NET URL at Authorized redirect URIs, 
                for example: http://localhost/gmailoauth/default.aspx. (Desktop Application doesn't require this step)
                Click "Create", you will get your client id and client secret.

            - Finally you can also set detail information for your project at Credentials -> OAuth consent screen.
            - If you used https://mail.google.com scope, you should verify your application that is inroduced in cosent screen.
                If you don't verify your application, your application is limited by some conditions.

            You must apply for your client id and client secret, don't use the client id in the sample project, because it is limited now.

            
            You must apply for your client id and client secret, don't use the client id in the sample project, because it is limited now.
            If you got "This app isn't verified" information, please click "advanced" -> Go to ... for test.
                */
            OauthProviderInterface provider = GoogleOauthProvider.Create("1072602369179-aru4rj97ateiho9rt4pf5i8l1r01mc16.apps.googleusercontent.com",
                                "Lnw8r5FvfKFNS_CSEucbdIE-");
            _oauthWrapper = new OauthDesktopWrapper(provider);
        }
        #endregion

        #region Retrieve emails from server

        private MailServer _buildServer()
        {
            MailServer server = new MailServer(textServer.Text.Trim(),
                textUser.Text.Trim(),
                textPassword.Text.Trim(),
                chkSSL.Checked,
                (ServerAuthType)ComboBoxAuthType.SelectedIndex,
                (ServerProtocol)ComboBoxProtocol.SelectedIndex);

            if (server.Protocol == ServerProtocol.Pop3)
            {
                server.Port = (chkSSL.Checked) ? 995 : 110;
            }
            else if (server.Protocol == ServerProtocol.Imap4)
            {
                server.Port = (chkSSL.Checked) ? 993 : 143;
            }

            return server;
        }

        private bool _validateInput()
        {
            if (string.IsNullOrEmpty(textServer.Text.Trim()))
            {
                MessageBox.Show("Please input server address!");
                textServer.Enabled = true;
                textServer.Focus();
                return false;
            }

            if (string.IsNullOrEmpty(textUser.Text.Trim()))
            {
                MessageBox.Show("Please input user!");
                textUser.Enabled = true;
                textUser.Focus();
                return false;
            }

            if (string.IsNullOrEmpty(textPassword.Text.Trim()))
            {
                MessageBox.Show("Please input password!");
                textPassword.Enabled = true;
                textPassword.Focus();
                return false;
            }

            return true;
        }

        private bool _tryOauth()
        {
            if (ComboBoxAuthType.SelectedIndex != (int)ServerAuthType.AuthXOAUTH2)
            {
                // We don't need to login user by Gmail XOAUTH
                return true;
            }

            // AccessToken is existed, if it is not expired, use it directly, otherwise refresh it.
            if (!string.IsNullOrEmpty(_oauthWrapper.OauthProvider.AccessToken))
            {
                if (!_oauthWrapper.IsAccessTokenExpired)
                {
                    return true;
                }

                textStatus.Text = "Refreshing access token ...";
                try
                {
                    _oauthWrapper.RefreshAccessToken();
                }
                catch
                {
                    textStatus.Text = "Failed to refresh access token, try to get a new access token ...";
                }
            }

            using (FormOauth DialogOauth = new FormOauth())
            {
                DialogOauth.OauthWrapper = _oauthWrapper;
                DialogOauth.ShowDialog();
            }

            try
            {
                textStatus.Text = "Requesting access token ...";
                _oauthWrapper.RequestAccessTokenAndUserEmail();
                textStatus.Text = "Oauth is completed.";
                return true;
            }
            catch (Exception ep)
            {
                MessageBox.Show(ep.Message);
                textStatus.Text = ep.Message;
                return false;
            }
        }

        private void _setMailRange(ref MailClient client)
        {
            client.GetMailInfosParam.Reset();
            if (ComboBoxProtocol.SelectedIndex == (int)ServerProtocol.Pop3)
            {
                return; // POP3 protocol doesn't support this feature.
            }

            if (chkNewOnly.Checked)
            {
                client.GetMailInfosParam.GetMailInfosOptions =
                    (client.GetMailInfosParam.GetMailInfosOptions | GetMailInfosOptionType.NewOnly);
            }

            switch (ComboBoxDateRange.SelectedIndex)
            {
                case 1:
                    client.GetMailInfosParam.GetMailInfosOptions =
                    (client.GetMailInfosParam.GetMailInfosOptions | GetMailInfosOptionType.DateRange);
                    client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-7);
                    client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1);
                    break;
                case 2:
                    client.GetMailInfosParam.GetMailInfosOptions =
                    (client.GetMailInfosParam.GetMailInfosOptions | GetMailInfosOptionType.DateRange);
                    client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-30);
                    client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1);
                    break;
                case 3:
                    client.GetMailInfosParam.GetMailInfosOptions =
                    (client.GetMailInfosParam.GetMailInfosOptions | GetMailInfosOptionType.DateRange);
                    client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-60);
                    client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1);
                    break;
                case 4:
                    client.GetMailInfosParam.GetMailInfosOptions =
                    (client.GetMailInfosParam.GetMailInfosOptions | GetMailInfosOptionType.DateRange);
                    client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-90);
                    client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1);
                    break;
                default:
                    break;
            }
        }

        private void _enableSettingControls(bool isEnabled, bool isCancelEnabled)
        {
            btnStart.Enabled = isEnabled;
            btnCancel.Enabled = isCancelEnabled;

            textServer.Enabled = isEnabled;
            chkSSL.Enabled = isEnabled;
            chkLeaveCopy.Enabled = isEnabled;

            ComboBoxAuthType.Enabled = isEnabled;
            ComboBoxProtocol.Enabled = isEnabled;

            if (ComboBoxAuthType.SelectedIndex != (int)ServerAuthType.AuthXOAUTH2)
            {
                textUser.Enabled = isEnabled;
                textPassword.Enabled = isEnabled;
            }

            if (ComboBoxProtocol.SelectedIndex != (int)ServerProtocol.Pop3)
            {
                chkNewOnly.Enabled = isEnabled;
                ComboBoxDateRange.Enabled = isEnabled;
            }
        }

        private string _createLocalInbox()
        {
            string localInbox = string.Format("{0}\\inbox", _currentPath);
            if (!Directory.Exists(localInbox))
            {
                Directory.CreateDirectory(localInbox);
            }

            return localInbox;
        }

        private string _generateFileName(int sequence)
        {
            DateTime currentDateTime = DateTime.Now;
            string sdate = currentDateTime.ToString("yyyyMMddHHmmss", new CultureInfo("en-US"));
            return string.Format("{0}-{1:000}-{2:000}.eml",
                currentDateTime.ToString("yyyyMMddHHmmss", new CultureInfo("en-US")),
                currentDateTime.Millisecond,
                sequence);
        }

        private ListViewItem _addNewMailToListView(ref Mail mail, string fullFileName)
        {
            ListViewItem item = new ListViewItem(mail.From.ToString());
            item.SubItems.Add(mail.Subject);
            item.SubItems.Add(mail.ReceivedDate.ToString("yyyy-MM-dd HH:mm:ss"));
            item.Tag = fullFileName;
            item.Font = new Font(this.Font, FontStyle.Bold);
            ListViewMail.Items.Add(item);

            return item;
        }

        private void btnStart_Click(object sender, System.EventArgs e)
        {
            _enableSettingControls(false, false);
            if (!_tryOauth())
            {
                _enableSettingControls(true, false);
                return;
            }

            if (ComboBoxAuthType.SelectedIndex == (int)ServerAuthType.AuthXOAUTH2)
            {
                textUser.Text = _oauthWrapper.OauthProvider.UserEmail;
                textPassword.Text = _oauthWrapper.OauthProvider.AccessToken;
            }

            if (!_validateInput())
            {
                _enableSettingControls(true, false);
                return;
            }

            _enableSettingControls(false, true);

            // UIDL is the identifier of every email on POP3/IMAP4/Exchange server, to avoid retrieve
            // the same email from server more than once, we record the email UIDL retrieved every time
            // if you delete the email from server every time and not to leave a copy of email on
            // the server, then please remove all the function about uidl.
            // UIDLManager wraps the function to write/read uidl record from a text file.
            UIDLManager oUIDLManager = new UIDLManager();
            bool _isUidlLoaded = false;

            try
            {
                // For evaluation usage, please use "TryIt" as the license code, otherwise the 
                // "Invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
                // "Trial version expired" exception will be thrown.
                MailClient client = new MailClient("TryIt");

                // Catching the following events is not necessary, 
                // just make the application more user friendly.
                // If you use the object in asp.net/windows service or non-gui application, 
                // You need not to catch the following events.
                // To learn more detail, please refer to the code in EAGetMail EventHandler region
                client.OnAuthorized += new MailClient.OnAuthorizedEventHandler(OnAuthorized);
                client.OnConnected += new MailClient.OnConnectedEventHandler(OnConnected);
                client.OnIdle += new MailClient.OnIdleEventHandler(OnIdle);
                client.OnSecuring += new MailClient.OnSecuringEventHandler(OnSecuring);
                client.OnReceivingDataStream += new MailClient.OnReceivingDataStreamEventHandler(OnReceivingDataStream);

                _isCancelOperation = false;
                textStatus.Text = "Connecting ...";

                // generate a log file for debug
                // client.LogFileName = string.Format("{0}\\log.txt", _currentPath);

                MailServer server = _buildServer();
                client.Connect(server);

                string localInbox = _createLocalInbox();

                // load existed uidl records to UIDLManager
                string uidlfile = string.Format("{0}\\{1}", localInbox, _uidlFile);
                oUIDLManager.Load(uidlfile);
                _isUidlLoaded = true;

                _setMailRange(ref client);

                textStatus.Text = "Retrieveing email list ...";
                MailInfo[] infos = client.GetMailInfos();
                textStatus.Text = string.Format("Total {0} email(s)", infos.Length);

                if (ComboBoxDateRange.SelectedIndex == 0)
                {
                    // Remove the local uidl that is not existed on the server,
                    // we only synchronize it with uidl of all emails in current mail folder
                    oUIDLManager.SyncUIDL(server, infos);
                    oUIDLManager.Update();
                }

                for (int i = 0; i < infos.Length; i++)
                {
                    pgBar.Maximum = 100;
                    pgBar.Minimum = 0;
                    pgBar.Value = 0;

                    textStatus.Text = string.Format("Checking {0}/{1}...", i + 1, infos.Length);

                    MailInfo info = infos[i];
                    if (oUIDLManager.FindUIDL(server, info.UIDL) != null)
                    {
                        //this email has been downloaded before.
                        continue;
                    }

                    textStatus.Text = string.Format("Retrieving {0}/{1}...", i + 1, infos.Length);

                    Mail mail = client.GetMail(info);

                    string fileName = _generateFileName(i + 1);
                    string fullFileName = string.Format("{0}\\{1}", localInbox, fileName);
                    mail.SaveAs(fullFileName, true);

                    _addNewMailToListView(ref mail, fullFileName);
                    mail.Clear();

                    LabelTotal.Text = string.Format("Total {0} email(s)", ListViewMail.Items.Count);

                    // If retrieve only new emails, after we retrieved it, mark it as read,
                    // With this feature, you don't have to UIDLManager to prevent duplicated emails.
                    if (chkNewOnly.Checked && ComboBoxProtocol.SelectedIndex != (int)ServerProtocol.Pop3)
                    {
                        client.MarkAsRead(info, true);
                    }

                    if (chkLeaveCopy.Checked)
                    {
                        // Add the email uidl to uidl file to avoid we retrieve it next time. 
                        oUIDLManager.AddUIDL(server, info.UIDL, fileName);
                    }
                    else
                    {
                        textStatus.Text = string.Format("Deleting {0}...", i + 1);
                        client.Delete(info);

                        // Remove UIDL from local uidl file.
                        oUIDLManager.RemoveUIDL(server, info.UIDL);
                    }
                }

                // Delete method just mark the email as deleted, 
                // Quit method expunge the emails from server exactly.
                client.Quit();

                // Update the uidl list to local uidl file and then we can load it next time.
                oUIDLManager.Update();
                textStatus.Text = "Completed";
            }
            catch (Exception ep)
            {
                if (_isUidlLoaded)
                {
                    // Update the uidl list to local uidl file and then we can load it next time.
                    oUIDLManager.Update();
                }

                MessageBox.Show(ep.Message);
                textStatus.Text = ep.Message;
            }

            _enableSettingControls(true, false);
        }

        private void btnCancel_Click(object sender, System.EventArgs e)
        {
            btnCancel.Enabled = false;
            _isCancelOperation = true;
        }

        #endregion

        #region Parse and display emails

        private void _loadLocalMails()
        {
            string localInbox = _createLocalInbox();
            string[] files = Directory.GetFiles(localInbox, "*.eml");
            for (int i = 0; i < files.Length; i++)
            {
                string fullFileName = files[i];
                // For evaluation usage, please use "TryIt" as the license code, otherwise the 
                // "invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
                // "trial version expired" exception will be thrown.
                Mail mail = new Mail("TryIt");

                // Load( file, true ) only load the email header to Mail object to save the CPU and memory
                // the Mail object will load the whole email file later automatically if bodytext or attachment is required..
                mail.Load(fullFileName, true);
                ListViewItem item = _addNewMailToListView(ref mail, fullFileName);

                string htmlFile = _getHtmlRenderFile(fullFileName);
                if (!File.Exists(htmlFile))
                {
                    // This email is not read, we set the font style to bold.
                    item.Font = new Font(this.Font, FontStyle.Bold);
                }
                else
                {
                    item.Font = new Font(this.Font, FontStyle.Regular);
                }

                mail.Clear();
            }
        }

        private string _formatHtmlTag(string src)
        {
            src = src.Replace(">", "&gt;");
            src = src.Replace("<", "&lt;");
            return src;
        }

        private void ListViewMail_Click(object sender, System.EventArgs e)
        {
            ListView.SelectedListViewItemCollection items = ListViewMail.SelectedItems;
            if (items.Count == 0)
                return;

            ListViewItem item = items[0] as ListViewItem;
            _showMail(item.Tag as string);
            item.Font = new Font(item.Font, FontStyle.Regular);
        }

        private string _getHtmlRenderFile(string emlFile)
        {
            int pos = emlFile.LastIndexOf(".");
            if (pos != -1)
            {
                return emlFile.Substring(0, pos) + ".html";
            }
            else
            {
                return emlFile + ".html";
            }
        }

        private string _getAttachmentFolder(string emlFile)
        {
            int pos = emlFile.LastIndexOf(".");
            if (pos != -1)
            {
                return emlFile.Substring(0, pos);
            }
            else
            {
                return emlFile + "_a";
            }
        }

        private void _showMail(string fileName)
        {
            try
            {
                string htmlFile = _getHtmlRenderFile(fileName);
                
                if (!File.Exists(htmlFile))
                {   // we haven't generate the html for this email, generate it now.
                    _GenerateHtmlForEmail(fileName);
                }

                WebMail.Navigate(htmlFile);
            }
            catch (Exception ep)
            {
                MessageBox.Show(ep.Message);
            }
        }

        private void btnDel_Click(object sender, System.EventArgs e)
        {
            ListView.SelectedListViewItemCollection items = ListViewMail.SelectedItems;
            if (items.Count == 0)
                return;

            if (MessageBox.Show("Do you want to delete all selected emails",
                            "",
                            MessageBoxButtons.YesNo) == DialogResult.No)
                return;

            while (items.Count > 0)
            {
                try
                {
                    string fileName = items[0].Tag as string;
                    File.Delete(fileName);

                    string htmlFile = _getHtmlRenderFile(fileName);
                    string attachmentFolder = _getAttachmentFolder(fileName);

                    if (File.Exists(htmlFile))
                    {
                        File.Delete(htmlFile);
                    }
                    
                    if (Directory.Exists(attachmentFolder))
                    {
                        Directory.Delete(attachmentFolder, true);
                    }

                    ListViewMail.Items.Remove(items[0]);
                }
                catch (Exception ep)
                {
                    MessageBox.Show(ep.Message);
                    break;
                }
            }

            LabelTotal.Text = string.Format("Total {0} email(s)", ListViewMail.Items.Count);
            WebMail.Navigate("about:blank");
        }

        // Generate a html + attachment folder for every email, once the html is created,
        // next time we don't need to parse the email again.
        private void _GenerateHtmlForEmail(string emlFile)
        {
            // For evaluation usage, please use "TryIt" as the license code, otherwise the 
            //"invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
            //"trial version expired" exception will be thrown.
            Mail mail = new Mail("TryIt");
            mail.Load(emlFile, false);

            if (mail.IsEncrypted)
            {
                try
                {
                    // this email is encrypted, we decrypt it by user default certificate.
                    // you can also use specified certificate like this
                    // oCert = new Certificate();
                    // oCert.Load("c:\\test.pfx", "pfxpassword", Certificate.CertificateKeyLocation.CRYPT_USER_KEYSET)
                    // oMail = oMail.Decrypt( oCert );
                    mail = mail.Decrypt(null);
                }
                catch (Exception ep)
                {
                    MessageBox.Show(ep.Message);
                }
            }

            if (mail.IsSigned)
            {
                try
                {
                    // This email is digital signed.
                    Certificate signerCertificate = mail.VerifySignature();
                    MessageBox.Show("This email contains a valid digital signature.");

                    // You can add the certificate to your certificate storage like this
                    // cert.AddToStore( Certificate.CertificateStoreLocation.CERT_SYSTEM_STORE_CURRENT_USER,
                    //	"addressbook" );
                    // then you can use send the encrypted email back to this sender.
                }
                catch (Exception ep)
                {
                    MessageBox.Show(ep.Message);
                }
            }

            // Decode winmail.dat (Outlook TNEF stream) automatically.
            // also convert RTF body to HTML body automatically.MO
            mail.DecodeTNEF();

            string html = mail.HtmlBody;
            StringBuilder header = new StringBuilder();

            header.Append("<font face=\"Courier New,Arial\" size=2>");
            header.Append("<b>From:</b> " + _formatHtmlTag(mail.From.ToString()) + "<br>");

            header.Append(_formatAddresses(mail.To, "To"));
            header.Append(_formatAddresses(mail.Cc, "Cc"));

            header.Append(string.Format("<b>Subject:</b>{0}<br>\r\n", _formatHtmlTag(mail.Subject)));

            string tempFolder = _getAttachmentFolder(emlFile);

            Attachment[] attachments = mail.Attachments;
            if (attachments.Length > 0)
            {
                if (!Directory.Exists(tempFolder))
                    Directory.CreateDirectory(tempFolder);

                header.Append("<b>Attachments:</b> ");
                for (int i = 0; i < attachments.Length; i++)
                {
                    Attachment attachment = attachments[i];

                    string attachmentName = string.Format("{0}\\{1}", tempFolder, attachment.Name);
                    attachment.SaveAs(attachmentName, true);

                    header.Append(string.Format("<a href=\"{0}\" target=\"_blank\">{1}</a> ",
                        attachmentName, attachment.Name));
                    if (attachment.ContentID.Length > 0)
                    {   // Show embedded image.
                        html = html.Replace("cid:" + attachment.ContentID, attachmentName);
                    }
                }
            }

            // Change original meta header encoding to utf-8
            Regex reg = new Regex("(<meta[^>]*charset[ \t]*=[ \t\"]*)([^<> \r\n\"]*)", RegexOptions.Multiline | RegexOptions.IgnoreCase);
            html = reg.Replace(html, "$1utf-8");
            if (!reg.IsMatch(html))
            {
                header.Insert(0, "<meta HTTP-EQUIV=\"Content-Type\" Content=\"text/html; charset=utf-8\">");
            }

            html = header.ToString() + "<hr>" + html;

            string htmlFile = _getHtmlRenderFile(emlFile);
            using (FileStream stream = new FileStream(htmlFile, FileMode.Create, FileAccess.Write, FileShare.None))
            { 
                byte[] buffer = Encoding.UTF8.GetBytes(html);
                stream.Write(buffer, 0, buffer.Length);
                stream.Close();
            }

            mail.Clear();
        }

        private string _formatAddresses(MailAddress[] addresses, string prefix)
        {
            if (addresses.Length == 0)
            {
                return "";
            }

            StringBuilder buffer = new StringBuilder();
            buffer.Append(string.Format("<b>{0}:</b> ", prefix));

            for (int i = 0; i < addresses.Length; i++)
            {
                buffer.Append(_formatHtmlTag(addresses[i].ToString()));
                if (i < addresses.Length - 1)
                {
                    buffer.Append("; ");
                }
            }

            buffer.Append("<br>");
            return buffer.ToString();
        }

        #endregion

        #region EAGetMail Event Handler

        public void OnConnected(object sender, ref bool cancel)
        {
            textStatus.Text = "Connected ...";
            cancel = _isCancelOperation;
            Application.DoEvents();
        }

        public void OnQuit(object sender, ref bool cancel)
        {
            textStatus.Text = "Disconnecting ...";
            cancel = _isCancelOperation;
            Application.DoEvents();
        }

        public void OnReceivingDataStream(object sender, MailInfo info, int received, int total, ref bool cancel)
        {
            pgBar.Minimum = 0;
            pgBar.Maximum = total;
            pgBar.Value = received;
            cancel = _isCancelOperation;
            Application.DoEvents();
        }

        public void OnIdle(object sender, ref bool cancel)
        {
            cancel = _isCancelOperation;
            Application.DoEvents();
        }

        public void OnAuthorized(object sender, ref bool cancel)
        {
            textStatus.Text = "Authorized ...";
            cancel = _isCancelOperation;
            Application.DoEvents();
        }

        public void OnSecuring(object sender, ref bool cancel)
        {
            textStatus.Text = "Securing ...";
            cancel = _isCancelOperation;
            Application.DoEvents();
        }


        #endregion

    }
}
