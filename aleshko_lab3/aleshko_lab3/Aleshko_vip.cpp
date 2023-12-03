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


void Aleshko_vip::CDCDraw(CDC* pDC, int* aLeft, vector<int> aLen, int& top, int lineHeight)
{


	pDC->TextOut(aLeft[3], top, to_string(credit_limit).c_str());
	Aleshko_account::CDCDraw(pDC, aLeft, aLen, top, lineHeight);

}

unsigned int Aleshko_vip::GetCredit()
{
	return this->credit_limit;
}

void Aleshko_vip::SetCredit(unsigned int credit)
{
	this->credit_limit = credit;
}


