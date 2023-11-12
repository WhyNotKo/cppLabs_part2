#include "pch.h"
#include "Aleshko_bank.h"


void Aleshko_bank::Load(CArchive& ar)
{
	int size;
	ar >> size;
	for (size_t i = 0; i < size; i++) {
		Aleshko_account* acc;
		ar >> acc;
		std::shared_ptr<Aleshko_account> newacc_shared(acc);
		accounts.push_back(newacc_shared);
	}
}

void Aleshko_bank::Save(CArchive& ar)
{


	ar << (int)accounts.size();
	for (auto& acc : accounts) {
		ar << acc.get();
	}
	std::cout << "Successful" << std::endl;
}

CSize Aleshko_bank::DrawTable(CDC* pDC)
{
	const int indent = 5;
	const int HorSpace = 15;
	const int LineHeight = 30;

	CString aHead[5];
	aHead[0] = "ФИО";
	aHead[1] = "Тип счёта";
	aHead[2] = "Кол-во средств";
	aHead[3] = "Вип";
	aHead[4] = "Кредитный лимит";


	int aLen[5];
	for (int i = 0; i < 5; ++i)
		aLen[i] = pDC->GetTextExtent(aHead[i]).cx;


	for (auto& prod : accounts)
	{
		int memLen[5];
		prod->GetLength(pDC, memLen);
		for (int i = 0; i < 5; ++i)
			if (memLen[i] > aLen[i])
				aLen[i] = memLen[i];
	}


	aLen[0] += indent;
	for (int i = 1; i < 5; ++i)
	{
		aLen[i - 1] += HorSpace;
		aLen[i] += aLen[i - 1];
	}

	int aLeft[5];
	aLeft[0] = indent;
	for (int i = 1; i < 5; ++i)
		aLeft[i] = aLen[i - 1];


	int top = indent;
	for (int i = 0; i < 5; ++i)
	{
		pDC->TextOutA(aLeft[i], top, aHead[i]);
	}
	top += LineHeight;


	for_each(accounts.begin(), accounts.end(), bind(&Aleshko_account::CDCDrow, placeholders::_1, pDC, aLeft, aLen, ref(top), LineHeight));

	POINT sizeAll;
	sizeAll.x = aLen[5] + indent;
	sizeAll.y = top;

	pDC->MoveTo(0, 0);
	pDC->LineTo(sizeAll.x, 0);
	pDC->LineTo(sizeAll);
	pDC->LineTo(0, sizeAll.y);
	pDC->LineTo(0, 0);

	for (int i = 1; i < 5; ++i)
	{
		pDC->MoveTo(aLeft[i] - HorSpace / 2, 0);
		pDC->LineTo(aLeft[i] - HorSpace / 2, sizeAll.y);
	}
	pDC->MoveTo(0, indent + LineHeight - 4);
	pDC->LineTo(sizeAll.x, indent + LineHeight - 4);

	return sizeAll;
}

void Aleshko_bank::Clear()
{
	accounts.clear();
}
