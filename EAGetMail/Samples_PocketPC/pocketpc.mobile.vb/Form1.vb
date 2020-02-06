Imports System.IO
Imports System.Text
Imports System.Text.RegularExpressions
Imports System.Globalization
Imports EAGetMail

Public Class Form1
    Private _cancelTask As Boolean = False
    Private _currentPath As String = ""

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        webMail.Navigate(New System.Uri("about:blank"))

        lstProtocol.Items.Add("POP3")
        lstProtocol.Items.Add("IMAP4")
        lstProtocol.Items.Add("Exchange Web Service - 2007/2010")
        lstProtocol.Items.Add("Exchange WebDAV - Exchange 2000/2003")

        lstProtocol.SelectedIndex = 0

        lstAuthType.Items.Add("USER/LOGIN")
        lstAuthType.Items.Add("APOP")
        lstAuthType.Items.Add("NTLM")
        lstAuthType.SelectedIndex = 0

        Dim asb As System.Reflection.Assembly = System.Reflection.Assembly.GetExecutingAssembly()
        Dim ms() As System.Reflection.Module = asb.GetModules()

        Dim file As String = "pocketpc.mobile.vb.exe"
        Dim count As Integer = ms.Length
        For i As Integer = 0 To count - 1
            If String.Compare(file, ms(i).Name, True) = 0 Then
                file = ms(i).FullyQualifiedName
                Exit For
            End If
        Next

        Dim path As String = file
        Dim pos As Integer = path.LastIndexOf("\")
        If (pos <> -1) Then
            path = path.Substring(0, pos)
        End If
        _currentPath = path

        LoadMails()
    End Sub

    Private Function _buildServer() As MailServer
        Dim server As MailServer = New MailServer(textServer.Text.Trim(), _
                                                  textUser.Text.Trim(), _
                                                  textPassword.Text.Trim(), _
                                                  chkSSL.Checked, _
                                                  CType(lstAuthType.SelectedIndex, ServerAuthType), _
                                                  CType(lstProtocol.SelectedIndex, ServerProtocol))

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

    Private Sub _enableSettingControls(ByVal isEnabled As Boolean, ByVal isCancelEnabled As Boolean)
        btnStart.Enabled = isEnabled
        btnCancel.Enabled = isCancelEnabled
        textServer.Enabled = isEnabled
        chkSSL.Enabled = isEnabled
        chkLeaveCopy.Enabled = isEnabled

        lstAuthType.Enabled = isEnabled
        lstProtocol.Enabled = isEnabled
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
        Return String.Format("{0}-{1:000}-{2:000}.eml", _
                             currentDateTime.ToString("yyyyMMddHHmmss", New CultureInfo("en-US")), _
                             currentDateTime.Millisecond, _
                             sequence)
    End Function

    Private Function _addNewMailToListView(ByRef mail As Mail, ByVal fullFileName As String) As ListViewItem
        Dim item As ListViewItem = New ListViewItem(mail.From.ToString())
        item.SubItems.Add(mail.Subject)
        item.SubItems.Add(mail.ReceivedDate.ToString("yyyy-MM-dd HH:mm:ss"))
        item.Tag = fullFileName

        lstMail.Items.Add(item)
        Return item
    End Function

    Private Sub btnStart_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnStart.Click
        _enableSettingControls(False, False)

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
        Dim isUidlLoaded As Boolean = False

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

            _cancelTask = False
            lblStatus.Text = "Connecting ..."

            Dim server As MailServer = _buildServer()
            client.Connect(server)

            Dim localInbox As String = _createLocalInbox()
            Dim uidlfile As String = String.Format("{0}\uidl.txt", localInbox)
            uidlManager.Load(uidlfile)
            isUidlLoaded = True

            ' generate a log file for debug
            ' client.LogFileName = String.Format("{0}\\log.txt", _currentPath)
            lblStatus.Text = "Retrieving email list ..."
            Dim infos As MailInfo() = client.GetMailInfos()
            lblStatus.Text = String.Format("Total {0} email(s)", infos.Length)

            ' Remove the local uidl that Is Not existed on the server,
            ' we only synchronize it with uidl of all emails in current mail folder
            uidlManager.SyncUIDL(server, infos)
            uidlManager.Update()

            For i As Integer = 0 To infos.Length - 1
                pgBar.Maximum = 100
                pgBar.Minimum = 0
                pgBar.Value = 0

                lblStatus.Text = String.Format("Checking {0}/{1}...", i + 1, infos.Length)
                Dim info As MailInfo = infos(i)

                If uidlManager.FindUIDL(server, info.UIDL) IsNot Nothing Then
                    ' This email has been downloaded before.
                    Continue For
                End If

                lblStatus.Text = String.Format("Retrieving {0}/{1}...", i + 1, infos.Length)
                Dim mail As Mail = client.GetMail(info)
                Dim fileName As String = _generateFileName(i + 1)
                Dim fullFileName As String = String.Format("{0}\{1}", localInbox, fileName)

                mail.SaveAs(fullFileName, True)
                _addNewMailToListView(mail, fullFileName)

                mail.Clear()
                lblStatus.Text = String.Format("Total {0} email(s)", lstMail.Items.Count)

                If chkLeaveCopy.Checked Then
                    ' Add the email uidl to uidl file to avoid we retrieve it next time. 
                    uidlManager.AddUIDL(server, info.UIDL, fileName)
                Else
                    lblStatus.Text = String.Format("Deleting {0}...", i + 1)
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
            lblStatus.Text = "Completed"
        Catch ep As Exception

            If isUidlLoaded Then
                ' Update the uidl list to local uidl file and then we can load it next time.
                uidlManager.Update()
            End If

            MessageBox.Show(ep.Message)
            lblStatus.Text = ep.Message
        End Try

        _enableSettingControls(True, False)
    End Sub

    Private Sub btnCancel_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCancel.Click
        btnCancel.Enabled = False
        _cancelTask = True
    End Sub

    Private Sub lstMail_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles lstMail.SelectedIndexChanged
        Dim items As ListView.SelectedIndexCollection = lstMail.SelectedIndices
        If (items.Count = 0) Then
            Exit Sub
        End If

        Dim oItem As ListViewItem = lstMail.Items(items(0))
        ShowMail(oItem.Tag)
    End Sub

#Region "Parse and Display Mails"
    Private Sub LoadMails()
        lstMail.Items.Clear()
        Dim localInbox As String = _createLocalInbox()
        Dim files() As String = Directory.GetFiles(localInbox, "*.eml")
        For i As Integer = 0 To files.Length - 1
            Dim fullname As String = files(i)
            'For evaluation usage, please use "TryIt" as the license code, otherwise the 
            '"invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
            '"trial version expired" exception will be thrown.
            Dim mail As New Mail("TryIt")

            'Load( file, true ) only load the email header to Mail object to save the CPU and memory
            ' the Mail object will load the whole email file later automatically if bodytext or attachment is required..
            mail.Load(fullname, True)

            _addNewMailToListView(mail, fullname)
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

    Private Function _formatAddresses(ByVal addresses As MailAddress(), ByVal prefix As String) As String
        If addresses.Length = 0 Then
            Return ""
        End If

        Dim buffer As StringBuilder = New StringBuilder()
        buffer.Append(String.Format("<b>{0}:</b> ", prefix))

        For i As Integer = 0 To addresses.Length - 1
            buffer.Append(_formatHtmlTag(addresses(i).ToString()))

            If i < addresses.Length - 1 Then
                buffer.Append(";")
            End If
        Next

        buffer.Append("<br>")
        Return buffer.ToString()
    End Function

    'we generate a html + attachment folder for every email, once the html is create,
    ' next time we don't need to parse the email again.
    Private Sub _GenerateHtmlForEmail(ByVal emlFile As String)
        Dim mail As Mail = New Mail("TryIt")
        mail.Load(emlFile, False)

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

    Private Sub ShowMail(ByVal fileName As String)

        Try
            Dim htmlFile As String = _getHtmlRenderFile(fileName)
            If Not (File.Exists(htmlFile)) Then
                'we haven't generate the html for this email, generate it now.
                _GenerateHtmlForEmail(fileName)
            End If
            webMail.Navigate(New System.Uri(htmlFile))
        Catch ep As Exception
            MessageBox.Show(ep.Message)
        End Try
    End Sub
#End Region

    Private Sub btnDel_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDel.Click
        Dim items As ListView.SelectedIndexCollection = lstMail.SelectedIndices
        If items.Count = 0 Then
            Exit Sub
        End If

        If MessageBox.Show("Do you want to delete all selected emails", _
                                 "", _
                                 MessageBoxButtons.YesNo, MessageBoxIcon.Question, MessageBoxDefaultButton.Button1) = DialogResult.No Then
            Exit Sub
        End If

        Dim selectedItems As New ArrayList()
        For i As Integer = 0 To items.Count - 1
            Dim index As Integer = items(i)
            Dim item As ListViewItem = lstMail.Items(index)
            selectedItems.Add(item)

            Try
                Dim fileName As String = item.Tag
                File.Delete(fileName)

                Dim htmlFile As String = _getHtmlRenderFile(fileName)
                Dim attachmentFolder As String = _getAttachmentFolder(fileName)

                If File.Exists(htmlFile) Then
                    File.Delete(htmlFile)
                End If

                If Directory.Exists(attachmentFolder) Then
                    Directory.Delete(attachmentFolder, True)
                End If
            Catch ep As Exception
                MessageBox.Show(ep.Message)
                Exit For
            End Try
        Next

        For i As Integer = 0 To selectedItems.Count - 1
            Dim item As ListViewItem = selectedItems(i)
            lstMail.Items.Remove(item)
        Next
        webMail.Navigate(New System.Uri("about:blank"))
    End Sub

#Region "EAGetMail Event Handler"
    Private Sub OnConnected(ByVal sender As Object, ByRef cancel As Boolean)
        lblStatus.Text = "Connected ..."
        cancel = _cancelTask
        Application.DoEvents()
    End Sub

    Private Sub OnQuit(ByVal sender As Object, ByRef cancel As Boolean)
        lblStatus.Text = "Quit ..."
        cancel = _cancelTask
        Application.DoEvents()
    End Sub

    Private Sub OnReceivingDataStream(ByVal sender As Object, ByVal info As MailInfo, ByVal received As Integer, ByVal total As Integer, ByRef cancel As Boolean)
        pgBar.Minimum = 0
        pgBar.Maximum = total
        pgBar.Value = received
        cancel = _cancelTask
        Application.DoEvents()
    End Sub

    Private Sub OnIdle(ByVal sender As Object, ByRef cancel As Boolean)
        cancel = _cancelTask
        Application.DoEvents()
    End Sub

    Private Sub OnAuthorized(ByVal sender As Object, ByRef cancel As Boolean)
        lblStatus.Text = "Authorized ..."
        cancel = _cancelTask
        Application.DoEvents()
    End Sub

    Private Sub OnSecuring(ByVal sender As Object, ByRef cancel As Boolean)
        lblStatus.Text = "Securing ..."
        cancel = _cancelTask
        Application.DoEvents()
    End Sub
#End Region

End Class
