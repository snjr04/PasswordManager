#include "pch.h"
#include "framework.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"
#include <random>
#include <fstream>
#include <afxwin.h>
#include <atlconv.h>
#include <windows.h>
#include <SecondDialog.h>
#include <FirstDialog.h>





#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}
/*
BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_COMMAND(IDC_MFCMENUBUTTON2, &CMFCApplication4Dlg::OnWindow1)
	ON_COMMAND(IDD_MFCAPPLICATION4_DIALOG, &CMFCApplication4Dlg::OnWindow2)
END_MESSAGE_MAP()
*/
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, _EDIT);
	DDX_Control(pDX, IDC_EDIT2, PassLength);

	DDX_Control(pDX, IDC_CHECK1, UpperCase);
	DDX_Control(pDX, IDC_CHECK2, Numbers);
	DDX_Control(pDX, IDC_CHECK4, Symbols);
	DDX_Control(pDX, IDC_EDIT3, _EditName);
	DDX_Control(pDX, IDC_CHECK3, LowerCase);
}



BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication4Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication4Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication4Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication4Dlg::OnBnClickedCheck1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication4Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication4Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_CHECK2, &CMFCApplication4Dlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK4, &CMFCApplication4Dlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK3, &CMFCApplication4Dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON2, &CMFCApplication4Dlg::OnBnClickedMfcmenubutton2)
END_MESSAGE_MAP()

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);		


	UpperCase.SetCheck(BST_CHECKED);
	m_Str = BST_CHECKED;
	UpperCase.SetCheck(m_Str);

	Numbers.SetCheck(BST_CHECKED);
	m_Num = BST_CHECKED;
	Numbers.SetCheck(m_Num);

	Symbols.SetCheck(BST_CHECKED);
	m_Sym = BST_CHECKED;
	Symbols.SetCheck(m_Sym);

	LowerCase.SetCheck(BST_CHECKED);
	m_Low = BST_CHECKED;
	LowerCase.SetCheck(m_Low);


	if (m_Num == BST_CHECKED) {
		if (m_Str == BST_UNCHECKED) {
			m_Str = BST_CHECKED;
		}

		if (m_Sym == BST_UNCHECKED) {
			m_Sym = BST_CHECKED;
			Symbols.SetCheck(m_Sym);
		}

		if (m_Low == BST_UNCHECKED) {
			m_Low = BST_CHECKED;
			LowerCase.SetCheck(m_Low);
		}
	}

	str.Format(_T("%d"), num);
	PassLength.SetWindowText(str);

	SetFileAttributes(FilePath, FILE_ATTRIBUTE_HIDDEN);
	
	return TRUE;  
}

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


void CMFCApplication4Dlg::OnPaint()
{
	CPaintDC dc(this);

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		dc.FillSolidRect(0, 0, 700, 500, RGB(238, 128, 98));
		CDialogEx::OnPaint();
	}



}

HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication4Dlg::OnEnChangeEdit2()
{
	PassLength.GetWindowText(str);
	int number = _ttoi(str);

	if (number < 4 || number > 54)
	{
		message = 1;
	}
	else {
		message = 0;
	}

}

void CMFCApplication4Dlg::OnBnClickedOk()
{

	if (message == 1)
	{
		AfxMessageBox(_T("Значение не может быть меньше 4 или больше 54!"));
		return;
	}
		CString str;
		PassLength.GetWindowText(str);
		int PassLen = _ttoi(str);

		std::string characters = "";
		const std::string charactersA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		const std::string charactersa = "abcdefghijklmnopqrstuvwxyz";
		const std::string characters01 = "0123456789";
		const std::string charactersSym = ":;/|!@#$%^&*()'{\\}[]";


		m_Str = UpperCase.GetCheck();
		m_Num = Numbers.GetCheck();
		m_Sym = Symbols.GetCheck();
		m_Low = LowerCase.GetCheck();

		if (m_Str == BST_CHECKED) {
			characters += charactersA;
		}
		if (m_Num == BST_CHECKED)
		{
			characters += characters01;
		}
		if (m_Sym == BST_CHECKED)
		{
			characters += charactersSym;
		}
		if (m_Low == BST_CHECKED)
		{
			characters += charactersa;
		}



		std::random_device rd;
		std::mt19937 generator(rd());
		std::uniform_int_distribution<> distribution(0, static_cast<int>(characters.size()) - 1);
		std::string password;

		for (int i = 0; i < PassLen; ++i)
		{
			password += characters[distribution(generator)];
		}

		cstrPassword = CString(password.c_str());
		_EDIT.SetWindowText(cstrPassword);
	}

void CMFCApplication4Dlg::OnBnClickedButton1()
{
	if (OpenClipboard())
	{
		EmptyClipboard();
		size_t strSize = (cstrPassword.GetLength() + 1) * sizeof(TCHAR);
		HGLOBAL hGlob = GlobalAlloc(GMEM_MOVEABLE, strSize);
		if (hGlob)
		{
			memcpy(GlobalLock(hGlob), (LPVOID)(LPCTSTR)cstrPassword, strSize);
			GlobalUnlock(hGlob);
#ifdef UNICODE
			SetClipboardData(CF_UNICODETEXT, hGlob);
#else
			SetClipboardData(CF_TEXT, hGlob);
#endif
		}

		CloseClipboard();
	}
}


CString encryptDecrypt(const CString& key, const CString& data) {
	CString result = data;
	for (int i = 0; i < data.GetLength(); ++i) {
		result.SetAt(i, data[i] ^ key[i % key.GetLength()]);
	}
	return result;
}

void CMFCApplication4Dlg::OnBnClickedButton2() {
	if (_EditName.GetWindowTextLengthW() == 0) {
		AfxMessageBox(L"Введите название для пароля!");
		return;
	}

	_EDIT.GetWindowTextW(_EDITTEXT);
	_EditName.GetWindowTextW(_EditNameData);

	if (_EDITTEXT.IsEmpty()) {
		AfxMessageBox(L"Поле ввода пустое. Нечего сохранять.");
		return;
	}

	CString key = _T("your_key"); 
	CString data = _EDITTEXT;     

	CString resultData = encryptDecrypt(key, data);
	std::ofstream outFile(CT2A(FilePath), std::ios_base::app);

	if (!outFile) {
		AfxMessageBox(L"Не удалось открыть файл для записи!");
		return;
	}

	outFile << "Название: " << CT2A(_EditNameData) << std::endl;
	outFile << "Пароль: " << CT2A(resultData) << std::endl;

	outFile.close();
	AfxMessageBox(L"Данные успешно сохранены в файл!");
}


void CMFCApplication4Dlg::OnEnChangeEdit1()
{

}

void CMFCApplication4Dlg::OnBnClickedCheck2()
{
	m_Str = UpperCase.GetCheck();
	m_Sym = Symbols.GetCheck();
	m_Num = Numbers.GetCheck();
	m_Low = LowerCase.GetCheck();

	if (m_Str == BST_UNCHECKED && m_Sym == BST_UNCHECKED && m_Low == BST_UNCHECKED) {
		AfxMessageBox(_T("Ты долен выбрать минимум 1 элемент для генерации!"));
		Numbers.SetCheck(BST_CHECKED);
	}
}

void CMFCApplication4Dlg::OnBnClickedCheck1()
{
	m_Str = UpperCase.GetCheck();
	m_Sym = Symbols.GetCheck();
	m_Num = Numbers.GetCheck();
	m_Low = LowerCase.GetCheck();

	if (m_Num == BST_UNCHECKED && m_Sym == BST_UNCHECKED && m_Low == BST_UNCHECKED) {
		AfxMessageBox(_T("Ты долен выбрать минимум 1 элемент для генерации!"));
		UpperCase.SetCheck(BST_CHECKED);
	}
}

void CMFCApplication4Dlg::OnBnClickedCheck4()
{
	m_Str = UpperCase.GetCheck();
	m_Sym = Symbols.GetCheck();
	m_Num = Numbers.GetCheck();
	m_Low = LowerCase.GetCheck();

	if (m_Str == BST_UNCHECKED && m_Num == BST_UNCHECKED && m_Low == BST_UNCHECKED)
	{
		AfxMessageBox(_T("Ты должен выбрать минимум 1 элемент для генерации кода!"));
		Symbols.SetCheck(BST_CHECKED);
	}

}

void CMFCApplication4Dlg::OnBnClickedCheck3()
{
	m_Str = UpperCase.GetCheck();
	m_Sym = Symbols.GetCheck();
	m_Num = Numbers.GetCheck();
	m_Low = LowerCase.GetCheck();

	if (m_Str == BST_UNCHECKED && m_Sym == BST_UNCHECKED && m_Num == BST_UNCHECKED) {
		AfxMessageBox(_T("Ты долен выбрать минимум 1 элемент для генерации!"));
		LowerCase.SetCheck(BST_CHECKED);
	}
}
/*
void CMFCApplication4Dlg::OnWindow1()
{
	
	CDialogEx dlg1(IDC_MFCMENUBUTTON1);
	dlg1.DoModal();

	FirstDialog dlg1;
	if (dlg1.DoModal() == IDOK)
	{
		// Если первый диалог закрылся с результатом IDOK, открываем второй
		SecondDialog dlg2;
		dlg2.DoModal();
	}
}

void CMFCApplication4Dlg::OnWindow2()
{
	// Открытие второго диалога
	CDialogEx dlg2(IDD_MFCAPPLICATION4_DIALOG);
	dlg2.DoModal();
	SecondDialog dlg2;
	dlg2.DoModal();
}
*/

void CMFCApplication4Dlg::OnBnClickedMfcmenubutton2()
{
	CDialogEx dlg1(IDC_MFCMENUBUTTON1);
	dlg1.DoModal();

	FirstDialog dlg1;
	if (dlg1.DoModal() == IDC_MFCMENUBUTTON2)
	{
		SecondDialog dlg2;
		dlg2.DoModal();
	}
}
