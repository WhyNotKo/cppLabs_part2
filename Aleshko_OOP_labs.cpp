// Aleshko_OOP_labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Aleshko_bank.h"

using namespace std;

void cout_menu()
{
	cout << "\n 1. Create account."
		<< "\n 2. Display all accounts."
		<< "\n 3. Load accounts from file."
		<< "\n 4. Save account to file."
		<< "\n 5. Delete all accounts."
		<< "\n 0. exit.\n";
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
			bank.createAccount();
		}
		if (menu == 2)
		{
			bank.displayAllAccounts();
		}
		if (menu == 3)
		{
			bank.loadAllAccounts();
		}
		if (menu == 4)
		{
			bank.saveAllAccounts();
		}
		if (menu == 5)
		{
			bank.~Aleshko_bank();

		}
		
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

