#pragma once
#include "afxcmn.h"


// ROOM 对话框

class ROOM : public CDialogEx
{
	DECLARE_DYNAMIC(ROOM)

public:
	ROOM(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ROOM();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
public:
	
	CDatabase DB;		//新建一个数据库对象
	CRecordset *Record;		//新建一个记录集指针对象
	CListCtrl List;	//列表控件的对象

	//承接从数据库得到的数据的变量
	CString RoomID;  //	教室的编号  （主键）
	CString NumberOfSeat;  //	座位的个数
	CString NumberOfComputer;  //		计算机的个数
	CString NumberOfWhitebash;  //		白板的个数
	CString NumberOfProject;  //		投影仪的个数
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();		
	afx_msg void OnBnClickedButton2();

	CString broad;		//控件的变量
	CString computer;
	CString ID;
	CString project;
	CString seat;
//	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
