Imports EAGetMail

Public Class FormSelectFolder
    Public OriginalFolderPath As String = ""

    Private Sub ButtonOK_Click(sender As Object, e As EventArgs) Handles ButtonOK.Click
        Dim node As TreeNode = TreeViewFolder.SelectedNode

        If node Is Nothing OrElse node.Parent Is Nothing Then
            MessageBox.Show("please select a folder.")
            Me.DialogResult = DialogResult.None
            Return
        End If

        Dim folder As Imap4Folder = TryCast(node.Tag, Imap4Folder)

        If String.Compare(folder.ServerPath, OriginalFolderPath, True) = 0 Then
            MessageBox.Show("please select a folder different with original folder.")
            Me.DialogResult = DialogResult.None
            Return
        End If

        Me.DialogResult = DialogResult.OK
    End Sub
End Class