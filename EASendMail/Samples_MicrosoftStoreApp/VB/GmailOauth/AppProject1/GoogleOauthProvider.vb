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
'      You must apply for your client id and client secret, don't use the client id in the sample project, because it is limited now.
'      If you got "This app isn't verified" information, please click "advanced" -> Go to ... for test.

Imports AppProject1

Public Class GoogleOauthProvider
    Implements OauthProviderInterface

    Public Shared Function Create(ByVal clientId As String, ByVal clientSecret As String) As OauthProviderInterface
        Return Create(clientId, clientSecret, String.Empty, String.Empty)
    End Function

    Public Shared Function Create(ByVal clientId As String, ByVal clientSecret As String, ByVal scope As String, ByVal redirectUri As String) As OauthProviderInterface
        Dim provider As GoogleOauthProvider = New GoogleOauthProvider()
        provider.ClientId = clientId
        provider.ClientSecret = clientSecret

        If Not String.IsNullOrEmpty(scope) Then
            provider.Scope = scope
        End If

        If Not String.IsNullOrEmpty(redirectUri) Then
            provider.RedirectUri = redirectUri
        End If

        Return provider
    End Function

    Private Sub New()
    End Sub

    Public Property ClientId As String = String.Empty Implements OauthProviderInterface.ClientId
    Public Property ClientSecret As String = String.Empty Implements OauthProviderInterface.ClientSecret

    Public Property UserEmail As String = String.Empty Implements OauthProviderInterface.UserEmail
    Public Property AccessToken As String = String.Empty Implements OauthProviderInterface.AccessToken
    Public Property RefreshToken As String = String.Empty Implements OauthProviderInterface.RefreshToken

    Const LocalRedirectUri As String = "urn:ietf:wg:oauth:2.0:oob"
    Public Property RedirectUri As String = "urn:ietf:wg:oauth:2.0:oob" Implements OauthProviderInterface.RedirectUri
    Public Property Scope As String = "email%20profile%20https://mail.google.com" Implements OauthProviderInterface.Scope
    Public Property AuthUri As String = "https://accounts.google.com/o/oauth2/v2/auth" Implements OauthProviderInterface.AuthUri
    Public Property TokenUri As String = "https://www.googleapis.com/oauth2/v4/token" Implements OauthProviderInterface.TokenUri
    Public Property TokenExpiresInSeconds As Integer = 600 Implements OauthProviderInterface.TokenExpiresInSeconds
    Public Property AccessTokenTimeStamp As Date = DateTime.Now Implements OauthProviderInterface.AccessTokenTimeStamp

    Public Sub ClearToken() Implements OauthProviderInterface.ClearToken
        AccessToken = ""
        RefreshToken = ""
        UserEmail = ""
        TokenExpiresInSeconds = 600
    End Sub

    Public Function GenerateFullAuthUri() As String Implements OauthProviderInterface.GenerateFullAuthUri
        If String.Compare(RedirectUri, LocalRedirectUri, True) = 0 Then
            Return String.Format("{0}?scope={1}&redirect_uri={2}&response_type=code&client_id={3}&prompt=login", AuthUri, Scope, RedirectUri, ClientId)
        Else
            Return String.Format("{0}?scope={1}&redirect_uri={2}&response_type=code&client_id={3}&access_type=offline&prompt=consent", AuthUri, Scope, RedirectUri, ClientId)
        End If
    End Function

    Public Function GenerateAccessTokenRequestData(authorizationCode As String) As String Implements OauthProviderInterface.GenerateAccessTokenRequestData
        Return String.Format("code={0}&client_id={1}&client_secret={2}&redirect_uri={3}&grant_type=authorization_code", authorizationCode, ClientId, ClientSecret, RedirectUri)
    End Function

    Public Function GenerateRefreshTokenRequestData() As String Implements OauthProviderInterface.GenerateRefreshTokenRequestData
        Return String.Format("client_id={0}&&client_secret={1}&refresh_token={2}&grant_type=refresh_token", ClientId, ClientSecret, RefreshToken)
    End Function
End Class
