// Aleshko_lab2.h: основной файл заголовка для библиотеки DLL Aleshko_lab2
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CAleshkolab2App
// Реализацию этого класса см. в файле Aleshko_lab2.cpp
//

class CAleshkolab2App : public CWinApp
{
public:
	CAleshkolab2App();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
