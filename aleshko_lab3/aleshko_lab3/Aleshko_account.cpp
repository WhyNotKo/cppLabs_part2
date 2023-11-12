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

void Aleshko_account::GetLength(CDC* pDC, int* aLen)
{
	aLen[0] = pDC->GetTextExtent(name).cx;
	aLen[1] = pDC->GetTextExtent(type).cx;
	aLen[2] = pDC->GetTextExtent(to_string(money).c_str()).cx;
	aLen[3] = 0;
	aLen[4] = 0;
}

void Aleshko_account::CDCDrow(CDC* pDC, int* aLeft, int* aLen, int& top, int lineHeight)
{

	pDC->TextOut(aLeft[0], top, name);
	pDC->TextOut(aLeft[1], top, type);
	pDC->TextOut(aLeft[2], top, to_string(money).c_str());
	top += lineHeight;
	pDC->MoveTo(0, top - 4);
	pDC->LineTo(aLen[4] + 4, top - 4);
}