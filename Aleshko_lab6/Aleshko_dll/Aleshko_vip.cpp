#include "pch.h"
#include "Aleshko_vip.h"

IMPLEMENT_SERIAL(Aleshko_vip, Aleshko_account,VERSIONABLE_SCHEMA | 0)

Aleshko_vip::Aleshko_vip(std::string name, std::string type, int money, int credit)
    :Aleshko_account(name, type, money), credit_limit(credit)
{
}

void Aleshko_vip::Serialize(CArchive& ar) {

	Aleshko_account::Serialize(ar);

	if (ar.IsStoring()) {
		ar << credit_limit;
	}
	else {
        ar >> credit_limit;

	}
}

bool Aleshko_vip::isVIP()
{
    return true;
}
