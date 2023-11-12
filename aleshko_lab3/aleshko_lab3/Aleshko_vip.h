#pragma once
#include "Aleshko_account.h"
class Aleshko_vip :
	public Aleshko_account
{
protected:
	int credit_limit = 0;
public:
	DECLARE_SERIAL(Aleshko_vip)
	Aleshko_vip() {};

	virtual ~Aleshko_vip() {};

	//void input() override;

	//void output() override;

	void Serialize(CArchive& ar);

	void GetLength(CDC* pDC, int* aLen);

	void CDCDrow(CDC* pDC, int* aLeft, int* aLen, int& top, int lineHeight);

};