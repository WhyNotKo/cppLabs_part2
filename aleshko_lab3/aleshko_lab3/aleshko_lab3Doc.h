﻿
// aleshko_lab3Doc.h: интерфейс класса Caleshkolab3Doc 
//


#include "Aleshko_bank.h"
#pragma once

class Caleshkolab3Doc : public CDocument
{
protected: // создать только из сериализации
	Caleshkolab3Doc() noexcept;
	DECLARE_DYNCREATE(Caleshkolab3Doc)

// Атрибуты
public:
	Aleshko_bank accounts;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~Caleshkolab3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

public:
	afx_msg void OnEditSssdialog();
	afx_msg void OnEditDialog();
};
