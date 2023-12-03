// Accs_dialog.cpp: файл реализации
//

#include "pch.h"
#include "aleshko_lab3.h"
#include "afxdialogex.h"
#include "Accs_dialog.h"
#include "Accone_dialog.h"


// Диалоговое окно Accs_dialog

IMPLEMENT_DYNAMIC(Accs_dialog, CDialogEx)

Accs_dialog::Accs_dialog(Caleshkolab3Doc* m_pDoc, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	this->m_pDoc = m_pDoc;
}

Accs_dialog::~Accs_dialog()
{
}

void Accs_dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTACC, AccsList);
	DDX_Control(pDX, IDC_ACCTYPE, type);
	DDX_Control(pDX, IDC_ACCNAME, name);
	DDX_Control(pDX, IDC_ACCMONEY, money);
	DDX_Control(pDX, IDC_ACCLIMIT, credit_limit);
	DDX_Control(pDX, IDC_STATIC_var, limit_txt);
}


BEGIN_MESSAGE_MAP(Accs_dialog, CDialogEx)
	ON_BN_CLICKED(IDC_ADDCLIENT, &Accs_dialog::OnBnClickedAddclient)
	ON_BN_CLICKED(IDC_CHANGEACC, &Accs_dialog::OnBnClickedChangeacc)
	ON_BN_CLICKED(IDC_DELETEACC, &Accs_dialog::OnBnClickedDeleteacc)
	ON_LBN_SELCHANGE(IDC_LISTACC, &Accs_dialog::OnLbnSelchangeListacc)
END_MESSAGE_MAP()

BOOL Accs_dialog::OnInitDialog() {
	CDialogEx::OnInitDialog();

	if (!m_pDoc->accounts.GetSize() == 0) {
		m_pDoc->accounts.ToListMembers(AccsList);
		OnLbnSelchangeListacc();
	}
	//OnBnClickedShowTitlesCheck();
	return TRUE;
}

// Обработчики сообщений Accs_dialog


void Accs_dialog::OnBnClickedAddclient()
{
	// TODO: добавьте свой код обработчика уведомлений
	Accone_dialog dlg(m_pDoc, this, TRUE);
	dlg.DoModal();
	m_pDoc->UpdateAllViews(NULL);
	m_pDoc->SetModifiedFlag();
}


void Accs_dialog::OnBnClickedChangeacc()
{
	// TODO: добавьте свой код обработчика уведомлений
	Accone_dialog dlg(m_pDoc, this, FALSE);
	dlg.DoModal();
	m_pDoc->UpdateAllViews(NULL);
	m_pDoc->SetModifiedFlag();
}


void Accs_dialog::OnBnClickedDeleteacc()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (current_index != -1) {
		m_pDoc->accounts.Erase(current_index);
		if (AccsList.GetCount() != 0)
		{
			while (AccsList.DeleteString(0));
			m_pDoc->accounts.ToListMembers(AccsList);
			int last = m_pDoc->accounts.GetSize() - 1;
			if (current_index > last)
				current_index = last;
			if (AccsList.GetCount() != 0)
			{
				AccsList.SetCurSel(current_index);
				OnLbnSelchangeListacc();
			}
			else
			{
				name.SetWindowText(_T(""));
				type.SetWindowText(_T(""));
				money.SetWindowText(_T(""));
				credit_limit.SetWindowText(_T(""));
			}
		}
		m_pDoc->SetModifiedFlag();
	}
}

void Accs_dialog::show_data(int index)
{
	Aleshko_account* mem = m_pDoc->accounts.GetNAcc(index).get();

	name.SetWindowText(mem->GetName());
	type.SetWindowText(mem->GetType());
	money.SetWindowText(std::to_string(mem->GetMoney()).c_str());

	if (dynamic_cast<Aleshko_vip*>(mem))
	{
		credit_limit.SetWindowText(
			std::to_string(dynamic_cast<Aleshko_vip*>(mem)->GetCredit()).c_str()
		);
	}
	else
	{
		credit_limit.SetWindowText(_T(""));
	}

}


void Accs_dialog::OnLbnSelchangeListacc()
{
	// TODO: добавьте свой код обработчика уведомлений

	current_index = AccsList.GetCurSel();
	if (current_index < 0)
		return;

	show_data(current_index);
}
