#include "pch.h"
#include "Aleshko_vip.h"

using namespace std;

IMPLEMENT_SERIAL(Aleshko_vip, Aleshko_account, VERSIONABLE_SCHEMA | 0)

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
	aLen[3] = pDC->GetTextExtent(to_string(credit_limit).c_str()).cx;
	
}

void Aleshko_vip::CDCDrow(CDC* pDC, int* aLeft, int* aLen, int& top, int lineHeight)
{


	pDC->TextOut(aLeft[3], top, to_string(credit_limit).c_str());
	Aleshko_account::CDCDrow(pDC, aLeft, aLen, top, lineHeight);

}