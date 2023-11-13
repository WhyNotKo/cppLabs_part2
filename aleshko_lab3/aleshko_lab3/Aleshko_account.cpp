#include "pch.h"
#include "Aleshko_account.h"

using namespace std;

IMPLEMENT_SERIAL(Aleshko_account, CObject, 0)

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

void Aleshko_account::GetLength(CDC* pDC, int* mesLen)
{
	mesLen[0] = pDC->GetTextExtent(name).cx;
	mesLen[1] = pDC->GetTextExtent(type).cx;
	mesLen[2] = pDC->GetTextExtent(to_string(money).c_str()).cx;
	mesLen[3] = 0;
}

void Aleshko_account::CDCDrow(CDC* pDC, int* aLeft, int* aLen, int& top, int lineHeight)
{

	pDC->TextOutA(aLeft[0], top, name);
	pDC->TextOutA(aLeft[1], top, type);
	pDC->TextOutA(aLeft[2], top, to_string(money).c_str());
	top += lineHeight;
	pDC->MoveTo(0, top - 5);
	pDC->LineTo(aLen[3] + 5, top - 5);
}