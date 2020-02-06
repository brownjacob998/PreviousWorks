
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
	, _leaveCopy(TRUE)
	, _retrieveNewOnly(FALSE)
	, _cancelTask(false)
	, _isFormLoad(false)
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
	DDX_Check(pDX, IDC_CHECK_LEAVECOPY, _leaveCopy);
	DDX_Check(pDX, IDC_CHECK_NEWONLY, _retrieveNewOnly);
	DDX_Control(pDX, IDC_COMBO_AUTHTYPE, _comboAuthType);
	DDX_Control(pDX, IDC_COMBO_PROTOCOL, _comboProtocol);
	DDX_Control(pDX, IDC_COMBO_DATERANGE, _comboDateRange);
	DDX_Control(pDX, IDC_PROGRESS_BAR, _progress);
	DDX_Control(pDX, IDC_LIST_MAIL, _listMail);
	DDX_Control(pDX, IDC_EXPLORER_MAIL, _mailBrowser);
}

BEGIN_MESSAGE_MAP(CProject1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_CBN_SELCHANGE(IDC_COMBO_AUTHTYPE, &CProject1Dlg::OnCbnSelchangeComboAuthtype)
	ON_CBN_SELCHANGE(IDC_COMBO_PROTOCOL, &CProject1Dlg::OnCbnSelchangeComboProtocol)
	ON_BN_CLICKED(IDC_BUTTON_START, &CProject1Dlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CProject1Dlg::OnBnClickedButtonCancel)
	ON_NOTIFY(NM_CLICK, IDC_LIST_MAIL, &CProject1Dlg::OnNMClickListMail)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CProject1Dlg::OnBnClickedButtonDelete)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_MAIL, &CProject1Dlg::OnNMCustomdrawListMail)
	ON_WM_GETMINMAXINFO()
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

	_loadLocalMails();

	return TRUE;  // return TRUE  unless you set the focus to a control
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
	_comboProtocol.AddString(_T("POP3"));
	_comboProtocol.AddString(_T("IMAP4"));
	_comboProtocol.AddString(_T("EWS - Exchange 2007-2019/Office 365"));
	_comboProtocol.AddString(_T("Exchange WebDAV - 2000/2003"));

	_comboProtocol.SetCurSel(0);
}

void CProject1Dlg::_initDateRange()
{
	_comboDateRange.AddString(_T("All emails"));
	_comboDateRange.AddString(_T("Last 7 days"));
	_comboDateRange.AddString(_T("Last 30 days"));
	_comboDateRange.AddString(_T("Last 60 days"));
	_comboDateRange.AddString(_T("Last 90 days"));

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
	return (int)(lParam2 - lParam1);
}

void CProject1Dlg::_initBoldFont()
{
	CFont* pFont = GetFont();
	if (pFont)
	{
		LOGFONT logfont;
		pFont->GetLogFont(&logfont);
		logfont.lfWeight = FW_BOLD;

		_boldFont.CreateFontIndirect(&logfont);
	}
}

void CProject1Dlg::OnCbnSelchangeComboAuthtype()
{
	UpdateData(TRUE);

	if (_comboAuthType.GetCurSel() == MailServerAuthXOAUTH2)
	{
		_comboProtocol.SetCurSel(MailServerImap4);
		GetDlgItem(IDC_CHECK_NEWONLY)->EnableWindow(true);
		GetDlgItem(IDC_COMBO_DATERANGE)->EnableWindow(true);

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


void CProject1Dlg::OnCbnSelchangeComboProtocol()
{
	UpdateData(TRUE);

	if (_comboProtocol.GetCurSel() == MailServerPop3)
	{
		_retrieveNewOnly = false;
		_comboDateRange.SetCurSel(0);
		GetDlgItem(IDC_CHECK_NEWONLY)->EnableWindow(false);
		GetDlgItem(IDC_COMBO_DATERANGE)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_CHECK_NEWONLY)->EnableWindow(true);
		GetDlgItem(IDC_COMBO_DATERANGE)->EnableWindow(true);
	}

	if (_comboProtocol.GetCurSel() == MailServerEWS)
	{
		_useSsl = true;
	}

	UpdateData(FALSE);
}
//========================================================================
// End Region: Initialize
//========================================================================


//========================================================================
// Region: Retrieve emails
//========================================================================
CString CProject1Dlg::_createLocalInbox()
{
	CString inboxPath = _currentPath;
	inboxPath.Append(_T("\\inbox"));

	::CreateDirectory(inboxPath.GetString(), NULL);
	return inboxPath;
}

void CProject1Dlg::_addMailToList(IMailPtr &mail, CString &filePath)
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

	_listMail.SetItemData(index, (DWORD_PTR)(receivedDateTime * 1000));
}

IMailServerPtr CProject1Dlg::_buildServer()
{
	IMailServerPtr server;
	server.CreateInstance(__uuidof(EAGetMailObjLib::MailServer));

	server->Server = _server.GetString();
	server->User = _user.GetString();
	server->Password = _password.GetString();

	server->AuthType = _comboAuthType.GetCurSel();
	server->Protocol = _comboProtocol.GetCurSel();
	server->SSLConnection = (_useSsl) ? VARIANT_TRUE : VARIANT_FALSE;

	if (server->Protocol == MailServerImap4)
	{
		server->Port = (_useSsl) ? 993 : 143;
	}
	else
	{
		server->Port = (_useSsl) ? 995 : 110;
	}

	return server;
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

	if (_client == nullptr || _comboProtocol.GetCurSel() == MailServerPop3)
	{
		return;
	}

	_client->GetMailInfosParam->Reset();
	if (_retrieveNewOnly)
	{
		_client->GetMailInfosParam->GetMailInfosOptions = (_client->GetMailInfosParam->GetMailInfosOptions | GetMailInfos_NewOnly);
	}

	if (_comboDateRange.GetCurSel() == 0)
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
	case 1:
		_client->GetMailInfosParam->DateRangeSINCE = (now - 7);
		break;
	case 2:
		_client->GetMailInfosParam->DateRangeSINCE = (now - 30);
		break;
	case 3:
		_client->GetMailInfosParam->DateRangeSINCE = (now - 60);
		break;
	case 4:
		_client->GetMailInfosParam->DateRangeSINCE = (now - 90);
		break;
	default:
		break;
	}

	_client->GetMailInfosParam->DateRangeBEFORE = (now + 1);
	_client->GetMailInfosParam->GetMailInfosOptions = (_client->GetMailInfosParam->GetMailInfosOptions | GetMailInfos_DateRange);
}

void
CProject1Dlg::_enableRelatedControls(bool isEnabled, bool isCancelEnabled)
{
	GetDlgItem(IDC_BUTTON_START)->EnableWindow(isEnabled);
	GetDlgItem(IDC_BUTTON_CANCEL)->EnableWindow(isCancelEnabled);

	GetDlgItem(IDC_EDIT_SERVER)->EnableWindow(isEnabled);
	GetDlgItem(IDC_CHECK_SSL)->EnableWindow(isEnabled);
	GetDlgItem(IDC_CHECK_LEAVECOPY)->EnableWindow(isEnabled);

	GetDlgItem(IDC_COMBO_AUTHTYPE)->EnableWindow(isEnabled);
	GetDlgItem(IDC_COMBO_PROTOCOL)->EnableWindow(isEnabled);

	if (_comboAuthType.GetCurSel() != MailServerAuthXOAUTH2)
	{
		GetDlgItem(IDC_EDIT_USER)->EnableWindow(isEnabled);
		GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(isEnabled);
	}

	if (_comboProtocol.GetCurSel() != MailServerPop3)
	{
		GetDlgItem(IDC_CHECK_NEWONLY)->EnableWindow(isEnabled);
		GetDlgItem(IDC_COMBO_DATERANGE)->EnableWindow(isEnabled);
	}
}

void CProject1Dlg::_loadLocalMails()
{
	CString localInbox = _createLocalInbox();
	CString find = localInbox + _T("\\*.eml");

	WIN32_FIND_DATA findData;
	HANDLE hFind = ::FindFirstFile(find.GetString(), &findData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		return;
	}

	try
	{
		do
		{
			CString file = localInbox;
			file.Append(_T("\\"));
			file.Append(findData.cFileName);

			IMailPtr mail;
			mail.CreateInstance(__uuidof(EAGetMailObjLib::Mail));
			// For evaluation usage, please use "TryIt" as the license code, otherwise the 
			// "invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
			// "trial version expired" exception will be thrown.
			mail->LicenseCode = _T("TryIt");

			// LoadFile( file, true ) only load the email header to Mail object to save the CPU and memory
			// the Mail object will load the whole email file later automatically if bodytext or attachment is required..
			mail->LoadFile(file.GetString(), VARIANT_TRUE);

			_addMailToList(mail, file);

		} while (::FindNextFile(hFind, &findData));
	}
	catch (_com_error &ep)
	{
		MessageBox((const TCHAR*)ep.Description());
	}

	::FindClose(hFind);
	_listMail.SortItems(ListMailCompareProc, 0);
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

	_enableRelatedControls(false, false);

	if (!_tryOauth())
	{
		_enableRelatedControls(true, false);
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
		_enableRelatedControls(true, false);
		return;
	}

	_enableRelatedControls(false, true);

	IUIDLManagerPtr uidlManager;
	bool isUidlLoaded = false;

	CString status;

	try
	{
		IMailServerPtr server = _buildServer();

		_statusBar.GetStatusBarCtrl().SetText(_T("Connecting server..."), 255, 0);
		_cancelTask = false;
		_client->Connect(server);

		uidlManager.CreateInstance(__uuidof(EAGetMailObjLib::UIDLManager));
		CString localInbox = _createLocalInbox();
		CString uidlFile = localInbox + _T("\\uidl.txt");
		uidlManager->Load(uidlFile.GetString());
		isUidlLoaded = true;

		_statusBar.GetStatusBarCtrl().SetText(_T("Retrieve email list ..."), 255, 0);
		_setMailRange();
		IMailInfoCollectionPtr mailInfos = _client->GetMailInfoList();

		if (_comboDateRange.GetCurSel() == 0)
		{
			// Remove the local uidl that is not existed on the server,
			// Only synchronize it with uidl of all emails in current mail folder
			uidlManager->SyncUIDLEX(server, mailInfos);
			uidlManager->Update();
		}

		for (int i = 0; i < mailInfos->Count; i++)
		{
			IMailInfoPtr info = mailInfos->GetItem(i);
			status.Format(_T("Checking %d/%d ..."), i + 1, mailInfos->Count);
			_statusBar.GetStatusBarCtrl().SetText(status.GetString(), 255, 0);


			IUIDLItemPtr uidl = uidlManager->FindUIDL(server, info->UIDL);
			if (uidl != nullptr)
			{
				// This email has been downloaded before
				continue;
			}

			status.Format(_T("Retrieveing %d/%d ..."), i + 1, mailInfos->Count);
			_statusBar.GetStatusBarCtrl().SetText(status.GetString(), 255, 0);

			IMailPtr mail = _client->GetMail(info);

			CString fileName = _generateFileName(i);
			CString fullPath = localInbox + _T("\\") + fileName;

			mail->SaveAs(fullPath.GetString(), VARIANT_TRUE);
			_addMailToList(mail, fullPath);

			if (_retrieveNewOnly && _comboProtocol.GetCurSel() != MailServerPop3)
			{
				// If retrieve only new emails, after we retrieved it, mark it as read,
				// With this feature, you don't have to UIDLManager to prevent duplicated emails.
				status.Format(_T("Mark %d/%d as read ..."), i + 1, mailInfos->Count);
				_statusBar.GetStatusBarCtrl().SetText(status.GetString(), 255, 0);

				_client->MarkAsRead(info, VARIANT_TRUE);
			}

			if (_leaveCopy)
			{
				// Add the email uidl to uidl file to avoid we retrieve it next time.
				uidlManager->AddUIDL(server, info->UIDL, fileName.GetString());
			}
			else
			{
				status.Format(_T("Deleting %d/%d ..."), i + 1, mailInfos->Count);
				_statusBar.GetStatusBarCtrl().SetText(status.GetString(), 255, 0);

				_client->Delete(info);
				// Remove UIDL from local uidl file.
				uidlManager->RemoveUIDL(server, info->UIDL);
			}
		}

		// Delete method just mark the email as deleted in POP3/IMAP protocol
		// Quit method expunge the emails from server exactly.
		_client->Quit();
		uidlManager->Update();

		_statusBar.GetStatusBarCtrl().SetText(_T("Completed"), 255, 0);
	}
	catch (_com_error &ep)
	{
		if (uidlManager != nullptr && isUidlLoaded)
		{
			uidlManager->Update();
		}

		MessageBox((const TCHAR*)ep.Description());
		_statusBar.GetStatusBarCtrl().SetText((const TCHAR*)ep.Description(), 255, 0);
	}

	_enableRelatedControls(true, false);
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
// Region: Parse and display emails
//========================================================================

void CProject1Dlg::OnNMClickListMail(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;

	if (pNMItemActivate->iItem == -1)
	{
		GetDlgItem(IDC_BUTTON_DELETE)->EnableWindow(false);
		return;
	}

	GetDlgItem(IDC_BUTTON_DELETE)->EnableWindow(true);

	CString file = _listMail.GetItemText(pNMItemActivate->iItem, 3);
	if (!file.IsEmpty())
	{
		_showMail(file.GetString());
	}
}


void CProject1Dlg::OnBnClickedButtonDelete()
{
	POSITION pos;;
	while ((pos = _listMail.GetFirstSelectedItemPosition()) != nullptr)
	{
		int index = _listMail.GetNextSelectedItem(pos);
		CString file = _listMail.GetItemText(index, 3);
		if (!file.IsEmpty())
		{
			CString htmlFile = _getHtmlRenderPath(file.GetString());
			CString tempFolder = _getAttachmentFolder(file.GetString());


			IToolsPtr tool;
			tool.CreateInstance(__uuidof(EAGetMailObjLib::Tools));
			tool->RemoveFile(file.GetString());
			tool->RemoveFile(htmlFile.GetString());
			tool->RemoveFolder(tempFolder.GetString(), VARIANT_TRUE);
		}

		_listMail.DeleteItem(index);
	}

	GetDlgItem(IDC_BUTTON_DELETE)->EnableWindow(false);
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


		IToolsPtr tool;
		tool.CreateInstance(__uuidof(EAGetMailObjLib::Tools));

		CString htmlFile = _getHtmlRenderPath(lpszFile);
		tool->WriteTextFile(htmlFile.GetString(), html.GetString(), CP_UTF8);
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
		CString fileName = _listMail.GetItemText((int)pLVCD->nmcd.dwItemSpec, 3);
		if (!fileName.IsEmpty())
		{
			CString htmlFile = _getHtmlRenderPath(fileName.GetString());
			if (!_existFile(htmlFile))
			{
				// html render file is not existed, use bold font to show as "unread"
				::SelectObject(pLVCD->nmcd.hdc, _boldFont.GetSafeHandle());
				*pResult = CDRF_NEWFONT;
			}
		}
	}
	break;
	default:
		break;
	}
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

void CProject1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (nID == SC_CLOSE)
		CDialogEx::OnCancel();

	__super::OnSysCommand(nID, lParam);
}
