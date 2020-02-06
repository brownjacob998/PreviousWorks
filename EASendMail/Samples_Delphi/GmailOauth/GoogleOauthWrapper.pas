
unit GoogleOauthWrapper;
//     To use Google OAUTH in your application, you must create a project in Google Developers Console.
//
//    - Create your project at https://console.developers.google.com/project.
//    - Select your project -> APIs & Services -> Dashboard -> Credentials;
//    - Credentials -> Create Credentials -> OAuth client ID -> Web application or Other (Desktop Application).
//     It depends on your application type.

//    - Input a name for your application, input your current ASP/ASP.NET URL at Authorized redirect URIs,
//     For example: http://localhost/gmailoauth/default.aspx. (Desktop Application doesn't require this step)
//     Click "Create", you will get your client id and client secret.
//
//    - Finally you can also set detail information for your project at Credentials -> OAuth consent screen.

//    - If you used https://mail.google.com scope, you should verify your application that is inroduced in cosent screen.
//      If you don't verify your application, your application is limited by some conditions.

//      You must apply for your client id and client secret, don't use the client id in the sample project, because it is limited now.
//      If you got "This app isn't verified" information, please click "advanced" -> Go to ... for test.

interface

uses  Windows, Forms, SysUtils, Variants, Classes, EASendMailObjLib_TLB, DateUtils, MSXML2_TLB;

type
  TGoogleOauthWrapper = class
    public
        AccessToken: string;
        RefreshToken: string;
        UserEmail: string;
        AuthorizationCode: string;

        constructor Create;

        function GetFullAuthUri(): string;
        function RequestAccessTokenAndUserEmail(): Boolean;
        function AccessTokenIsExpired(): Boolean;
        function RefreshAccessToken(): Boolean;
        function GetLastError(): string;
        procedure ClearError();
        procedure Clear();

    private
        m_lastError: string;
        m_tokenExpiresInSeconds: integer;
        m_accessTokenTimeStamp: TDateTime;    
        procedure Reset();

  end;
const
    // The following clientId and clientSecret is only for test purpose,
    // You should apply for your clientId and clientSecret in production environment.
    clientId = '1072602369179-aru4rj97ateiho9rt4pf5i8l1r01mc16.apps.googleusercontent.com';
    clientSecret = 'Lnw8r5FvfKFNS_CSEucbdIE-';
    redirectUri = 'urn:ietf:wg:oauth:2.0:oob';
    scope = 'email%20profile%20https://mail.google.com';
    authUri = 'https://accounts.google.com/o/oauth2/v2/auth';
    tokenUri = 'https://www.googleapis.com/oauth2/v4/token';

  implementation 

constructor TGoogleOauthWrapper.Create;
begin
    m_lastError := '';
    Reset();
end;

procedure TGoogleOauthWrapper.Reset();
begin
    RefreshToken := '';
    AccessToken := '';
    UserEmail := '';
    AuthorizationCode := '';
    m_tokenExpiresInSeconds := 600;
    m_accessTokenTimeStamp := Now();
end;

function TGoogleOauthWrapper.GetFullAuthUri(): string;
begin
    result := authUri + '?scope=' + scope + '&redirect_uri=' + redirectUri
    + '&response_type=code&client_id=' + clientId + '&prompt=login';
end;

function TGoogleOauthWrapper.AccessTokenIsExpired(): Boolean;
begin
    result := (IncSecond(m_accessTokenTimeStamp, m_tokenExpiresInSeconds - 30) < Now());
end;

function TGoogleOauthWrapper.GetLastError(): string;
begin
    result := m_lastError;
end;

procedure TGoogleOauthWrapper.ClearError();
begin
    m_lastError := '';
end;

procedure TGoogleOauthWrapper.Clear();
begin
    m_lastError := '';
    Reset();
end;

function TGoogleOauthWrapper.RequestAccessTokenAndUserEmail(): Boolean;
var
    httpRequest: TServerXMLHTTP;
    oauthParser: TOAuthResponseParser;
    requestData: OleVariant;
    status: integer;
    responseText: string;
begin
    result := false;

    httpRequest := TServerXMLHTTP.Create(Application);
    
    requestData := 'code=';
    requestData := requestData + AuthorizationCode;
    requestData := requestData + '&client_id=' + clientId;
    requestData := requestData + '&client_secret=' + clientSecret;
    requestData := requestData + '&redirect_uri=' + redirectUri;
    requestData := requestData + '&grant_type=authorization_code';

    httpRequest.setOption(2, 13056);
    httpRequest.open('POST', tokenUri, true);
    httpRequest.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    httpRequest.send(requestData);

    while( httpRequest.readyState <> 4 ) do
    begin
      try
        httpRequest.waitForResponse(1);
        Application.ProcessMessages();
      except
        m_lastError := 'Server response timeout (access token).';
        Reset();
        exit;
      end;
    end;

    status := httpRequest.status;
    if (status < 200) or (status >= 300) then
    begin
        m_lastError := 'Failed to get access token from server.';
        Reset();
      exit;
    end;
    
    responseText := httpRequest.responseText;
    oauthParser := TOAuthResponseParser.Create(Application);
    oauthParser.Load(responseText);

    AccessToken := oauthParser.AccessToken;
    RefreshToken := oauthParser.RefreshToken;
    UserEmail := oauthParser.EmailInIdToken;
    m_tokenExpiresInSeconds := oauthParser.TokenExpiresInSeconds;
    
    if AccessToken = '' then
    begin
        m_lastError := 'Failed to parse access token from server response.';
        Reset();
        exit;
    end;
    
    if UserEmail = '' then
    begin
        m_lastError := 'Failed to parse user email from server response.';
        Reset();
        exit;
    end;

    m_accessTokenTimeStamp := Now();    
    result := True
end;

function TGoogleOauthWrapper.RefreshAccessToken(): Boolean;
var
    httpRequest: TServerXMLHTTP;
    oauthParser: TOAuthResponseParser;
    requestData: OleVariant;
    status: integer;
    responseText: string;
begin
    result := false;
    
    if RefreshToken = '' then
    begin
        m_lastError := 'Refresh token is non-existed.';
        Reset();
        exit;
    end;

    httpRequest := TServerXMLHTTP.Create(Application);
    
    requestData := 'client_id=';
    requestData := requestData + clientId;
    requestData := requestData + '&client_secret=' + clientSecret;
    requestData := requestData + '&refresh_token=' + RefreshToken;
    requestData := requestData + '&grant_type=refresh_token';

    httpRequest.setOption(2, 13056);
    httpRequest.open('POST', tokenUri, true);
    httpRequest.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    httpRequest.send(requestData);

    while( httpRequest.readyState <> 4 ) do
    begin
      try
        httpRequest.waitForResponse(1);
        Application.ProcessMessages();
      except
        m_lastError := 'Server response timeout (refresh token).';
        Reset();
        exit;
      end;
    end;

    status := httpRequest.status;
    if (status < 200) or (status >= 300) then
    begin
        m_lastError := 'Failed to refresh access token from server.';
        Reset();
      exit;
    end;
    
    responseText := httpRequest.responseText;

    oauthParser := TOAuthResponseParser.Create(Application);
    oauthParser.Load(responseText);
    
    AccessToken := oauthParser.AccessToken;
    if AccessToken = '' then
    begin
        m_lastError := 'Failed to parse access token from refresh response.';
        Reset();
        exit;
    end;
    
    if oauthParser.RefreshToken <> '' then
        RefreshToken := oauthParser.RefreshToken;
    
    if oauthParser.TokenExpiresInSeconds <> 0 then
        m_tokenExpiresInSeconds := oauthParser.TokenExpiresInSeconds;

    m_accessTokenTimeStamp := Now();
    result := true;
end;


end.