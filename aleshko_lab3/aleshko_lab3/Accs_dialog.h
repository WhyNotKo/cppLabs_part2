#pragma once
#include "afxdialogex.h"
#include "aleshko_lab3Doc.h"


class Caleshkolab3Doc;

// Диалоговое окно Accs_dialog

class Accs_dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Accs_dialog)
	Caleshkolab3Doc* m_pDoc;

public:
	Accs_dialog(Caleshkolab3Doc* m_pDoc, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~Accs_dialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnInitDialog();

	CListBox AccsList;
	CEdit type;
	CEdit name;
	CEdit money;
	CEdit credit_limit;
	CStatic limit_txt;
	int current_index = -1;

	afx_msg void OnBnClickedAddclient();
	afx_msg void OnBnClickedChangeacc();
	afx_msg void OnBnClickedDeleteacc();

	void show_data(int index);
	afx_msg void OnLbnSelchangeListacc();
};
