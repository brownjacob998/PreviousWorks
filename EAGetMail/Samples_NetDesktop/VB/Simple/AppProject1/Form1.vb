Imports System.Globalization
Imports System.Text
Imports System.Text.RegularExpressions
Imports System.IO
Imports EAGetMail

Public Class Form1

    Private _isCancelOperation As Boolean = False
    Private _uidlFile As String = "uidl.txt"
    Private _currentPath As String = ""

#Region "Resize Control Automatically"
    Dim _isFormLoaded As Boolean = False
    Dim _listViewMailWidthOffset As Integer = 0
    Dim _webMailHeightOffset As Integer = 0
    Dim _buttonDeleteLeftOffset As Integer = 0

    Private Sub _initControlOffset()
        ' No smaller than design time size
        Me.MinimumSize = New System.Drawing.Size(Me.Width, Me.Height)
        _isFormLoaded = True
        _listViewMailWidthOffset = Me.Width - ListViewMail.Width
        _webMailHeightOffset = Me.Height - WebMail.Height
        _buttonDeleteLeftOffset = Me.Width - ButtonDelete.Left
    End Sub

    Private Sub Form1_Resize(sender As Object, e As EventArgs) Handles MyBase.Resize
        If Not _isFormLoaded Then
            Return
        End If

        ListViewMail.Width = Me.Width - _listViewMailWidthOffset
        WebMail.Width = ListViewMail.Width
        WebMail.Height = Me.Height - _webMailHeightOffset
        ButtonDelete.Left = Me.Width - _buttonDeleteLeftOffset
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
            ComboBoxProtocol.SelectedIndex = CInt(ServerProtocol.Imap4)
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

    Private Sub ComboBoxProtocol_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBoxProtocol.SelectedIndexChanged
        If ComboBoxProtocol.SelectedIndex = CInt(ServerProtocol.Pop3) Then
            chkNewOnly.Checked = False
            chkNewOnly.Enabled = False
            ComboBoxDateRange.SelectedIndex = 0
            ComboBoxDateRange.Enabled = False
        Else
            chkNewOnly.Enabled = True
            ComboBoxDateRange.Enabled = True
        End If

        If ComboBoxProtocol.SelectedIndex = CInt(ServerProtocol.ExchangeEWS) Then
            chkSSL.Checked = True
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

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        _initCurrentPath()
        _initControlOffset()
        _initOauthWrapper()

        WebMail.Navigate("about:blank")

        ComboBoxAuthType.Items.Add("USER/LOGIN")
        ComboBoxAuthType.Items.Add("APOP")
        ComboBoxAuthType.Items.Add("NTLM")
        ComboBoxAuthType.Items.Add("Gmail XOAUTH2")
        ComboBoxAuthType.SelectedIndex = 0

        ComboBoxDateRange.Items.Add("All emails")
        ComboBoxDateRange.Items.Add("Last 7 days")
        ComboBoxDateRange.Items.Add("Last 30 days")
        ComboBoxDateRange.Items.Add("Last 60 days")
        ComboBoxDateRange.Items.Add("Last 90 days")
        ComboBoxDateRange.SelectedIndex = 0

        ComboBoxProtocol.Items.Add("POP3")
        ComboBoxProtocol.Items.Add("IMAP4")
        ComboBoxProtocol.Items.Add("EWS - Exchange 2007-2019/Office365")
        ComboBoxProtocol.Items.Add("WebDAV - Exchange 2000/2003")
        ComboBoxProtocol.SelectedIndex = 0

        ListViewMail.Sorting = SortOrder.Descending
        ListViewMail.ListViewItemSorter = New ListMailItemCompare()

        _loadLocalMails()
        LabelTotal.Text = String.Format("Total {0} email(s)", ListViewMail.Items.Count)
    End Sub

#End Region

#Region "Retrieve emails from server"

    Private Function _buildServer() As MailServer
        Dim server As MailServer = New MailServer(textServer.Text.Trim(),
                                                  textUser.Text.Trim(),
                                                  textPassword.Text.Trim(),
                                                  chkSSL.Checked,
                                                  CType(ComboBoxAuthType.SelectedIndex, ServerAuthType),
                                                  CType(ComboBoxProtocol.SelectedIndex, ServerProtocol))

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

    Private Sub _setMailRange(ByRef client As MailClient)
        client.GetMailInfosParam.Reset()

        If ComboBoxProtocol.SelectedIndex = CInt(ServerProtocol.Pop3) Then
            Return ' POP3 protocol doesn't support this feature.
        End If

        If chkNewOnly.Checked Then
            client.GetMailInfosParam.GetMailInfosOptions = (client.GetMailInfosParam.GetMailInfosOptions Or GetMailInfosOptionType.NewOnly)
        End If

        Select Case ComboBoxDateRange.SelectedIndex
            Case 1
                client.GetMailInfosParam.GetMailInfosOptions = (client.GetMailInfosParam.GetMailInfosOptions Or GetMailInfosOptionType.DateRange)
                client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-7)
                client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1)
            Case 2
                client.GetMailInfosParam.GetMailInfosOptions = (client.GetMailInfosParam.GetMailInfosOptions Or GetMailInfosOptionType.DateRange)
                client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-30)
                client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1)
            Case 3
                client.GetMailInfosParam.GetMailInfosOptions = (client.GetMailInfosParam.GetMailInfosOptions Or GetMailInfosOptionType.DateRange)
                client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-60)
                client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1)
            Case 4
                client.GetMailInfosParam.GetMailInfosOptions = (client.GetMailInfosParam.GetMailInfosOptions Or GetMailInfosOptionType.DateRange)
                client.GetMailInfosParam.DateRange.SINCE = DateTime.Now.AddDays(-90)
                client.GetMailInfosParam.DateRange.BEFORE = DateTime.Now.AddDays(1)
            Case Else
        End Select
    End Sub

    Private Sub _enableSettingControls(ByVal isEnabled As Boolean, ByVal isCancelEnabled As Boolean)
        btnStart.Enabled = isEnabled
        btnCancel.Enabled = isCancelEnabled
        textServer.Enabled = isEnabled
        chkSSL.Enabled = isEnabled
        chkLeaveCopy.Enabled = isEnabled

        ComboBoxAuthType.Enabled = isEnabled
        ComboBoxProtocol.Enabled = isEnabled

        If ComboBoxAuthType.SelectedIndex <> CInt(ServerAuthType.AuthXOAUTH2) Then
            textUser.Enabled = isEnabled
            textPassword.Enabled = isEnabled
        End If

        If ComboBoxProtocol.SelectedIndex <> CInt(ServerProtocol.Pop3) Then
            chkNewOnly.Enabled = isEnabled
            ComboBoxDateRange.Enabled = isEnabled
        End If
    End Sub

    Private Function _createLocalInbox() As String
        Dim localInbox As String = String.Format("{0}\inbox", _currentPath)

        If Not Directory.Exists(localInbox) Then
            Directory.CreateDirectory(localInbox)
        End If

        Return localInbox
    End Function

    Private Function _generateFileName(ByVal sequence As Integer) As String
        Dim currentDateTime As DateTime = DateTime.Now
        Dim sdate As String = currentDateTime.ToString("yyyyMMddHHmmss", New CultureInfo("en-US"))
        Return String.Format("{0}-{1:000}-{2:000}.eml",
                             currentDateTime.ToString("yyyyMMddHHmmss", New CultureInfo("en-US")),
                             currentDateTime.Millisecond,
                             sequence)
    End Function

    Private Function _addNewMailToListView(ByRef mail As Mail, ByVal fullFileName As String) As ListViewItem
        Dim item As ListViewItem = New ListViewItem(mail.From.ToString())
        item.SubItems.Add(mail.Subject)
        item.SubItems.Add(mail.ReceivedDate.ToString("yyyy-MM-dd HH:mm:ss"))
        item.Tag = fullFileName

        item.Font = New Font(Me.Font, FontStyle.Bold)
        ListViewMail.Items.Add(item)
        Return item
    End Function

    Private Sub btnStart_Click(sender As Object, e As EventArgs) Handles btnStart.Click
        _enableSettingControls(False, False)

        If Not _tryOauth() Then
            _enableSettingControls(True, False)
            Return
        End If

        If ComboBoxAuthType.SelectedIndex = CInt(ServerAuthType.AuthXOAUTH2) Then
            textUser.Text = _oauthWrapper.OauthProvider.UserEmail
            textPassword.Text = _oauthWrapper.OauthProvider.AccessToken
        End If

        If Not _validateInput() Then
            _enableSettingControls(True, False)
            Return
        End If

        _enableSettingControls(False, True)

        ' UIDL is the identifier of every email on POP3/IMAP4/Exchange server, to avoid retrieve
        ' the same email from server more than once, we record the email UIDL retrieved every time
        ' if you delete the email from server every time and not to leave a copy of email on
        ' the server, then please remove all the function about uidl.
        ' UIDLManager wraps the function to write/read uidl record from a text file.
        Dim uidlManager As UIDLManager = New UIDLManager()
        Dim _isUidlLoaded As Boolean = False

        Try
            Dim client As MailClient = New MailClient("TryIt")

            ' Catching the following events is not necessary, 
            ' just make the application more user friendly.
            ' If you use the object in asp.net/windows service or non-gui application, 
            ' You need not to catch the following events.
            AddHandler client.OnAuthorized, AddressOf OnAuthorized
            AddHandler client.OnConnected, AddressOf OnConnected
            AddHandler client.OnIdle, AddressOf OnIdle
            AddHandler client.OnSecuring, AddressOf OnSecuring
            AddHandler client.OnReceivingDataStream, AddressOf OnReceivingDataStream

            _isCancelOperation = False
            textStatus.Text = "Connecting ..."

            Dim server As MailServer = _buildServer()
            client.Connect(server)

            Dim localInbox As String = _createLocalInbox()
            Dim uidlfile As String = String.Format("{0}\{1}", localInbox, _uidlFile)
            uidlManager.Load(uidlfile)
            _isUidlLoaded = True

            _setMailRange(client)

            ' generate a log file for debug
            ' client.LogFileName = String.Format("{0}\\log.txt", _currentPath)
            textStatus.Text = "Retrieving email list ..."
            Dim infos As MailInfo() = client.GetMailInfos()
            textStatus.Text = String.Format("Total {0} email(s)", infos.Length)

            If ComboBoxDateRange.SelectedIndex = 0 Then
                ' Remove the local uidl that Is Not existed on the server,
                ' we only synchronize it with uidl of all emails in current mail folder
                uidlManager.SyncUIDL(server, infos)
                uidlManager.Update()
            End If

            For i As Integer = 0 To infos.Length - 1
                pgBar.Maximum = 100
                pgBar.Minimum = 0
                pgBar.Value = 0

                textStatus.Text = String.Format("Checking {0}/{1}...", i + 1, infos.Length)
                Dim info As MailInfo = infos(i)

                If uidlManager.FindUIDL(server, info.UIDL) IsNot Nothing Then
                    ' This email has been downloaded before.
                    Continue For
                End If

                textStatus.Text = String.Format("Retrieving {0}/{1}...", i + 1, infos.Length)
                Dim mail As Mail = client.GetMail(info)
                Dim fileName As String = _generateFileName(i + 1)
                Dim fullFileName As String = String.Format("{0}\{1}", localInbox, fileName)

                mail.SaveAs(fullFileName, True)
                _addNewMailToListView(mail, fullFileName)

                mail.Clear()
                LabelTotal.Text = String.Format("Total {0} email(s)", ListViewMail.Items.Count)

                ' If retrieve only new emails, after we retrieved it, mark it as read,
                ' With this feature, you don't have to UIDLManager to prevent duplicated emails.
                If chkNewOnly.Checked And ComboBoxProtocol.SelectedIndex <> CInt(ServerProtocol.Pop3) Then
                    client.MarkAsRead(info, True)
                End If

                If chkLeaveCopy.Checked Then
                    ' Add the email uidl to uidl file to avoid we retrieve it next time. 
                    uidlManager.AddUIDL(server, info.UIDL, fileName)
                Else
                    textStatus.Text = String.Format("Deleting {0}...", i + 1)
                    client.Delete(info)

                    ' Remove UIDL from local uidl file.
                    uidlManager.RemoveUIDL(server, info.UIDL)
                End If
            Next

            ' Delete method just mark the email as deleted, 
            ' Quit method expunge the emails from server exactly.
            client.Quit()
            ' Update the uidl list to local uidl file and then we can load it next time.
            uidlManager.Update()
            textStatus.Text = "Completed"
        Catch ep As Exception

            If _isUidlLoaded Then
                ' Update the uidl list to local uidl file and then we can load it next time.
                uidlManager.Update()
            End If

            MessageBox.Show(ep.Message)
            textStatus.Text = ep.Message
        End Try

        _enableSettingControls(True, False)
    End Sub

    Private Sub btnCancel_Click(sender As Object, e As EventArgs) Handles btnCancel.Click
        btnCancel.Enabled = False
        _isCancelOperation = True
    End Sub

#End Region

#Region "Parse And display emails"

    Private Sub _loadLocalMails()
        Dim localInbox As String = _createLocalInbox()
        Dim files As String() = Directory.GetFiles(localInbox, "*.eml")

        For i As Integer = 0 To files.Length - 1
            Dim fullFileName As String = files(i)

            Dim mail As Mail = New Mail("TryIt")
            mail.Load(fullFileName, True)

            Dim item As ListViewItem = _addNewMailToListView(mail, fullFileName)
            Dim htmlFile As String = _getHtmlRenderFile(fullFileName)

            If Not File.Exists(htmlFile) Then
                item.Font = New Font(Me.Font, FontStyle.Bold)
            Else
                item.Font = New Font(Me.Font, FontStyle.Regular)
            End If

            mail.Clear()
        Next
    End Sub

    Private Function _formatHtmlTag(ByVal src As String) As String
        src = src.Replace(">", "&gt;")
        src = src.Replace("<", "&lt;")
        Return src
    End Function

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

    Private Sub ListViewMail_Click(sender As Object, e As EventArgs) Handles ListViewMail.Click
        Dim items As ListView.SelectedListViewItemCollection = ListViewMail.SelectedItems
        If items.Count = 0 Then Return

        Dim item As ListViewItem = TryCast(items(0), ListViewItem)
        _showMail(TryCast(item.Tag, String))
        item.Font = New Font(item.Font, FontStyle.Regular)
    End Sub

    Private Sub _showMail(ByVal fileName As String)
        Try
            Dim htmlFile As String = _getHtmlRenderFile(fileName)

            If Not File.Exists(htmlFile) Then
                ' We haven't generated the html for this email, generate it now.
                _GenerateHtmlForEmail(fileName)
            End If

            WebMail.Navigate(htmlFile)
        Catch ep As Exception
            MessageBox.Show(ep.Message)
        End Try
    End Sub

    ' We generate a html + attachment folder for every email, once the html is create,
    ' next time we don't need to parse the email again.
    Private Sub _GenerateHtmlForEmail(ByVal emlFile As String)
        Dim mail As Mail = New Mail("TryIt")
        mail.Load(emlFile, False)

        If mail.IsEncrypted Then
            Try
                ' This email is encrypted, we decrypt it by user default certificate.
                ' you can also use specified certificate like this
                ' cert = new Certificate()
                ' cert.Load("c:\test.pfx", "pfxpassword", Certificate.CertificateKeyLocation.CRYPT_USER_KEYSET)
                ' mail = mail.Decrypt(cert)
                mail = mail.Decrypt(Nothing)
            Catch ep As Exception
                MessageBox.Show(ep.Message)
            End Try
        End If

        If mail.IsSigned Then
            Try
                ' This email is digital signed.
                Dim signerCertificate As Certificate = mail.VerifySignature()
                MessageBox.Show("This email contains a valid digital signature.")
            Catch ep As Exception
                MessageBox.Show(ep.Message)
            End Try
        End If

        ' Decode winmail.dat (Outlook TNEF Stream) automatically.
        ' also convert RTF body to HTML body automatically
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
                    ' Show embedded image.
                    html = html.Replace("cid:" & attachment.ContentID, attachmentName)
                End If
            Next
        End If

        ' Change original meta header encoding to utf-8
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

    Private Sub ButtonDelete_Click(sender As Object, e As EventArgs) Handles ButtonDelete.Click
        Dim items As ListView.SelectedListViewItemCollection = ListViewMail.SelectedItems
        If items.Count = 0 Then Return
        If MessageBox.Show("Do you want to delete all selected emails", "", MessageBoxButtons.YesNo) = DialogResult.No Then Return

        While items.Count > 0

            Try
                Dim fileName As String = TryCast(items(0).Tag, String)
                File.Delete(fileName)
                Dim htmlFile As String = _getHtmlRenderFile(fileName)
                Dim attachmentFolder As String = _getAttachmentFolder(fileName)

                If File.Exists(htmlFile) Then
                    File.Delete(htmlFile)
                End If

                If Directory.Exists(attachmentFolder) Then
                    Directory.Delete(attachmentFolder, True)
                End If

                ListViewMail.Items.Remove(items(0))
            Catch ep As Exception
                MessageBox.Show(ep.Message)
                Exit While
            End Try
        End While

        LabelTotal.Text = String.Format("Total {0} email(s)", ListViewMail.Items.Count)
        WebMail.Navigate("about:blank")
    End Sub

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
