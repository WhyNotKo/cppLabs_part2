#include "Aleshko_account.h"


std::ifstream& operator >> (std::ifstream& fin, Aleshko_account& acc)
{
	fin.ignore();

	std::getline(fin, acc.name);
	std::getline(fin, acc.type);
	fin	>> acc.money; 

	return fin;
}


std::ostream& operator << (std::ostream& out, const Aleshko_account& acc)
{
	std::cout << "Client: " << acc.name << std::endl;
	std::cout << "Type of account : " << acc.type << std::endl;
	std::cout << "Set deposited money: " << acc.money << std::endl;
	return out;
}

std::ofstream& operator << (std::ofstream& fout, const Aleshko_account& acc)
{
	fout << acc.name << std::endl
		<< acc.type << std::endl
		<< acc.money;
	return fout;
}

