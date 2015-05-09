#pragma once
#include "afxcmn.h"
#include "ClassRoomManagerSet.h"

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
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtoncontect();
	afx_msg void OnBnClickedButtoninsert();
	afx_msg void OnBnClickedButtondelete();
	CListCtrl List;
	long broad;
	long computer;
	long ID;
	long project;
	long seat;
	CString RoomID;
	CString NumberOfSeat;
	CString NumberOfComputer;
	CString NumberOfWhitebash;
	CString NumberOfProject;
	CDatabase DB;
	CClassRoomManagerSet *Record;			//动态集对象
};
