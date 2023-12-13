#include "pch.h"
#include "Aleshko_bank.h"
#include "Aleshko_account.h"
#include "Aleshko_vip.h"



void Aleshko_bank::push(std::shared_ptr<Aleshko_account> acc)
{
    accounts.push_back(acc);
}



void Aleshko_bank::clear() {
    accounts.clear();
}

void Aleshko_bank::WriteToFile(CArchive& ar) const
{
    ar << (int)accounts.size();
    for (const auto& acc : accounts) {
        ar << acc.get();
    }
}

void Aleshko_bank::ReadFromFile(CArchive& ar)
{
    int n;
    Aleshko_account* acc;
    ar >> n;
    for (int i = 0; i < n; ++i) {
        ar >> acc;
        push(std::shared_ptr<Aleshko_account>(acc));
    }
}
