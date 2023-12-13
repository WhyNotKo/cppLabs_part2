#pragma once
#include"Aleshko_account.h"

class Aleshko_vip:
    public Aleshko_account
{
public:
    int credit_limit = 0;

	DECLARE_SERIAL(Aleshko_vip)
	Aleshko_vip(std::string, std::string, int, int);
	Aleshko_vip() : Aleshko_account() {}

	virtual ~Aleshko_vip() {};

	virtual void Serialize(CArchive& ar) override;

	virtual bool isVIP() override;
};

