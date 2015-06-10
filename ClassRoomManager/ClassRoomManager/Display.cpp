// Display.cpp : 实现文件
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "Display.h"
#include "afxdialogex.h"
#include "ExChange.h"


// Display 对话框

IMPLEMENT_DYNAMIC(Display, CDialogEx)

Display::Display(CWnd* pParent /*=NULL*/)
	: CDialogEx(Display::IDD, pParent)
{

}

Display::~Display()
{
}

void Display::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, List);
}


BEGIN_MESSAGE_MAP(Display, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Display::OnBnClickedCancel)
END_MESSAGE_MAP()


// Display 消息处理程序


void Display::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL Display::OnInitDialog()
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
			//MessageBox(_T("成功的与数据库建立连接"));
		}
		else{
			MessageBox(_T("没有检索到表"));
		}
	}
	else{
		MessageBox(_T("数据库连接失败"));
	}

	int index = 0;																//创建一个列表控件的行数标记变量
	//从记录集复制数据到本地变量
	Record->MoveFirst();													//确保记录集指向第一个记录
	for (index = 0; !(Record->IsEOF()); index++){					//不断循环，  当记录集有数据的时候，isEOF方法为0，所以在前面加上！，以保证循环
		if(  (Record->m_NumberOfComputer>=ExChange::FindComputer)&&(Record->m_NumberOfSeat>=ExChange::FindSeat)&&(Record->m_NumberOfProject>=ExChange::FindProject)&&(Record->m_NumberOfWhitebash>=ExChange::FindBorad)  ){
			Record->GetFieldValue((short)0, RoomID);					//从记录集读取数据到变量
			Record->GetFieldValue((short)1, NumberOfSeat);
			Record->GetFieldValue((short)2, NumberOfComputer);
			Record->GetFieldValue((short)3, NumberOfWhitebash);
			Record->GetFieldValue((short)4, NumberOfProject);
			//定义行
			LV_ITEM lvitem;														// 设置行的变量
			index = List.GetItemCount();										//获取当前行数
			lvitem.iItem = index;
			lvitem.mask = LVFIF_TEXT;
			lvitem.iSubItem = 0;
			lvitem.pszText = (char *)(LPCTSTR)RoomID;
			//插入一行
			List.InsertItem(&lvitem);											//插入一行，
			List.SetItemText(index, 0, RoomID);							//在这个坐标的格子上，插入变量
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
		Record->MoveNext();												//记录集移动到下一条
	}
		
	UpdateData(false);		
	return TRUE;  // return TRUE unless you set the focus to a control
}
