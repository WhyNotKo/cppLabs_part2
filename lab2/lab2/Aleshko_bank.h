#pragma once
#include<vector>
#include"Aleshko_account.h"
#include"Aleshko_vip.h"

class Aleshko_bank
{
private:
    std::vector<std::shared_ptr<Aleshko_account>> accounts;

public:

    void addAccount();

    void addVIP();

    void displayAllAccounts() const;

    void clear();

    void loadAllAccounts(const CString& filename);

    void saveAllAccounts(const CString& filename);

};

