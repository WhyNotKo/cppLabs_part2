#include "pch.h"
#include "Aleshko_vip.h"

using namespace std;

void Aleshko_vip::Serialize(CArchive& ar) {

	Aleshko_account::Serialize(ar);

	if (ar.IsStoring()) {
		ar << credit_limit;
	}
	else {
		ar >> credit_limit;

	}
}

void Aleshko_vip::GetLength(CDC* pDC, int* aLen)
{
	Aleshko_account::GetLength(pDC, aLen);
	aLen[4] = pDC->GetTextExtent(to_string(credit_limit).c_str()).cx;
	
}

void Aleshko_vip::CDCDrow(CDC* pDC, int* aLeft, int* aLen, int& top, int lineHeight)
{


	pDC->TextOut(aLeft[4], top, to_string(credit_limit).c_str());
	Aleshko_account::CDCDrow(pDC, aLeft, aLen, top, lineHeight);

}