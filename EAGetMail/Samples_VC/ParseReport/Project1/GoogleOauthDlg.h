#pragma once
#include "GoogleOauthWrapper.h"
#include "explorer_mail.h"

// GoogleOauthDlg dialog

class GoogleOauthDlg : public CDialogEx
{
	DECLARE_DYNAMIC(GoogleOauthDlg)

public:
	GoogleOauthDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~GoogleOauthDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_OAUTH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
	GoogleOauthWrapper *pOauth;

private:
	CExplorer_mail OauthBrowser;
	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorerOauth(LPDISPATCH pDisp, VARIANT* URL);
};
