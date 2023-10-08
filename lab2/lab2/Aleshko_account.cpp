#include "pch.h"
#include "Aleshko_account.h"

IMPLEMENT_SERIAL(Aleshko_account, CObject, 0)

void Aleshko_account::input()
{
	std::string name, type;
	std::cout << "Введите ФИО клиента: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	this->name = name.c_str();
	std::cout << "Тип счёта: ";
	std::getline(std::cin, type);
	this->type = type.c_str();
	std::cout << "Колличество денег: ";
	this->money = GetCorrectNumber(0);
}


//std::ifstream& operator >> (std::ifstream& fin, Aleshko_account& acc)
//{
//	fin.ignore();
//
//	std::getline(fin, acc.name);
//	std::getline(fin, acc.type);
//	fin >> acc.money;
//
//	return fin;
//}


void Aleshko_account::output()
{
	std::cout << "Клиентt: " << this->name << std::endl;
	std::cout << "Тип счёта : " << this->type << std::endl;
	std::cout << "Средства на счёте: " << this->money << std::endl;
}

//std::ofstream& operator << (std::ofstream& fout, const Aleshko_account& acc)
//{
//	fout << acc.name << std::endl
//		<< acc.type << std::endl
//		<< acc.money;
//	return fout;
//}

void Aleshko_account::Serialize(CArchive& ar) {

	if (ar.IsStoring()) {
		ar << name
			<< type
			<< money;
	}
	else {
		ar >> name
			>> type
			>> money;

	}
}

