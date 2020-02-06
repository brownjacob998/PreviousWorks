
// Project1Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "explorer_mail.h"
#include "GoogleOauthDlg.h"

#include <atlcom.h>

static _ATL_FUNC_INFO OnIdle = { CC_STDCALL, VT_EMPTY, 2, { VT_DISPATCH, VT_BOOL | VT_BYREF } };
static _ATL_FUNC_INFO OnConnected = { CC_STDCALL, VT_EMPTY, 2, { VT_DISPATCH, VT_BOOL | VT_BYREF } };
static _ATL_FUNC_INFO OnQuit = { CC_STDCALL, VT_EMPTY, 2, { VT_DISPATCH, VT_BOOL | VT_BYREF } };
static _ATL_FUNC_INFO OnSendCommand = { CC_STDCALL, VT_EMPTY, 4, { VT_DISPATCH, VT_VARIANT, VT_BOOL, VT_BOOL | VT_BYREF } };
static _ATL_FUNC_INFO OnReceiveResponse = { CC_STDCALL, VT_EMPTY, 4, { VT_DISPATCH, VT_VARIANT, VT_BOOL, VT_BOOL | VT_BYREF } };
static _ATL_FUNC_INFO OnSecuring = { CC_STDCALL, VT_EMPTY, 2, { VT_DISPATCH, VT_BOOL | VT_BYREF } };
static _ATL_FUNC_INFO OnAuthorized = { CC_STDCALL, VT_EMPTY, 2, { VT_DISPATCH, VT_BOOL | VT_BYREF } };
static _ATL_FUNC_INFO OnSendingDataStream = { CC_STDCALL, VT_EMPTY, 4, { VT_DISPATCH, VT_I4, VT_I4, VT_BOOL | VT_BYREF } };
static _ATL_FUNC_INFO OnReceivingDataStream = { CC_STDCALL, VT_EMPTY, 5, { VT_DISPATCH, VT_DISPATCH, VT_I4, VT_I4, VT_BOOL | VT_BYREF } };

// CProject1Dlg dialog
class CProject1Dlg : public CDialogEx,
	public IDispEventSimpleImpl<IDD_PROJECT1_DIALOG,
	CProject1Dlg, &__uuidof(_IMailClientEvents)>
{
// Construction
public:
	CProject1Dlg(CWnd* pParent = NULL);	// standard constructor

	BEGIN_SINK_MAP(CProject1Dlg)
		SINK_ENTRY_INFO(IDD_PROJECT1_DIALOG, __uuidof(_IMailClientEvents), 1, OnIdleHandler, &OnIdle)
		SINK_ENTRY_INFO(IDD_PROJECT1_DIALOG, __uuidof(_IMailClientEvents), 2, OnConnectedHandler, &OnConnected)
		SINK_ENTRY_INFO(IDD_PROJECT1_DIALOG, __uuidof(_IMailClientEvents), 3, OnQuitHandler, &OnQuit)
		SINK_ENTRY_INFO(IDD_PROJECT1_DIALOG, __uuidof(_IMailClientEvents), 4, OnSendCommandHandler, &OnSendCommand)
		SINK_ENTRY_INFO(IDD_PROJECT1_DIALOG, __uuidof(_IMailClientEvents), 5, OnReceiveResponseHandler, &OnReceiveResponse)
		SINK_ENTRY_INFO(IDD_PROJECT1_DIALOG, __uuidof(_IMailClientEvents), 6, OnSecuringHandler, &OnSecuring)
		SINK_ENTRY_INFO(IDD_PROJECT1_DIALOG, __uuidof(_IMailClientEvents), 7, OnAuthorizedHandler, &OnAuthorized)
		SINK_ENTRY_INFO(IDD_PROJECT1_DIALOG, __uuidof(_IMailClientEvents), 8, OnSendingDataStreamHandler, &OnSendingDataStream)
		SINK_ENTRY_INFO(IDD_PROJECT1_DIALOG, __uuidof(_IMailClientEvents), 9, OnReceivingDataStreamHandler, &OnReceivingDataStream)
	END_SINK_MAP()

// Dialog Data
	enum { IDD = IDD_PROJECT1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	// EAGetMail Event Handler Implementation.
private:
	bool _cancelTask;
	void _doEvents(); 

	HRESULT __stdcall OnIdleHandler(
		IDispatch * oSender,
		VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnConnectedHandler(
		IDispatch * oSender,
		VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnQuitHandler(
		IDispatch * oSender,
		VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnSendCommandHandler(
		IDispatch * oSender,
		VARIANT data,
		VARIANT_BOOL IsDataStream,
		VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnReceiveResponseHandler(
		IDispatch * oSender,
		VARIANT data,
		VARIANT_BOOL IsDataStream,
		VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnSecuringHandler(
		IDispatch * oSender,
		VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnAuthorizedHandler(
		IDispatch * oSender,
		VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnSendingDataStreamHandler(
		IDispatch * oSender,
		long Sent,
		long Total,
		VARIANT_BOOL * Cancel);

	HRESULT __stdcall OnReceivingDataStreamHandler(
		IDispatch * oSender,
		IDispatch * oInfo,
		long Received,
		long Total,
		VARIANT_BOOL * Cancel);

private:
	void _initResize();
	void _initCurrentPath();
	void _initStatusBar();
	void _initAuthType();
	void _initProtocol();
	void _initDateRange();
	void _initListMail();
	bool _initMailClient();
	void _initBoldFont();

	static int CALLBACK ListMailCompareProc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

	CString _createLocalInbox();
	void _loadLocalMails();
	void _addMailToList(IMailPtr &mail, CString &filePath);

	IMailServerPtr _buildServer();
	bool _validateInput();
	bool _tryOauth();
	void _setMailRange();
	void _enableRelatedControls(bool isEnabled, bool isCancelEnabled);

	static bool _existFile(LPCTSTR lpszFile);
	static CString _generateFileName(int sequence);

	void _showMail(LPCTSTR lpszFile);
	CString _getHtmlRenderPath(LPCTSTR lpszFile);
	CString _getAttachmentFolder(LPCTSTR lpszFile);
	CString _formatAddresses(IAddressCollectionPtr &addresses, LPCTSTR prefix);
	CString _formatHtmlTag(LPCTSTR lpszSrc);
	void _generateHtmlForEmail(LPCTSTR lpszFile);

private:
	CStatusBar _statusBar;

private:
	bool _isFormLoad;
	CRect _formRect;

	int _originalWidth;
	int _originalHeight;
	
	void _offsetChildWindow(CWnd* child, int dx, int dy, int dw, int dh);

private:
	CString _server;
	CString _user;
	CString _password;

	BOOL _useSsl;
	BOOL _leaveCopy;
	BOOL _retrieveNewOnly;

	CComboBox _comboAuthType;
	CComboBox _comboProtocol;
	CComboBox _comboDateRange;

	CProgressCtrl _progress;
	CListCtrl _listMail;
	CExplorer_mail _mailBrowser;

	CString _currentPath;

	GoogleOauthWrapper _oauth;
	IMailClientPtr _client;

	CFont _boldFont;

public:
	afx_msg void OnCbnSelchangeComboAuthtype();
	afx_msg void OnCbnSelchangeComboProtocol();

	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonCancel();

	afx_msg void OnNMClickListMail(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListMail(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonDelete();

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	void OnOK() override {}
	void OnCancel() override {}
};
