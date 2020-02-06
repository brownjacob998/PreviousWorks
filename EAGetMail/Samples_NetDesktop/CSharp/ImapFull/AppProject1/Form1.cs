using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using EAGetMail;
using EAGetMail.Oauth;
using System.Globalization;
using System.Text.RegularExpressions;

namespace AppProject1
{
    public partial class Form1 : Form
    {
        readonly int _protocolOffset = 1;

        // MailClient and Server
        MailServer _currentServer = null;
        MailClient _client = null;

        // UIDL 
        string _currentPath = "";
        UIDLManager _uidlManager = new UIDLManager();

        // Cancel current operation flag
        bool _isCancelOperation = false;

        bool _isWorking = false;
        bool _isSelectedFolderChanged = false;
        string _selectedFolderPath = "";

        public Form1()
        {
            InitializeComponent();

            // For evaluation usage, please use "TryIt" as the license code, otherwise the 
            // "Invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
            // "Trial version expired" exception will be thrown.
            _client = new MailClient("TryIt");

            // Catching the following events is not necessary, 
            // just make the application more user friendly.
            // If you use the object in asp.net/windows service or non-gui application, 
            // You need not to catch the following events.
            // To learn more detail, please refer to the code in EAGetMail EventHandler region
            _client.OnAuthorized += new MailClient.OnAuthorizedEventHandler(OnAuthorized);
            _client.OnConnected += new MailClient.OnConnectedEventHandler(OnConnected);
            _client.OnIdle += new MailClient.OnIdleEventHandler(OnIdle);
            _client.OnSecuring += new MailClient.OnSecuringEventHandler(OnSecuring);
            _client.OnReceivingDataStream += new MailClient.OnReceivingDataStreamEventHandler(OnReceivingDataStream);
        }

        #region Resize Control Automatically

        bool _isFormLoaded = false;
        int _listViewMailWidthOffset = 0;
        int _webMailHeightOffset = 0;
        int _pgBarTopOffset = 0;
        int _tvFolderHeightOffset = 0;

        private void _initControlOffset()
        {
            // No smaller than design time size
            this.MinimumSize = new System.Drawing.Size(this.Width, this.Height);
            _isFormLoaded = true;

            _listViewMailWidthOffset = this.Width - ListViewMail.Width;
            _webMailHeightOffset = this.Height - webMail.Height;
            _pgBarTopOffset = this.Height - pgBar.Top;
            _tvFolderHeightOffset = this.Height - TreeViewFolder.Height;
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            if (!_isFormLoaded)
            {
                return;
            }

            ListViewMail.Width = this.Width - _listViewMailWidthOffset;
            webMail.Width = ListViewMail.Width;
            webMail.Height = this.Height - _webMailHeightOffset;

            pgBar.Width = webMail.Width;
            pgBar.Top = this.Height - _pgBarTopOffset;
            TreeViewFolder.Height = this.Height - _tvFolderHeightOffset;
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
        private void Form1_Load(object sender, EventArgs e)
        {
            _initCurrentPath();
            _initControlOffset();
            _initOauthWrapper();

            webMail.Navigate("about:blank");

            // initialize authentication type
            ComboBoxAuthType.Items.Add("USER/LOGIN");
            ComboBoxAuthType.Items.Add("APOP");
            ComboBoxAuthType.Items.Add("NTLM");
            ComboBoxAuthType.Items.Add("Gmail XOAUTH2");

            ComboBoxAuthType.SelectedIndex = 0;

            // initialize mail date range
            ComboBoxDateRange.Items.Add("Sync last 7 days emails");
            ComboBoxDateRange.Items.Add("Sync last 30 days emails");
            ComboBoxDateRange.Items.Add("Sync last 60 days emails");
            ComboBoxDateRange.Items.Add("Sync last 90 days emails");
            ComboBoxDateRange.Items.Add("Sync all emails (slow)");

            ComboBoxDateRange.SelectedIndex = 0;

            // initialize protocols.
            ComboBoxProtocol.Items.Add("IMAP4");
            ComboBoxProtocol.Items.Add("EWS - Exchange 2007-2019/Office365");
            ComboBoxProtocol.Items.Add("WebDAV - Exchange 2000/2003");

            ComboBoxProtocol.SelectedIndex = 0;

            ListViewMail.Sorting = SortOrder.Descending;
            ListViewMail.ListViewItemSorter = new ListMailItemCompare();

            textStatus.Text = "";
            TreeViewFolder.Nodes.Clear();

            _isWorking = false;
        }

        private void ComboBoxAuthType_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (ComboBoxAuthType.SelectedIndex == (int)ServerAuthType.AuthXOAUTH2)
            {
                ComboBoxProtocol.SelectedIndex = (int)ServerProtocol.Imap4 - _protocolOffset;
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

        #region Login, Cancel, Quit

        private MailServer _buildServer()
        {
            MailServer server = new MailServer(textServer.Text.Trim(),
                textUser.Text.Trim(),
                textPassword.Text.Trim(),
                chkSSL.Checked,
                (ServerAuthType)ComboBoxAuthType.SelectedIndex,
                (ServerProtocol)(ComboBoxProtocol.SelectedIndex + _protocolOffset));

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

            switch (ComboBoxDateRange.SelectedIndex)
            {
                case 0:
                    client.GetMailInfosParam.GetMailInfosOptions =
                    (client.GetMailInfosParam.GetMailInfosOptions | GetMailInfosOptionType.DateRange);
                    client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-7);
                    client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1);
                    break;
                case 1:
                    client.GetMailInfosParam.GetMailInfosOptions =
                    (client.GetMailInfosParam.GetMailInfosOptions | GetMailInfosOptionType.DateRange);
                    client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-30);
                    client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1);
                    break;
                case 2:
                    client.GetMailInfosParam.GetMailInfosOptions =
                    (client.GetMailInfosParam.GetMailInfosOptions | GetMailInfosOptionType.DateRange);
                    client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-60);
                    client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1);
                    break;
                case 3:
                    client.GetMailInfosParam.GetMailInfosOptions =
                    (client.GetMailInfosParam.GetMailInfosOptions | GetMailInfosOptionType.DateRange);
                    client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-90);
                    client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1);
                    break;
                default:
                    break;
            }
        }

        void _connectServerOnDemand()
        {
            _isSelectedFolderChanged = false;
            if (!_client.Connected)
            {
                textStatus.Text = "Connecting server ...";
                _isCancelOperation = false;

                _client.Connect(_currentServer);
                textStatus.Text = "Connected";
            }

            var node = _getSelectedNode(false);
            if (node == null)
            {
                return;
            }

            var folder = node.Tag as Imap4Folder;
            if (string.Compare(folder.ServerPath, _selectedFolderPath, true) == 0)
            {
                return;
            }

            // folder changed, clear current mail list.
            ListViewMail.Items.Clear();
            _selectedFolderPath = folder.ServerPath;
            _isSelectedFolderChanged = true;

            if (folder.NoSelect)
            {
                return;
            }

            _client.SelectFolder(folder);
        }

        TreeNode _getSelectedNode(bool includeRoot)
        {
            TreeNode node = TreeViewFolder.SelectedNode;
            if (includeRoot)
            {
                return node;
            }

            return (node != null && node.Parent == null) ? null : node;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            _prepareLogin();

            if (!_tryOauth())
            {
                textStatus.Text = "Failed to request/refresh access token.";
                _afterLoginError();
                return;
            }

            if (ComboBoxAuthType.SelectedIndex == (int)ServerAuthType.AuthXOAUTH2)
            {
                // Use Gmail Oauth, now put user email and access token to user and password.
                textUser.Text = _oauthWrapper.OauthProvider.UserEmail;
                textPassword.Text = _oauthWrapper.OauthProvider.AccessToken;
            }

            if (!_validateInput())
            {
                _afterLoginError();
                return;
            }

            btnStart.Enabled = false;

            try
            {
                _prepareWork();

                _currentServer = _buildServer();
                textStatus.Text = "Connecting ...";

                _client.Connect(_currentServer);
                textStatus.Text = "Connected";

                _showAllFolders();

                _endWork();
                _afterLoginSucceeded();

            }
            catch (Exception ep)
            {
                _afterError(ep);
                _afterLoginError();
            }
        }

        private void btnQuit_Click(object sender, EventArgs e)
        {
            try
            {
                _client.Logout();
                _client.Close();
            }
            catch { }
            _afterQuit();
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            _isCancelOperation = true;
            btnCancel.Enabled = false;
        }

        void _prepareLogin()
        {
            textServer.Enabled = false;

            textUser.Enabled = false;
            textPassword.Enabled = false;

            ComboBoxAuthType.Enabled = false;
            ComboBoxProtocol.Enabled = false;
            ComboBoxDateRange.Enabled = false;

            chkSSL.Enabled = false;
            btnStart.Enabled = false;

            _selectedFolderPath = "";
        }

        void _afterLoginSucceeded()
        {
            textServer.Enabled = false;

            textUser.Enabled = false;
            textPassword.Enabled = false;

            chkSSL.Enabled = false;
            btnStart.Enabled = false;
            btnQuit.Enabled = true;

            _selectedFolderPath = "";
        }

        void _afterLoginError()
        {
            textServer.Enabled = true;

            if (ComboBoxAuthType.SelectedIndex != (int)ServerAuthType.AuthXOAUTH2)
            {
                textUser.Enabled = true;
                textPassword.Enabled = true;
            }
            else
            {
                textUser.Enabled = false;
                textPassword.Enabled = false;
            }

            ComboBoxAuthType.Enabled = true;
            ComboBoxDateRange.Enabled = true;
            ComboBoxProtocol.Enabled = true;

            chkSSL.Enabled = true;
            btnStart.Enabled = true;
            btnQuit.Enabled = false;

            webMail.Navigate("about:blank");

            ListViewMail.Items.Clear();
            TreeViewFolder.Nodes.Clear();

            _selectedFolderPath = "";
        }

        void _afterQuit()
        {
            _endWork();

            webMail.Navigate("about:blank");
            ListViewMail.Items.Clear();
            TreeViewFolder.Nodes.Clear();

            textServer.Enabled = true;

            if (ComboBoxAuthType.SelectedIndex != (int)ServerAuthType.AuthXOAUTH2)
            {
                textUser.Enabled = true;
                textPassword.Enabled = true;
            }

            ComboBoxAuthType.Enabled = true;
            ComboBoxProtocol.Enabled = true;
            ComboBoxDateRange.Enabled = true;

            chkSSL.Enabled = true;
            btnStart.Enabled = true;

            btnQuit.Enabled = false;

            _selectedFolderPath = "";
            textStatus.Text = "Disconnected";
        }

        void _afterError(Exception ep)
        {
            _endWork();

            _client.Close();
            MessageBox.Show(ep.Message);

            _selectedFolderPath = "";
            textStatus.Text = ep.Message;
        }

        void _prepareWork()
        {
            _isWorking = true;
            _isCancelOperation = false;

            btnCancel.Enabled = true;
            btnQuit.Enabled = false;

            _enableControlDynamic();
        }

        void _endWork()
        {
            _isWorking = false;

            btnCancel.Enabled = false;
            btnQuit.Enabled = true;

            _enableControlDynamic();
        }

        void _enableControlDynamic()
        {
            ListView.SelectedListViewItemCollection items = ListViewMail.SelectedItems;
            int selectMailCount = (items == null) ? 0 : items.Count;
            bool isFolderSelected = (_getSelectedNode(false) != null);

            TreeViewFolder.Enabled = !_isWorking;
            ListViewMail.Enabled = !_isWorking;
            btnDelete.Enabled = !_isWorking && isFolderSelected && (selectMailCount > 0);

            if (ComboBoxProtocol.SelectedIndex + _protocolOffset == (int)ServerProtocol.Imap4)
            {
                btnUndelete.Enabled = !_isWorking && isFolderSelected && (selectMailCount > 0);
                btnExpunge.Enabled = !_isWorking && isFolderSelected;
            }
            else
            {
                btnUndelete.Enabled = false;
                btnExpunge.Enabled = false;
            }

            btnUnread.Enabled = !_isWorking && isFolderSelected && (selectMailCount > 0);

            btnMove.Enabled = !_isWorking && isFolderSelected && (selectMailCount > 0);
            btnCopy.Enabled = !_isWorking && isFolderSelected && (selectMailCount > 0);

            btnUpload.Enabled = !_isWorking && isFolderSelected;
        }

        #endregion

        #region Show server folders and expand folders.

        void _showAllFolders()
        {
            TreeViewFolder.Nodes.Clear();

            TreeNode rootNode = new TreeNode(string.Format("{0}\\{1}", _currentServer.Server.ToLower(), _currentServer.User.ToLower()));
            rootNode.Tag = _currentServer;

            TreeViewFolder.Nodes.Add(rootNode);
            TreeViewFolder.SelectedNode = rootNode;

            textStatus.Text = "Refreshing folder list ...";
            _expandFolders(_client.Imap4Folders, rootNode);
            rootNode.ExpandAll();
            textStatus.Text = "";
        }

        private void _expandFolders(Imap4Folder[] folders, TreeNode parentNode)
        {
            parentNode.Nodes.Clear();
            for (int i = 0; i < folders.Length; i++)
            {
                Imap4Folder folder = folders[i];
                TreeNode node = parentNode.Nodes.Add(folder.Name);
                node.Tag = folder;
                _expandFolders(folder.SubFolders, node);
            }
        }

        #endregion

        #region Add, delete, rename folders

        private string _getLocalFolderPath(Imap4Folder folder)
        {
            return string.Format("{0}\\{1}\\{2}\\{3}", _currentPath, _currentServer.Server, _currentServer.User, folder.LocalPath);
        }

        private void contextMenuFolder_Opening(object sender, CancelEventArgs e)
        {
            var node = _getSelectedNode(true);
            if (node == null)
            {
                e.Cancel = true;
                return;
            }

            addFolderToolStripMenuItem.Enabled = (!_isWorking);
            deleteFolderToolStripMenuItem.Enabled = (!_isWorking && node.Parent != null);
            refreshFoldersToolStripMenuItem.Enabled = (!_isWorking);
            renameFolderToolStripMenuItem.Enabled = (!_isWorking && node.Parent != null);
            refreshMailsToolStripMenuItem.Enabled = (!_isWorking && node.Parent != null);
        }

        private void addFolderToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormAddFolder folderDialog = new FormAddFolder();
            if (folderDialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                string folderName = folderDialog.textFolderName.Text;
                var node = _getSelectedNode(true);

                Imap4Folder fd = (node.Parent != null) ?
                        _client.CreateFolder(node.Tag as Imap4Folder, folderName) :
                        _client.CreateFolder(null, folderName);

                TreeNode newNode = node.Nodes.Add(fd.Name);
                newNode.Tag = fd;
                node.ExpandAll();

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        private void deleteFolderToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var node = _getSelectedNode(false);
            if (node == null)
            {
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                string localFolderPath = _getLocalFolderPath(node.Tag as Imap4Folder);
                _client.DeleteFolder(node.Tag as Imap4Folder);

                TreeViewFolder.SelectedNode = null;
                node.Remove();

                ListViewMail.Items.Clear();

                if (Directory.Exists(localFolderPath))
                {
                    Directory.Delete(localFolderPath, true);
                }

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        private void renameFolderToolStripMenuItem_Click(object sender, EventArgs e)
        {
            TreeNode node = _getSelectedNode(false);
            if (node == null)
            {
                return;
            }

            TreeViewFolder.LabelEdit = true;
            if (!node.IsEditing)
            {
                node.BeginEdit();
            }
        }

        private void TreeViewFolder_AfterLabelEdit(object sender, NodeLabelEditEventArgs e)
        {
            if (e.Label == null)
                return;

            if (e.Label.Length == 0)
            {
                e.CancelEdit = true;
                MessageBox.Show("Invalid folder name.The name cannot be blank!");
                return;
            }

            TreeNode node = e.Node;
            if (node.Tag == null) // rename folder
            {
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                string localFolderPath = _getLocalFolderPath(node.Tag as Imap4Folder);
                _client.RenameFolder(node.Tag as Imap4Folder, e.Label);
                e.Node.EndEdit(false);

                string newFolderPath = _getLocalFolderPath(node.Tag as Imap4Folder);
                if (Directory.Exists(localFolderPath))
                {
                    Directory.Move(localFolderPath, newFolderPath);
                }

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
                e.CancelEdit = true;
            }
        }

        private void refreshFoldersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                _prepareWork();
                _connectServerOnDemand();

                _client.RefreshFolders();
                _showAllFolders();

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        private void refreshMailsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            TreeNode node = _getSelectedNode(false);
            if (node == null)
            {
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                _client.RefreshMailInfos();
                _loadServerMails(node);

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        #endregion

        #region Display current folder email list
        private void TreeViewFolder_AfterSelect(object sender, TreeViewEventArgs e)
        {
            if (e.Node.Parent == null)
            {
                ListViewMail.Items.Clear();
                textStatus.Text = "Root";
                _isSelectedFolderChanged = true;
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                if (_isSelectedFolderChanged)
                {
                    _loadServerMails(e.Node);
                }

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        void _loadServerMails(TreeNode node)
        {
            ListViewMail.Items.Clear();

            Imap4Folder folder = node.Tag as Imap4Folder;
            if (folder.NoSelect)
            {
                // current server folder is unselectable.
                return;
            }

            bool isUidlLoaded = false;
            try
            {
                string folderPath = _getLocalFolderPath(folder);
                _createFullFolder(folderPath);
                _uidlManager.Load(string.Format("{0}\\uidl.txt", folderPath));
                isUidlLoaded = true;

                _setMailRange(ref _client);

                textStatus.Text = "Refreshing email list ...";
                MailInfo[] infos = _client.GetMailInfos();

                if (ComboBoxDateRange.SelectedIndex == 4)
                {
                    // Remove the local uidl which is not existed on the server.
                    // We only synchronize it with uidl of all emails in current mail folder
                    _uidlManager.SyncUIDL(_currentServer, infos);
                    _uidlManager.Update();
                }

                textStatus.Text = string.Format("Total {0} emails", infos.Length);

                for (int i = 0; i < infos.Length; i++)
                {
                    MailInfo info = infos[i];

                    string emailHeaderFile = "";
                    // Detect if current email has been downloaded before.
                    UIDLItem uidlItem = _uidlManager.FindUIDL(_currentServer, info.UIDL);
                    if (uidlItem != null)
                    {
                        // Get existed email headers file from existed email headers file.
                        emailHeaderFile = uidlItem.FileName;
                    }
                    else
                    {
                        // Current email headers has not been downloaded, generate a new file to store email headers
                        emailHeaderFile = _generateFileName(i);
                    }

                    string fullEmailHeaderFile = string.Format("{0}\\{1}", folderPath, emailHeaderFile);
                    textStatus.Text = string.Format("Retrieve summary {0}/{1} ...", i + 1, infos.Length);

                    Mail mail = new Mail("TryIt");
                    if (File.Exists(fullEmailHeaderFile))
                    {
                        mail.Load(fullEmailHeaderFile, true);
                        // This mail has been downloaded from server.
                    }
                    else
                    {
                        // Get the mail header from server.
                        mail.Load(_client.GetMailHeader(info));
                        mail.SaveAs(fullEmailHeaderFile, true);
                    }

                    pgBar.Value = pgBar.Maximum;

                    _addNewMailToList(ref info, ref mail);

                    if (uidlItem == null)
                    {
                        // Add the email UIDL and local file name to uidl file to avoid we retrieve it again. 
                        _uidlManager.AddUIDL(_currentServer, info.UIDL, emailHeaderFile);
                    }
                }

                _clearLocalMails(folderPath);
                _uidlManager.Update();
                textStatus.Text = string.Format("Total {0} emails", ListViewMail.Items.Count);

            }
            catch (Exception ep)
            {
                if (isUidlLoaded)
                {
                    _uidlManager.Update();
                }

                textStatus.Text = string.Format("Total {0} emails", ListViewMail.Items.Count);
                throw ep;
            }
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

        ListViewItem _addNewMailToList(ref MailInfo info, ref Mail mail)
        {
            ListViewItem item = new ListViewItem(mail.From.ToString());
            item.SubItems.Add(mail.Subject);
            item.SubItems.Add(mail.ReceivedDate.ToString("yyyy-MM-dd HH:mm:ss"));
            item.Tag = info;

            _updateItemFont(ref item);

            ListViewMail.Items.Add(item);
            return item;
        }

        void _updateItemFont(ref ListViewItem item)
        {
            MailInfo info = item.Tag as MailInfo;
            if (info.Deleted)
            {
                item.Font = new Font(this.Font, FontStyle.Strikeout);
            }
            else if (!info.Read)
            {
                item.Font = new Font(this.Font, FontStyle.Bold);
            }
            else
            {
                item.Font = new Font(this.Font, FontStyle.Regular);
            }
        }

        private void _createFullFolder(string path)
        {
            if (Directory.Exists(path))
                return;

            int pos = _currentPath.Length + 1;
            while ((pos = path.IndexOf('\\', pos)) != -1)
            {
                string parentPath = path.Substring(0, pos);
                if (!Directory.Exists(parentPath))
                {
                    Directory.CreateDirectory(parentPath);
                }

                pos++;
            }

            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }
        }

        // Clear local file that is not existed on server.
        private void _clearLocalMails(
            string localFolder)
        {
            string[] files = Directory.GetFiles(localFolder, "*.eml");
            int count = files.Length;
            for (int i = 0; i < count; i++)
            {
                string fileName = files[i];
                int pos = fileName.LastIndexOf("\\");
                if (pos != -1)
                {
                    fileName = fileName.Substring(pos + 1);
                }

                UIDLItem uidlItem = _uidlManager.FindLocalFile(fileName);
                if (uidlItem != null)
                {
                    continue;
                }

                string fullFilePath = files[i];
                File.Delete(fullFilePath);

                string htmlFile = _getHtmlRenderFile(fullFilePath);
                if (File.Exists(htmlFile))
                {
                    File.Delete(htmlFile);
                }

                string tempFolder = _getAttachmentFolder(fullFilePath);
                if (Directory.Exists(tempFolder))
                {
                    Directory.Delete(tempFolder, true);
                }
            }
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

        #endregion

        #region Copy, move, delete, unread emails ..

        Imap4Folder _getDestFolder()
        {
            FormSelectFolder selectFolderDialog = new FormSelectFolder();
            selectFolderDialog.OriginalFolderPath = _selectedFolderPath;

            TreeNode destRoot = selectFolderDialog.TreeViewFolder.Nodes.Add("Root");
            _copyNodes(TreeViewFolder.Nodes[0], destRoot);
            destRoot.ExpandAll();

            if (selectFolderDialog.ShowDialog() != DialogResult.OK)
            {
                return null;
            }

            return selectFolderDialog.TreeViewFolder.SelectedNode.Tag as Imap4Folder;
        }

        void _copyNodes(TreeNode sourceRoot, TreeNode destRoot)
        {
            var nodes = sourceRoot.Nodes;
            for (int i = 0; i < nodes.Count; i++)
            {
                TreeNode sourceNode = nodes[i];
                var destNode = destRoot.Nodes.Add(sourceNode.Text);
                destNode.Tag = sourceNode.Tag;
                _copyNodes(sourceNode, destNode);
            }
        }

        private void btnCopy_Click(object sender, EventArgs e)
        {
            if (_getSelectedNode(false) == null)
            {
                return;
            }

            Imap4Folder destFolder = _getDestFolder();
            if (destFolder == null)
            {
                return;
            }

            ListView.SelectedListViewItemCollection items = ListViewMail.SelectedItems;
            if (items == null || items.Count == 0)
            {
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                for (int i = 0; i < items.Count; i++)
                {
                    ListViewItem item = items[i];
                    MailInfo info = item.Tag as MailInfo;
                    _client.Copy(info, destFolder);
                }

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        private void btnMove_Click(object sender, EventArgs e)
        {
            if (_getSelectedNode(false) == null)
            {
                return;
            }

            Imap4Folder destFolder = _getDestFolder();
            if (destFolder == null)
            {
                return;
            }

            ListView.SelectedListViewItemCollection items = ListViewMail.SelectedItems;
            if (items == null || items.Count == 0)
            {
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                foreach (ListViewItem item in items)
                {
                    MailInfo info = item.Tag as MailInfo;
                    _client.Move(info, destFolder);
                    ListViewMail.Items.Remove(item);
                }

                if (_currentServer.Protocol == ServerProtocol.Imap4)
                {
                    _client.Expunge();
                }

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        private void btnExpunge_Click(object sender, EventArgs e)
        {
            if (_getSelectedNode(false) == null)
            {
                return;
            }

            if (_currentServer.Protocol != ServerProtocol.Imap4)
            {
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                _client.Expunge();

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
            }

        }

        private void btnUnread_Click(object sender, EventArgs e)
        {
            ListView.SelectedListViewItemCollection items = ListViewMail.SelectedItems;
            if (items == null || items.Count == 0)
            {
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                for (int i = 0; i < items.Count; i++)
                {
                    ListViewItem item = items[i];
                    MailInfo info = item.Tag as MailInfo;
                    _client.MarkAsRead(info, false);
                    _updateItemFont(ref item);
                }

                _endWork();

            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        private void btnUndelete_Click(object sender, EventArgs e)
        {
            ListView.SelectedListViewItemCollection items = ListViewMail.SelectedItems;
            if (items == null || items.Count == 0)
            {
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                for (int i = 0; i < items.Count; i++)
                {
                    ListViewItem item = items[i];
                    MailInfo info = item.Tag as MailInfo;
                    _client.Undelete(info);

                    _updateItemFont(ref item);
                }

                _endWork();

            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            ListView.SelectedListViewItemCollection items = ListViewMail.SelectedItems;
            if (items == null || items.Count == 0)
            {
                return;
            }

            try
            {
                _prepareWork();
                _connectServerOnDemand();

                foreach (ListViewItem item in items)
                {
                    MailInfo info = item.Tag as MailInfo;
                    _client.Delete(info);
                    ListViewMail.Items.Remove(item);
                }

                if (_currentServer.Protocol == ServerProtocol.Imap4)
                {
                     _client.Expunge();
                }

                _endWork();

            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        private void btnUpload_Click(object sender, EventArgs e)
        {
            TreeNode node = _getSelectedNode(false);
            if (node == null)
            {
                return;
            }

            openFileDialog1.Multiselect = false;
            if (openFileDialog1.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            try
            {
                Mail mailToUpload = new Mail("TryIt");
                mailToUpload.Load(openFileDialog1.FileName, false);

                _prepareWork();
                _connectServerOnDemand();

                _client.Append(node.Tag as Imap4Folder, mailToUpload.Content);
                _client.RefreshMailInfos();
                _loadServerMails(node);

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
            }

            pgBar.Value = 0;
        }

        #endregion

        #region Display, parse, download emails
        private void ListViewMail_ItemSelectionChanged(object sender, ListViewItemSelectionChangedEventArgs e)
        {
            TreeNode node = _getSelectedNode(false);
            ListView.SelectedListViewItemCollection items = ListViewMail.SelectedItems;
            if (node == null || items == null || items.Count != 1 || _isWorking)
            {
                return;
            }

            string originalStatus = textStatus.Text;
            try
            {
                _prepareWork();
                _connectServerOnDemand();

                Imap4Folder folder = node.Tag as Imap4Folder;
                ListViewItem item = items[0];
                MailInfo info = item.Tag as MailInfo;

                UIDLItem uidl = _uidlManager.FindUIDL(_currentServer, info.UIDL);
                if (uidl == null)
                {
                    // Should never happen except you delete the file from the folder manually.
                    throw new Exception("No local email file found!");
                }

                string folderPath = _getLocalFolderPath(folder);
                string fileName = string.Format("{0}\\{1}", folderPath, uidl.FileName);
                string htmlFile = _getHtmlRenderFile(fileName);
                string tempFolder = _getAttachmentFolder(fileName);

                // only mail header is retrieved, now retrieve full content of mail.
                if (!File.Exists(htmlFile))
                {
                    textStatus.Text = "Downloading current email ...";
                    pgBar.Value = 0;

                    Mail mail = _client.GetMail(info);
                    mail.SaveAs(fileName, true);

                    pgBar.Value = pgBar.Maximum;
                }

                if (!info.Read)
                {
                    _client.MarkAsRead(info, true);
                    _updateItemFont(ref item);
                }

                textStatus.Text = originalStatus;

                _showMail(fileName);

                _endWork();
            }
            catch (Exception ep)
            {
                _afterError(ep);
            }
        }

        private void _showMail(string fileName)
        {
            string htmlFile = _getHtmlRenderFile(fileName);

            if (!File.Exists(htmlFile))
            {   // we haven't generate the html for this email, generate it now.
                _GenerateHtmlForEmail(fileName);
            }

            webMail.Navigate(htmlFile);
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

        private string _formatHtmlTag(string src)
        {
            src = src.Replace(">", "&gt;");
            src = src.Replace("<", "&lt;");
            return src;
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
