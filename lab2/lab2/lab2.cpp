// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<Windows.h>
#include "pch.h"
#include "framework.h"
#include "lab2.h"
#include "Aleshko_bank.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Единственный объект приложения

CWinApp theApp;
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


void cout_user_menu()
{
	cout << "\n 1. Обычный аккаунт."
		<< "\n 2. VIP."
		<< "\n 0. Выход в меню.\n";
}

int input_menu(int upperBound, int lowerBound = 0)
{
	while (true)
	{
		int a = GetCorrectNumber(lowerBound, upperBound);
		return a;
	}
}

//std::string enterFilename()
//{
//	
//	return filename;
//}


int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Aleshko_bank bank;
	int menu = 0;
	while (true)
	{
		cout_menu();
		menu = input_menu(5);

		if (!menu)
		{
			break;
		}

		if (menu == 1)
		{
			system("cls");
			while (true) {
				cout_user_menu();
				int user_menu = input_menu(2);

				if (user_menu == 1)
					bank.addAccount();
				else {
					if (user_menu == 2)
						bank.addVIP();
					else
						break;
				}

			}
		}
		if (menu == 2)
		{
			system("cls");
			bank.displayAllAccounts();
		}
		if (menu == 3)
		{
			system("cls");
			cout << "Введите название файла: ";
			string filename;
			cin >> filename;
			bank.loadAllAccounts(filename.c_str());
		}
		if (menu == 4)
		{
			system("cls");
			cout << "Введите название файла: ";
			string filename;
			cin >> filename;
			bank.saveAllAccounts(filename.c_str());
		}
		if (menu == 5)
		{
			system("cls");
			bank.clear();
		}

	}
	return 0;
}
