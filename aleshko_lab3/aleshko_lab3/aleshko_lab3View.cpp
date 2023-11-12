
// aleshko_lab3View.cpp: реализация класса Caleshkolab3View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "aleshko_lab3.h"
#endif

#include "aleshko_lab3Doc.h"
#include "aleshko_lab3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Caleshkolab3View

IMPLEMENT_DYNCREATE(Caleshkolab3View, CScrollView)

BEGIN_MESSAGE_MAP(Caleshkolab3View, CScrollView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Создание или уничтожение Caleshkolab3View

Caleshkolab3View::Caleshkolab3View() noexcept
{
	// TODO: добавьте код создания

}

Caleshkolab3View::~Caleshkolab3View()
{
}

BOOL Caleshkolab3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование Caleshkolab3View

void Caleshkolab3View::OnDraw(CDC* /*pDC*/)
{
	Caleshkolab3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}

void Caleshkolab3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика Caleshkolab3View

#ifdef _DEBUG
void Caleshkolab3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Caleshkolab3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Caleshkolab3Doc* Caleshkolab3View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Caleshkolab3Doc)));
	return (Caleshkolab3Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений Caleshkolab3View


//void Caleshkolab3View::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	//CWindowDC dc(this);
//	//CString s;
//	//s.Format(_T("[%d, %d]", point.x, point.y);
//	//dc.TextOut(point.x, point.y, s);
//	//CScrollView::OnLButtonDown(nFlags, point);
//}
	