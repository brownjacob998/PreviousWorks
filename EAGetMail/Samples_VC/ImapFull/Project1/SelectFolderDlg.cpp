// SelectFolderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Project1.h"
#include "SelectFolderDlg.h"
#include "afxdialogex.h"


// CSelectFolderDlg dialog

IMPLEMENT_DYNAMIC(CSelectFolderDlg, CDialogEx)

CSelectFolderDlg::CSelectFolderDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SELECTFOLDER, pParent)
	, OriginalFolder(_T(""))
	, SourceTree(nullptr)
	, SelectedFolder(nullptr)
{
}

CSelectFolderDlg::~CSelectFolderDlg()
{
}

void CSelectFolderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_SELECTFOLDER, _tvFolder);
}


BEGIN_MESSAGE_MAP(CSelectFolderDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSelectFolderDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSelectFolderDlg message handlers


void CSelectFolderDlg::OnBnClickedOk()
{
	HTREEITEM node = _tvFolder.GetSelectedItem();
	if (node == nullptr || _tvFolder.GetParentItem(node) == nullptr)
	{
		MessageBox(_T("Please select a folder!"));
		return;
	}

	IImap4Folder* folder = (IImap4Folder*)_tvFolder.GetItemData(node);
	if (OriginalFolder.Compare((const TCHAR*)folder->Name) == 0)
	{
		MessageBox(_T("Please select a folder different with original folder!"));
		return;
	}

	SelectedFolder = folder;
	CDialogEx::OnOK();
}


BOOL CSelectFolderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HTREEITEM destRoot = _tvFolder.InsertItem(_T("Root"));
	_copyNodes(SourceTree, SourceTree->GetRootItem(), &_tvFolder, destRoot);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CSelectFolderDlg::_copyNodes(CTreeCtrl *sourceTree, HTREEITEM source, CTreeCtrl *destTree, HTREEITEM dest)
{
	if (sourceTree == nullptr || source == nullptr || destTree == nullptr || dest == nullptr)
	{
		return;
	}

	if (!sourceTree->ItemHasChildren(source))
	{
		return;
	}

	HTREEITEM next;
	HTREEITEM child = sourceTree->GetChildItem(source);

	while (child != nullptr)
	{
		CString text = sourceTree->GetItemText(child);
		DWORD_PTR data = sourceTree->GetItemData(child);

		HTREEITEM node = destTree->InsertItem(text, dest);
		destTree->SetItemData(node, data);

		_copyNodes(sourceTree, child, destTree, node);

		next = sourceTree->GetNextItem(child, TVGN_NEXT);
		child = next;
	}

	destTree->Expand(dest, TVE_EXPAND);
}
