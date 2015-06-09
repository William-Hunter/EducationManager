#pragma once
#include "afxcmn.h"
#include "ClassRoomManagerSet.h"
#include "ExChange.h"

// Room �Ի���

class Room : public CDialogEx
{
	DECLARE_DYNAMIC(Room)

public:
	Room(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Room();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	CClassRoomManagerSet *Record;			//��̬������
	//���������ݿ⸳ֵ���ؼ��ϵı���
	CString RoomID;
	CString NumberOfSeat;
	CString NumberOfComputer;
	CString NumberOfWhitebash;
	CString NumberOfProject;
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
