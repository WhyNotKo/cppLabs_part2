// Aleshko_dll.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "pch.h"
#include "framework.h"
#include "Aleshko_dll.h"
#include "Aleshko_bank.h"
#include <memory>
#include <filesystem>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CAleshkodllApp

BEGIN_MESSAGE_MAP(CAleshkodllApp, CWinApp)
END_MESSAGE_MAP()


// Создание CAleshkodllApp

CAleshkodllApp::CAleshkodllApp()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CAleshkodllApp

CAleshkodllApp theApp;


// Инициализация CAleshkodllApp

BOOL CAleshkodllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

struct Account_struct {
	char name[100];
	char type[100];
	int money;
	int credit;
	bool isVIP;
};


Aleshko_bank bank;

extern "C"
{
	__declspec(dllexport) int __stdcall getContainerSize()
	{
		return bank.accounts.size();
	}

	__declspec(dllexport) void __stdcall loadFromFile(const char* filename)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		CFile f(CString(filename), CFile::modeRead);
		CArchive ar(&f, CArchive::load);
		bank.clear();
		bank.ReadFromFile(ar);
		ar.Close();
		f.Close();
	}

	__declspec(dllexport) void __stdcall saveToFile(const char* filename)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		CFile f(CString(filename), CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&f, CArchive::store);
		bank.WriteToFile(ar);
		ar.Close();
		f.Close();
	}


	_declspec(dllexport) void __stdcall deleteAccount(int index)
	{
		bank.accounts.erase(bank.accounts.begin() + index);
	}


	__declspec(dllexport) void __stdcall getAccount(Account_struct& s, int index)
	{
		strcpy_s(s.name, (CStringA)bank.accounts[index]->name);
		strcpy_s(s.type, (CStringA)bank.accounts[index]->type);
		s.money = bank.accounts[index]->money;

		Aleshko_vip* vip = dynamic_cast<Aleshko_vip*>(bank.accounts[index].get());
		if (vip)
		{
			s.isVIP = true;

			s.credit = vip->credit_limit;
		}
		else
		{
			s.isVIP = false;
		}
	}


	_declspec(dllexport) void __stdcall updateAccount(Account_struct& s, int index)
	{
		bank.accounts[index]->name = s.name;
		bank.accounts[index]->type = s.type;
		bank.accounts[index]->money = s.money;

		Aleshko_vip* vip = dynamic_cast<Aleshko_vip*>(bank.accounts[index].get());
		if (vip)
		{
			vip->credit_limit = s.credit;
		}
	}


	_declspec(dllexport) void __stdcall addAccount(Account_struct& s)
	{
		if (s.isVIP)
		{
			std::shared_ptr<Aleshko_vip> vip = std::make_shared<Aleshko_vip>(s.name, s.type, s.money, s.credit);
			bank.accounts.push_back(vip);
		}
		else
		{
			std::shared_ptr<Aleshko_account> acc = std::make_shared<Aleshko_account>(s.name, s.type, s.money);
			bank.accounts.push_back(acc);
		}
	}
}