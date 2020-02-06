using System;
using System.Collections.Generic;
using System.Text;

namespace EASendMail.Oauth
{
    public interface OauthProviderInterface
    {
        string ClientId { get; set; }
        string ClientSecret { get; set; }
        string UserEmail { get; set; }
        string AccessToken { get; set; }
        string RefreshToken { get; set; }
        string RedirectUri { get; set; }
        string Scope { get; set; }
        string AuthUri { get; set; }
        string TokenUri { get; set; }

        int TokenExpiresInSeconds { get; set; }
        DateTime AccessTokenTimeStamp { get; set; }

        string GenerateFullAuthUri();
        string GenerateAccessTokenRequestData(string authorizationCode);
        string GenerateRefreshTokenRequestData();

        void ClearToken();
    }
}
