#pragma once
#include<iostream>
#include<fstream>
#include<string>


template <typename T>
T GetCorrectNumber(T min = 0, T max = 10000000)
{
	T x{};
	while (((std::cin >> x) || x<min || x>max) && (std::cin.peek() != EOF && std::cin.peek() != '\n'))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Enter the correct number... " << std::endl;
	}
	return x;
}

class Aleshko_account: public CObject
{
protected:
	CString name;
	CString type;
	int money;

public:
	DECLARE_SERIAL(Aleshko_account)
	/*Aleshko_account(const std::string& name, const std::string& type, long int money)
	{
		this->name = name;
		this->type = type;
		this->money = money;
	}*/

	Aleshko_account() {}

	virtual ~Aleshko_account() {}

	virtual void input();
	
	virtual void output();

	virtual void Serialize(CArchive& ar);

	//friend std::istream& operator >> (std::istream& in, Aleshko_account& acc);

	//friend std::ifstream& operator >> (std::ifstream& fin, Aleshko_account& acc);

	//friend std::ostream& operator << (std::ostream& out, const Aleshko_account& acc);

	//friend std::ofstream& operator << (std::ofstream& fout, const Aleshko_account& acc);
};

