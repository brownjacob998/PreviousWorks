#pragma once


// CAddFolderDlg dialog

class CAddFolderDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddFolderDlg)

public:
	CAddFolderDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddFolderDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDFOLDER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString _folderName;
	afx_msg void OnBnClickedOk();
};
