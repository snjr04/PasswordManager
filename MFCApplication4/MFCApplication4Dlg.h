#include <string>


#pragma once


// Диалоговое окно CMFCApplication4Dlg
class CMFCApplication4Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication4Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	enum { TIMER_BUTTON_ID = 1 };

	afx_msg void OnBnClickedYourButton();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit _EDIT;
	afx_msg void OnBnClickedButton1();
	CString cstrPassword;
	afx_msg void OnBnClickedButton2();
	CEdit PassLength;
	const std::string characters;


	CButton UpperCase;
	CButton Numbers;
	CButton LowerCase;
	CButton Symbols;

	BOOL m_Sym;
	BOOL m_Str;
	BOOL m_Num;
	BOOL m_Low;
	afx_msg void OnBnClickedCheck1();

	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();

	int num = 4;
	CString str;
	int message;
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck3();

	CString FilePath = _T("C:\\Users\\user\\Documents\\C++projects\\MFCApplication4\\MFCApplication4\\Debug\\MFCApplication4.tlog\\Data.txt");
	CString _EDITTEXT;
	CString _EditNameData;

	CEdit _EditName;

};
