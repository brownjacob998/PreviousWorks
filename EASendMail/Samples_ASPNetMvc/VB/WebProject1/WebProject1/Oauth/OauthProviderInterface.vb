Public Interface OauthProviderInterface
    Property ClientId As String
    Property ClientSecret As String
    Property UserEmail As String
    Property AccessToken As String
    Property RefreshToken As String
    Property RedirectUri As String
    Property Scope As String
    Property AuthUri As String
    Property TokenUri As String
    Property TokenExpiresInSeconds As Integer
    Property AccessTokenTimeStamp As DateTime
    Function GenerateFullAuthUri() As String
    Function GenerateAccessTokenRequestData(ByVal authorizationCode As String) As String
    Function GenerateRefreshTokenRequestData() As String
    Sub ClearToken()
End Interface
