// Finder.cpp : 实现文件
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "Finder.h"
#include "afxdialogex.h"
#include "ExChange.h"
#include "Display.h"


// Finder 对话框

IMPLEMENT_DYNAMIC(Finder, CDialogEx)

Finder::Finder(CWnd* pParent /*=NULL*/)
	: CDialogEx(Finder::IDD, pParent)
	, FindBorad(0)
	, FindComputer(0)
	, FindProject(0)
	, FindSeat(0)
{
}

Finder::~Finder()
{
}

void Finder::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FindBorad, FindBorad);
	DDX_Text(pDX, IDC_EDIT_FindComputer, FindComputer);
	DDX_Text(pDX, IDC_EDIT_FindProject, FindProject);
	DDX_Text(pDX, IDC_EDIT_FindSeat, FindSeat);
}


BEGIN_MESSAGE_MAP(Finder, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Finder::OnBnClickedCancel)
	ON_BN_CLICKED(ID_search, &Finder::OnBnClickedsearch)
END_MESSAGE_MAP()


// Finder 消息处理程序


void Finder::OnBnClickedsearch()
{
	UpdateData();					//从控件拿到数据

	if(NULL==FindComputer&&NULL==FindSeat&&NULL==FindBorad&&NULL==FindProject){        //判断用户输入是否正确
		MessageBox("输入不完全");
		return ;
	}else{
		ExChange::FindComputer=FindComputer;			//将用户输入数据拿到静态交换空间
		ExChange::FindSeat=FindSeat;
		ExChange::FindProject=FindProject;
		ExChange::FindBorad=FindBorad;

		Display dialog;
		dialog.DoModal();
	}	

	UpdateData(false);					//更新数据到控件
}


void Finder::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
	DestroyWindow();
}

