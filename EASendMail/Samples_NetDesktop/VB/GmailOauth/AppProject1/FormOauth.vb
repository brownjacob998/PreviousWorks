Public Class FormOauth
    Public Property OauthWrapper As OauthDesktopWrapper = Nothing

    Public Sub New()
        MyBase.New()
        InitializeComponent()
        Me.DialogResult = DialogResult.Cancel
    End Sub

    Private Sub FormOauth_Load(ByVal sender As Object, ByVal e As EventArgs) Handles MyBase.Load
        OauthBrowser.Navigate(OauthWrapper.OauthProvider.GenerateFullAuthUri())
    End Sub

    Private Sub OauthBrowser_DocumentCompleted(ByVal sender As Object, ByVal e As WebBrowserDocumentCompletedEventArgs) Handles OauthBrowser.DocumentCompleted
        Dim elment As HtmlElement = OauthBrowser.Document.GetElementById("code")
        If elment Is Nothing Then
            Return
        End If

        Dim code As String = elment.GetAttribute("value")
        OauthWrapper.AuthorizationCode = code
        Me.DialogResult = DialogResult.OK
        Me.Close()
    End Sub
End Class