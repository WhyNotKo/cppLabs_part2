#pragma once
#include "afxdialogex.h"
#include "Accs_dialog.h"
#include "aleshko_lab3Doc.h"


// Диалоговое окно Accone_dialog
class Accone_dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Accone_dialog)


public:
	Accone_dialog(Caleshkolab3Doc* m_pDoc, Accs_dialog* m_pDiag, BOOL add_new, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~Accone_dialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	Caleshkolab3Doc* m_pDoc;
	Accs_dialog* m_pDiag;
	BOOL OnInitDialog();

	BOOL is_vip;
	BOOL add_new;

	CEdit pname;
	CEdit ptype;
	CEdit pmoney;
	CEdit pcredit_limit;
	afx_msg void OnBnClickedOk();
	CButton CB_vip;

	void add_member();
	void add_vip();
	void change_acc(Aleshko_account* acc, BOOL is_v);
	afx_msg void OnBnHotItemChangeVip(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedVip();
};
