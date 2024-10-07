
// MFCApplication4Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"
#include <random>
#include <fstream>
#include <afxwin.h>
#include <atlconv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCApplication4Dlg



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
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication4Dlg

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию


	UpperCase.SetCheck(BST_CHECKED);
	m_Str = BST_CHECKED;
	UpperCase.SetCheck(m_Str);

	Numbers.SetCheck(BST_CHECKED);
	m_Num = BST_CHECKED;
	Numbers.SetCheck(m_Num);

	Symbols.SetCheck(BST_CHECKED);
	m_Sym = BST_CHECKED;
	Symbols.SetCheck(m_Sym);


	if (m_Str== BST_UNCHECKED && m_Sym == BST_UNCHECKED) {
		AfxMessageBox(_T("Ты долен выбрать минимум 1 элемент для генерации!"));
	}
	else {
		m_Num = BST_CHECKED;
		Symbols.SetCheck(m_Sym);
	}
	if (m_Num == BST_UNCHECKED && m_Str == BST_UNCHECKED) {
		AfxMessageBox(_T("Ты долен выбрать минимум 1 элемент для генерации!"));
	}
	else {
		m_Sym = BST_CHECKED;
		Symbols.SetCheck(m_Sym);
	}


	str.Format(_T("%d"), num);
	PassLength.SetWindowText(str);


	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication4Dlg::OnPaint()
{
	CPaintDC dc(this); // Создаем контекст устройства для рисования

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		dc.FillSolidRect(0, 0, 600, 500, RGB(238, 128, 98));

		CDialogEx::OnPaint();
	}
}


// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication4Dlg::OnEnChangeEdit2()
{
	PassLength.GetWindowText(str);
	int number = _ttoi(str);

	if (number < 4 || number > 24)
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
		AfxMessageBox(_T("Значение не может быть меньше 4 или больше 24!"));
		return;
	}
		CString str;
		PassLength.GetWindowText(str);
		int PassLen = _ttoi(str);

		std::string characters = "";
		const std::string charactersA = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		const std::string characters01 = "0123456789";
		const std::string charactersSym = ":;/|!@#$%^&*()'{\\}[]";


		m_Str = UpperCase.GetCheck();
		m_Num = Numbers.GetCheck();
		m_Sym = Symbols.GetCheck();

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
		std::random_device rd;
		std::mt19937 generator(rd());
		std::uniform_int_distribution<> distribution(0, static_cast<int>(characters.size()) - 1);
		std::string password;

		for (int i = 0; i < PassLen; ++i)
		{
			password += characters[distribution(generator)];
		}

		// Преобразуем std::string в CString
		cstrPassword = CString(password.c_str());

		// Устанавливаем пароль в поле _EDIT
		_EDIT.SetWindowText(cstrPassword);
	}


// Копирование пароля в буфер обмена
void CMFCApplication4Dlg::OnBnClickedButton1()
{
	// Открываем буфер обмена
	if (OpenClipboard())
	{
		// Очищаем буфер обмена
		EmptyClipboard();

		// Определяем длину строки, включая завершающий нулевой символ
		size_t strSize = (cstrPassword.GetLength() + 1) * sizeof(TCHAR);

		// Выделяем глобальную память для строки
		HGLOBAL hGlob = GlobalAlloc(GMEM_MOVEABLE, strSize);

		if (hGlob)
		{
			// Копируем текст в выделенную память
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







void CMFCApplication4Dlg::OnBnClickedButton2()
{
	_EDIT.GetWindowTextW(_EDITTEXT);

	if (_EDITTEXT.IsEmpty())
	{
		AfxMessageBox(L"Поле ввода пустое. Нечего сохранять.");
		return;
	}

	int response = AfxMessageBox(L"Вы хотите сохронить?", MB_YESNO | MB_ICONQUESTION);
	if (response == IDNO) {
		return;
	}

	std::ofstream outFile(CT2A(FilePath), std::ios_base::app);

	if (!outFile) {
		AfxMessageBox(L"Не удалось открыть файл для записи!");
		return;
	}

	outFile << CT2A(_EDITTEXT) << std::endl;

	outFile.close();
	AfxMessageBox(L"Данные успешно сохранены в файл!");

}











void CMFCApplication4Dlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}






void CMFCApplication4Dlg::OnBnClickedCheck2()
{
	m_Str = UpperCase.GetCheck();
	m_Sym = Symbols.GetCheck();
	m_Num = Numbers.GetCheck();


	if (m_Str == BST_UNCHECKED && m_Sym == BST_UNCHECKED) {
		AfxMessageBox(_T("Ты долен выбрать минимум 1 элемент для генерации!"));
		Numbers.SetCheck(BST_CHECKED);
	}
}

void CMFCApplication4Dlg::OnBnClickedCheck1()
{
	m_Str = UpperCase.GetCheck();
	m_Sym = Symbols.GetCheck();
	m_Num = Numbers.GetCheck();

	if (m_Num == BST_UNCHECKED && m_Sym == BST_UNCHECKED) {
		AfxMessageBox(_T("Ты долен выбрать минимум 1 элемент для генерации!"));
		UpperCase.SetCheck(BST_CHECKED);
	}
}

void CMFCApplication4Dlg::OnBnClickedCheck4()
{
	m_Str = UpperCase.GetCheck();
	m_Sym = Symbols.GetCheck();
	m_Num = Numbers.GetCheck();
	if (m_Str == BST_UNCHECKED && m_Num == BST_UNCHECKED)
	{
		AfxMessageBox(_T("Ты должен выбрать минимум 1 элемент для генерации кода!"));
		Symbols.SetCheck(BST_CHECKED);
	}
}


void CMFCApplication4Dlg::OnBnClickedCheck3()
{
	// TODO: добавьте свой код обработчика уведомлений
}
