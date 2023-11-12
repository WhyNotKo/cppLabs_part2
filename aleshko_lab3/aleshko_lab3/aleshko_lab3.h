
// aleshko_lab3.h: основной файл заголовка для приложения aleshko_lab3
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Caleshkolab3App:
// Сведения о реализации этого класса: aleshko_lab3.cpp
//

class Caleshkolab3App : public CWinApp
{
public:
	Caleshkolab3App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Caleshkolab3App theApp;
