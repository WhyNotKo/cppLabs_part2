// Aleshko_dll.h: основной файл заголовка для библиотеки DLL Aleshko_dll
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CAleshkodllApp
// Реализацию этого класса см. в файле Aleshko_dll.cpp
//

class CAleshkodllApp : public CWinApp
{
public:
	CAleshkodllApp();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
