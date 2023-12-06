// Accone_dialog.cpp: файл реализации
//

#include "pch.h"
#include "aleshko_lab3.h"
#include "afxdialogex.h"
#include "Accone_dialog.h"


// Диалоговое окно Accone_dialog

IMPLEMENT_DYNAMIC(Accone_dialog, CDialogEx)

Accone_dialog::Accone_dialog(Caleshkolab3Doc* m_pDoc, Accs_dialog* m_pDiag, BOOL add_new, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, is_vip(FALSE)
{
	this->m_pDoc = m_pDoc;
	this->m_pDiag = m_pDiag;
	this->add_new = add_new;
}

Accone_dialog::~Accone_dialog()
{
}

BOOL Accone_dialog::OnInitDialog() {
	CDialogEx::OnInitDialog();

	if (add_new) {
		pcredit_limit.EnableWindow(FALSE);
	}

	else {

		Aleshko_account* acc = m_pDoc->accounts.GetNAcc(m_pDiag->current_index).get();

		pname.SetWindowText(acc->GetName());
		ptype.SetWindowText(acc->GetType());
		pmoney.SetWindowText(std::to_string(acc->GetMoney()).c_str());

		if (dynamic_cast<Aleshko_vip*>(acc)) {
			pcredit_limit.SetWindowText(std::to_string(dynamic_cast<Aleshko_vip*>(acc)->GetCredit()).c_str());
			CB_vip.SetCheck(TRUE);
			CB_vip.EnableWindow(FALSE);
		}

		else {
			CB_vip.SetCheck(FALSE);
			CB_vip.EnableWindow(FALSE);
			pcredit_limit.EnableWindow(FALSE);
		}
	}
	return TRUE;
}

void Accone_dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ONENAME, pname);
	DDX_Control(pDX, IDC_ONETYPE, ptype);
	DDX_Control(pDX, IDC_ONEMONEY, pmoney);
	DDX_Control(pDX, IDC_ONECREDIT, pcredit_limit);
	DDX_Control(pDX, IDC_VIP, CB_vip);
	DDX_Check(pDX, IDC_VIP, is_vip);	
}


BEGIN_MESSAGE_MAP(Accone_dialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &Accone_dialog::OnBnClickedOk)
	ON_NOTIFY(BCN_HOTITEMCHANGE, IDC_VIP, &Accone_dialog::OnBnHotItemChangeVip)
	ON_BN_CLICKED(IDC_VIP, &Accone_dialog::OnBnClickedVip)
END_MESSAGE_MAP()


// Обработчики сообщений Accone_dialog


void Accone_dialog::OnBnClickedOk()
{
	int idx;
	CDialogEx::OnOK();

	if (add_new) {
		if (is_vip)
			add_vip();
		else
			add_member();
		idx = m_pDoc->accounts.GetSize() - 1;
	}
	else {
		idx = m_pDiag->AccsList.GetCurSel();
		Aleshko_account* acc = m_pDoc->accounts.GetNAcc(idx).get();
		change_acc(acc, CB_vip.GetCheck());
	}	
	if (m_pDiag->AccsList.GetCount())
		while (m_pDiag->AccsList.DeleteString(0));
	m_pDoc->accounts.ToListMembers(m_pDiag->AccsList);
	m_pDiag->AccsList.SetCurSel(idx);
	m_pDiag->OnLbnSelchangeListacc();
}

void Accone_dialog::add_member()
{
	std::shared_ptr<Aleshko_account> pmem = std::make_shared<Aleshko_account>();

	CString name, type, money;
	GetDlgItemText(IDC_ONENAME, name);
	pmem->SetName(name);

	GetDlgItemText(IDC_ONETYPE, type);
	pmem->SetType(type);

	GetDlgItemText(IDC_ONEMONEY, money);
	pmem->SetMoney(_ttoi(money));

	m_pDoc->accounts.Add(pmem);
}

void Accone_dialog::add_vip()
{
	std::shared_ptr<Aleshko_vip> pmem = std::make_shared<Aleshko_vip>();

	CString name, type, money, credit;
	GetDlgItemText(IDC_ONENAME, name);
	pmem->SetName(name);

	GetDlgItemText(IDC_ONETYPE, type);
	pmem->SetType(type);

	GetDlgItemText(IDC_ONEMONEY, money);
	pmem->SetMoney(_ttoi(money));

	GetDlgItemText(IDC_ONECREDIT, credit);
	pmem->SetCredit(_ttoi(credit));

	m_pDoc->accounts.Addvip(pmem);
}

void Accone_dialog::change_acc(Aleshko_account* acc, BOOL is_v)
{
	CString name, type, money;
	GetDlgItemText(IDC_ONENAME, name);
	acc->SetName(name);

	GetDlgItemText(IDC_ONETYPE, type);
	acc->SetType(type);

	GetDlgItemText(IDC_ONEMONEY, money);
	acc->SetMoney(_ttoi(money));

	if (is_v) {
		CString credit;
		GetDlgItemText(IDC_ONECREDIT, credit);
		dynamic_cast<Aleshko_vip*>(acc)->SetCredit(_ttoi(credit));
	}
}


void Accone_dialog::OnBnHotItemChangeVip(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMBCHOTITEM pHotItem = reinterpret_cast<LPNMBCHOTITEM>(pNMHDR);
	pcredit_limit.EnableWindow(CB_vip.GetCheck());
	*pResult = 0;
}


void Accone_dialog::OnBnClickedVip()
{
	// TODO: добавьте свой код обработчика уведомлений
	pcredit_limit.EnableWindow(CB_vip.GetCheck());
}
