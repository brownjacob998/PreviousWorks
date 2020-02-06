Imports System.Globalization
Imports System.Text
Imports System.IO
Imports EAGetMail

Public Class Main
    Dim oServer As MailServer = Login.oServer
    Dim oClient As MailClient = Login.oClient
    Dim lstindex As Integer = -1
    Public infos As MailInfo()
    Public content, subject, sender As String
    Function _generateFileName(ByVal sequence As Integer) As String
        Dim currentDateTime As DateTime = DateTime.Now
        Return String.Format("{0}-{1:000}-{2:000}.eml",
                            currentDateTime.ToString("yyyyMMddHHmmss", New CultureInfo("en-US")),
                            currentDateTime.Millisecond,
                            sequence)
    End Function
    Private Sub Main_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        btndebug.Hide()
        btnRefresh.Hide()
        Try
            ' Create a folder named "inbox" under current directory
            ' to save the email retrieved.
            Dim localInbox As String = String.Format("{0}\inbox", Directory.GetCurrentDirectory())

            ' If the folder is not existed, create it.
            If Not Directory.Exists(localInbox) Then
                Directory.CreateDirectory(localInbox)
            End If

            'infos = oClient.GetMailInfosParam.Reset()
            'infos = oClient.GetMailInfosParam.GetMailInfosOptions = GetMailInfosOptionType.NewOnly
            infos = oClient.GetMailInfos()
            Console.WriteLine("Total {0} email(s)", infos.Length)

            For i As Integer = 0 To infos.Length - 1
                Dim info As MailInfo = infos(i)

                Console.WriteLine("Index: {0}; Size: {1}; UIDL: {2}",
                        info.Index, info.Size, info.UIDL)

                ' Retrieve email from IMAP server
                Dim oMail As Mail = oClient.GetMail(info)
                lstEmail.Items.Add(oMail.From.ToString + " " + oMail.Subject)

                ' Generate an unqiue email file name based on date time.
                Dim fileName As String = _generateFileName(i + 1)
                Dim fullPath As String = String.Format("{0}\{1}", localInbox, fileName)

                ' Save email to local disk
                oMail.SaveAs(fullPath, True)

                ' Mark email as deleted from IMAP server.
                ' oClient.Delete(info)



            Next

            ' Quit and expunge emails marked as deleted from IMAP server.
            Console.WriteLine("Completed!")

        Catch ep As Exception
            Console.WriteLine(ep.Message)
        End Try
    End Sub

    Private Sub BtnRetrieve_Click(sender As Object, e As EventArgs) Handles btnRetrieve.Click
        Dim oMail As Mail = oClient.GetMail(infos(lstindex))
        ViewEmail.txtFrom.Text = oMail.ReplyTo.ToString
        ViewEmail.txtSubject.Text = oMail.Subject
        ViewEmail.txtContent.Text = oMail.TextBody
        Me.Hide()
        ViewEmail.Show()
    End Sub
    Private Sub lstEmail_SelectedIndexChanged(sender As Object, e As EventArgs) Handles lstEmail.SelectedIndexChanged
        lstindex = lstEmail.SelectedIndex
    End Sub

    Private Sub BtnDelete_Click(sender As Object, e As EventArgs) Handles btnDelete.Click
        If lstindex <> -1 Then
            lstEmail.Items.RemoveAt(lstindex)
            Dim dinfo As MailInfo = infos(lstindex + 1)
            oClient.Delete(dinfo)
        End If
    End Sub

    Private Sub btnSend_Click(sender As Object, e As EventArgs) Handles btnSend.Click
        Me.Hide()
        Compose.Show()
    End Sub

    Private Sub btnRefresh_Click(sender As Object, e As EventArgs) Handles btnRefresh.Click
        lstEmail.Items.Clear()
        infos = oClient.GetMailInfos()
        For x As Integer = 0 To infos.Length - 1
            Dim info As MailInfo = infos(x)

            Console.WriteLine("Index: {0}; Size: {1}; UIDL: {2}",
                    info.Index, info.Size, info.UIDL)

            ' Retrieve email from IMAP server
            Dim oMail As Mail = oClient.GetMail(info)
            lstEmail.Items.Add(oMail.From.ToString + " " + oMail.Subject)

            ' Save email to local disk
        Next

    End Sub

    Private Sub btndebug_Click(sender As Object, e As EventArgs) Handles btndebug.Click
        lstEmail.Items.Add(lstindex.ToString())
    End Sub

    Private Sub btnClose_Click(sender As Object, e As EventArgs) Handles btnClose.Click
        oClient.Quit()
        Me.Close()
        End
    End Sub
End Class