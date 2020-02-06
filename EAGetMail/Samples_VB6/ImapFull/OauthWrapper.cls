VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "OauthWrapper"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False


'     To use Google OAUTH in your application, you must create a project in Google Developers Console.
'
'    - Create your project at https://console.developers.google.com/project.
'    - Select your project -> APIs & Services -> Dashboard -> Credentials;
'    - Credentials -> Create Credentials -> OAuth client ID -> Web application or Other (Desktop Application).
'      It depends on your application type.

'    - Input a name for your application, input your current ASP/ASP.NET URL at Authorized redirect URIs,
'      For example: http://localhost/gmailoauth/default.aspx. (Desktop Application doesn't require this step)
'      Click "Create", you will get your client id and client secret.
'
'    - Finally you can also set detail information for your project at Credentials -> OAuth consent screen.

'    - If you used https://mail.google.com scope, you should verify your application that is inroduced in cosent screen.
'      If you don't verify your application, your application is limited by some conditions.

'      You must apply for your client id and client secret, don't use the client id in the sample project, because it is limited now.
'      If you got "This app isn't verified" information, please click "advanced" -> Go to ... for test.

Option Explicit

Public AccessToken As String
Public RefreshToken As String
Public UserEmail As String
Public AuthorizationCode As String

' The following clientId and clientSecret is only for test purpose,
' You should apply for your clientId and clientSecret in production environment.
Const clientId = "1072602369179-aru4rj97ateiho9rt4pf5i8l1r01mc16.apps.googleusercontent.com"
Const clientSecret = "Lnw8r5FvfKFNS_CSEucbdIE-"
Const redirectUri = "urn:ietf:wg:oauth:2.0:oob"
Const scope = "email%20profile%20https://mail.google.com"
Const authUri = "https://accounts.google.com/o/oauth2/v2/auth"
Const tokenUri = "https://www.googleapis.com/oauth2/v4/token"

Private m_lastError As String
Private m_tokenExpiresInSeconds As Long
Private m_accessTokenTimeStamp As Date

Private Sub Class_Initialize()
    m_lastError = ""
    Reset
End Sub

Public Function GetFullAuthUri() As String
    Dim fullAuthUri As String
    fullAuthUri = authUri & "?scope=" & scope & "&redirect_uri=" & redirectUri & "&response_type=code&client_id=" & clientId & "&prompt=login"
    GetFullAuthUri = fullAuthUri
End Function

Private Sub Reset()
    RefreshToken = ""
    AccessToken = ""
    UserEmail = ""
    AuthorizationCode = ""
    m_tokenExpiresInSeconds = 600
    m_accessTokenTimeStamp = Now
End Sub

' This method is not used for Google
Public Function ParseAuthorizationCode(Uri As String) As Boolean
    
    ParseAuthorizationCode = True
    If AuthorizationCode <> "" Then
        Exit Function
    End If
    
    Dim pos As Integer
    pos = InStr(1, Uri, "?")
    If pos <= 0 Then
        Exit Function
    End If
    
    Uri = Mid(Uri, pos + 1)
    Dim parameters, i, uriParameter
    parameters = Split(Uri, "&")
    
    For i = LBound(parameters) To UBound(parameters)
        uriParameter = parameters(i)
        If InStr(1, uriParameter, "code=", vbTextCompare) = 1 Then
            AuthorizationCode = Mid(uriParameter, Len("code=") + 1)
            Exit Function
        End If
    Next
    
    ParseAuthorizationCode = False
    
End Function

Public Function RequestAccessTokenAndUserEmail() As Boolean

    RequestAccessTokenAndUserEmail = False

On Error GoTo ErrorHandle

    Dim httpRequest
    Set httpRequest = CreateObject("MSXML2.ServerXMLHTTP")
    
    Dim requestData As String
    requestData = "code=" & AuthorizationCode
    requestData = requestData & "&client_id=" & clientId
    requestData = requestData & "&client_secret=" & clientSecret
    requestData = requestData & "&redirect_uri=" & redirectUri
    requestData = requestData & "&grant_type=authorization_code"

    httpRequest.setOption 2, 13056
    httpRequest.Open "POST", tokenUri, True
    httpRequest.setRequestHeader "Content-Type", "application/x-www-form-urlencoded"
    httpRequest.Send requestData
    
    Do While httpRequest.ReadyState <> 4
        DoEvents
        httpRequest.waitForResponse (1)
    Loop
    
    Dim Status
    Status = httpRequest.Status
    
    If Status < 200 Or Status >= 300 Then
        m_lastError = "Failed to get access token from server."
        Reset
        Exit Function
    End If


    Dim result
    result = httpRequest.responseText
    
    Dim oauthParser As New EAGetMailObjLib.OAuthResponseParser
    oauthParser.Load result
    
    AccessToken = oauthParser.AccessToken
    RefreshToken = oauthParser.RefreshToken
    UserEmail = oauthParser.EmailInIdToken
    m_tokenExpiresInSeconds = oauthParser.TokenExpiresInSeconds
    
    If AccessToken = "" Then
        m_lastError = "Failed to parse access token from server response."
        Reset
        Exit Function
    End If
    
    If UserEmail = "" Then
         m_lastError = "Failed to parse user email from server response."
         Reset
        Exit Function
    End If
    
    RequestAccessTokenAndUserEmail = True
    m_accessTokenTimeStamp = Now
    Exit Function

ErrorHandle:
    If Err.Description <> "" Then
        m_lastError = Err.Description
    Else
        m_lastError = "Server timeout (access token)."
    End If
    Reset

End Function

Public Function AccessTokenIsExpired() As Boolean
    AccessTokenIsExpired = (DateDiff("s", m_accessTokenTimeStamp, Now) > (m_tokenExpiresInSeconds - 30))
End Function

Public Function RefreshAccessToken() As Boolean
    RefreshAccessToken = False
        
    If RefreshToken = "" Then
        m_lastError = "Refresh token is non-existed."
        Reset
        Exit Function
    End If
    
On Error GoTo ErrorHandle

    Dim httpRequest
    Set httpRequest = CreateObject("MSXML2.ServerXMLHTTP")
    
    Dim requestData As String
    requestData = "client_id=" & clientId
    requestData = requestData & "&client_secret=" & clientSecret
    requestData = requestData & "&refresh_token=" & RefreshToken
    requestData = requestData & "&grant_type=refresh_token"

    httpRequest.setOption 2, 13056
    httpRequest.Open "POST", tokenUri, True
    httpRequest.setRequestHeader "Content-Type", "application/x-www-form-urlencoded"
    httpRequest.Send requestData
    
    Do While httpRequest.ReadyState <> 4
        DoEvents
        httpRequest.waitForResponse (1)
    Loop
    
    Dim Status
    Status = httpRequest.Status
    
    If Status < 200 Or Status >= 300 Then
        m_lastError = "Failed to refresh access token from server."
        Reset
        Exit Function
    End If

    Dim result
    result = httpRequest.responseText
    
    Dim oauthParser As New EAGetMailObjLib.OAuthResponseParser
    oauthParser.Load result

    AccessToken = oauthParser.AccessToken
    If AccessToken = "" Then
        m_lastError = "Failed to parse access token from refresh response."
        Reset
        Exit Function
    End If
    
    If oauthParser.RefreshToken <> "" Then
        RefreshToken = oauthParser.RefreshToken
    End If
    
    If oauthParser.TokenExpiresInSeconds <> 0 Then
        m_tokenExpiresInSeconds = oauthParser.TokenExpiresInSeconds
    End If
    m_accessTokenTimeStamp = Now
    RefreshAccessToken = True
    Exit Function
    
ErrorHandle:
    m_lastError = "Server timeout (refresh token)."
    Reset

End Function

Public Sub ClearError()
    m_lastError = ""
End Sub

Public Sub Clear()
    m_lastError = ""
    Reset
End Sub

Public Function GetLastError() As String
    GetLastError = m_lastError
End Function


