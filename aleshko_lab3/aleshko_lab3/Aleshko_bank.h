#pragma once
#include"Aleshko_vip.h"
class Aleshko_bank
{
private:
    std::vector<std::shared_ptr<Aleshko_account>> accounts;

public:

    //void addAccount();

    //void addVIP();

    //void displayAllAccounts() const;

    void Load(CArchive& ar);

    void Save(CArchive& ar);

    CSize DrawTable(CDC* pDC);

    void Clear();

};

