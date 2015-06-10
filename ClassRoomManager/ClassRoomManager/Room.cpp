// Room.cpp : 实现文件
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "Room.h"
#include "afxdialogex.h"
#include "Input.h"

// Room 对话框

IMPLEMENT_DYNAMIC(Room, CDialogEx)

Room::Room(CWnd* pParent /*=NULL*/)
	: CDialogEx(Room::IDD, pParent)
{
}

Room::~Room()
{
}

void Room::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, List);
}


BEGIN_MESSAGE_MAP(Room, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_insert, &Room::OnBnClickedButtoninsert)
	ON_BN_CLICKED(IDC_BUTTON_change, &Room::OnBnClickedButtonchange)
	ON_BN_CLICKED(IDC_BUTTON_delete, &Room::OnBnClickedButtondelete)
	ON_BN_CLICKED(IDCANCEL, &Room::OnBnClickedCancel)
ON_NOTIFY(NM_CLICK, IDC_LIST1, &Room::OnClickList1)
END_MESSAGE_MAP()


// Room 消息处理程序

BOOL Room::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//窗口控件的初始化
	List.ModifyStyle(0, LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS);
	List.SetTextColor(RGB(0, 0, 0));
	List.SetBkColor(RGB(255, 255, 255));
	List.InsertColumn(0, _T("教室编号"), LVCFMT_CENTER, 80, 0);
	List.InsertColumn(1, _T("座位数量"), LVCFMT_CENTER, 140, 0);
	List.InsertColumn(2, _T("计算机数量"), LVCFMT_CENTER, 180, 0);
	List.InsertColumn(3, _T("演示白板数量"), LVCFMT_CENTER, 180, 0);
	List.InsertColumn(4, _T("投影仪数量"), LVCFMT_CENTER, 160, 0);
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
	Contect();

	return TRUE;  
}

void Room::Contect()
{
	UpdateData();																		//从控件更新数据到变量

	int index = 0;																		//创建一个列表控件的行数标记变量
	//从记录集复制数据到本地变量
	Record->MoveFirst();															//确保记录集指向第一个记录
	for (index = 0; !(Record->IsEOF()); index++){							//不断循环，  当记录集有数据的时候，isEOF方法为0，所以在前面加上！，以保证循环
		Record->GetFieldValue((short)0, RoomID);							//从记录集读取数据到变量
		Record->GetFieldValue((short)1, NumberOfSeat);
		Record->GetFieldValue((short)2, NumberOfComputer);
		Record->GetFieldValue((short)3, NumberOfWhitebash);
		Record->GetFieldValue((short)4, NumberOfProject);
		//定义行
		LV_ITEM lvitem;																// 设置行的变量
		index = List.GetItemCount();												//获取当前行数
		lvitem.iItem = index;
		lvitem.mask = LVFIF_TEXT;
		lvitem.iSubItem = 0;
		lvitem.pszText = (char *)(LPCTSTR)RoomID;
		//插入一行
		List.InsertItem(&lvitem);													//插入一行，
		List.SetItemText(index, 0, RoomID);									//在这个坐标的格子上，插入变量
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
		Record->MoveNext();														//记录集移动到下一条
	}

	UpdateData(false);																//更新数据到控件
}


void Room::OnBnClickedButtoninsert()
{
	UpdateData();

	ExChange::Clean();
	Input dialog;
	dialog.DoModal();
	if(ExChange::FLAG==TRUE){													//如果用户完成输入
		Record->MoveLast();													   	//让动态记录集指向第最后一个记录
		Record->AddNew();															//添加一条新的记录
		Record->m_RoomID = ExChange::ID;									//为新记录的变量赋值
		Record->m_NumberOfComputer = ExChange::computer;		
		Record->m_NumberOfSeat = ExChange::seat;
		Record->m_NumberOfWhitebash = ExChange::borad;
		Record->m_NumberOfProject = ExChange::project;
		Record->Update();														   //刷新纪录
		Record->Requery();		
		List.DeleteAllItems();		      											//删除列表控件内的所有项
		Contect();							     										//重新把数据从表拿到列表
		ExChange::Clean();															//清理数据交换变量
	}
	
	UpdateData(false);
}

long Room::TakeLine()
{
	long Row=-1;																		//设置Row为-1，这样当用户未选中任何行时不会误操作
	POSITION pos = List.GetFirstSelectedItemPosition();					
	while (pos){
		Row = List.GetNextSelectedItem(pos);								//获取当前鼠标点击的行的上一个
	}
	Row++;
	return Row;
}

void Room::OnBnClickedButtonchange()
{
	UpdateData();

	Input dialog;
	dialog.DoModal();																//创建输入窗口
	if(ExChange::FLAG==TRUE){													//如果用户完成无误输入
		Record->SetAbsolutePosition(TakeLine());							//获取用户点击的那一行对应的记录集行
		Record->Edit();																//对此行进行编辑
		Record->m_RoomID = ExChange::ID;		    						//为此记录的变量赋值
		Record->m_NumberOfComputer = ExChange::computer;		
		Record->m_NumberOfSeat = ExChange::seat;
		Record->m_NumberOfWhitebash = ExChange::borad;
		Record->m_NumberOfProject = ExChange::project;
		Record->Update();															//更新数据
		Record->Requery();
		List.DeleteAllItems();														//删除所有项
		Contect();							     										//重新把数据从表拿到列表
		ExChange::Clean();
	}

	UpdateData(false);
}


void Room::OnBnClickedButtondelete()
{
	UpdateData();

	Record->SetAbsolutePosition(TakeLine());								//获取用户点击的行号
	Record->Delete();																//删除记录  
	Record->Requery();			
	List.DeleteAllItems();															//删除所有项
	Contect();							     											//重新拿取数据

	UpdateData(false);
}


void Room::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	UpdateData();

	Record->SetAbsolutePosition(TakeLine());								//获取用户点击的行号

	//将这行的数据复制到静态变量
	ExChange::Set(Record->m_RoomID,Record->m_NumberOfComputer,Record->m_NumberOfSeat,Record->m_NumberOfWhitebash,Record->m_NumberOfProject);

	*pResult = 0;
	UpdateData(false);																//更新
}


void Room::OnBnClickedCancel()
{
	Record->Close();																	//关闭记录集
	DB.Close();																			//关闭数据库连接
	CDialogEx::OnCancel();															//离开窗口
	DestroyWindow();																//销毁窗口
}






