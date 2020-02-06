// GoogleOauthDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Project1.h"
#include "GoogleOauthDlg.h"
#include "afxdialogex.h"


// GoogleOauthDlg dialog

IMPLEMENT_DYNAMIC(GoogleOauthDlg, CDialogEx)

GoogleOauthDlg::GoogleOauthDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(GoogleOauthDlg::IDD, pParent)
{

}

GoogleOauthDlg::~GoogleOauthDlg()
{
}

void GoogleOauthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER_OAUTH, OauthBrowser);
}


BEGIN_MESSAGE_MAP(GoogleOauthDlg, CDialogEx)
END_MESSAGE_MAP()


// GoogleOauthDlg message handlers

BOOL GoogleOauthDlg::OnInitDialog()
{
	_ASSERT(pOauth != NULL);

	CDialog::OnInitDialog();

	::CoInitialize(NULL);

	OauthBrowser.put_Silent(TRUE);
	CString  authURI = pOauth->GetFullAuthUri();
	OauthBrowser.Navigate(authURI, NULL, NULL, NULL, NULL);
	return TRUE;
}

BEGIN_EVENTSINK_MAP(GoogleOauthDlg, CDialog)
	ON_EVENT(GoogleOauthDlg, IDC_EXPLORER_OAUTH, 259, GoogleOauthDlg::DocumentCompleteExplorerOauth, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

void GoogleOauthDlg::DocumentCompleteExplorerOauth(LPDISPATCH pDisp, VARIANT* URL)
{

	CComPtr<IHTMLDocument2> spDoc;
	spDoc = (IHTMLDocument2*)OauthBrowser.get_Document();

	CComPtr<IHTMLDocument3> spHtml;
	spDoc->QueryInterface(IID_IHTMLDocument3, (void**)&spHtml);

	CComPtr<IHTMLElement> spElement = NULL;
	spHtml->getElementById(L"code", &spElement);
	if (spElement == NULL)
	{
		return;
	}
	CComPtr<IHTMLInputElement> spInput;
	spElement->QueryInterface(IID_IHTMLInputElement, (void**)&spInput);
	if (spInput == NULL)
	{
		return;
	}

	BSTR bstr = NULL;
	spInput->get_value(&bstr);
	pOauth->AuthorizationCode = bstr;
	::SysFreeString(bstr);

	CDialog::OnOK();
}