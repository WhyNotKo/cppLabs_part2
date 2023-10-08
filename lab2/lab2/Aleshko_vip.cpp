#include "pch.h"
#include "Aleshko_vip.h"

IMPLEMENT_SERIAL(Aleshko_vip, Aleshko_account,VERSIONABLE_SCHEMA | 0)

void Aleshko_vip::input() {

    Aleshko_account::input();
    std::cout << "¬ведите кредитный лимит: ";
    credit_limit = GetCorrectNumber(0);
}


void Aleshko_vip::output() {
    std::cout << std::endl;
    std::cout << "VIP" << std::endl;
    Aleshko_account::output();
    std::cout << " редитный лимит: "
        << credit_limit << std::endl<< std::endl;
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