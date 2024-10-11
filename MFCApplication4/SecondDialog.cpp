// SecondDialog.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication4.h"
#include "afxdialogex.h"
#include "SecondDialog.h"


// Диалоговое окно SecondDialog

IMPLEMENT_DYNAMIC(SecondDialog, CDialogEx)

SecondDialog::SecondDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

SecondDialog::~SecondDialog()
{
}

void SecondDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SecondDialog, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений SecondDialog
