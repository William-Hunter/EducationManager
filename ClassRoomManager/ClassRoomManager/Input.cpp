// Input.cpp : 实现文件
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "Input.h"
#include "afxdialogex.h"
#include "ExChange.h"

// Input 对话框

IMPLEMENT_DYNAMIC(Input, CDialogEx)

Input::Input(CWnd* pParent /*=NULL*/)
	: CDialogEx(Input::IDD, pParent)
	, borad(0)
	, computer(0)
	, ID(0)
	, project(0)
	, seat(0)
{

}

Input::~Input()
{
}

void Input::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_borad, borad);
	DDX_Text(pDX, IDC_EDIT_computer, computer);
	DDX_Text(pDX, IDC_EDIT_ID, ID);
	DDX_Text(pDX, IDC_EDIT_project, project);
	DDX_Text(pDX, IDC_EDIT_seat, seat);
}


BEGIN_MESSAGE_MAP(Input, CDialogEx)
	ON_BN_CLICKED(IDOK, &Input::OnBnClickedOk)
END_MESSAGE_MAP()


// Input 消息处理程序



BOOL Input::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData();

	ID=ExChange::ID;
	seat=ExChange::seat;
	project=ExChange::project;
	borad=ExChange::borad;
	computer=ExChange::computer;

	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
}


void Input::OnBnClickedOk()
{
	UpdateData();
	if(seat==NULL||computer==NULL||ID==NULL){
		MessageBox("你还没有完全输入");
		ExChange::FLAG=FALSE;
	}else{
		ExChange::ID=ID;
		ExChange::seat=seat;
		ExChange::borad=borad;
		ExChange::computer=computer;
		ExChange::project=project;
		ExChange::FLAG=TRUE;
	}
	UpdateData(false);
	CDialogEx::OnOK();
}


