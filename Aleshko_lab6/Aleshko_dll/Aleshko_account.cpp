#include "pch.h"
#include "Aleshko_account.h"

IMPLEMENT_SERIAL(Aleshko_account, CObject, 0)

Aleshko_account::Aleshko_account(const std::string name, const std::string type, int money)
	:name(name.c_str()), type(type.c_str()), money(money){
}

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

bool Aleshko_account::isVIP()
{
	return false;
}

