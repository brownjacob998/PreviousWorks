Imports EASendMail

Public Class Compose
    Private Sub btnSend_Click(sender As Object, e As EventArgs) Handles btnSend.Click
        Try
            Dim oMail As New SmtpMail("TryIt")
            ' Your gmail email address
            oMail.From = Login.username
            ' Set recipient email address, please change it to yours
            oMail.To = txtReceiver.Text

            ' Set email subject
            oMail.Subject = txtSubject.Text
            ' Set email body
            oMail.TextBody = txtEmail.Text

            'Gmail SMTP server address
            Dim oServer As New SmtpServer("smtp.gmail.com")

            ' Gmail user authentication should use your
            ' Gmail email address as the user name.
            ' For example: your email is "gmailid@gmail.com", then the user should be "gmailid@gmail.com"
            oServer.User = Login.username
            oServer.Password = Login.pw

            ' set 465 port
            oServer.Port = 465

            ' detect SSL/TLS automatically
            oServer.ConnectType = SmtpConnectType.ConnectSSLAuto

            Console.WriteLine("start to send email over SSL ...")

            Dim oSmtp As New SmtpClient()
            oSmtp.SendMail(oServer, oMail)

            Console.WriteLine("email was sent successfully!")
        Catch ep As Exception
            Console.WriteLine("failed to send email with the following error:")
            Console.WriteLine(ep.Message)
        End Try
        Me.Hide()
        Main.Show()
    End Sub

    Private Sub btnBack_Click(sender As Object, e As EventArgs) Handles btnBack.Click
        Me.Hide()
        Main.Show()
    End Sub
End Class