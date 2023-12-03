#pragma once
#include"Aleshko_vip.h"
class Aleshko_bank
{
private:
    std::vector<std::shared_ptr<Aleshko_account>> accounts;

public:

    void Load(CArchive& ar);

    void Add(std::shared_ptr<Aleshko_account> ptr);

    void Addvip(std::shared_ptr<Aleshko_vip> ptr);

    void Save(CArchive& ar);

    CSize DrawTable(CDC* pDC);

    void Clear();

    void Erase(int n);

    void ToListMembers(CListBox& list);

    size_t GetSize();

    std::shared_ptr<Aleshko_account> GetNAcc(int index);

};

