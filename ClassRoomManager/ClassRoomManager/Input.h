#pragma once


// Input �Ի���

class Input : public CDialogEx
{
	DECLARE_DYNAMIC(Input)

public:
	Input(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Input();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long borad;
	long computer;
	long ID;
	long project;
	long seat;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
