#pragma once
#include<vector>
#include"Aleshko_account.h"
#include"Aleshko_vip.h"

class Aleshko_bank
{
public:
    std::vector<std::shared_ptr<Aleshko_account>> accounts;

    void push(std::shared_ptr<Aleshko_account>);
    void clear();
    void WriteToFile(CArchive&) const;
    void ReadFromFile(CArchive&);

};

