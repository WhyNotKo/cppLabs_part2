// Aleshko_lab2.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include <iostream>
#include "Aleshko_bank.h"
#include "pch.h"
#include "framework.h"
#include "Aleshko_lab2.h"

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

// CAleshkolab2App

BEGIN_MESSAGE_MAP(CAleshkolab2App, CWinApp)
END_MESSAGE_MAP()


// Создание CAleshkolab2App

CAleshkolab2App::CAleshkolab2App()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CAleshkolab2App

CAleshkolab2App theApp;


// Инициализация CAleshkolab2App

BOOL CAleshkolab2App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

// Aleshko_OOP_labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


using namespace std;

void cout_menu()
{
	cout << "\n 1. Создать счёт."
		<< "\n 2. Показать все счета."
		<< "\n 3. Загрузить из файла."
		<< "\n 4. Сохранить в файл."
		<< "\n 5. Очистить банк."
		<< "\n 0. Выход.\n";
}

int input_menu()
{
	while (true)
	{
		int a = GetCorrectNumber(0, 5);
		return a;
	}
}


int main()
{
	setlocale(LC_ALL, "");
	Aleshko_bank bank;
	int menu = 0;
	while (true)
	{
		cout_menu();
		menu = input_menu();

		if (!menu)
		{
			break;
		}

		if (menu == 1)
		{
			system("cls");
			bank.createAccount();
		}
		if (menu == 2)
		{
			system("cls");
			bank.displayAllAccounts();
		}
		if (menu == 3)
		{
			system("cls");
			bank.loadAllAccounts();
		}
		if (menu == 4)
		{
			system("cls");
			bank.saveAllAccounts();
		}
		if (menu == 5)
		{
			system("cls");
			bank.~Aleshko_bank();

		}

	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

