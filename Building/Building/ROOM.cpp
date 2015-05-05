// ROOM.cpp : 实现文件
//

#include "stdafx.h"
#include "Building.h"
#include "BuildingSet.h"
#include "ROOM.h"
#include "afxdialogex.h"


// ROOM 对话框

IMPLEMENT_DYNAMIC(ROOM, CDialogEx)

ROOM::ROOM(CWnd* pParent /*=NULL*/)
	: CDialogEx(ROOM::IDD, pParent)
	, broad(_T(""))
	, computer(_T(""))
	, ID(_T(""))
	, project(_T(""))
	, seat(_T(""))
{			//控件的初始化不要写在这里，当这个对象被创立时，窗口还没有创建，何谈控件？
	//变量初始化
	RoomID = "";
	NumberOfSeat = "";
	NumberOfComputer = "";
	NumberOfWhitebash = "";
	NumberOfProject = "";
}

ROOM::~ROOM()
{
}

void ROOM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, List);
	DDX_Text(pDX, IDC_EDIT_broad, broad);
	DDX_Text(pDX, IDC_EDIT_computer, computer);
	DDX_Text(pDX, IDC_EDIT_ID, ID);
	DDX_Text(pDX, IDC_EDIT_project, project);
	DDX_Text(pDX, IDC_EDIT_seat, seat);
}

BEGIN_MESSAGE_MAP(ROOM, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ROOM::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ROOM::OnBnClickedButton2)

	ON_NOTIFY(NM_CLICK, IDC_LIST1, &ROOM::OnClickList1)
END_MESSAGE_MAP()

// ROOM 消息处理程序

BOOL ROOM::OnInitDialog()				//重写的窗口初始化函数，在这里可以写一些控件的初始化
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	//窗口控件的初始化
	List.ModifyStyle(0, LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS);
	List.SetTextColor(RGB(0, 0, 0));
	List.SetBkColor(RGB(255, 255, 255));
	List.InsertColumn(0, _T("RoomID"), LVCFMT_CENTER, 60, 0);
	List.InsertColumn(1, _T("NumberOfSeat"), LVCFMT_CENTER, 100, 0);
	List.InsertColumn(2, _T("NumberOfComputer"), LVCFMT_CENTER, 140, 0);
	List.InsertColumn(3, _T("NumberOfWhitebash"), LVCFMT_CENTER, 140, 0);
	List.InsertColumn(4, _T("NumberOfProject"), LVCFMT_CENTER, 140, 0);
	//数据库连接初始化
	CString DSNname = _T("DSN=BuildingManager");
	Record = new CRecordset(&DB);
	if (DB.OpenEx(DSNname, 0)){
		if (Record->Open(CRecordset::dynaset, _T("select * from detailofroom7"), CRecordset::none)){
			MessageBox(_T("成功的与数据库建立连接"));
		}
		else{
			MessageBox(_T("没有检索到表"));
		}
	}
	else{
		MessageBox(_T("数据库连接失败"));
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void ROOM::OnBnClickedButton1()
{
	UpdateData();			//从控件更新数据到变量
	
	int index;			//创建一个列表控件的行数标记变量
	//从记录集复制数据到本地变量
	Record->MoveFirst();				//确保记录集指向第一个记录

	for (index = 0; !(Record->IsEOF()); index++){			//不断循环，  当记录集有数据的时候，isEOF方法为0，所以在前面加上！，以保证循环
		Record->GetFieldValue((short)0, RoomID);			//从记录集读取数据到变量
		Record->GetFieldValue((short)1, NumberOfSeat);
		Record->GetFieldValue((short)2, NumberOfComputer);
		Record->GetFieldValue((short)3, NumberOfWhitebash);
		Record->GetFieldValue((short)4, NumberOfProject);
		Record->MoveNext();							//记录集移动到下一条
		//定义行
		index = List.GetItemCount();//对标题进行初始化
		LV_ITEM lvitem;
		lvitem.iItem = index;
		lvitem.mask = LVFIF_TEXT;
		lvitem.iSubItem = 0;
		lvitem.pszText = (LPWSTR)(char *)(LPCTSTR)RoomID;
		//插入一行
		List.InsertItem(&lvitem);				//插入一行，
		List.SetItemText(index, 0, RoomID);				//在这个坐标的格子上，插入变量
		List.SetItemText(index, 1, NumberOfSeat);
		List.SetItemText(index, 2, NumberOfComputer);
		List.SetItemText(index, 3, NumberOfWhitebash);
		List.SetItemText(index, 4, NumberOfProject);
		//清理数据
		RoomID = "";
		NumberOfSeat = "";
		NumberOfComputer = "";
		NumberOfWhitebash = "";
		NumberOfProject = "";
	}

	UpdateData(false);				//更新数据到控件
}

void ROOM::OnBnClickedButton2()
{
	UpdateData();
	



	Record->Requery();

	UpdateData(false);
}
/*
CString exec=_T("INSERT INTO ");
CString tablename;
tablename=Record->GetTableName();
exec = exec + tablename + _T(" VALUE(\'") + ID + _T("\',\'") + seat + _T("\',\'") + computer + _T("\',\'") + broad + _T("\',\'") + project + _T("\')");
//	MessageBox(exec);
//	DB.ExecuteSQL(exec);
DB.ExecuteSQL(_T(" insert into [DetailOfRoom7] VALUE( ) "));

*/





void ROOM::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	UpdateData();

	//获取点击行数
	POSITION pos = List.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("你没有选中任何item"));
	}
	else{
		while (pos)
		{
			int line = List.GetNextSelectedItem(pos);
		}
	}

	


	*pResult = 0;
	UpdateData(false);
}
