// Room.cpp : 实现文件
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "ClassRoomManagerSet.h"
#include "Room.h"
#include "afxdialogex.h"


// Room 对话框

IMPLEMENT_DYNAMIC(Room, CDialogEx)

Room::Room(CWnd* pParent /*=NULL*/)
	: CDialogEx(Room::IDD, pParent)
	, broad(0)
	, computer(0)
	, ID(0)
	, project(0)
	, seat(0)
{

}

Room::~Room()
{
}

void Room::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, List);
	DDX_Text(pDX, IDC_EDIT_broad, broad);
	DDX_Text(pDX, IDC_EDIT_computer, computer);
	DDX_Text(pDX, IDC_EDIT_ID, ID);
	DDX_Text(pDX, IDC_EDIT_project, project);
	DDX_Text(pDX, IDC_EDIT_seat, seat);
}


BEGIN_MESSAGE_MAP(Room, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_contect, &Room::OnBnClickedButtoncontect)
	ON_BN_CLICKED(IDC_BUTTON_insert, &Room::OnBnClickedButtoninsert)
	ON_BN_CLICKED(IDC_BUTTON_delete, &Room::OnBnClickedButtondelete)
	ON_BN_CLICKED(IDC_BUTTON_change, &Room::OnBnClickedButtonchange)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &Room::OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON_clean, &Room::OnBnClickedButtonclean)
END_MESSAGE_MAP()


// Room 消息处理程序


BOOL Room::OnInitDialog()				//初始化的虚函数
{
	CDialogEx::OnInitDialog();
	//对于变量进行初始化赋值
	RoomID = "";
	NumberOfSeat = "";
	NumberOfComputer = "";
	NumberOfWhitebash = "";
	NumberOfProject = "";
	//窗口控件的初始化
	List.ModifyStyle(0, LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS);
	List.SetTextColor(RGB(0, 0, 0));
	List.SetBkColor(RGB(255, 255, 255));
	List.InsertColumn(0, _T("RoomID"), LVCFMT_CENTER, 80, 0);
	List.InsertColumn(1, _T("NumberOfSeat"), LVCFMT_CENTER, 140, 0);
	List.InsertColumn(2, _T("NumberOfComputer"), LVCFMT_CENTER, 180, 0);
	List.InsertColumn(3, _T("NumberOfWhitebash"), LVCFMT_CENTER, 180, 0);
	List.InsertColumn(4, _T("NumberOfProject"), LVCFMT_CENTER, 160, 0);
	//对数据库进行连接，并且打开表，是的记录集成为动态的，
	CString DSNname = _T("DSN=BuildingManager");
	Record = new CClassRoomManagerSet(&DB);
	if (DB.OpenEx(DSNname, 0)){
		if (Record->Open(CRecordset::dynaset, _T("select * from detailofroom"), CRecordset::none)){
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


void Room::OnBnClickedButtoncontect()
{
	UpdateData();			//从控件更新数据到变量

	int index = 0;			//创建一个列表控件的行数标记变量
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
		LV_ITEM lvitem;		// 设置行的变量
		index = List.GetItemCount();//获取当前行数
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
		//清理数据，避免循环时造成数据混乱使用
		RoomID = "";
		NumberOfSeat = "";
		NumberOfComputer = "";
		NumberOfWhitebash = "";
		NumberOfProject = "";
	}

	UpdateData(false);				//更新数据到控件
}


void Room::OnBnClickedButtoninsert()		//插入按钮的响应函数
{
	UpdateData();

	Record->MoveLast();		//让动态记录集指向第一个记录
	Record->AddNew();		//添加一条新的记录
	Record->m_RoomID = ID;			//为新记录的变量赋值
	Record->m_NumberOfComputer = computer;		
	Record->m_NumberOfSeat = seat;
	Record->m_NumberOfWhitebash = broad;
	Record->m_NumberOfProject = project;
	Record->Update();		//刷新纪录
	Record->Requery();		
	List.DeleteAllItems();			//删除列表控件内的所有项
	OnBnClickedButtoncontect();		//重新把数据从表拿到列表

	UpdateData(false);
}


void Room::OnBnClickedButtondelete()
{
	UpdateData();

	long Row=0;
	POSITION pos = List.GetFirstSelectedItemPosition();
	while (pos){
		Row = List.GetNextSelectedItem(pos);			//获取当前鼠标点击的行数
	}
	Record->SetAbsolutePosition(Row + 1);
	Record->Delete();			//删除记录  
	Record->Requery();			
	List.DeleteAllItems();		//删除所有项
	OnBnClickedButtoncontect();			//重新拿取数据

	UpdateData(false);
}



void Room::OnBnClickedButtonchange()
{
	UpdateData();

	long Row=0;
	POSITION pos = List.GetFirstSelectedItemPosition();
	while (pos){
		Row = List.GetNextSelectedItem(pos);			//获取当前鼠标点击的行数
	}
	Record->SetAbsolutePosition(Row + 1);
	Record->Edit();
	Record->m_RoomID=ID ;
	Record->m_NumberOfComputer = computer;
	Record->m_NumberOfSeat = seat;
	Record->m_NumberOfWhitebash = broad;
	Record->m_NumberOfProject = project;
	Record->Update();
	Record->Requery();
	List.DeleteAllItems();		//删除所有项
	OnBnClickedButtoncontect();			//重新拿取数据

	UpdateData(false);
}


void Room::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	UpdateData();

	long Row = 0;
	POSITION pos = List.GetFirstSelectedItemPosition();
	while (pos){
		Row = List.GetNextSelectedItem(pos);			//获取当前鼠标点击的行数
	}
	Record->SetAbsolutePosition(Row+1);
	ID = Record->m_RoomID;
	computer = Record->m_NumberOfComputer;
	seat = Record->m_NumberOfSeat;
	broad = Record->m_NumberOfWhitebash;
	project = Record->m_NumberOfProject;

	*pResult = 0;
	UpdateData(false);
}


void Room::OnBnClickedButtonclean()
{
	UpdateData();

	ID = 0;
	seat = 0;
	computer = 0;
	broad = 0;
	project = 0;

	UpdateData(false);
}
