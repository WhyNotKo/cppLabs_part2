#include "pch.h"
#include "Aleshko_bank.h"

using namespace std;

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
}

CSize Aleshko_bank::DrawTable(CDC* pDC)
{
	const int indent = 5;
	const int Linered = 20;
	const int LineHeight = 35;

	CString aHead[4];
	aHead[0] = "ФИО";
	aHead[1] = "Тип счёта";
	aHead[2] = "Кол-во средств";
	aHead[3] = "Кредитный лимит";


	vector<int> aLen{ 0, 0, 0, 0 };
	for (int i = 0; i < 4; ++i)
		aLen[i] = pDC->GetTextExtent(aHead[i]).cx;


	for (auto acc : accounts)
	{
		vector <int> memLen = {0, 0, 0, 0};
		acc->GetLength(pDC, memLen);
		for (int i = 0; i < 4; ++i)
		{
			if (memLen[i] > aLen[i])
			{
				aLen[i] = memLen[i];
			}
		}
	}


	aLen[0] += indent;
	for (int i = 1; i < 4; ++i)
	{
		aLen[i - 1] += Linered;
		aLen[i] += aLen[i - 1];
	}

	int aLeft[4];
	aLeft[0] = indent;
	for (int i = 1; i < 4; ++i)
		aLeft[i] = aLen[i - 1];


	int top = indent;
	for (int i = 0; i < 4; ++i)
	{
		pDC->TextOut(aLeft[i], top, aHead[i]);
	}
	top += LineHeight;


	for_each(accounts.begin(), accounts.end(), bind(&Aleshko_account::CDCDraw, placeholders::_1, pDC, aLeft, aLen, ref(top), LineHeight));

	POINT sizeAll;
	sizeAll.x = aLen[3] + indent;
	sizeAll.y = top - indent;

	pDC->MoveTo(0, 0);
	pDC->LineTo(sizeAll.x, 0);
	pDC->LineTo(sizeAll);
	pDC->MoveTo(0, sizeAll.y);
	pDC->LineTo(0, 0);

	for (int i = 1; i < 4; ++i)
	{
		pDC->MoveTo(aLeft[i] - Linered / 2, 0);
		pDC->LineTo(aLeft[i] - Linered / 2, sizeAll.y);
	}
	pDC->MoveTo(0, LineHeight);
	pDC->LineTo(sizeAll.x, LineHeight);

	return sizeAll;
}

void Aleshko_bank::Clear()
{
	accounts.clear();
}
