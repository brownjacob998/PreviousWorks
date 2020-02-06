#pragma once
class GoogleOauthWrapper
{
public:
	GoogleOauthWrapper();
	~GoogleOauthWrapper();

public:
	CString AccessToken;
	CString RefreshToken;
	CString UserEmail;
	CString AuthorizationCode;

public:
	CString GetFullAuthUri();
	BOOL RequestAccessTokenAndUserEmail();
	BOOL AccessTokenIsExpired();
	BOOL RefreshAccessToken();
	void ClearError();
	void Clear();
	CString GetLastError();

private:
	void Reset();
	void DoEvents();
	BOOL PostHttp(CString &requestData, CString &requestUri, CString &result);

private:
	static const TCHAR* clientId;
	static const TCHAR* clientSecret;
	static const TCHAR* redirectUri;
	static const TCHAR* scope;
	static const TCHAR* authUri;
	static const TCHAR* tokenUri;

private:
	CString m_lastError;
	int m_tokenExpiresInSeconds;
	time_t m_accessTokenTimeStamp;
};

