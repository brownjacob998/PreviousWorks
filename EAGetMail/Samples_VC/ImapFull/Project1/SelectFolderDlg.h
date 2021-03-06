#pragma once


// CSelectFolderDlg dialog

class CSelectFolderDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectFolderDlg)

public:
	CSelectFolderDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSelectFolderDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELECTFOLDER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()


public:
	CTreeCtrl *SourceTree;
	CString OriginalFolder;
	IImap4Folder* SelectedFolder;

private:
	CTreeCtrl _tvFolder;
	void _copyNodes(CTreeCtrl *sourceTree, HTREEITEM source, CTreeCtrl *destTree, HTREEITEM dest);

private:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
