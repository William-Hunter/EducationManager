#pragma once
#include "afxcmn.h"
#include "ClassRoomManagerSet.h"


// Display �Ի���

class Display : public CDialogEx
{
	DECLARE_DYNAMIC(Display)

public:
	Display(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Display();

// �Ի�������
	enum { IDD = IDD_DIALOG_display };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl List;
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CDatabase DB;
	CClassRoomManagerSet *Record;
	//��ʾ�ؼ�ʹ�õı���
	CString RoomID;
	CString NumberOfSeat;
	CString NumberOfComputer;
	CString NumberOfWhitebash;
	CString NumberOfProject;
};
