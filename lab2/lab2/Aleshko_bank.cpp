#include "pch.h"
#include "Aleshko_bank.h"
#include "Aleshko_account.h"
#include "Aleshko_vip.h"




void Aleshko_bank::addAccount()
{
    
    std::shared_ptr <Aleshko_account> account = std::make_shared<Aleshko_account>();
    account->input();
    accounts.push_back(account);
}
void Aleshko_bank::displayAllAccounts() const {
    if (accounts.size())
    {
        std::cout << "Все счета банка:" << std::endl << std::endl;
        for (auto &account : accounts) {
            account.get()->output();
        }
    }
    else
    {
        std::cout << "\nУ банка нет клиентов..." << std::endl;
    }

}



void Aleshko_bank::saveAllAccounts(const CString& filename)
{
    CFile f;
    f.Open("data.dat", CFile::modeCreate | CFile::modeWrite);
    CArchive ar(&f, CArchive::store);

    ar << accounts.size();
    for (auto acc : accounts) {
        ar << acc.get();
    }

    ar.Close();
    f.Close();
}

void Aleshko_bank::loadAllAccounts(const CString& filename)
{
    accounts.clear();

    CFile f;
    f.Open("data", CFile::modeRead);
    CArchive ar(&f, CArchive::load);

    int size = 0;
    ar >> size;

    for (int i = 0; i < size; i++) {
        Aleshko_account* acc;
        ar >> acc;
        std::shared_ptr<Aleshko_account> account(acc);
        accounts.push_back(account);
    }
    ar.Close();
    f.Close();
}

void Aleshko_bank::clear() {
    accounts.clear();
}

void Aleshko_bank::addVIP() {
    std::shared_ptr <Aleshko_vip> account = std::make_shared<Aleshko_vip>();
    account->input();
    accounts.push_back(account);
}