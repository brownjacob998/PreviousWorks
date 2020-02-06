using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;
using System.IO;
using System.Globalization;
using EAGetMail;


namespace pocketpc.mobile.cs
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        private bool _cancelTask = false;
        private string _currentPath = "";
       
        private void Form1_Load(object sender, EventArgs e)
        {
            System.Reflection.Assembly asb = System.Reflection.Assembly.GetExecutingAssembly();
            System.Reflection.Module[] ms = asb.GetModules();

            string file = "pocketpc.mobile.cs.exe";
            int count = ms.Length;
            for (int i = 0; i < count; i++)
            {
                if (string.Compare(file, ms[i].Name, true) == 0)
                {
                    file = ms[i].FullyQualifiedName;
                    break;
                }
            }

            string path = file;
            int pos = path.LastIndexOf('\\');
            if (pos != -1)
                path = path.Substring(0, pos);

            _currentPath = path;

            webMail.Navigate(new System.Uri("about:blank"));

            lstProtocol.Items.Add("POP3");
            lstProtocol.Items.Add("IMAP4");
            lstProtocol.Items.Add("Exchange Web Service - 2007/2010");
            lstProtocol.Items.Add("Exchange WebDAV - Exchange 2000/2003");

            lstProtocol.SelectedIndex = 0;

            lstAuthType.Items.Add("USER/LOGIN");
            lstAuthType.Items.Add("APOP");
            lstAuthType.Items.Add("NTLM");
            lstAuthType.SelectedIndex = 0;

            LoadMails();
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
            
            lstMail.Items.Add(item);

            return item;
        }

        private void _enableSettingControls(bool isEnabled, bool isCancelEnabled)
        {
            btnStart.Enabled = isEnabled;
            btnCancel.Enabled = isCancelEnabled;

            textServer.Enabled = isEnabled;
            chkSSL.Enabled = isEnabled;
            chkLeaveCopy.Enabled = isEnabled;

            lstAuthType.Enabled = isEnabled;
            lstProtocol.Enabled = isEnabled;
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

        private MailServer _buildServer()
        {
            MailServer server = new MailServer(textServer.Text.Trim(),
                textUser.Text.Trim(),
                textPassword.Text.Trim(),
                chkSSL.Checked,
                (ServerAuthType)lstAuthType.SelectedIndex,
                (ServerProtocol)lstProtocol.SelectedIndex);

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

        private void btnStart_Click(object sender, EventArgs e)
        {
            _enableSettingControls(false, false);

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
            UIDLManager uidlManager = new UIDLManager();
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

                _cancelTask = false;
                lblStatus.Text = "Connecting ...";

                // generate a log file for debug
                // client.LogFileName = string.Format("{0}\\log.txt", _currentPath);

                MailServer server = _buildServer();
                client.Connect(server);

                string localInbox = _createLocalInbox();

                // load existed uidl records to UIDLManager
                string uidlfile = string.Format("{0}\\uidl.txt", localInbox);
                uidlManager.Load(uidlfile);
                _isUidlLoaded = true;

                lblStatus.Text = "Retrieveing email list ...";

                MailInfo[] infos = client.GetMailInfos();
                lblStatus.Text = string.Format("Total {0} email(s)", infos.Length);

                // Remove the local uidl that is not existed on the server,
                // we only synchronize it with uidl of all emails in current mail folder
                uidlManager.SyncUIDL(server, infos);
                uidlManager.Update();

                for (int i = 0; i < infos.Length; i++)
                {
                    pgBar.Maximum = 100;
                    pgBar.Minimum = 0;
                    pgBar.Value = 0;

                    lblStatus.Text = string.Format("Checking {0}/{1}...", i + 1, infos.Length);

                    MailInfo info = infos[i];
                    if (uidlManager.FindUIDL(server, info.UIDL) != null)
                    {
                        //this email has been downloaded before.
                        continue;
                    }

                    lblStatus.Text = string.Format("Retrieving {0}/{1}...", i + 1, infos.Length);

                    Mail mail = client.GetMail(info);

                    string fileName = _generateFileName(i + 1);
                    string fullFileName = string.Format("{0}\\{1}", localInbox, fileName);
                    mail.SaveAs(fullFileName, true);

                    _addNewMailToListView(ref mail, fullFileName);
                    mail.Clear();

                    lblStatus.Text = string.Format("Total {0} email(s)", lstMail.Items.Count);

                    if (chkLeaveCopy.Checked)
                    {
                        // Add the email uidl to uidl file to avoid we retrieve it next time. 
                        uidlManager.AddUIDL(server, info.UIDL, fileName);
                    }
                    else
                    {
                        lblStatus.Text = string.Format("Deleting {0}...", i + 1);
                        client.Delete(info);

                        // Remove UIDL from local uidl file.
                        uidlManager.RemoveUIDL(server, info.UIDL);
                    }
                }

                // Delete method just mark the email as deleted, 
                // Quit method expunge the emails from server exactly.
                client.Quit();

                // Update the uidl list to local uidl file and then we can load it next time.
                uidlManager.Update();
                lblStatus.Text = "Completed";
            }
            catch (Exception ep)
            {
                if (_isUidlLoaded)
                {
                    // Update the uidl list to local uidl file and then we can load it next time.
                    uidlManager.Update();
                }

                MessageBox.Show(ep.Message);
                lblStatus.Text = ep.Message;
            }

            _enableSettingControls(true, false);
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            btnCancel.Enabled = false;
            _cancelTask = true;
        }

        #region Parse and Display Mails

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

        private void LoadMails()
        {
            lstMail.Items.Clear();
            string localInbox = _createLocalInbox();
            string[] files = Directory.GetFiles(localInbox, "*.eml");

            for (int i = 0; i < files.Length; i++)
            {
                string fullname = files[i];
                //For evaluation usage, please use "TryIt" as the license code, otherwise the 
                //"invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
                //"trial version expired" exception will be thrown.
                Mail mail = new Mail("TryIt");

                // Load( file, true ) only load the email header to Mail object to save the CPU and memory
                // the Mail object will load the whole email file later automatically if bodytext or attachment is required..
                mail.Load(fullname, true);
                _addNewMailToListView(ref mail, fullname);
            }
        }

        private string _FormatHtmlTag(string src)
        {
            src = src.Replace(">", "&gt;");
            src = src.Replace("<", "&lt;");
            return src;
        }

        // we generate a html + attachment folder for every email, once the html is create,
        // next time we don't need to parse the email again.
        private void _GenerateHtmlForEmail(string emlFile)
        {
            // For evaluation usage, please use "TryIt" as the license code, otherwise the 
            //"invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
            //"trial version expired" exception will be thrown.
            Mail mail = new Mail("TryIt");
            mail.Load(emlFile, false);

            // Decode winmail.dat (Outlook TNEF stream) automatically.
            // also convert RTF body to HTML body automatically.MO
            mail.DecodeTNEF();

            string html = mail.HtmlBody;
            StringBuilder header = new StringBuilder();

            header.Append("<font face=\"Courier New,Arial\" size=2>");
            header.Append("<b>From:</b> " + FormatHtmlTag(mail.From.ToString()) + "<br>");

            header.Append(FormatAddresses(mail.To, "To"));
            header.Append(FormatAddresses(mail.Cc, "Cc"));

            header.Append(string.Format("<b>Subject:</b>{0}<br>\r\n", FormatHtmlTag(mail.Subject)));

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
        }

        private string FormatAddresses(MailAddress[] addresses, string prefix)
        {
            if (addresses.Length == 0)
            {
                return "";
            }

            StringBuilder buffer = new StringBuilder();
            buffer.Append(string.Format("<b>{0}:</b> ", prefix));

            for (int i = 0; i < addresses.Length; i++)
            {
                buffer.Append((addresses[i].ToString()));
                if (i < addresses.Length - 1)
                {
                    buffer.Append(";");
                }
            }

            buffer.Append("<br>");
            return buffer.ToString();
        }

        private string FormatHtmlTag(string src)
        {
            src = src.Replace(">", "&gt;");
            src = src.Replace("<", "&lt;");
            return src;
        }

        private void ShowMail(string fileName)
        {
            try
            {
                string htmlFile = _getHtmlRenderFile(fileName);
                if (!File.Exists(htmlFile))
                {   // we haven't generate the html for this email, generate it now.
                    _GenerateHtmlForEmail(fileName);
                }

                webMail.Navigate(new System.Uri(htmlFile));
            }
            catch (Exception ep)
            {
                MessageBox.Show(ep.Message);
            }
        }

        #endregion

        private void btnDel_Click(object sender, EventArgs e)
        {
            ListView.SelectedIndexCollection items = lstMail.SelectedIndices;
            if (items.Count == 0)
                return;

            if (MessageBox.Show("Do you want to delete all selected emails",
                            "",
                            MessageBoxButtons.YesNo, MessageBoxIcon.Question, MessageBoxDefaultButton.Button1) == DialogResult.No)
                return;

            ArrayList selectedItems = new ArrayList();
            for( int i = 0; i < items.Count; i++ )
            {
                int index = items[i];
                ListViewItem item = lstMail.Items[index];
                selectedItems.Add(item);
                try
                {
                    string fileName = item.Tag as string;
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
                }
                catch (Exception ep)
                {
                    MessageBox.Show(ep.Message);
                    break;
                }
            }

            for (int i = 0; i < selectedItems.Count; i++)
            {
                ListViewItem item = selectedItems[i] as ListViewItem;
                lstMail.Items.Remove(item);
            }

            webMail.Navigate( new System.Uri("about:blank"));
        }

        private void lstMail_SelectedIndexChanged(object sender, EventArgs e)
        {
            ListView.SelectedIndexCollection items = lstMail.SelectedIndices;
            if (items.Count == 0)
                return;

            ListViewItem item = lstMail.Items[items[0]] as ListViewItem;
            ShowMail(item.Tag as string);
        }

        #region EAGetMail Event Handler
        public void OnConnected(object sender, ref bool cancel)
        {
            lblStatus.Text = "Connected ...";
            cancel = _cancelTask;
            Application.DoEvents();
        }

        public void OnQuit(object sender, ref bool cancel)
        {
            lblStatus.Text = "Quit ...";
            cancel = _cancelTask;
            Application.DoEvents();
        }

        public void OnReceivingDataStream(object sender, MailInfo info, int received, int total, ref bool cancel)
        {
            pgBar.Minimum = 0;
            pgBar.Maximum = total;
            pgBar.Value = received;
            cancel = _cancelTask;
            Application.DoEvents();
        }

        public void OnIdle(object sender, ref bool cancel)
        {
            cancel = _cancelTask;
            Application.DoEvents();
        }

        public void OnAuthorized(object sender, ref bool cancel)
        {
            lblStatus.Text = "Authorized ...";
            cancel = _cancelTask;
            Application.DoEvents();
        }

        public void OnSecuring(object sender, ref bool cancel)
        {
            lblStatus.Text = "Securing ...";
            cancel = _cancelTask;
            Application.DoEvents();
        }
        #endregion

    }
}