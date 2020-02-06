#include "stdafx.h"
#include "GoogleOauthWrapper.h"


//     To use Google OAUTH in your application, you must create a project in Google Developers Console.
//
//    - Create your project at https://console.developers.google.com/project.
//    - Select your project -> APIs & Services -> Dashboard -> Credentials;
//    - Credentials -> Create Credentials -> OAuth client ID -> Web application or Other (Desktop Application).
//      It depends on your application type.

//    - Input a name for your application, input your current ASP/ASP.NET URL at Authorized redirect URIs,
//      For example: http://localhost/gmailoauth/default.aspx. (Desktop Application doesn't require this step)
//      Click "Create", you will get your client id and client secret.
//
//    - Finally you can also set detail information for your project at Credentials -> OAuth consent screen.

//    - If you used https://mail.google.com scope, you should verify your application that is inroduced in cosent screen.
//      If you don't verify your application, your application is limited by some conditions.

// 		You must apply for your client id and client secret, don't use the client id in the sample project, because it is limited now.
//      If you got "This app isn't verified" information, please click "advanced" -> Go to ... for test.

// The following clientId and clientSecret is only for test purpose,
// You should apply for your clientId and clientSecret in production environment.

const TCHAR* GoogleOauthWrapper::clientId = _T("1072602369179-aru4rj97ateiho9rt4pf5i8l1r01mc16.apps.googleusercontent.com");
const TCHAR* GoogleOauthWrapper::clientSecret = _T("Lnw8r5FvfKFNS_CSEucbdIE-");
const TCHAR* GoogleOauthWrapper::redirectUri = _T("urn:ietf:wg:oauth:2.0:oob");
const TCHAR* GoogleOauthWrapper::scope = _T("email%20profile%20https://mail.google.com");
const TCHAR* GoogleOauthWrapper::authUri = _T("https://accounts.google.com/o/oauth2/v2/auth");
const TCHAR* GoogleOauthWrapper::tokenUri = _T("https://www.googleapis.com/oauth2/v4/token");

GoogleOauthWrapper::GoogleOauthWrapper()
{
	Clear();
}

GoogleOauthWrapper::~GoogleOauthWrapper()
{
}

CString
GoogleOauthWrapper::GetFullAuthUri()
{
	CString uri;
	uri.Format(_T("%s?scope=%s&redirect_uri=%s&response_type=code&client_id=%s&prompt=login"),
		authUri, scope, redirectUri, clientId);
	return uri;
}

void
GoogleOauthWrapper::Reset()
{
	RefreshToken = _T("");
	AccessToken = _T("");
	UserEmail = _T("");
	AuthorizationCode = _T("");

	m_tokenExpiresInSeconds = 600;
	::time(&m_accessTokenTimeStamp);
}

void
GoogleOauthWrapper::ClearError()
{
	m_lastError = _T("");
}

void
GoogleOauthWrapper::Clear()
{
	m_lastError = _T("");
	Reset();
}

CString
GoogleOauthWrapper::GetLastError()
{
	return m_lastError;
}

BOOL
GoogleOauthWrapper::AccessTokenIsExpired()
{
	time_t now;
	::time(&now);

	return (difftime(now, m_accessTokenTimeStamp) > (m_tokenExpiresInSeconds - 30));
}

BOOL 
GoogleOauthWrapper::RequestAccessTokenAndUserEmail()
{
	CString data = _T("code=");
	data += AuthorizationCode;
	data += _T("&client_id=");
	data += clientId;
	data += _T("&client_secret=");
	data += clientSecret;
	data += _T("&redirect_uri=");
	data += redirectUri;
	data += _T("&grant_type=authorization_code");

	CString myTokenUri = tokenUri;
	CString responseText;
	if (!PostHttp(data, myTokenUri, responseText))
	{
		return FALSE;
	}

	IOAuthResponseParserPtr oauthParser = NULL;
	oauthParser.CreateInstance(__uuidof(EAGetMailObjLib::OAuthResponseParser));
	if (oauthParser == NULL)
	{
		m_lastError = _T("Failed to create OAuthResponseParser Object, please make sure you install latest EASendMail on your machine.\r\n");
		return FALSE;
	}
	
	oauthParser->Load((const TCHAR*)responseText);

	AccessToken = (const TCHAR*)oauthParser->AccessToken;
	RefreshToken = (const TCHAR*)oauthParser->RefreshToken;
	UserEmail = (const TCHAR*)oauthParser->EmailInIdToken;
	m_tokenExpiresInSeconds = oauthParser->TokenExpiresInSeconds;

	if (AccessToken.GetLength() == 0)
	{
		m_lastError = _T("Failed to parse access token from server response.");
		Reset();
		return FALSE;
	}
	
	if (UserEmail.GetLength() == 0)
	{
		m_lastError = _T("Failed to parse user email from server response.");
		Reset();
		return FALSE;
	}
		
	::time(&m_accessTokenTimeStamp);
	return TRUE;
}

BOOL 
GoogleOauthWrapper::RefreshAccessToken()
{
	CString data = _T("client_id=");
	data += clientId;
	data += "&client_secret=";
	data += clientSecret;
	data += "&refresh_token=";
	data += RefreshToken;
	data += "&grant_type=refresh_token";

	CString myTokenUri = tokenUri;
	CString responseText;
	if (!PostHttp(data, myTokenUri, responseText))
	{
		return FALSE;
	}

	IOAuthResponseParserPtr oauthParser = NULL;
	oauthParser.CreateInstance(__uuidof(EAGetMailObjLib::OAuthResponseParser));
	if (oauthParser == NULL)
	{
		m_lastError = _T("Failed to create OAuthResponseParser Object, please make sure you install latest EASendMail on your machine.\r\n");
		return FALSE;
	}
	
	oauthParser->Load((const TCHAR*)responseText);

	AccessToken = (const TCHAR*)oauthParser->AccessToken;
	if (AccessToken.GetLength() == 0)
	{
		m_lastError = _T("Failed to parse access token from server refresh response.");
		Reset();
		return FALSE;
	}

	
	CString tempValue = (const TCHAR*)oauthParser->RefreshToken;
	if (tempValue.GetLength() > 0)
	{
		RefreshToken = tempValue;
	}

	if (oauthParser->TokenExpiresInSeconds > 0)
	{
		m_tokenExpiresInSeconds = oauthParser->TokenExpiresInSeconds;
	}

	::time(&m_accessTokenTimeStamp);
	return TRUE;
}

BOOL
GoogleOauthWrapper::PostHttp(CString &requestData, CString &requestUri, CString &result)
{
	try
	{
		IServerXMLHTTPRequestPtr httpRequest = NULL;
		httpRequest.CreateInstance(__uuidof(MSXML2::ServerXMLHTTP));
		if (httpRequest == NULL)
		{
			m_lastError = _T("Failed to create XML HTTP Object, please make sure you install MSXML 3.0 on your machine.\r\n");
			return FALSE;
		}

		LPSAFEARRAY	psaHunk = NULL;
		LONG k;

		BYTE cdata = requestData.GetLength();
		psaHunk = ::SafeArrayCreateVectorEx(VT_UI1, 0, cdata, NULL);

		for (k = 0; k < (int)cdata; k++)
		{
			BYTE ch = (BYTE)requestData[k];
			::SafeArrayPutElement(psaHunk, &k, &ch);
		}

		_variant_t requestBuffer;
		requestBuffer.vt = (VT_ARRAY | VT_UI1);
		requestBuffer.parray = psaHunk;

		_variant_t async(true);
		_bstr_t uri((const TCHAR*)requestUri);

		httpRequest->setOption((MSXML2::SERVERXMLHTTP_OPTION)2, 13056);
		httpRequest->open(L"POST", uri, async, vtMissing, vtMissing);
		httpRequest->setRequestHeader(L"Content-Type", L"application/x-www-form-urlencoded");
		httpRequest->send(requestBuffer);

		while (httpRequest->readyState != 4) {
			httpRequest->waitForResponse(1);
			DoEvents();
		}

		long status = 0;
		httpRequest->get_status(&status);

		if (status < 200 || status >= 300)
		{
			m_lastError = _T("Failed to get access token from Google server\r\n");
			return FALSE;
		}

		BSTR bstrResult = NULL;
		result = (const TCHAR*)httpRequest->responseText;
		return TRUE;
	}
	catch (_com_error &ep)
	{
		_bstr_t bstr = ep.Description();
		m_lastError = _T("Failed to get access token from Google server\r\n");
		m_lastError += (const TCHAR*)ep.Description();
		return FALSE;
	}
}

void 
GoogleOauthWrapper::DoEvents()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}