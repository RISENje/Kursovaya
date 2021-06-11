#pragma once
#include "KursovayaDlg.h"

// Диалоговое окно CStartupDlg

class CStartupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStartupDlg)

public:
	CStartupDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CStartupDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGMenu };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	CKursovayaDlg* dlgParent;
	BOOL AIPlayerOn;
public:
	CString FPlayerName;
	CString SPlayerName;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedStartbutton();
	void SetDlgParent(CKursovayaDlg* p);
};
