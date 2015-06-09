#pragma once
#include "afxcmn.h"
#include "ClassRoomManagerSet.h"
#include "ExChange.h"

// Room 对话框

class Room : public CDialogEx
{
	DECLARE_DYNAMIC(Room)

public:
	Room(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Room();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtondisplay();
	afx_msg void OnBnClickedButtoninsert();
	afx_msg void OnBnClickedButtonchange();
	afx_msg void OnBnClickedButtondelete();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CListCtrl List;
	CDatabase DB;
	CClassRoomManagerSet *Record;			//动态集对象
	//用来从数据库赋值到控件上的变量
	CString RoomID;
	CString NumberOfSeat;
	CString NumberOfComputer;
	CString NumberOfWhitebash;
	CString NumberOfProject;
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
