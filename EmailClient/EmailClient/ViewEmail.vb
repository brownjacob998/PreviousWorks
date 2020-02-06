Public Class ViewEmail
    Private Sub ViewEmail_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        txtFrom.Text = Main.sender
        txtSubject.Text = Main.subject
        txtContent.Text = Main.content
    End Sub

    Private Sub btnReply_Click(sender As Object, e As EventArgs) Handles btnReply.Click
        Compose.txtReceiver.Text = txtFrom.Text
        Compose.txtSubject.Text = "Re: " + txtSubject.Text
        Me.Hide()
        Compose.Show()
    End Sub

    Private Sub btnBack_Click(sender As Object, e As EventArgs) Handles btnBack.Click
        Me.Hide()
        Main.Show()
    End Sub
End Class