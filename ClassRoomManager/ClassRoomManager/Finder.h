#pragma once


// Finder �Ի���

class Finder : public CDialogEx
{
	DECLARE_DYNAMIC(Finder)

public:
	Finder(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Finder();

// �Ի�������
	enum { IDD = IDD_DIALOG_Found };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedsearch();
	long FindBorad;
	long FindComputer;
	long FindProject;
	long FindSeat;
};
