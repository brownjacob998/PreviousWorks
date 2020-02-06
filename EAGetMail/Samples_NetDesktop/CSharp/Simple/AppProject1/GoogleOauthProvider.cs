using System;
using System.Collections.Generic;
using System.Text;

namespace EAGetMail.Oauth
{
    /*
     To use Google OAUTH in your application, you must create a project in Google Developers Console.

    - Create your project at https://console.developers.google.com/project.
    - Select your project -> APIs & Services -> Dashboard -> Credentials;
    - Credentials -> Create Credentials -> OAuth client ID -> Web application or Other (Desktop Application). 
      It depends on your application type.

    - Input a name for your application, input your current ASP/ASP.NET URL at Authorized redirect URIs, 
      for example: http://localhost/gmailoauth/default.aspx. (Desktop Application doesn't require this step)
      Click "Create", you will get your client id and client secret.

    - Finally you can also set detail information for your project at Credentials -> OAuth consent screen.
    
    - If you used https://mail.google.com scope, you should verify your application that is inroduced in cosent screen.
      If you don't verify your application, your application is limited by some conditions.

      
      You must apply for your client id and client secret, don't use the client id in the sample project, because it is limited now.
      If you got "This app isn't verified" information, please click "advanced" -> Go to ... for test.
    */

    public class GoogleOauthProvider : OauthProviderInterface
    {
        //  readonly string _clientId = "1072602369179-aru4rj97ateiho9rt4pf5i8l1r01mc16.apps.googleusercontent.com";
        //  readonly string _clientSecret = "Lnw8r5FvfKFNS_CSEucbdIE-";
        string _clientId = string.Empty;
        public string ClientId
        {
            get { return _clientId; }
            set { _clientId = value; }
        }

        string _clientSecret = string.Empty;
        public string ClientSecret
        {
            get { return _clientSecret; }
            set { _clientSecret = value; }
        }

        const string LocalRedirectUri = "urn:ietf:wg:oauth:2.0:oob";
        string _redirectUri = LocalRedirectUri;
        public string RedirectUri
        {
            get { return _redirectUri; }
            set { _redirectUri = value; }
        }

        string _scope = "email%20profile%20https://mail.google.com";
        public string Scope
        {
            get { return _scope; }
            set { _scope = value; }
        }

        string _authUri = "https://accounts.google.com/o/oauth2/v2/auth";
        public string AuthUri
        {
            get { return _authUri; }
            set { _authUri = value; }
        }

        string _tokenUri = "https://www.googleapis.com/oauth2/v4/token";
        public string TokenUri
        {
            get { return _tokenUri; }
            set { _tokenUri = value; }
        }

        public static OauthProviderInterface Create(string clientId, string clientSecret)
        {
            return Create(clientId, clientSecret, string.Empty, string.Empty);
        }

        public static OauthProviderInterface Create(string clientId, string clientSecret, string scope, string redirectUri)
        {
            GoogleOauthProvider provider = new GoogleOauthProvider();

            provider.ClientId = clientId;
            provider.ClientSecret = clientSecret;

            if (!string.IsNullOrEmpty(scope))
            {
                provider.Scope = scope;
            }

            if (!string.IsNullOrEmpty(redirectUri))
            {
                provider.RedirectUri = redirectUri;
            }

            return provider;
        }

        private GoogleOauthProvider()
        { }

        string _accessToken = string.Empty;
        public string AccessToken
        {
            get { return _accessToken; }
            set { _accessToken = value; }
        }

        string _userEmail = string.Empty;
        public string UserEmail
        {
            get { return _userEmail; }
            set { _userEmail = value; }
        }

        string _refreshToken = string.Empty;
        public string RefreshToken
        {
            get { return _refreshToken; }
            set { _refreshToken = value; }
        }

        int _tokenExpiresInSeconds = 600;
        public int TokenExpiresInSeconds
        {
            get { return _tokenExpiresInSeconds; }
            set { _tokenExpiresInSeconds = value; }
        }

        DateTime _accessTokenTimeStamp = DateTime.Now;
        public DateTime AccessTokenTimeStamp
        {
            get { return _accessTokenTimeStamp; }
            set { _accessTokenTimeStamp = value; }
        }

        public void ClearToken()
        {
            _accessToken = "";
            _refreshToken = "";
            _userEmail = "";
            _tokenExpiresInSeconds = 600;
        }

        public string GenerateFullAuthUri()
        {
            if (string.Compare(RedirectUri, LocalRedirectUri, true) == 0)
            {
                return string.Format("{0}?scope={1}&redirect_uri={2}&response_type=code&client_id={3}&prompt=login",
                    AuthUri, Scope, RedirectUri, ClientId);
            }
            else
            {
                return string.Format("{0}?scope={1}&redirect_uri={2}&response_type=code&client_id={3}&}&access_type=offline&prompt=consent",
                    AuthUri, Scope, RedirectUri, ClientId);
            }
        }

        public string GenerateAccessTokenRequestData(string authorizationCode)
        {
            return string.Format(
              "code={0}&client_id={1}&client_secret={2}&redirect_uri={3}&grant_type=authorization_code",
              authorizationCode, ClientId, ClientSecret, RedirectUri);
        }

        public string GenerateRefreshTokenRequestData()
        {
            return string.Format(
                "client_id={0}&&client_secret={1}&refresh_token={2}&&grant_type=refresh_token",
                ClientId, ClientSecret, RefreshToken);
        }
    }
}
