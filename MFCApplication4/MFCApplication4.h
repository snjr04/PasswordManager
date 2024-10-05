
// MFCApplication4.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCApplication4App:
// Сведения о реализации этого класса: MFCApplication4.cpp
//

class CMFCApplication4App : public CWinApp
{
public:
	CMFCApplication4App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication4App theApp;
