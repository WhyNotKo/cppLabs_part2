#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include <afx.h>

#include "pch.h"


class Aleshko_account: public CObject
{
public:
	CString name;
	CString type;
	int money;

	DECLARE_SERIAL(Aleshko_account)
	
	Aleshko_account(const std::string name, const std::string type, int money);
	Aleshko_account() = default;

	virtual ~Aleshko_account() {}

	virtual void Serialize(CArchive& ar) override;

	virtual bool isVIP();
};

