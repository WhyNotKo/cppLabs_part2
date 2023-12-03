
// aleshko_lab3View.h: интерфейс класса Caleshkolab3View
//

#pragma once


class Caleshkolab3View : public CScrollView
{
protected: // создать только из сериализации
	Caleshkolab3View() noexcept;
	DECLARE_DYNCREATE(Caleshkolab3View)

// Атрибуты
public:
	Caleshkolab3Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~Caleshkolab3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в aleshko_lab3View.cpp
inline Caleshkolab3Doc* Caleshkolab3View::GetDocument() const
   { return reinterpret_cast<Caleshkolab3Doc*>(m_pDocument); }
#endif

