Imports System.Globalization
Imports System.IO
Imports System.Text
Imports System.Text.RegularExpressions
Imports EAGetMail

Public Class Form1
    ReadOnly _protocolOffset As Integer = 1

    ' MailClient and Server
    Private _currentServer As MailServer = Nothing
    Private _client As MailClient = Nothing

    ' UIDL 
    Private _currentPath As String = ""
    Private _uidlManager As UIDLManager = New UIDLManager()

    ' Cancel current operation flag
    Private _isCancelOperation As Boolean = False
    Private _isWorking As Boolean = False

    Private _isSelectedFolderChanged As Boolean = False
    Private _selectedFolderPath As String = ""

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ' For evaluation usage, please use "TryIt" as the license code, otherwise the 
        ' "Invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
        ' "Trial version expired" exception will be thrown.
        _client = New MailClient("TryIt")

        ' Catching the following events is not necessary, 
        ' just make the application more user friendly.
        ' If you use the object in asp.net/windows service or non-gui application, 
        ' You need not to catch the following events.
        AddHandler _client.OnAuthorized, AddressOf OnAuthorized
        AddHandler _client.OnConnected, AddressOf OnConnected
        AddHandler _client.OnIdle, AddressOf OnIdle
        AddHandler _client.OnSecuring, AddressOf OnSecuring
        AddHandler _client.OnReceivingDataStream, AddressOf OnReceivingDataStream

        _initCurrentPath()
        _initControlOffset()
        _initOauthWrapper()

        webMail.Navigate("about:blank")

        ComboBoxAuthType.Items.Add("USER/LOGIN")
        ComboBoxAuthType.Items.Add("APOP")
        ComboBoxAuthType.Items.Add("NTLM")
        ComboBoxAuthType.Items.Add("Gmail XOAUTH2")
        ComboBoxAuthType.SelectedIndex = 0

        ComboBoxDateRange.Items.Add("Sync last 7 days emails")
        ComboBoxDateRange.Items.Add("Sync last 30 days emails")
        ComboBoxDateRange.Items.Add("Sync last 60 days emails")
        ComboBoxDateRange.Items.Add("Sync last 90 days emails")
        ComboBoxDateRange.Items.Add("Sync all emails (slow)")
        ComboBoxDateRange.SelectedIndex = 0

        ComboBoxProtocol.Items.Add("IMAP4")
        ComboBoxProtocol.Items.Add("EWS - Exchange 2007-2019/Office365")
        ComboBoxProtocol.Items.Add("WebDAV - Exchange 2000/2003")
        ComboBoxProtocol.SelectedIndex = 0

        ListViewMail.Sorting = SortOrder.Descending
        ListViewMail.ListViewItemSorter = New ListMailItemCompare()

        textStatus.Text = ""
        TreeViewFolder.Nodes.Clear()

        _isWorking = False
    End Sub

#Region "Resize Control Automatically"

    Private _isFormLoaded As Boolean = False
    Private _listViewMailWidthOffset As Integer = 0
    Private _webMailHeightOffset As Integer = 0
    Private _pgBarTopOffset As Integer = 0
    Private _tvFolderHeightOffset As Integer = 0

    Private Sub _initControlOffset()
        Me.MinimumSize = New System.Drawing.Size(Me.Width, Me.Height)
        _isFormLoaded = True

        _listViewMailWidthOffset = Me.Width - ListViewMail.Width
        _webMailHeightOffset = Me.Height - webMail.Height
        _pgBarTopOffset = Me.Height - pgBar.Top
        _tvFolderHeightOffset = Me.Height - TreeViewFolder.Height
    End Sub

    Private Sub Form1_Resize(sender As Object, e As EventArgs) Handles MyBase.Resize
        If Not _isFormLoaded Then
            Return
        End If

        ListViewMail.Width = Me.Width - _listViewMailWidthOffset
        webMail.Width = ListViewMail.Width
        webMail.Height = Me.Height - _webMailHeightOffset
        pgBar.Width = webMail.Width
        pgBar.Top = Me.Height - _pgBarTopOffset
        TreeViewFolder.Height = Me.Height - _tvFolderHeightOffset
    End Sub

#End Region

#Region "Initialize Controls"

    Private Sub _initCurrentPath()
        Dim path As String = Application.ExecutablePath
        Dim pos As Integer = path.LastIndexOfAny("\/".ToCharArray())

        If pos <> -1 Then
            path = path.Substring(0, pos)
        End If

        _currentPath = path
    End Sub

    Private Sub ComboBoxAuthType_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBoxAuthType.SelectedIndexChanged
        If ComboBoxAuthType.SelectedIndex = CInt(ServerAuthType.AuthXOAUTH2) Then
            ComboBoxProtocol.SelectedIndex = CInt(ServerProtocol.Imap4) - _protocolOffset
            textServer.Text = "imap.gmail.com"
            chkSSL.Checked = True
            textUser.Enabled = False
            textPassword.Enabled = False
            textStatus.Text = "Please click ""Start"" to login Gmail by Web OAUTH."
        Else
            textUser.Enabled = True
            textPassword.Enabled = True
            textStatus.Text = ""
            _oauthWrapper.OauthProvider.ClearToken()
            _oauthWrapper.AuthorizationCode = ""
        End If
    End Sub

    Private _oauthWrapper As OauthDesktopWrapper = Nothing
    Private Sub _initOauthWrapper()
        '
        '     To use Google OAUTH in your application, you must create a project in Google Developers Console.
        '
        '    - Create your project at https//console.developers.google.com/project.
        '    - Select your project -> APIs & Services -> Dashboard -> Credentials;
        '    - Credentials -> Create Credentials -> OAuth client ID -> Web application Or Other (Desktop Application). 
        '      It depends On your application type.
        '
        '    - Input a name for your application, input your current ASP/ASP.NET URL at Authorized redirect URIs, 
        '      For example: http : //localhost/gmailoauth/default.aspx. (Desktop Application doesn't require this step)
        '      Click "Create", you will get your client id And client secret.
        '
        '    - Finally you can also set detail information for your project at Credentials -> OAuth consent screen.

        '    - If you used https://mail.google.com scope, you should verify your application that Is inroduced in cosent screen.
        '      If you don't verify your application, your application is limited by some conditions.
        '
        '      You must apply For your client id And client secret, don't use the client id in the sample project, because it is limited now.
        '      If you got "This app isn't verified" information, please click "advanced" -> Go to ... for test.
        '
        Dim provider As OauthProviderInterface = GoogleOauthProvider.Create("1072602369179-aru4rj97ateiho9rt4pf5i8l1r01mc16.apps.googleusercontent.com", "Lnw8r5FvfKFNS_CSEucbdIE-")
        _oauthWrapper = New OauthDesktopWrapper(provider)
    End Sub

#End Region

#Region "Login, Cancel, Quit"

    Private Function _buildServer() As MailServer
        Dim server As MailServer = New MailServer(textServer.Text.Trim(), textUser.Text.Trim(), textPassword.Text.Trim(), chkSSL.Checked, CType(ComboBoxAuthType.SelectedIndex, ServerAuthType), CType((ComboBoxProtocol.SelectedIndex + _protocolOffset), ServerProtocol))

        If server.Protocol = ServerProtocol.Pop3 Then
            server.Port = If((chkSSL.Checked), 995, 110)
        ElseIf server.Protocol = ServerProtocol.Imap4 Then
            server.Port = If((chkSSL.Checked), 993, 143)
        End If

        Return server
    End Function

    Private Function _validateInput() As Boolean
        If String.IsNullOrEmpty(textServer.Text.Trim()) Then
            MessageBox.Show("Please input server address!")
            textServer.Enabled = True
            textServer.Focus()
            Return False
        End If

        If String.IsNullOrEmpty(textUser.Text.Trim()) Then
            MessageBox.Show("Please input user!")
            textUser.Enabled = True
            textUser.Focus()
            Return False
        End If

        If String.IsNullOrEmpty(textPassword.Text.Trim()) Then
            MessageBox.Show("Please input password!")
            textPassword.Enabled = True
            textPassword.Focus()
            Return False
        End If

        Return True
    End Function

    Private Function _tryOauth() As Boolean
        If ComboBoxAuthType.SelectedIndex <> CInt(ServerAuthType.AuthXOAUTH2) Then
            Return True
        End If

        If Not String.IsNullOrEmpty(_oauthWrapper.OauthProvider.AccessToken) Then

            If Not _oauthWrapper.IsAccessTokenExpired Then
                Return True
            End If

            textStatus.Text = "Refreshing access token ..."

            Try
                _oauthWrapper.RefreshAccessToken()
            Catch
                textStatus.Text = "Failed to refresh access token, try to get a new access token ..."
            End Try
        End If

        Using DialogOauth As FormOauth = New FormOauth()
            DialogOauth.OauthWrapper = _oauthWrapper
            DialogOauth.ShowDialog()
        End Using

        Try
            textStatus.Text = "Requesting access token ..."
            _oauthWrapper.RequestAccessTokenAndUserEmail()
            textStatus.Text = "Oauth is completed."
            Return True
        Catch ep As Exception
            MessageBox.Show(ep.Message)
            textStatus.Text = ep.Message
            Return False
        End Try
    End Function

    Private Sub _setMailRange()
        _client.GetMailInfosParam.Reset()

        Select Case ComboBoxDateRange.SelectedIndex
            Case 0
                _client.GetMailInfosParam.GetMailInfosOptions = (_client.GetMailInfosParam.GetMailInfosOptions Or GetMailInfosOptionType.DateRange)
                _client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-7)
                _client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1)
            Case 1
                _client.GetMailInfosParam.GetMailInfosOptions = (_client.GetMailInfosParam.GetMailInfosOptions Or GetMailInfosOptionType.DateRange)
                _client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-30)
                _client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1)
            Case 2
                _client.GetMailInfosParam.GetMailInfosOptions = (_client.GetMailInfosParam.GetMailInfosOptions Or GetMailInfosOptionType.DateRange)
                _client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-60)
                _client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1)
            Case 3
                _client.GetMailInfosParam.GetMailInfosOptions = (_client.GetMailInfosParam.GetMailInfosOptions Or GetMailInfosOptionType.DateRange)
                _client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-90)
                _client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1)
            Case Else
        End Select
    End Sub

    Private Sub _connectServerOnDemand()
        _isSelectedFolderChanged = False

        If Not _client.Connected Then
            textStatus.Text = "Connecting server ..."
            _isCancelOperation = False
            _client.Connect(_currentServer)
            textStatus.Text = "Connected"
        End If

        Dim node = _getSelectedNode(False)

        If node Is Nothing Then
            Return
        End If

        Dim folder = TryCast(node.Tag, Imap4Folder)

        If String.Compare(folder.ServerPath, _selectedFolderPath, True) = 0 Then
            Return
        End If

        ListViewMail.Items.Clear()
        _selectedFolderPath = folder.ServerPath
        _isSelectedFolderChanged = True

        If folder.NoSelect Then
            Return
        End If

        _client.SelectFolder(folder)
    End Sub

    Private Function _getSelectedNode(ByVal includeRoot As Boolean) As TreeNode
        Dim node As TreeNode = TreeViewFolder.SelectedNode

        If includeRoot Then
            Return node
        End If

        Return If((node IsNot Nothing AndAlso node.Parent Is Nothing), Nothing, node)
    End Function

    Private Sub btnStart_Click(sender As Object, e As EventArgs) Handles btnStart.Click
        _prepareLogin()

        If Not _tryOauth() Then
            textStatus.Text = "Failed to request/refresh access token."
            _afterLoginError()
            Return
        End If

        If ComboBoxAuthType.SelectedIndex = CInt(ServerAuthType.AuthXOAUTH2) Then
            textUser.Text = _oauthWrapper.OauthProvider.UserEmail
            textPassword.Text = _oauthWrapper.OauthProvider.AccessToken
        End If

        If Not _validateInput() Then
            _afterLoginError()
            Return
        End If

        btnStart.Enabled = False

        Try
            _prepareWork()

            _currentServer = _buildServer()
            textStatus.Text = "Connecting ..."
            _client.Connect(_currentServer)
            textStatus.Text = "Connected"

            _showAllFolders()

            _endWork()
            _afterLoginSucceeded()
        Catch ep As Exception
            _afterError(ep)
            _afterLoginError()
        End Try
    End Sub

    Private Sub btnQuit_Click(sender As Object, e As EventArgs) Handles btnQuit.Click
        Try
            _client.Logout()
            _client.Close()
        Catch
        End Try

        _afterQuit()
    End Sub

    Private Sub btnCancel_Click(sender As Object, e As EventArgs) Handles btnCancel.Click
        _isCancelOperation = True
        btnCancel.Enabled = False
    End Sub

    Private Sub _prepareLogin()
        textServer.Enabled = False
        textUser.Enabled = False
        textPassword.Enabled = False

        ComboBoxAuthType.Enabled = False
        ComboBoxProtocol.Enabled = False
        ComboBoxDateRange.Enabled = False

        chkSSL.Enabled = False
        btnStart.Enabled = False

        _selectedFolderPath = ""
    End Sub

    Private Sub _afterLoginSucceeded()
        textServer.Enabled = False
        textUser.Enabled = False
        textPassword.Enabled = False

        chkSSL.Enabled = False
        btnStart.Enabled = False
        btnQuit.Enabled = True

        _selectedFolderPath = ""
    End Sub

    Private Sub _afterLoginError()
        textServer.Enabled = True

        If ComboBoxAuthType.SelectedIndex <> CInt(ServerAuthType.AuthXOAUTH2) Then
            textUser.Enabled = True
            textPassword.Enabled = True
        Else
            textUser.Enabled = False
            textPassword.Enabled = False
        End If

        ComboBoxAuthType.Enabled = True
        ComboBoxDateRange.Enabled = True
        ComboBoxProtocol.Enabled = True

        chkSSL.Enabled = True

        btnStart.Enabled = True
        btnQuit.Enabled = False

        webMail.Navigate("about:blank")
        ListViewMail.Items.Clear()
        TreeViewFolder.Nodes.Clear()

        _selectedFolderPath = ""
    End Sub

    Private Sub _afterQuit()
        _endWork()

        webMail.Navigate("about:blank")
        ListViewMail.Items.Clear()
        TreeViewFolder.Nodes.Clear()
        textServer.Enabled = True

        If ComboBoxAuthType.SelectedIndex <> CInt(ServerAuthType.AuthXOAUTH2) Then
            textUser.Enabled = True
            textPassword.Enabled = True
        End If

        ComboBoxAuthType.Enabled = True
        ComboBoxProtocol.Enabled = True
        ComboBoxDateRange.Enabled = True

        chkSSL.Enabled = True
        btnStart.Enabled = True
        btnQuit.Enabled = False

        _selectedFolderPath = ""
        textStatus.Text = "Disconnected"
    End Sub

    Private Sub _afterError(ByVal ep As Exception)
        _endWork()
        _client.Close()

        MessageBox.Show(ep.Message)

        _selectedFolderPath = ""
        textStatus.Text = ep.Message
    End Sub

    Private Sub _prepareWork()
        _isWorking = True
        _isCancelOperation = False

        btnCancel.Enabled = True
        btnQuit.Enabled = False

        _enableControlDynamic()
    End Sub

    Private Sub _endWork()
        _isWorking = False

        btnCancel.Enabled = False
        btnQuit.Enabled = True

        _enableControlDynamic()
    End Sub

    Private Sub _enableControlDynamic()
        Dim items As ListView.SelectedListViewItemCollection = ListViewMail.SelectedItems
        Dim selectMailCount As Integer = If((items Is Nothing), 0, items.Count)
        Dim isFolderSelected As Boolean = (_getSelectedNode(False) IsNot Nothing)

        TreeViewFolder.Enabled = Not _isWorking
        ListViewMail.Enabled = Not _isWorking
        btnDelete.Enabled = Not _isWorking AndAlso isFolderSelected AndAlso (selectMailCount > 0)

        If ComboBoxProtocol.SelectedIndex + _protocolOffset = CInt(ServerProtocol.Imap4) Then
            btnUndelete.Enabled = Not _isWorking AndAlso isFolderSelected AndAlso (selectMailCount > 0)
            btnExpunge.Enabled = Not _isWorking AndAlso isFolderSelected
        Else
            btnUndelete.Enabled = False
            btnExpunge.Enabled = False
        End If

        btnUnread.Enabled = Not _isWorking AndAlso isFolderSelected AndAlso (selectMailCount > 0)
        btnMove.Enabled = Not _isWorking AndAlso isFolderSelected AndAlso (selectMailCount > 0)
        btnCopy.Enabled = Not _isWorking AndAlso isFolderSelected AndAlso (selectMailCount > 0)
        btnUpload.Enabled = Not _isWorking AndAlso isFolderSelected
    End Sub

#End Region

#Region "Show server folders and expand folders"

    Private Sub _showAllFolders()
        TreeViewFolder.Nodes.Clear()
        Dim rootNode As TreeNode = New TreeNode(String.Format("{0}\{1}", _currentServer.Server.ToLower(), _currentServer.User.ToLower()))
        rootNode.Tag = _currentServer

        TreeViewFolder.Nodes.Add(rootNode)
        TreeViewFolder.SelectedNode = rootNode

        textStatus.Text = "Refreshing folder list ..."
        _expandFolders(_client.Imap4Folders, rootNode)
        rootNode.ExpandAll()

        textStatus.Text = ""
    End Sub

    Private Sub _expandFolders(ByVal folders As Imap4Folder(), ByVal parentNode As TreeNode)
        parentNode.Nodes.Clear()

        For i As Integer = 0 To folders.Length - 1
            Dim folder As Imap4Folder = folders(i)
            Dim node As TreeNode = parentNode.Nodes.Add(folder.Name)
            node.Tag = folder
            _expandFolders(folder.SubFolders, node)
        Next
    End Sub

#End Region

#Region "Add, delete, rename folders"

    Private Function _getLocalFolderPath(ByRef folder As Imap4Folder)
        Return String.Format("{0}\{1}\{2}\{3}", _currentPath, _currentServer.Server, _currentServer.User, folder.LocalPath)
    End Function

    Private Sub contextMenuFolder_Opening(sender As Object, e As System.ComponentModel.CancelEventArgs) Handles contextMenuFolder.Opening
        Dim node = _getSelectedNode(True)

        If node Is Nothing Then
            e.Cancel = True
            Return
        End If

        addFolderToolStripMenuItem.Enabled = (Not _isWorking)
        deleteFolderToolStripMenuItem.Enabled = (Not _isWorking AndAlso node.Parent IsNot Nothing)
        refreshFoldersToolStripMenuItem.Enabled = (Not _isWorking)
        renameFolderToolStripMenuItem.Enabled = (Not _isWorking AndAlso node.Parent IsNot Nothing)
        refreshMailsToolStripMenuItem.Enabled = (Not _isWorking AndAlso node.Parent IsNot Nothing)
    End Sub

    Private Sub refreshFoldersToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles refreshFoldersToolStripMenuItem.Click
        Try
            _prepareWork()
            _connectServerOnDemand()

            _client.RefreshFolders()
            _showAllFolders()

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub refreshMailsToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles refreshMailsToolStripMenuItem.Click
        Dim node As TreeNode = _getSelectedNode(False)

        If node Is Nothing Then
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()

            _client.RefreshMailInfos()
            _loadServerMails(node)

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub addFolderToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles addFolderToolStripMenuItem.Click
        Dim folderDialog As FormAddFolder = New FormAddFolder()

        If folderDialog.ShowDialog() <> DialogResult.OK Then
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()

            Dim folderName As String = folderDialog.textFolderName.Text
            Dim node = _getSelectedNode(True)

            Dim folder As Imap4Folder = If((node.Parent IsNot Nothing), _client.CreateFolder(TryCast(node.Tag, Imap4Folder), folderName), _client.CreateFolder(Nothing, folderName))
            Dim newNode As TreeNode = node.Nodes.Add(folder.Name)
            newNode.Tag = folder

            node.ExpandAll()

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub deleteFolderToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles deleteFolderToolStripMenuItem.Click
        Dim node = _getSelectedNode(False)

        If node Is Nothing Then
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()

            Dim localFolderPath = _getLocalFolderPath(node.Tag)
            _client.DeleteFolder(TryCast(node.Tag, Imap4Folder))
            TreeViewFolder.SelectedNode = Nothing
            node.Remove()

            ListViewMail.Items.Clear()

            If Directory.Exists(localFolderPath) Then
                Directory.Delete(localFolderPath, True)
            End If

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub renameFolderToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles renameFolderToolStripMenuItem.Click
        Dim node As TreeNode = _getSelectedNode(False)

        If node Is Nothing Then
            Return
        End If

        TreeViewFolder.LabelEdit = True

        If Not node.IsEditing Then
            node.BeginEdit()
            ListViewMail.Enabled = False
        End If
    End Sub

    Private Sub TreeViewFolder_AfterLabelEdit(sender As Object, e As NodeLabelEditEventArgs) Handles TreeViewFolder.AfterLabelEdit
        If e.Label Is Nothing Then Return

        If e.Label.Length = 0 Then
            e.CancelEdit = True
            MessageBox.Show("Invalid folder name.The name cannot be blank!")
            ListViewMail.Enabled = True
            Return
        End If

        Dim node As TreeNode = e.Node

        If node.Tag Is Nothing Then
            ListViewMail.Enabled = True
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()

            Dim localFolderPath = _getLocalFolderPath(node.Tag)
            _client.RenameFolder(TryCast(node.Tag, Imap4Folder), e.Label)
            e.Node.EndEdit(False)

            Dim newFolderPath = _getLocalFolderPath(node.Tag)
            If Directory.Exists(localFolderPath) Then
                Directory.Move(localFolderPath, newFolderPath)
            End If

            _endWork()
        Catch ep As Exception
            _afterError(ep)
            e.CancelEdit = True
        End Try

    End Sub


#End Region

#Region "Display current folder email list"

    Private Sub TreeViewFolder_AfterSelect(sender As Object, e As TreeViewEventArgs) Handles TreeViewFolder.AfterSelect
        If e.Node.Parent Is Nothing Then
            ListViewMail.Items.Clear()
            textStatus.Text = "Root"
            _isSelectedFolderChanged = True
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()

            If _isSelectedFolderChanged Then
                _loadServerMails(e.Node)
            End If

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub _loadServerMails(ByVal node As TreeNode)
        ListViewMail.Items.Clear()
        Dim folder As Imap4Folder = TryCast(node.Tag, Imap4Folder)

        If folder.NoSelect Then
            Return
        End If

        Dim isUidlLoaded As Boolean = False

        Try
            Dim folderPath As String = _getLocalFolderPath(folder)
            _createFullFolder(folderPath)
            _uidlManager.Load(String.Format("{0}\uidl.txt", folderPath))
            isUidlLoaded = True

            _setMailRange()
            textStatus.Text = "Refreshing email list ..."
            Dim infos As MailInfo() = _client.GetMailInfos()

            If ComboBoxDateRange.SelectedIndex = 4 Then
                _uidlManager.SyncUIDL(_currentServer, infos)
                _uidlManager.Update()
            End If

            textStatus.Text = String.Format("Total {0} emails", infos.Length)

            For i As Integer = 0 To infos.Length - 1
                Dim info As MailInfo = infos(i)
                Dim emailHeaderFile As String = ""
                Dim uidlItem As UIDLItem = _uidlManager.FindUIDL(_currentServer, info.UIDL)

                If uidlItem IsNot Nothing Then
                    emailHeaderFile = uidlItem.FileName
                Else
                    emailHeaderFile = _generateFileName(i)
                End If

                Dim fullEmailHeaderFile As String = String.Format("{0}\{1}", folderPath, emailHeaderFile)
                textStatus.Text = String.Format("Retrieve summary {0}/{1} ...", i + 1, infos.Length)
                Dim mail As Mail = New Mail("TryIt")

                If File.Exists(fullEmailHeaderFile) Then
                    mail.Load(fullEmailHeaderFile, True)
                Else
                    mail.Load(_client.GetMailHeader(info))
                    mail.SaveAs(fullEmailHeaderFile, True)
                End If

                pgBar.Value = pgBar.Maximum
                _addNewMailToList(info, mail)

                If uidlItem Is Nothing Then
                    _uidlManager.AddUIDL(_currentServer, info.UIDL, emailHeaderFile)
                End If
            Next

            _clearLocalMails(folderPath)
            _uidlManager.Update()
            textStatus.Text = String.Format("Total {0} emails", ListViewMail.Items.Count)
        Catch ep As Exception

            If isUidlLoaded Then
                _uidlManager.Update()
            End If

            textStatus.Text = String.Format("Total {0} emails", ListViewMail.Items.Count)
            Throw ep
        End Try
    End Sub

    Private Function _generateFileName(ByVal sequence As Integer) As String
        Dim currentDateTime As DateTime = DateTime.Now
        Dim sdate As String = currentDateTime.ToString("yyyyMMddHHmmss", New CultureInfo("en-US"))
        Return String.Format("{0}-{1:000}-{2:000}.eml", currentDateTime.ToString("yyyyMMddHHmmss", New CultureInfo("en-US")), currentDateTime.Millisecond, sequence)
    End Function

    Private Function _addNewMailToList(ByRef info As MailInfo, ByRef mail As Mail) As ListViewItem
        Dim item As ListViewItem = New ListViewItem(mail.From.ToString())
        item.SubItems.Add(mail.Subject)
        item.SubItems.Add(mail.ReceivedDate.ToString("yyyy-MM-dd HH:mm:ss"))
        item.Tag = info

        _updateItemFont(item)

        ListViewMail.Items.Add(item)
        Return item
    End Function

    Private Sub _updateItemFont(ByRef item As ListViewItem)
        Dim info As MailInfo = TryCast(item.Tag, MailInfo)

        If info.Deleted Then
            item.Font = New Font(Me.Font, FontStyle.Strikeout)
        ElseIf Not info.Read Then
            item.Font = New Font(Me.Font, FontStyle.Bold)
        Else
            item.Font = New Font(Me.Font, FontStyle.Regular)
        End If
    End Sub

    Private Sub _createFullFolder(ByVal path As String)
        If Directory.Exists(path) Then Return
        Dim startIndex As Integer = _currentPath.Length + 1
        While True
            Dim pos As Integer = path.IndexOf("\", startIndex)
            If pos = -1 Then
                Exit While
            End If

            Dim parentFolder As String = path.Substring(0, pos)
            startIndex = pos + 1

            If Not Directory.Exists(parentFolder) Then
                Directory.CreateDirectory(parentFolder)
            End If

        End While

        If Not Directory.Exists(path) Then
            Directory.CreateDirectory(path)
        End If
    End Sub

    Private Sub _clearLocalMails(ByVal localFolder As String)
        Dim files As String() = Directory.GetFiles(localFolder, "*.eml")
        Dim count As Integer = files.Length

        For i As Integer = 0 To count - 1
            Dim fileName As String = files(i)
            Dim pos As Integer = fileName.LastIndexOf("\")

            If pos <> -1 Then
                fileName = fileName.Substring(pos + 1)
            End If

            Dim uidlItem As UIDLItem = _uidlManager.FindLocalFile(fileName)

            If uidlItem IsNot Nothing Then
                Continue For
            End If

            Dim fullFilePath As String = files(i)
            File.Delete(fullFilePath)
            Dim htmlFile As String = _getHtmlRenderFile(fullFilePath)

            If File.Exists(htmlFile) Then
                File.Delete(htmlFile)
            End If

            Dim tempFolder As String = _getAttachmentFolder(fullFilePath)

            If Directory.Exists(tempFolder) Then
                Directory.Delete(tempFolder, True)
            End If
        Next
    End Sub

    Private Function _getHtmlRenderFile(ByVal emlFile As String) As String
        Dim pos As Integer = emlFile.LastIndexOf(".")

        If pos <> -1 Then
            Return emlFile.Substring(0, pos) & ".html"
        Else
            Return emlFile & ".html"
        End If
    End Function

    Private Function _getAttachmentFolder(ByVal emlFile As String) As String
        Dim pos As Integer = emlFile.LastIndexOf(".")

        If pos <> -1 Then
            Return emlFile.Substring(0, pos)
        Else
            Return emlFile & "_a"
        End If
    End Function

#End Region

#Region "Copy, move, delete, unread emails .."
    Private Function _getDestFolder() As Imap4Folder

        Dim selectFolderDialog As FormSelectFolder = New FormSelectFolder()
        selectFolderDialog.OriginalFolderPath = _selectedFolderPath

        Dim destRoot As TreeNode = selectFolderDialog.TreeViewFolder.Nodes.Add("Root")
        _copyNodes(TreeViewFolder.Nodes(0), destRoot)
        destRoot.ExpandAll()

        If selectFolderDialog.ShowDialog() <> DialogResult.OK Then
            Return Nothing
        End If

        Return TryCast(selectFolderDialog.TreeViewFolder.SelectedNode.Tag, Imap4Folder)
    End Function

    Private Sub _copyNodes(ByVal sourceRoot As TreeNode, ByVal destRoot As TreeNode)
        Dim nodes = sourceRoot.Nodes

        For i As Integer = 0 To nodes.Count - 1
            Dim sourceNode As TreeNode = nodes(i)
            Dim destNode = destRoot.Nodes.Add(sourceNode.Text)
            destNode.Tag = sourceNode.Tag

            _copyNodes(sourceNode, destNode)
        Next
    End Sub

    Private Sub btnDelete_Click(sender As Object, e As EventArgs) Handles btnDelete.Click
        Dim items As ListView.SelectedListViewItemCollection = ListViewMail.SelectedItems

        If items Is Nothing OrElse items.Count = 0 Then
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()

            For Each item In items
                Dim info As MailInfo = TryCast(item.Tag, MailInfo)
                _client.Delete(info)

                ListViewMail.Items.Remove(item)
            Next

            If _currentServer.Protocol = ServerProtocol.Imap4 Then
                _client.Expunge()
            End If

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub btnUndelete_Click(sender As Object, e As EventArgs) Handles btnUndelete.Click
        Dim items As ListView.SelectedListViewItemCollection = ListViewMail.SelectedItems

        If items Is Nothing OrElse items.Count = 0 Then
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()

            For Each item In items
                Dim info As MailInfo = TryCast(item.Tag, MailInfo)
                _client.Undelete(info)
                _updateItemFont(item)
            Next

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub btnUnread_Click(sender As Object, e As EventArgs) Handles btnUnread.Click
        Dim items As ListView.SelectedListViewItemCollection = ListViewMail.SelectedItems

        If items Is Nothing OrElse items.Count = 0 Then
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()

            For Each item In items
                Dim info As MailInfo = TryCast(item.Tag, MailInfo)
                _client.MarkAsRead(info, False)
                _updateItemFont(item)
            Next

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub btnExpunge_Click(sender As Object, e As EventArgs) Handles btnExpunge.Click
        If _getSelectedNode(False) Is Nothing Then
            Return
        End If

        If _currentServer.Protocol <> ServerProtocol.Imap4 Then
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()
            _client.Expunge()
            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub btnCopy_Click(sender As Object, e As EventArgs) Handles btnCopy.Click
        If _getSelectedNode(False) Is Nothing Then
            Return
        End If

        Dim destFolder As Imap4Folder = _getDestFolder()

        If destFolder Is Nothing Then
            Return
        End If

        Dim items As ListView.SelectedListViewItemCollection = ListViewMail.SelectedItems

        If items Is Nothing OrElse items.Count = 0 Then
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()

            For Each item In items
                Dim info As MailInfo = TryCast(item.Tag, MailInfo)
                _client.Copy(info, destFolder)
            Next

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub btnMove_Click(sender As Object, e As EventArgs) Handles btnMove.Click
        If _getSelectedNode(False) Is Nothing Then
            Return
        End If

        Dim destFolder As Imap4Folder = _getDestFolder()

        If destFolder Is Nothing Then
            Return
        End If

        Dim items As ListView.SelectedListViewItemCollection = ListViewMail.SelectedItems

        If items Is Nothing OrElse items.Count = 0 Then
            Return
        End If

        Try
            _prepareWork()
            _connectServerOnDemand()

            For Each item In items
                Dim info As MailInfo = TryCast(item.Tag, MailInfo)
                _client.Move(info, destFolder)
                ListViewMail.Items.Remove(item)
            Next

            If _currentServer.Protocol = ServerProtocol.Imap4 Then
                _client.Expunge()
            End If

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub btnUpload_Click(sender As Object, e As EventArgs) Handles btnUpload.Click
        Dim node As TreeNode = _getSelectedNode(False)

        If node Is Nothing Then
            Return
        End If

        openFileDialog1.Multiselect = False

        If openFileDialog1.ShowDialog() <> DialogResult.OK Then
            Return
        End If

        Try
            Dim mailToUpload As Mail = New Mail("TryIt")
            mailToUpload.Load(openFileDialog1.FileName, False)

            _prepareWork()
            _connectServerOnDemand()

            _client.Append(TryCast(node.Tag, Imap4Folder), mailToUpload.Content)
            _client.RefreshMailInfos()
            _loadServerMails(node)

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try

        pgBar.Value = 0
    End Sub

#End Region

#Region "Display, parse, download emails"

    Private Sub ListViewMail_ItemSelectionChanged(sender As Object, e As ListViewItemSelectionChangedEventArgs) Handles ListViewMail.ItemSelectionChanged
        Dim node As TreeNode = _getSelectedNode(False)
        Dim items As ListView.SelectedListViewItemCollection = ListViewMail.SelectedItems

        If node Is Nothing OrElse items Is Nothing OrElse items.Count <> 1 OrElse _isWorking Then
            Return
        End If

        Dim originalStatus As String = textStatus.Text

        Try
            _prepareWork()
            _connectServerOnDemand()

            Dim folder As Imap4Folder = TryCast(node.Tag, Imap4Folder)
            Dim item As ListViewItem = items(0)
            Dim info As MailInfo = TryCast(item.Tag, MailInfo)
            Dim uidl As UIDLItem = _uidlManager.FindUIDL(_currentServer, info.UIDL)

            If uidl Is Nothing Then
                Throw New Exception("No local email file found!")
            End If

            Dim folderPath As String = _getLocalFolderPath(folder)
            Dim fileName As String = String.Format("{0}\{1}", folderPath, uidl.FileName)
            Dim htmlFile As String = _getHtmlRenderFile(fileName)
            Dim tempFolder As String = _getAttachmentFolder(fileName)

            If Not File.Exists(htmlFile) Then
                textStatus.Text = "Downloading current email ..."
                pgBar.Value = 0

                Dim mail As Mail = _client.GetMail(info)
                mail.SaveAs(fileName, True)

                pgBar.Value = pgBar.Maximum
            End If

            If Not info.Read Then
                _client.MarkAsRead(info, True)
                _updateItemFont(item)
            End If

            textStatus.Text = originalStatus
            _showMail(fileName)

            _endWork()
        Catch ep As Exception
            _afterError(ep)
        End Try
    End Sub

    Private Sub _showMail(ByVal fileName As String)
        Dim htmlFile As String = _getHtmlRenderFile(fileName)

        If Not File.Exists(htmlFile) Then
            _GenerateHtmlForEmail(fileName)
        End If

        webMail.Navigate(htmlFile)
    End Sub

    Private Sub _GenerateHtmlForEmail(ByVal emlFile As String)
        Dim mail As Mail = New Mail("TryIt")
        mail.Load(emlFile, False)

        If mail.IsEncrypted Then

            Try
                mail = mail.Decrypt(Nothing)
            Catch ep As Exception
                MessageBox.Show(ep.Message)
            End Try
        End If

        If mail.IsSigned Then

            Try
                Dim signerCertificate As Certificate = mail.VerifySignature()
                MessageBox.Show("This email contains a valid digital signature.")
            Catch ep As Exception
                MessageBox.Show(ep.Message)
            End Try
        End If

        mail.DecodeTNEF()

        Dim html As String = mail.HtmlBody
        Dim header As StringBuilder = New StringBuilder()

        header.Append("<font face=""Courier New,Arial"" size=2>")
        header.Append("<b>From:</b> " & _formatHtmlTag(mail.From.ToString()) & "<br>")
        header.Append(_formatAddresses(mail.[To], "To"))
        header.Append(_formatAddresses(mail.Cc, "Cc"))
        header.Append(String.Format("<b>Subject:</b>{0}<br>" & vbCrLf, _formatHtmlTag(mail.Subject)))

        Dim tempFolder As String = _getAttachmentFolder(emlFile)
        Dim attachments As Attachment() = mail.Attachments

        If attachments.Length > 0 Then
            If Not Directory.Exists(tempFolder) Then Directory.CreateDirectory(tempFolder)
            header.Append("<b>Attachments:</b> ")

            For i As Integer = 0 To attachments.Length - 1
                Dim attachment As Attachment = attachments(i)
                Dim attachmentName As String = String.Format("{0}\{1}", tempFolder, attachment.Name)

                attachment.SaveAs(attachmentName, True)
                header.Append(String.Format("<a href=""{0}"" target=""_blank"">{1}</a> ", attachmentName, attachment.Name))

                If attachment.ContentID.Length > 0 Then
                    html = html.Replace("cid:" & attachment.ContentID, attachmentName)
                End If
            Next
        End If

        Dim reg As Regex = New Regex("(<meta[^>]*charset[ " & vbTab & "]*=[ " & vbTab & """]*)([^<> " & vbCrLf & """]*)", RegexOptions.Multiline Or RegexOptions.IgnoreCase)
        html = reg.Replace(html, "$1utf-8")

        If Not reg.IsMatch(html) Then
            header.Insert(0, "<meta HTTP-EQUIV=""Content-Type"" Content=""text/html; charset=utf-8"">")
        End If

        html = header.ToString() & "<hr>" & html
        Dim htmlFile As String = _getHtmlRenderFile(emlFile)

        Using stream As FileStream = New FileStream(htmlFile, FileMode.Create, FileAccess.Write, FileShare.None)
            Dim buffer As Byte() = Encoding.UTF8.GetBytes(html)
            stream.Write(buffer, 0, buffer.Length)
            stream.Close()
        End Using

        mail.Clear()
    End Sub

    Private Function _formatHtmlTag(ByVal src As String) As String
        src = src.Replace(">", "&gt;")
        src = src.Replace("<", "&lt;")
        Return src
    End Function

    Private Function _formatAddresses(ByVal addresses As MailAddress(), ByVal prefix As String) As String
        If addresses.Length = 0 Then
            Return ""
        End If

        Dim buffer As StringBuilder = New StringBuilder()
        buffer.Append(String.Format("<b>{0}:</b> ", prefix))

        For i As Integer = 0 To addresses.Length - 1
            buffer.Append(_formatHtmlTag(addresses(i).ToString()))

            If i < addresses.Length - 1 Then
                buffer.Append("; ")
            End If
        Next

        buffer.Append("<br>")
        Return buffer.ToString()
    End Function

#End Region

#Region "EAGetMail Event Handler"

    Private Sub OnConnected(ByVal sender As Object, ByRef cancel As Boolean)
        textStatus.Text = "Connected ..."
        cancel = _isCancelOperation
        Application.DoEvents()
    End Sub

    Private Sub OnQuit(ByVal sender As Object, ByRef cancel As Boolean)
        textStatus.Text = "Quit ..."
        cancel = _isCancelOperation
        Application.DoEvents()
    End Sub

    Private Sub OnReceivingDataStream(ByVal sender As Object, ByVal info As MailInfo, ByVal received As Integer, ByVal total As Integer, ByRef cancel As Boolean)
        pgBar.Minimum = 0
        pgBar.Maximum = total
        pgBar.Value = received
        cancel = _isCancelOperation
        Application.DoEvents()
    End Sub

    Private Sub OnIdle(ByVal sender As Object, ByRef cancel As Boolean)
        cancel = _isCancelOperation
        Application.DoEvents()
    End Sub

    Private Sub OnAuthorized(ByVal sender As Object, ByRef cancel As Boolean)
        textStatus.Text = "Authorized ..."
        cancel = _isCancelOperation
        Application.DoEvents()
    End Sub

    Private Sub OnSecuring(ByVal sender As Object, ByRef cancel As Boolean)
        textStatus.Text = "Securing ..."
        cancel = _isCancelOperation
        Application.DoEvents()
    End Sub


#End Region

End Class
