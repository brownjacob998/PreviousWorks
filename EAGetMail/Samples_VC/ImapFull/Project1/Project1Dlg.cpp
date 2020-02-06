
// Project1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Project1.h"
#include "Project1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CProject1Dlg dialog

// Connection Type
const int MailServerConnectType_ConnectSSLAuto = 0;
const int MailServerConnectType_ConnectSSL = 1;
const int MailServerConnectType_ConnectTLS = 2;

// Proxy, EWS/WebDAV doesn't support proxy server
const int ProxyType_Socks4 = 0;
const int ProxyType_Socks5 = 1;
const int ProxyType_Http = 2;

// Auth Type
const int MailServerAuthLogin = 0;
const int MailServerAuthCRAM5 = 1;
const int MailServerAuthNTLM = 2;
const int MailServerAuthXOAUTH2 = 3;

// Mail Server Protocols
const int MailServerPop3 = 0;
const int MailServerImap4 = 1;
const int MailServerEWS = 2; // EWS, Exchange 2007-2019/Office 365
const int MailServerDAV = 3; // Exchange WebDAV, Exchange 2000/2003
const int ProtocolOffset = 1;

// GetMailInfosParam Flags
const int GetMailInfos_All = 1;
const int GetMailInfos_NewOnly = 2;
const int GetMailInfos_ReadOnly = 4;
const int GetMailInfos_SeqRange = 8;
const int GetMailInfos_UIDRange = 16;
const int GetMailInfos_PR_ENTRYID = 32;
const int GetMailInfos_DateRange = 64;
const int GetMailInfos_OrderByDateTime = 128;

CProject1Dlg::CProject1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProject1Dlg::IDD, pParent)
	, _server(_T(""))
	, _user(_T(""))
	, _password(_T(""))
	, _useSsl(TRUE)
	, _cancelTask(false)
	, _isWorking(false)
	, _isFormLoad(false)
	, _isSelectedFolderChanged(true)
	, _selectedFolderPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProject1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SERVER, _server);
	DDV_MaxChars(pDX, _server, 255);
	DDX_Text(pDX, IDC_EDIT_USER, _user);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, _password);
	DDX_Check(pDX, IDC_CHECK_SSL, _useSsl);
	DDX_Control(pDX, IDC_COMBO_AUTHTYPE, _comboAuthType);
	DDX_Control(pDX, IDC_COMBO_PROTOCOL, _comboProtocol);
	DDX_Control(pDX, IDC_COMBO_DATERANGE, _comboDateRange);
	DDX_Control(pDX, IDC_PROGRESS_BAR, _progress);
	DDX_Control(pDX, IDC_LIST_MAIL, _listMail);
	DDX_Control(pDX, IDC_EXPLORER_MAIL, _mailBrowser);
	DDX_Control(pDX, IDC_TREE_FOLDER, _tvFolder);
}

BEGIN_MESSAGE_MAP(CProject1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_CBN_SELCHANGE(IDC_COMBO_AUTHTYPE, &CProject1Dlg::OnCbnSelchangeComboAuthtype)
	ON_BN_CLICKED(IDC_BUTTON_START, &CProject1Dlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CProject1Dlg::OnBnClickedButtonCancel)
	ON_NOTIFY(NM_CLICK, IDC_LIST_MAIL, &CProject1Dlg::OnNMClickListMail)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CProject1Dlg::OnBnClickedButtonDelete)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_MAIL, &CProject1Dlg::OnNMCustomdrawListMail)
	ON_WM_GETMINMAXINFO()
	ON_BN_CLICKED(IDC_BUTTON_QUIT, &CProject1Dlg::OnBnClickedButtonQuit)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_FOLDER, &CProject1Dlg::OnTvnSelchangedTreeFolder)
	ON_NOTIFY(NM_RCLICK, IDC_TREE_FOLDER, &CProject1Dlg::OnNMRClickTreeFolder)
	ON_COMMAND(ID_MAILMENU_ADDFOLDER, &CProject1Dlg::OnMailMenuAddFolder)
	ON_COMMAND(ID_MAILMENU_DELETEFOLDER, &CProject1Dlg::OnMailmenuDeleteFolder)
	ON_COMMAND(ID_MAILMENU_RENAMEFOLDER, &CProject1Dlg::OnMailMenuRenameFolder)
	ON_NOTIFY(TVN_ENDLABELEDIT, IDC_TREE_FOLDER, &CProject1Dlg::OnTvnEndlabeleditTreeFolder)
	ON_COMMAND(ID_MAILMENU_REFRESHFOLDER, &CProject1Dlg::OnMailMenuRefreshFolder)
	ON_COMMAND(ID_MAILMENU_REFRESHMAILS, &CProject1Dlg::OnMailMenuRefreshMails)
	ON_BN_CLICKED(IDC_BUTTON_COPY, &CProject1Dlg::OnBnClickedButtonCopy)
	ON_BN_CLICKED(IDC_BUTTON_UNDELETE, &CProject1Dlg::OnBnClickedButtonUndelete)
	ON_BN_CLICKED(IDC_BUTTON_UNREAD, &CProject1Dlg::OnBnClickedButtonUnread)
	ON_BN_CLICKED(IDC_BUTTON_MOVE, &CProject1Dlg::OnBnClickedButtonMove)
	ON_BN_CLICKED(IDC_BUTTON_UPLOAD, &CProject1Dlg::OnBnClickedButtonUpload)
	ON_BN_CLICKED(IDC_BUTTON_EXPUNGE, &CProject1Dlg::OnBnClickedButtonExpunge)
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()


// CProject1Dlg message handlers

BOOL CProject1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	::CoInitialize(NULL);

	if (!_initMailClient())
	{
		PostQuitMessage(0);
	}

	_mailBrowser.Navigate(_T("about:blank"), nullptr, nullptr, nullptr, nullptr);

	_initCurrentPath();
	_initStatusBar();
	_initAuthType();
	_initProtocol();
	_initDateRange();
	_initListMail();

	_initResize();
	_initBoldFont();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// clear object attached to TreeCtrl and ListCtrl
BOOL CProject1Dlg::DestroyWindow()
{
	_deleteAllNodes();
	_deleteAllMailItems();
	return __super::DestroyWindow();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProject1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProject1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//========================================================================
// Region: Initialize
//========================================================================
bool CProject1Dlg::_initMailClient()
{
	_client.CreateInstance(__uuidof(EAGetMailObjLib::MailClient));
	if (_client == nullptr)
	{
		MessageBox(_T("Please make sure you have installed EAGetMail on your machine!"));
		return false;
	}

	_uidlManager.CreateInstance(__uuidof(EAGetMailObjLib::UIDLManager));
	_tools.CreateInstance(__uuidof(EAGetMailObjLib::Tools));

	try
	{
		// For evaluation usage, please use "TryIt" as the license code, otherwise the
		// "invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
		// "trial version expired" exception will be thrown.
		_client->LicenseCode = _T("TryIt");

		// attach EAGetMail events to current dialog,
		DispEventAdvise(_client.GetInterfacePtr());

		// If you used MailClient as a local variable in function, please detach events before function return like this
		// DispEventUnadvise(_client.GetInterfacePtr());
	}
	catch (_com_error &ep)
	{
		MessageBox((const TCHAR*)ep.Description());
		return false;
	}

	return true;
}

void CProject1Dlg::_initCurrentPath()
{
	WCHAR moduleFile[MAX_PATH + 1];
	DWORD size = ::GetModuleFileNameW(nullptr, moduleFile, MAX_PATH);
	moduleFile[size] = L'\0';

	LPCWSTR pszBuf = wcsrchr(moduleFile, L'\\');
	if (pszBuf != nullptr)
	{
		_currentPath.Append(moduleFile, (int)(pszBuf - moduleFile));
	}
}

void CProject1Dlg::_initStatusBar()
{
	_statusBar.Create(this);

	CStatusBarCtrl & statusBarCtrl = _statusBar.GetStatusBarCtrl();
	statusBarCtrl.SetSimple(TRUE);
	statusBarCtrl.SetMinHeight(30);

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
}

void CProject1Dlg::_initAuthType()
{
	_comboAuthType.AddString(_T("USER/LOGIN"));
	_comboAuthType.AddString(_T("APOP(CRAM-MD5)"));
	_comboAuthType.AddString(_T("NTLM"));
	_comboAuthType.AddString(_T("Gmail XOAUTH2"));

	_comboAuthType.SetCurSel(0);
}

void CProject1Dlg::_initProtocol()
{
	_comboProtocol.AddString(_T("IMAP4"));
	_comboProtocol.AddString(_T("EWS - Exchange 2007-2019/Office 365"));
	_comboProtocol.AddString(_T("Exchange WebDAV - 2000/2003"));

	_comboProtocol.SetCurSel(0);
}

void CProject1Dlg::_initDateRange()
{
	_comboDateRange.AddString(_T("Sync last 7 days emails"));
	_comboDateRange.AddString(_T("Sync last 30 days emails"));
	_comboDateRange.AddString(_T("Sync last 60 days emails"));
	_comboDateRange.AddString(_T("Sync last 90 days emails"));
	_comboDateRange.AddString(_T("Sync all emails (slow)"));

	_comboDateRange.SetCurSel(0);
}

void CProject1Dlg::_initListMail()
{
	const int columnCount = 4;
	static TCHAR* columnNames[columnCount] = { _T("From"), _T("Subject"), _T("Date"), _T("File") };
	static INT columnWidths[columnCount] = { 150, 200, 150, 1 };

	DWORD style = _listMail.GetExtendedStyle();
	style |= (LVS_EX_FULLROWSELECT | LVS_EX_FLATSB);
	_listMail.SetExtendedStyle(style);

	for (int i = 0; i < columnCount; i++)
	{
		LVCOLUMN column;
		column.mask = (LVCF_TEXT | LVCF_WIDTH);

		column.cx = columnWidths[i];
		column.pszText = columnNames[i];

		_listMail.InsertColumn(i, &column);
	}
}

int CALLBACK CProject1Dlg::ListMailCompareProc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	return (int)(((SortMailInfo*)lParam2)->receivedDate - ((SortMailInfo*)lParam1)->receivedDate);
}

void CProject1Dlg::_initBoldFont()
{
	CFont* pFont = GetFont();
	if (pFont)
	{
		LOGFONT logfont;
		pFont->GetLogFont(&logfont);
		_regularFont.CreateFontIndirect(&logfont);

		logfont.lfWeight = FW_BOLD;
		_boldFont.CreateFontIndirect(&logfont);

		logfont.lfWeight = FW_NORMAL;
		logfont.lfStrikeOut = TRUE;
		_strikeFont.CreateFontIndirect(&logfont);
	}
}

void CProject1Dlg::OnCbnSelchangeComboAuthtype()
{
	UpdateData(TRUE);

	if (_comboAuthType.GetCurSel() == MailServerAuthXOAUTH2)
	{
		_comboProtocol.SetCurSel(MailServerImap4 - ProtocolOffset);

		_server = _T("imap.gmail.com");
		_useSsl = true;

		GetDlgItem(IDC_EDIT_USER)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(false);

		_statusBar.GetStatusBarCtrl().SetText(_T("Please click \"Start\" to login Gmail by Web OAUTH!"), 255, 0);
	}
	else
	{
		GetDlgItem(IDC_EDIT_USER)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(true);

		// Clear existed access token
		_oauth.Clear();
		_statusBar.GetStatusBarCtrl().SetText(_T(""), 255, 0);
	}

	UpdateData(FALSE);
}

//========================================================================
// End Region: Initialize
//========================================================================


//========================================================================
// Region: Retrieve emails
//========================================================================
CString CProject1Dlg::_getLocalPath(IImap4Folder *folder)
{
	CString localPath = _currentPath + _T("\\") +
		(const TCHAR*)_currentServer->Server + _T("\\") +
		(const TCHAR*)_currentServer->User + _T("\\") +
		(const TCHAR*)folder->LocalPath;

	return localPath;
}

void CProject1Dlg::_addMailToList(IMailInfoPtr &info, IMailPtr &mail, CString &filePath)
{
	CString sender;
	sender.Format(_T("%s <%s>"), (const TCHAR*)mail->From->Name, (const TCHAR*)mail->From->Address);

	DATE receivedDateTime = mail->ReceivedDate;
	SYSTEMTIME receivedSystemDateTime;
	::VariantTimeToSystemTime(receivedDateTime, &receivedSystemDateTime);

	CString displayDateTime;
	displayDateTime.Format(_T("%04d-%02d-%02d %02d:%02d:%02d"),
		receivedSystemDateTime.wYear,
		receivedSystemDateTime.wMonth,
		receivedSystemDateTime.wDay,
		receivedSystemDateTime.wHour,
		receivedSystemDateTime.wMinute,
		receivedSystemDateTime.wSecond);

	INT index = _listMail.InsertItem(0, _T("temporary"));

	_listMail.SetItemText(index, 0, sender.GetString());
	_listMail.SetItemText(index, 1, (const TCHAR*)mail->Subject);
	_listMail.SetItemText(index, 2, displayDateTime.GetString());
	_listMail.SetItemText(index, 3, filePath.GetString());

	SortMailInfo *sortData = new SortMailInfo();
	sortData->receivedDate = (int)(receivedDateTime * 1000);
	sortData->mailInfo = info.GetInterfacePtr();
	info.AddRef();

	_listMail.SetItemData(index, (DWORD_PTR)sortData);
}

void CProject1Dlg::_buildServer()
{
	if (_currentServer != nullptr)
	{
		_currentServer.Release();
	}
	_currentServer.CreateInstance(__uuidof(EAGetMailObjLib::MailServer));

	_currentServer->Server = _server.GetString();
	_currentServer->User = _user.GetString();
	_currentServer->Password = _password.GetString();

	_currentServer->AuthType = _comboAuthType.GetCurSel();
	_currentServer->Protocol = _comboProtocol.GetCurSel() + ProtocolOffset;
	_currentServer->SSLConnection = (_useSsl) ? VARIANT_TRUE : VARIANT_FALSE;

	if (_currentServer->Protocol == MailServerImap4)
	{
		_currentServer->Port = (_useSsl) ? 993 : 143;
	}
	else
	{
		_currentServer->Port = (_useSsl) ? 995 : 110;
	}
}

bool CProject1Dlg::_validateInput()
{
	if (_server.IsEmpty())
	{
		MessageBox(_T("Please input server address!"));
		GetDlgItem(IDC_EDIT_SERVER)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_SERVER)->SetFocus();
		return false;
	}

	if (_user.IsEmpty())
	{
		MessageBox(_T("Please input user name!"));
		GetDlgItem(IDC_EDIT_USER)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_USER)->SetFocus();
		return false;
	}

	if (_password.IsEmpty())
	{
		MessageBox(_T("Please input password!"));
		GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_PASSWORD)->SetFocus();
		return false;
	}

	return true;
}

bool CProject1Dlg::_tryOauth()
{
	if (_comboAuthType.GetCurSel() != MailServerAuthXOAUTH2)
	{
		// We don't need to login user by Gmail XOAUTH
		return true;
	}

	if (_oauth.AccessToken.GetLength() > 0)
	{
		if (!_oauth.AccessTokenIsExpired())
		{
			return true;
		}

		_statusBar.GetStatusBarCtrl().SetText(_T("Refresh expired access token from server ..."), 255, 0);
		if (_oauth.RefreshAccessToken())
		{
			return true;
		}

		_oauth.Clear();
		_statusBar.GetStatusBarCtrl().SetText(_T("Failed to refresh expired access token, now request new token again."), 255, 0);
	}

	GoogleOauthDlg OauthDlg;
	OauthDlg.pOauth = &_oauth;
	OauthDlg.DoModal();

	if (_oauth.AuthorizationCode.GetLength() == 0)
	{
		MessageBox(_T("Failed to login user and get authorization code."));
		_statusBar.GetStatusBarCtrl().SetText(_T("Failed to login user and get authorization code."), 255, 0);
		return false;
	}

	_statusBar.GetStatusBarCtrl().SetText(_T("Request access token from server ..."), 255, 0);
	if (!_oauth.RequestAccessTokenAndUserEmail())
	{
		MessageBox((const TCHAR*)_oauth.GetLastError());
		_statusBar.GetStatusBarCtrl().SetText((const TCHAR*)_oauth.GetLastError(), 255, 0);
		return false;
	}

	return true;
}

void CProject1Dlg::_setMailRange()
{

	if (_client == nullptr || _currentServer == nullptr)
	{
		return;
	}

	_client->GetMailInfosParam->Reset();

	if (_comboDateRange.GetCurSel() == 4)
	{
		// retrieve all emails.
		return;
	}

	SYSTEMTIME currentTime;
	::GetSystemTime(&currentTime);

	DATE now = 2;
	::SystemTimeToVariantTime(&currentTime, &now);

	// For variant time, Adding 1 to the value increments the date by a day
	switch (_comboDateRange.GetCurSel())
	{
	case 0:
		_client->GetMailInfosParam->DateRangeSINCE = (now - 7);
		break;
	case 1:
		_client->GetMailInfosParam->DateRangeSINCE = (now - 30);
		break;
	case 2:
		_client->GetMailInfosParam->DateRangeSINCE = (now - 60);
		break;
	case 3:
		_client->GetMailInfosParam->DateRangeSINCE = (now - 90);
		break;
	default:
		break;
	}

	_client->GetMailInfosParam->DateRangeBEFORE = (now + 1);
	_client->GetMailInfosParam->GetMailInfosOptions = (_client->GetMailInfosParam->GetMailInfosOptions | GetMailInfos_DateRange);
}

HTREEITEM CProject1Dlg::_getSelectedNode(bool includeRoot)
{
	HTREEITEM node = _tvFolder.GetSelectedItem();
	if (includeRoot)
	{
		return node;
	}

	return (node != nullptr && _tvFolder.GetParentItem(node) != nullptr)
		? node : nullptr;
}

void CProject1Dlg::_connectServerOnDemand()
{
	_isSelectedFolderChanged = false;
	if (_client->Connected != VARIANT_TRUE)
	{
		_statusBar.GetStatusBarCtrl().SetText(_T("Connecting server ..."), 255, 0);

		_cancelTask = false;
		_client->Connect(_currentServer);

		_statusBar.GetStatusBarCtrl().SetText(_T("Connected"), 255, 0);
	}

	HTREEITEM node = _getSelectedNode(false);
	if (node == nullptr)
	{
		return;
	}

	IImap4Folder* folder = (IImap4Folder*)_tvFolder.GetItemData(node);
	if (_tcsicmp(_selectedFolderPath.GetString(), (const TCHAR*)folder->ServerPath) == 0)
	{
		return;
	}

	_deleteAllMailItems();

	_selectedFolderPath = (const TCHAR*)folder->ServerPath;
	_isSelectedFolderChanged = true;

	if (folder->NoSelect != VARIANT_TRUE)
	{
		_client->SelectFolder(folder);
	}
}

void CProject1Dlg::_prepareLogin()
{
	GetDlgItem(IDC_EDIT_SERVER)->EnableWindow(false);

	GetDlgItem(IDC_EDIT_USER)->EnableWindow(false);
	GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(false);

	_comboAuthType.EnableWindow(false);
	_comboProtocol.EnableWindow(false);
	_comboDateRange.EnableWindow(false);

	GetDlgItem(IDC_CHECK_SSL)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_START)->EnableWindow(false);

	_selectedFolderPath = _T("");
}

void CProject1Dlg::_afterLoginSucceeded()
{
	GetDlgItem(IDC_EDIT_SERVER)->EnableWindow(false);

	GetDlgItem(IDC_EDIT_USER)->EnableWindow(false);
	GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(false);


	GetDlgItem(IDC_CHECK_SSL)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_START)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_QUIT)->EnableWindow(true);

	_selectedFolderPath = _T("");
}

void CProject1Dlg::_afterLoginError()
{
	GetDlgItem(IDC_EDIT_SERVER)->EnableWindow(true);

	if (_comboAuthType.GetCurSel() == MailServerAuthXOAUTH2)
	{
		GetDlgItem(IDC_EDIT_USER)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_EDIT_USER)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(true);
	}

	_comboAuthType.EnableWindow(true);
	_comboProtocol.EnableWindow(true);
	_comboDateRange.EnableWindow(true);

	GetDlgItem(IDC_CHECK_SSL)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_START)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_QUIT)->EnableWindow(false);

	_mailBrowser.Navigate(_T("about:blank"), nullptr, nullptr, nullptr, nullptr);

	_deleteAllMailItems();
	_deleteAllNodes();

	_selectedFolderPath = _T("");
}

void CProject1Dlg::_afterQuit()
{
	_endWork();

	_mailBrowser.Navigate(_T("about:blank"), nullptr, nullptr, nullptr, nullptr);

	_deleteAllMailItems();
	_deleteAllNodes();

	GetDlgItem(IDC_EDIT_SERVER)->EnableWindow(true);

	if (_comboAuthType.GetCurSel() == MailServerAuthXOAUTH2)
	{
		GetDlgItem(IDC_EDIT_USER)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_EDIT_USER)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(true);
	}

	_comboAuthType.EnableWindow(true);
	_comboProtocol.EnableWindow(true);
	_comboDateRange.EnableWindow(true);

	GetDlgItem(IDC_CHECK_SSL)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_START)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_QUIT)->EnableWindow(false);

	_selectedFolderPath = _T("");
	_statusBar.GetStatusBarCtrl().SetText(_T("Disconnected"), 255, 0);
}

void CProject1Dlg::_afterError(_com_error &ep)
{
	_endWork();

	_client->Close();
	MessageBox((const TCHAR*)ep.Description());

	_selectedFolderPath = _T("");
	_statusBar.GetStatusBarCtrl().SetText((const TCHAR*)ep.Description(), 255, 0);
}

void CProject1Dlg::_prepareWork()
{
	_isWorking = true;
	_cancelTask = false;
	GetDlgItem(IDC_BUTTON_CANCEL)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_QUIT)->EnableWindow(false);

	_enableControlDynamic();
}

void CProject1Dlg::_endWork()
{
	_isWorking = false;
	GetDlgItem(IDC_BUTTON_CANCEL)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_QUIT)->EnableWindow(true);

	_enableControlDynamic();
}

void CProject1Dlg::_enableControlDynamic()
{
	int selectedMailCount = _listMail.GetSelectedCount();
	bool isFolderSelected = (_getSelectedNode(false) != nullptr);

	_tvFolder.EnableWindow(!_isWorking);
	_listMail.EnableWindow(!_isWorking);

	bool isFolderAndMailSelected = (isFolderSelected && selectedMailCount > 0);

	GetDlgItem(IDC_BUTTON_DELETE)->EnableWindow(!_isWorking && isFolderAndMailSelected);
	GetDlgItem(IDC_BUTTON_UNREAD)->EnableWindow(!_isWorking && isFolderAndMailSelected);
	GetDlgItem(IDC_BUTTON_MOVE)->EnableWindow(!_isWorking && isFolderAndMailSelected);
	GetDlgItem(IDC_BUTTON_COPY)->EnableWindow(!_isWorking && isFolderAndMailSelected);
	GetDlgItem(IDC_BUTTON_UPLOAD)->EnableWindow(!_isWorking && isFolderSelected);

	if (_comboProtocol.GetCurSel() + ProtocolOffset == MailServerImap4)
	{
		GetDlgItem(IDC_BUTTON_UNDELETE)->EnableWindow(!_isWorking && isFolderAndMailSelected);
		GetDlgItem(IDC_BUTTON_EXPUNGE)->EnableWindow(!_isWorking && isFolderSelected);
	}
	else
	{
		GetDlgItem(IDC_BUTTON_UNDELETE)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_EXPUNGE)->EnableWindow(false);
	}
}

bool CProject1Dlg::_existFile(LPCTSTR lpszFile)
{
	bool isExisted = false;
	WIN32_FIND_DATA findData;
	HANDLE hFind = ::FindFirstFile(lpszFile, &findData);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		::FindClose(hFind);
		isExisted = true;
	}

	return isExisted;
}

CString CProject1Dlg::_generateFileName(int sequence)
{
	CString fileName;
	SYSTEMTIME currentDateTime;
	::GetLocalTime(&currentDateTime);
	fileName.Format(_T("%04d%02d%02d%02d%02d%02d%03d%03d.eml"),
		currentDateTime.wYear,
		currentDateTime.wMonth,
		currentDateTime.wDay,
		currentDateTime.wHour,
		currentDateTime.wMinute,
		currentDateTime.wSecond,
		currentDateTime.wMilliseconds,
		sequence);

	return fileName;
}

void CProject1Dlg::OnBnClickedButtonStart()
{
	UpdateData(TRUE);

	_prepareLogin();

	if (!_tryOauth())
	{
		_afterLoginError();
		return;
	}

	if (_comboAuthType.GetCurSel() == MailServerAuthXOAUTH2)
	{
		_user = _oauth.UserEmail;
		_password = _oauth.AccessToken;
		UpdateData(FALSE);
	}

	if (!_validateInput())
	{
		_afterLoginError();
		return;
	}

	GetDlgItem(IDC_BUTTON_START)->EnableWindow(false);

	try
	{
		_prepareWork();
		_buildServer();

		_statusBar.GetStatusBarCtrl().SetText(_T("Connecting server ..."), 255, 0);
		_client->Connect(_currentServer);
		_statusBar.GetStatusBarCtrl().SetText(_T("Connected"), 255, 0);

		_showAllFolders();

		_endWork();
		_afterLoginSucceeded();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
		_afterLoginError();
	}
}


void CProject1Dlg::OnBnClickedButtonQuit()
{
	try
	{
		_client->Logout();
		_client->Close();
	}
	catch (...)
	{
	}

	_afterQuit();
}

void CProject1Dlg::OnBnClickedButtonCancel()
{
	_cancelTask = true;
	GetDlgItem(IDC_BUTTON_CANCEL)->EnableWindow(false);
}
//========================================================================
// End Region: Retrieve emails
//========================================================================

//========================================================================
// Region: Retrieve and display folders
//========================================================================
void CProject1Dlg::_showAllFolders()
{
	_deleteAllNodes();

	CString rootPath;
	rootPath.Format(_T("%s\\%s"), (const TCHAR*)_currentServer->Server, (const TCHAR*)_currentServer->User);
	HTREEITEM root = _tvFolder.InsertItem(rootPath);
	_tvFolder.SetItemData(root, (DWORD_PTR)0);
	_tvFolder.SelectItem(root);

	IFolderCollectionPtr folders = _client->GetFolderList();
	_expandFolders(folders, root);

	_tvFolder.Expand(root, TVE_EXPAND);
}

void CProject1Dlg::_expandFolders(IFolderCollectionPtr &folders, HTREEITEM parent)
{
	for (int i = 0; i < folders->Count; i++)
	{
		IImap4FolderPtr folder = folders->GetItem(i);
		HTREEITEM node = _tvFolder.InsertItem((const TCHAR*)folder->Name, parent);
		_tvFolder.SetItemData(node, (DWORD_PTR)folder.GetInterfacePtr());

		IFolderCollectionPtr subFolders = folder->GetSubFolderList();
		_expandFolders(subFolders, node);

		_tvFolder.Expand(node, TVE_EXPAND);
		folder.Detach(); // because ItemData has take the control of IImapFolder, so use detach instead of release
	}
}
//========================================================================
// End Region: Retrieve and display folders
//========================================================================

//========================================================================
// Region: Add/remove/rename folders
//========================================================================
void
CProject1Dlg::_deleteNode(HTREEITEM node)
{
	if (node == nullptr)
	{
		return;
	}

	IImap4Folder *folder = (IImap4Folder*)_tvFolder.GetItemData(node);
	if (folder != nullptr)
	{
		folder->Release();
	}

	if (_tvFolder.ItemHasChildren(node))
	{
		HTREEITEM next;
		HTREEITEM child = _tvFolder.GetChildItem(node);

		while (child != nullptr)
		{
			next = _tvFolder.GetNextItem(child, TVGN_NEXT);
			_deleteNode(child);

			child = next;
		}
	}

	_tvFolder.DeleteItem(node);

}

void
CProject1Dlg::_deleteAllNodes()
{
	if (_tvFolder.GetRootItem() == nullptr)
	{
		return;
	}

	_tvFolder.SelectItem(_tvFolder.GetRootItem());
	_deleteNode(_tvFolder.GetRootItem());
	_tvFolder.DeleteAllItems();
}

void
CProject1Dlg::_deleteMailItem(int index)
{
	SortMailInfo* data = (SortMailInfo*)_listMail.GetItemData(index);
	if (data != nullptr)
	{
		if (data->mailInfo != nullptr)
		{
			data->mailInfo->Release();
		}
		delete data;
	}

	_listMail.DeleteItem(index);
}

void
CProject1Dlg::_deleteAllMailItems()
{
	int count = _listMail.GetItemCount();
	for (int i = 0; i < count; i++)
	{
		SortMailInfo* data = (SortMailInfo*)_listMail.GetItemData(i);
		if (data != nullptr)
		{
			if (data->mailInfo != nullptr)
			{
				data->mailInfo->Release();
			}
			delete data;
		}
	}
	_listMail.DeleteAllItems();
}

void CProject1Dlg::OnNMRClickTreeFolder(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;

	if (_tvFolder.GetSelectedItem() == nullptr)
	{
		return;
	}

	CMenu mnuPopupSubmit;
	mnuPopupSubmit.LoadMenu(IDR_MENU1);

	POINT point;
	::GetCursorPos(&point);
	CMenu *mnuPopupMenu = mnuPopupSubmit.GetSubMenu(0);

	if (_isWorking)
	{
		mnuPopupMenu->EnableMenuItem(ID_MAILMENU_REFRESHFOLDER, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		mnuPopupMenu->EnableMenuItem(ID_MAILMENU_REFRESHMAILS, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		mnuPopupMenu->EnableMenuItem(ID_MAILMENU_ADDFOLDER, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		mnuPopupMenu->EnableMenuItem(ID_MAILMENU_RENAMEFOLDER, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		mnuPopupMenu->EnableMenuItem(ID_MAILMENU_DELETEFOLDER, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}
	else if (_getSelectedNode(false) == nullptr)
	{
		mnuPopupMenu->EnableMenuItem(ID_MAILMENU_REFRESHMAILS, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		mnuPopupMenu->EnableMenuItem(ID_MAILMENU_RENAMEFOLDER, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		mnuPopupMenu->EnableMenuItem(ID_MAILMENU_DELETEFOLDER, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	}

	mnuPopupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}

void CProject1Dlg::OnMailMenuAddFolder()
{
	CAddFolderDlg addDlg;
	if (addDlg.DoModal() != IDOK)
	{
		return;
	}

	CString folderName = addDlg._folderName;

	HTREEITEM parentNode = _getSelectedNode(true);
	if (parentNode == nullptr)
	{
		parentNode = _tvFolder.GetRootItem();
	}

	IImap4Folder* parentFolder =
		(_tvFolder.GetParentItem(parentNode) != nullptr) ?
		(IImap4Folder*)_tvFolder.GetItemData(parentNode) : nullptr;

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		IImap4FolderPtr folder = _client->CreateFolder(parentFolder, folderName.GetString());
		HTREEITEM newNode = _tvFolder.InsertItem(folderName.GetString(), parentNode);

		_tvFolder.SetItemData(newNode, (DWORD_PTR)folder.GetInterfacePtr());
		folder.Detach();

		_tvFolder.Expand(parentNode, TVE_EXPAND);

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}

}

void CProject1Dlg::OnMailmenuDeleteFolder()
{
	HTREEITEM node = _getSelectedNode(false);
	if (node == nullptr)
	{
		return;
	}

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		IImap4Folder* folder = (IImap4Folder*)_tvFolder.GetItemData(node);
		CString localPath = _getLocalPath(folder);

		_client->DeleteFolder(folder);
		_deleteNode(node);

		_tools->RemoveFolder(localPath.GetString(), VARIANT_TRUE); 

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}
}

void CProject1Dlg::OnMailMenuRenameFolder()
{
	HTREEITEM node = _getSelectedNode(false);
	if (node == nullptr)
	{
		return;
	}

	_listMail.EnableWindow(false);
	_tvFolder.EditLabel(node);
}

void CProject1Dlg::OnTvnEndlabeleditTreeFolder(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	HTREEITEM node = pTVDispInfo->item.hItem;
	if (node == nullptr || pTVDispInfo->item.pszText == nullptr)
	{
		_tvFolder.EndEditLabelNow(true);
		_listMail.EnableWindow(true);
		return;
	}

	CString newName = pTVDispInfo->item.pszText;

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		IImap4Folder* folder = (IImap4Folder*)_tvFolder.GetItemData(node);
		CString originalLocalFolder = _getLocalPath(folder);

		if (_tcscmp(newName.GetString(), (const TCHAR*)folder->Name) != 0)
		{
			_client->RenameFolder(folder, newName.GetString());
			_tvFolder.SetItemText(node, newName.GetString());

			CString newLocalFolder = _getLocalPath(folder);
			::MoveFile(originalLocalFolder.GetString(), newLocalFolder.GetString());
		}

		_endWork();
	}
	catch (_com_error &ep)
	{
		_tvFolder.EndEditLabelNow(true);
		_afterError(ep);
	}

}

void CProject1Dlg::OnMailMenuRefreshFolder()
{
	try
	{
		_prepareWork();
		_connectServerOnDemand();

		_client->RefreshFolders();
		_showAllFolders();

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}
}

void CProject1Dlg::OnMailMenuRefreshMails()
{
	HTREEITEM node = _getSelectedNode(false);
	if (node == nullptr)
	{
		return;
	}

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		_client->RefreshMailInfos();
		_loadServerMails(node);

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}
}

//========================================================================
// End Region: Add/remove/rename folders
//========================================================================

//========================================================================
// Region: list/copy/move and other operations for emails.
//========================================================================
void CProject1Dlg::OnNMCustomdrawListMail(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);
	// TODO: Add your control notification handler code here

	*pResult = 0;

	switch (pLVCD->nmcd.dwDrawStage)
	{
	case CDDS_PREPAINT:
		*pResult = CDRF_NOTIFYITEMDRAW;
		break;

	case CDDS_ITEMPREPAINT:
	{
		SortMailInfo* data = (SortMailInfo*)_listMail.GetItemData((int)pLVCD->nmcd.dwItemSpec);
		if (data != nullptr && data->mailInfo != nullptr)
		{
			if (data->mailInfo->Read == VARIANT_FALSE)
			{
				::SelectObject(pLVCD->nmcd.hdc, _boldFont.GetSafeHandle());
				*pResult = CDRF_NEWFONT;
			}
			else if (data->mailInfo->Deleted == VARIANT_TRUE)
			{
				::SelectObject(pLVCD->nmcd.hdc, _strikeFont.GetSafeHandle());
				*pResult = CDRF_NEWFONT;
			}
			else
			{
				::SelectObject(pLVCD->nmcd.hdc, _regularFont.GetSafeHandle());
				*pResult = CDRF_NEWFONT;
			}
		}

	}
	break;
	default:
		break;
	}
}

void CProject1Dlg::OnTvnSelchangedTreeFolder(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	*pResult = 0;

	HTREEITEM node = pNMTreeView->itemNew.hItem;
	if (_tvFolder.GetParentItem(node) == nullptr)
	{
		_deleteAllMailItems();
		_statusBar.GetStatusBarCtrl().SetText(_T("Root"), 255, 0);

		_endWork();
		return;
	}

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		if (_isSelectedFolderChanged)
		{
			_loadServerMails(node);
		}

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}

}

void CProject1Dlg::_loadServerMails(HTREEITEM node)
{
	_deleteAllMailItems();
	IImap4Folder *folder = (IImap4Folder*)_tvFolder.GetItemData(node);
	if (folder == nullptr || folder->NoSelect == VARIANT_TRUE)
	{
		_tvFolder.Expand(node, TVE_EXPAND);
		return;
	}

	CString status;
	bool isUidlLoaded = false;

	try
	{
		CString localPath = _getLocalPath(folder);
		_createFullLocalFolder(localPath);

		CString uidlFile = localPath + _T("\\uidl.txt");
		_uidlManager->Load(uidlFile.GetString());
		isUidlLoaded = true;

		_setMailRange();
		_statusBar.GetStatusBarCtrl().SetText(_T("Refreshing email list ..."), 255, 0);

		IMailInfoCollectionPtr mailInfos = _client->GetMailInfoList();
		status.Format(_T("Total %d email(s)"), mailInfos->Count);
		_statusBar.GetStatusBarCtrl().SetText(status.GetString(), 255, 0);

		if (_comboDateRange.GetCurSel() == 4)
		{
			// Remove the local uidl which is not existed on the server.
			// we only synchronize it with uidl of all emails in current mail folder
			_uidlManager->SyncUIDLEX(_currentServer, mailInfos);
			_uidlManager->Update();
		}

		for (int i = 0; i < mailInfos->Count; i++)
		{
			IMailInfoPtr info = mailInfos->GetItem(i);
			IUIDLItemPtr uidlItem = _uidlManager->FindUIDL(_currentServer, info->UIDL);

			CString emailHeaderFile;
			if (uidlItem == nullptr)
			{
				// Current email headers has not been downloaded, generate a new file to store email headers
				emailHeaderFile = _generateFileName(i);
			}
			else
			{
				// Get existed email headers file from existed email headers file.
				emailHeaderFile = (const TCHAR*)uidlItem->FileName;
			}

			CString fullEmailHeaderFile = localPath + _T("\\") + emailHeaderFile;
			status.Format(_T("Retrieving headers of %d/%d ..."), i + 1, mailInfos->Count);
			_statusBar.GetStatusBarCtrl().SetText(status.GetString(), 255, 0);

			IMailPtr mail;
			mail.CreateInstance(__uuidof(EAGetMailObjLib::Mail));
			mail->LicenseCode = _T("TryIt");

			if (_existFile(fullEmailHeaderFile.GetString()))
			{
				mail->LoadFile(fullEmailHeaderFile.GetString(), VARIANT_FALSE);
			}
			else
			{
				mail->Load(_client->GetMailHeader(info));
				mail->SaveAs(fullEmailHeaderFile.GetString(), VARIANT_TRUE);
			}

			_addMailToList(info, mail, fullEmailHeaderFile);

			int lower = 0, upper = 0;
			_progress.GetRange(lower, upper);
			_progress.SetPos(upper);

			if (uidlItem == nullptr)
			{
				_uidlManager->AddUIDL(_currentServer, info->UIDL, emailHeaderFile.GetString());
			}

		}

		_listMail.SortItems(ListMailCompareProc, 0);

		// Remove local file that is not existed on server.
		_clearLocalMails(localPath.GetString());

		_uidlManager->Update();
		status.Format(_T("Total %d emails"), _listMail.GetItemCount());
		_statusBar.GetStatusBarCtrl().SetText(status.GetString(), 255, 0);
	}
	catch (_com_error &ep)
	{
		if (isUidlLoaded)
		{
			_uidlManager->Update();
		}

		status.Format(_T("Total %d emails"), _listMail.GetItemCount());
		_statusBar.GetStatusBarCtrl().SetText(status.GetString(), 255, 0);
		throw ep;
	}
}

// Remove local file that is not existed on server.
void CProject1Dlg::_clearLocalMails(LPCTSTR lpszFolder)
{
	CString find = lpszFolder;
	find.Append(_T("\\*.eml"));
	
	WIN32_FIND_DATA findData;
	HANDLE hFind = ::FindFirstFile(find.GetString(), &findData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		return;
	}

	BOOL hasNextFile = true;
	while (hasNextFile)
	{
		CString file, htmlFile, attachmentFolder;
		file.Format(_T("%s\\%s"), lpszFolder, findData.cFileName);
		htmlFile = _getHtmlRenderPath(file);
		attachmentFolder = _getAttachmentFolder(file);

		if (_uidlManager->FindLocalFile(findData.cFileName) == nullptr)
		{
			::DeleteFile(file);
			::DeleteFile(htmlFile);

			if (_tools->ExistFile(attachmentFolder.GetString()))
			{
				_tools->RemoveFolder(attachmentFolder.GetString(), VARIANT_TRUE);
			}
		}

		hasNextFile = ::FindNextFile(hFind, &findData);
	}

	::FindClose(hFind);
}

void CProject1Dlg::_createFullLocalFolder(CString &path)
{
	int startIndex = _currentPath.GetLength() + 1;
	int pos = 0;
	while ((pos = path.Find(_T("\\"), startIndex)) != -1)
	{
		CString part = path.Mid(0, pos);
		if (!_existFile(part.GetString()))
		{
			::CreateDirectory(part.GetString(), nullptr);
		}
		startIndex = pos + 1;
	}

	if (!_existFile(path.GetString()))
	{
		::CreateDirectory(path.GetString(), nullptr);
	}
}

IImap4Folder* CProject1Dlg::_getDestFolder()
{
	IImap4Folder* destFolder = nullptr;

	HTREEITEM node = _getSelectedNode(false);
	if (node == nullptr)
	{
		return destFolder;
	}

	IImap4Folder* currentFolder = (IImap4Folder*)_tvFolder.GetItemData(node);

	CSelectFolderDlg selectDlg;
	selectDlg.OriginalFolder = (const TCHAR*)currentFolder->ServerPath;
	selectDlg.SourceTree = &_tvFolder;
	
	if (selectDlg.DoModal() != IDOK)
	{
		return destFolder;
	}

	destFolder = selectDlg.SelectedFolder;
	return destFolder;
}

void CProject1Dlg::OnBnClickedButtonDelete()
{
	if (_listMail.GetSelectedCount() == 0)
	{
		return;
	}

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		int index = -1;
		while ((index = _listMail.GetNextItem(index, LVNI_SELECTED)) != -1)
		{
			SortMailInfo* data = (SortMailInfo*)_listMail.GetItemData(index);
			_client->Delete(data->mailInfo);

			_deleteMailItem(index);
			index = -1;
		}

		if (_currentServer->Protocol == MailServerImap4)
		{
			_client->Expunge();
		}

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}
}

void CProject1Dlg::OnBnClickedButtonUndelete()
{
	if (_listMail.GetSelectedCount() == 0)
	{
		return;
	}

	if (_currentServer->Protocol != MailServerImap4)
	{
		return;
	}

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		int index = -1;
		while ((index = _listMail.GetNextItem(index, LVNI_SELECTED)) != -1)
		{
			SortMailInfo* data = (SortMailInfo*)_listMail.GetItemData(index);
			if(data->mailInfo->Deleted == VARIANT_TRUE)
			{
				_client->Undelete(data->mailInfo);
			}
		}
		
		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}
}

void CProject1Dlg::OnBnClickedButtonUnread()
{
	if (_listMail.GetSelectedCount() == 0)
	{
		return;
	}

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		int index = -1;
		while ((index = _listMail.GetNextItem(index, LVNI_SELECTED)) != -1)
		{
			SortMailInfo* data = (SortMailInfo*)_listMail.GetItemData(index);
			if (data->mailInfo->Read == VARIANT_TRUE)
			{
				_client->MarkAsRead(data->mailInfo, VARIANT_FALSE);
			}
		}

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}
}

void CProject1Dlg::OnBnClickedButtonCopy()
{
	IImap4Folder *folder =_getDestFolder();
	if (folder == nullptr)
	{
		return;
	}

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		int index = -1;
		while ((index = _listMail.GetNextItem(index, LVNI_SELECTED)) != -1)
		{
			SortMailInfo* data = (SortMailInfo*)_listMail.GetItemData(index);
			_client->Copy(data->mailInfo, folder);
		}

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}
}

void CProject1Dlg::OnBnClickedButtonMove()
{
	IImap4Folder *folder = _getDestFolder();
	if (folder == nullptr)
	{
		return;
	}

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		int index = -1;
		while ((index = _listMail.GetNextItem(index, LVNI_SELECTED)) != -1)
		{
			SortMailInfo* data = (SortMailInfo*)_listMail.GetItemData(index);
			_client->Move(data->mailInfo, folder);

			_deleteMailItem(index);
			index = -1;
		}

		if (_currentServer->Protocol == MailServerImap4)
		{
			_client->Expunge();
		}

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}
}

void CProject1Dlg::OnBnClickedButtonUpload()
{
	HTREEITEM node = _getSelectedNode(false);
	if (node == nullptr)
	{
		return;
	}

	CFileDialog fileDlg(TRUE, _T("*.EML"), NULL, 4 | 2, _T("Email File (*.EML)|*.EML||"));
	fileDlg.m_ofn.Flags;
	fileDlg.m_ofn.Flags |= OFN_FILEMUSTEXIST;

	if (fileDlg.DoModal() != IDOK)
	{
		return;
	}

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		CString fileName;
		fileName.Format(_T("%s\\%s"), fileDlg.GetFolderPath(), fileDlg.GetFileName());

		IMailPtr mail;
		mail.CreateInstance(__uuidof(EAGetMailObjLib::Mail));
		mail->LicenseCode = _T("TryIt");

		mail->LoadFile(fileName.GetString(), VARIANT_FALSE);

		IImap4Folder* folder = (IImap4Folder*)_tvFolder.GetItemData(node);
		_client->Append(folder, mail->Content);
		_client->RefreshMailInfos();
		_loadServerMails(node);

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}
}

void CProject1Dlg::OnBnClickedButtonExpunge()
{
	HTREEITEM node = _getSelectedNode(false);
	if (node == nullptr)
	{
		return;
	}

	if (_currentServer->Protocol != MailServerImap4)
	{
		return;
	}

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		_client->Expunge();
		_loadServerMails(node);

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}
}
//========================================================================
// End Region: list/copy/move and other operations for emails.
//========================================================================

//========================================================================
// Region: Parse and display emails
//========================================================================

void CProject1Dlg::OnNMClickListMail(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;

	if (pNMItemActivate->iItem == -1 || _listMail.GetSelectedCount() != 1 || _isWorking)
	{
		_enableControlDynamic();
		return;
	}

	HTREEITEM node = _getSelectedNode(false);
	if (node == nullptr)
	{
		return;
	}

	int index = pNMItemActivate->iItem;

	try
	{
		_prepareWork();
		_connectServerOnDemand();

		IImap4Folder* folder = (IImap4Folder*)_tvFolder.GetItemData(node);
		IMailInfo* info = ((SortMailInfo*)_listMail.GetItemData(index))->mailInfo;

		CString localPath = _currentPath + _T("\\") +
			(const TCHAR*)_currentServer->Server + _T("\\") +
			(const TCHAR*)_currentServer->User + _T("\\") +
			(const TCHAR*)folder->LocalPath;

		IUIDLItemPtr uidlItem = _uidlManager->FindUIDL(_currentServer, info->UIDL);
		if (uidlItem == nullptr)
		{
			// should never happen except you deleted the email file from the folder manually.
			MessageBox(_T("No email file found"));
			_endWork();
			return;
		}

		CString fileName = localPath + _T("\\") + (const TCHAR*)uidlItem->FileName;
		CString htmlFile = _getHtmlRenderPath(fileName.GetString());

		if (!_existFile(htmlFile))
		{
			IMailPtr mail;
			mail.CreateInstance(__uuidof(EAGetMailObjLib::Mail));

			_progress.SetRange(0, 100);
			_progress.SetPos(0);

			_statusBar.GetStatusBarCtrl().SetText(_T("Downloading email ..."), 255, 0);

			mail = _client->GetMail(info);
			mail->SaveAs(fileName.GetString(), VARIANT_TRUE);

			_statusBar.GetStatusBarCtrl().SetText(_T("Completed"), 255, 0);

			int lower = 0, upper = 0;
			_progress.GetRange(lower, upper);
			_progress.SetPos(upper);
		}

		if (info->Read != VARIANT_TRUE)
		{
			_client->MarkAsRead(info, VARIANT_TRUE);
		}

		_showMail(fileName.GetString());

		_endWork();
	}
	catch (_com_error &ep)
	{
		_afterError(ep);
	}

}

CString CProject1Dlg::_getHtmlRenderPath(LPCTSTR lpszFile)
{
	CString htmlFile;
	LPCTSTR pszBuf = _tcsrchr(lpszFile, _T('.'));
	htmlFile.Append(lpszFile, (int)(pszBuf - lpszFile));
	htmlFile.Append(_T(".html"));

	return htmlFile;
}

CString CProject1Dlg::_getAttachmentFolder(LPCTSTR lpszFile)
{
	CString tempFolder;
	LPCTSTR pszBuf = _tcsrchr(lpszFile, _T('.'));
	tempFolder.Append(lpszFile, (int)(pszBuf - lpszFile));

	return tempFolder;
}

void CProject1Dlg::_showMail(LPCTSTR lpszFile)
{
	CString htmlFile = _getHtmlRenderPath(lpszFile);
	if (!_existFile(htmlFile.GetString()))
	{
		// We haven't generated the html for this email, generate it now.
		_generateHtmlForEmail(lpszFile);
	}

	_mailBrowser.Navigate(htmlFile.GetString(), nullptr, nullptr, nullptr, nullptr);
}

// Generate a html + temporal attachment folder for every email, once the html is created,
// next time we don't need to parse the email again.
void CProject1Dlg::_generateHtmlForEmail(LPCTSTR lpszFile)
{
	CString tempFolder = _getAttachmentFolder(lpszFile);

	try
	{
		IMailPtr mail;
		mail.CreateInstance(__uuidof(EAGetMailObjLib::Mail));
		mail->LicenseCode = _T("TryIt");
		mail->LoadFile(lpszFile, VARIANT_FALSE);

		if (mail->IsEncrypted == VARIANT_TRUE)
		{
			try
			{
				mail = mail->Decrypt(nullptr);
			}
			catch (_com_error &exp)
			{
				MessageBox((const TCHAR*)exp.Description());
			}
		}

		if (mail->IsSigned == VARIANT_TRUE)
		{
			try
			{
				ICertificatePtr signerCert = mail->VerifySignature();
				MessageBox(_T("This email contains a valid digital signature!"));
			}
			catch (_com_error &exp)
			{
				MessageBox((const TCHAR*)exp.Description());
			}
		}

		// Decode winmail.dat (TNEF stream) automatically;
		// also convert RTF body to HTML body automatically.
		mail->DecodeTNEF();

		CString html = (TCHAR*)mail->HtmlBody;
		CString header;
		header.Preallocate(1024 * 5);

		header.Append(_T("<meta HTTP-EQUIV=\"Content-Type\" Content=\"text/html; charset=utf-8\">"));
		header.Append(_T("<div style=\"font-family: consolas, \'Courier New\', Arial; font-size: 14px; background-color: #fff;\">"));
		header.AppendFormat(_T("<b>From:</b> %s &lt;%s&gt;<br>"), (const TCHAR*)mail->From->Name, (const TCHAR*)mail->From->Address);

		header.Append(_formatAddresses(mail->ToList, _T("To")));
		header.Append(_formatAddresses(mail->CcList, _T("To")));

		header.AppendFormat(_T("<b>Subject:</b> %s<br>\r\n"), _formatHtmlTag(mail->Subject).GetString());

		IAttachmentCollectionPtr attachments = mail->AttachmentList;
		if (attachments->Count > 0)
		{
			header.Append(_T("<b>Attachments:</b> "));
			if (!_existFile(tempFolder.GetString()))
			{
				::CreateDirectory(tempFolder.GetString(), nullptr);
			}
		}

		for (int i = 0; i < attachments->Count; i++)
		{
			IAttachmentPtr attachment = attachments->GetItem(i);
			CString attachmentName = tempFolder + _T("\\");
			attachmentName += (const TCHAR*)attachment->Name;

			attachment->SaveAs(attachmentName.GetString(), VARIANT_TRUE);

			header.AppendFormat(_T("<a href=\"%s\" target=\"_blank\">%s</a> "), attachmentName.GetString(), (const TCHAR*)attachment->Name);

			CString contentId = attachment->ContentID;
			if (!contentId.IsEmpty() && html.Find(contentId) != -1)
			{// this is an embedded attachment.
				CString contentIdLink = _T("cid:") + contentId;
				html.Replace(contentIdLink, attachmentName);
			}
		}

		header.Append(_T("</div>\r\n"));
		header.Append(_T("<hr>"));

		html = header + html;

		CString htmlFile = _getHtmlRenderPath(lpszFile);
		_tools->WriteTextFile(htmlFile.GetString(), html.GetString(), CP_UTF8);
	}
	catch (_com_error &ep)
	{
		MessageBox((const TCHAR*)ep.Description());
	}
}

CString CProject1Dlg::_formatHtmlTag(LPCTSTR lpszSrc)
{
	CString buffer = lpszSrc;

	buffer.Replace(_T(">"), _T("&gt;"));
	buffer.Replace(_T("<"), _T("&lt;"));
	return buffer;
}

CString CProject1Dlg::_formatAddresses(IAddressCollectionPtr &addresses, LPCTSTR prefix)
{
	CString buffer;
	if (addresses->Count == 0)
	{
		return buffer;
	}

	buffer.Format(_T("<b>%s:</b> "), prefix); // To or Cc
	for (int i = 0; i < addresses->Count; i++)
	{
		IMailAddressPtr address = addresses->GetItem(i);
		CString name = address->Name;
		if (name.IsEmpty())
		{
			buffer.AppendFormat(_T("&lt;%s&gt;"), (const TCHAR*)address->Address);
		}
		else
		{
			buffer.AppendFormat(_T("%s &lt;%s&gt;"), name.GetString(), (const TCHAR*)address->Address);
		}

		if (i < addresses->Count - 1)
		{
			buffer.Append(_T("; "));
		}
	}

	buffer.Append(_T("<br>"));
	return buffer;
}

//========================================================================
// End Region: Parse and display emails
//========================================================================

//========================================================================
// Region: Auto resize related control
//========================================================================
void CProject1Dlg::_initResize()
{
	CRect rect;
	GetWindowRect(&rect);

	_originalHeight = rect.Height();
	_originalWidth = rect.Width();

	GetClientRect(&_formRect);
	_isFormLoad = true;
}

void CProject1Dlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	lpMMI->ptMinTrackSize.x = _originalWidth;
	lpMMI->ptMinTrackSize.y = _originalHeight;
	__super::OnGetMinMaxInfo(lpMMI);
}

void CProject1Dlg::_offsetChildWindow(CWnd* child, int dx, int dy, int dw, int dh)
{
	if (!child) return;
	if (!child->GetParent()) return;
	if (!IsWindow(child->m_hWnd)) return;

	//find child window's coordinates relative to top-left of parent
	CRect rc;
	child->GetWindowRect(&rc);

	CPoint p(0, 0);
	::ScreenToClient(child->GetParent()->GetSafeHwnd(), &p);
	rc.OffsetRect(p);

	//prevent negative size
	if ((rc.Width() + dw) < 0) dw = -rc.Width();
	if ((rc.Height() + dh) < 0) dh = -rc.Height();

	child->SetWindowPos(0, rc.left + dx, rc.top + dy, rc.Width() + dw, rc.Height() + dh, 0);
	child->Invalidate(FALSE);
}

void CProject1Dlg::OnSize(UINT nType, int cx, int cy)
{
	if (!_isFormLoad)
	{
		return;
	}

	CDialogEx::OnSize(nType, cx, cy);

	if (nType == SIZE_MINIMIZED)
	{
		return;
	}

	int dx = cx - _formRect.right;
	int dy = cy - _formRect.bottom;

	_offsetChildWindow(&_listMail, 0, 0, dx, 0);
	_offsetChildWindow(&_tvFolder, 0, 0, 0, dy);
	_offsetChildWindow(&_progress, 0, dy, dx, 0);
	_offsetChildWindow(&_mailBrowser, 0, 0, dx, dy);
	_offsetChildWindow(&_statusBar, 0, dy, dx, 0);

	GetClientRect(&_formRect);
}

//========================================================================
// End Region: Auto resize related control
//========================================================================

//==========================================================
// Region: EAGetMail Event Handler
//==========================================================
// Catching the following events is not necessary, 
// just make the application more user friendly.
// If you use the object in asp.net/windows service or non-gui application, 
// You need not to catch the following events.
// To learn more detail, please refer to the code in EAGetMail EventHandler region
HRESULT __stdcall
CProject1Dlg::OnIdleHandler(
	IDispatch * oSender,
	VARIANT_BOOL * Cancel)
{
	*Cancel = _cancelTask ? VARIANT_TRUE : VARIANT_FALSE;
	_doEvents();
	return S_OK;
}

HRESULT __stdcall
CProject1Dlg::OnConnectedHandler(
	IDispatch * oSender,
	VARIANT_BOOL * Cancel)
{
	_statusBar.GetStatusBarCtrl().SetText(_T("Connected"), 255, 0);

	*Cancel = _cancelTask ? VARIANT_TRUE : VARIANT_FALSE;
	_doEvents();
	return S_OK;
}

HRESULT __stdcall
CProject1Dlg::OnQuitHandler(
	IDispatch * oSender,
	VARIANT_BOOL * Cancel)
{
	_statusBar.GetStatusBarCtrl().SetText(_T("Disconnecting ..."), 255, 0);
	return S_OK;
}

HRESULT __stdcall
CProject1Dlg::OnSendCommandHandler(
	IDispatch * oSender,
	VARIANT data,
	VARIANT_BOOL IsDataStream,
	VARIANT_BOOL * Cancel)
{
	// this event is fired by Append method.
	return S_OK;
}

HRESULT __stdcall
CProject1Dlg::OnReceiveResponseHandler(
	IDispatch * oSender,
	VARIANT data,
	VARIANT_BOOL IsDataStream,
	VARIANT_BOOL * Cancel)
{
	return S_OK;
}

HRESULT __stdcall
CProject1Dlg::OnSecuringHandler(
	IDispatch * oSender,
	VARIANT_BOOL * Cancel)
{
	_statusBar.GetStatusBarCtrl().SetText(_T("Securing ..."), 255, 0);

	*Cancel = _cancelTask ? VARIANT_TRUE : VARIANT_FALSE;
	_doEvents();
	return S_OK;
}

HRESULT __stdcall
CProject1Dlg::OnAuthorizedHandler(
	IDispatch * oSender,
	VARIANT_BOOL * Cancel)
{
	_statusBar.GetStatusBarCtrl().SetText(_T("Authorized"), 255, 0);

	*Cancel = _cancelTask ? VARIANT_TRUE : VARIANT_FALSE;
	_doEvents();
	return S_OK;
}

HRESULT __stdcall
CProject1Dlg::OnSendingDataStreamHandler(
	IDispatch * oSender,
	long Sent,
	long Total,
	VARIANT_BOOL * Cancel)
{

	return S_OK;
}

HRESULT __stdcall
CProject1Dlg::OnReceivingDataStreamHandler(
	IDispatch * oSender,
	IDispatch * oInfo,
	long Received,
	long Total,
	VARIANT_BOOL * Cancel)
{

	_progress.SetRange32(0, Total);
	_progress.SetPos(Received);

	*Cancel = _cancelTask ? VARIANT_TRUE : VARIANT_FALSE;
	_doEvents();
	return S_OK;
}

void CProject1Dlg::_doEvents()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
			return;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
//==========================================================
// End Region: EAGetMail Event Handler
//==========================================================


