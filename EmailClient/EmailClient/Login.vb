Imports EAGetMail

Public Class Login
    Public username, pw As String
    Public oServer As MailServer
    Public oClient As MailClient
    Private Sub BtnLogin_Click(sender As Object, e As EventArgs) Handles btnLogin.Click
        pw = txtPassword.Text
        username = txtUserName.Text
        Try
            oServer = New MailServer("imap.gmail.com",
                            username,
                            pw,
                            ServerProtocol.Imap4)

            ' Enable SSL/TLS connection, most modern email server require SSL/TLS connection by default.
            oServer.SSLConnection = True
            ' Set 993 IMAP SSL Port
            oServer.Port = 993

            Console.WriteLine("Connecting server ...")

            oClient = New MailClient("TryIt")
            oClient.Connect(oServer)
            Me.Hide()
            Main.Show()
        Catch

        End Try
    End Sub
End Class
