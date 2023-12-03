#pragma once
#include "Aleshko_account.h"
class Aleshko_vip :
	public Aleshko_account
{
protected:
	unsigned int credit_limit = 0;
public:
	DECLARE_SERIAL(Aleshko_vip)
	Aleshko_vip() {};

	virtual ~Aleshko_vip() {};

	void Serialize(CArchive& ar);

	void CDCDraw(CDC* pDC, int* aLeft, std::vector<int> aLen, int& top, int lineHeight);

	unsigned int GetCredit();

	void SetCredit(unsigned int credit);
};