#pragma once
#include "afxcmn.h"
#include "ClassRoomManagerSet.h"


// Display 对话框

class Display : public CDialogEx
{
	DECLARE_DYNAMIC(Display)

public:
	Display(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Display();

// 对话框数据
	enum { IDD = IDD_DIALOG_display };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl List;
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CDatabase DB;
	CClassRoomManagerSet *Record;
	//显示控件使用的变量
	CString RoomID;
	CString NumberOfSeat;
	CString NumberOfComputer;
	CString NumberOfWhitebash;
	CString NumberOfProject;
};
