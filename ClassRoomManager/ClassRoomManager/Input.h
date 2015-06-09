#pragma once


// Input 对话框

class Input : public CDialogEx
{
	DECLARE_DYNAMIC(Input)

public:
	Input(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Input();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
