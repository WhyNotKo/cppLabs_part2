#pragma once
#include"framework.h"


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

class Aleshko_account : public CObject
{
protected:
	CString name;
	CString type;
	int money;

public:
	DECLARE_SERIAL(Aleshko_account)

	Aleshko_account() {}

	virtual ~Aleshko_account() {}

	//virtual void input();

	//virtual void output();

	virtual void Serialize(CArchive& ar);

	virtual void GetLength(CDC* pDC, int* aLen);

	virtual void CDCDrow(CDC* pDC, int* aLeft, int* aLen, int& top, int lineHeight);


};


