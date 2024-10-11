#pragma once
#include "afxdialogex.h"


// Диалоговое окно SecondDialog

class SecondDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SecondDialog)

public:
	SecondDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~SecondDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
