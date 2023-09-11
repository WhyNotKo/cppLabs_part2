// Aleshko_OOP_labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Aleshko_bank.h"

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

