#pragma once
#include "afxdialogex.h"


class FirstDialog : public CDialogEx
{
	DECLARE_DYNAMIC(FirstDialog)
public:
	FirstDialog(CWnd* pParent = nullptr);
	virtual ~FirstDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:

};
