#pragma once
#include"Aleshko_account.h"

class Aleshko_vip:
    public Aleshko_account
{
protected:
    int credit_limit = 0;
public:
	DECLARE_SERIAL(Aleshko_vip)
	Aleshko_vip() {};

	virtual ~Aleshko_vip() {};

	void input() override;

	void output() override;

	virtual void Serialize(CArchive& ar);

	/*friend std::ostream& operator << (std::ostream& out, const Aleshko_vip& vip);

	friend std::ofstream& operator << (std::ofstream& fout, const Aleshko_vip& vip);*/
};

