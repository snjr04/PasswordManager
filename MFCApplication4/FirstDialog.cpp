// FirstDialog.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication4.h"
#include "afxdialogex.h"
#include "FirstDialog.h"


// Диалоговое окно FirstDialog

IMPLEMENT_DYNAMIC(FirstDialog, CDialogEx)

FirstDialog::FirstDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
{

}

FirstDialog::~FirstDialog()
{
}

void FirstDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FirstDialog, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений FirstDialog
