#pragma once


// Finder 对话框

class Finder : public CDialogEx
{
	DECLARE_DYNAMIC(Finder)

public:
	Finder(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Finder();

// 对话框数据
	enum { IDD = IDD_DIALOG_Found };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedsearch();
	long FindBorad;
	long FindComputer;
	long FindProject;
	long FindSeat;
};
