Public Class FormAddFolder
    Private Sub ButtonOK_Click(sender As Object, e As EventArgs) Handles ButtonOK.Click
        textFolderName.Text = textFolderName.Text.Trim()

        If textFolderName.Text.Length = 0 Then
            MessageBox.Show("Please input folder name!")
            Me.DialogResult = DialogResult.None
        Else
            Me.DialogResult = DialogResult.OK
        End If
    End Sub
End Class