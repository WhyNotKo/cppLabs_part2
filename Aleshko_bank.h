#pragma once
#include<string>
#include<vector>
#include<iostream>
#include "Aleshko_account.h"

class Aleshko_bank
{
private:
    std::vector<Aleshko_account*> accounts;

public:
        
    void createAccount();

    void displayAllAccounts() const;

    ~Aleshko_bank() {
        for (Aleshko_account* account : accounts) {
            delete account;
        }
    }

    void loadAllAccounts();

    void saveAllAccounts();

};

