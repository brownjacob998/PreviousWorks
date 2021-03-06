// CAddFolderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Project1.h"
#include "AddFolderDlg.h"
#include "afxdialogex.h"


// CAddFolderDlg dialog

IMPLEMENT_DYNAMIC(CAddFolderDlg, CDialogEx)

CAddFolderDlg::CAddFolderDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDFOLDER, pParent)
	, _folderName(_T(""))
{

}

CAddFolderDlg::~CAddFolderDlg()
{
}

void CAddFolderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FOLDERNAME, _folderName);
}


BEGIN_MESSAGE_MAP(CAddFolderDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddFolderDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddFolderDlg message handlers


void CAddFolderDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	_folderName = _folderName.Trim();
	if (_folderName.GetLength() == 0)
	{
		MessageBox(_T("Please input folder name!"));
		GetDlgItem(IDC_EDIT_FOLDERNAME)->SetFocus();
		UpdateData(FALSE);
		return;
	}

	CDialogEx::OnOK();
}


