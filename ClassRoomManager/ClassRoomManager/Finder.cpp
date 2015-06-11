// Finder.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "Finder.h"
#include "afxdialogex.h"
#include "ExChange.h"
#include "Display.h"


// Finder �Ի���

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


// Finder ��Ϣ�������


void Finder::OnBnClickedsearch()
{
	UpdateData();					//�ӿؼ��õ�����

	if(NULL==FindComputer&&NULL==FindSeat&&NULL==FindBorad&&NULL==FindProject){        //�ж��û������Ƿ���ȷ
		MessageBox("���벻��ȫ");
		return ;
	}else{
		ExChange::FindComputer=FindComputer;			//���û����������õ���̬�����ռ�
		ExChange::FindSeat=FindSeat;
		ExChange::FindProject=FindProject;
		ExChange::FindBorad=FindBorad;

		Display dialog;
		dialog.DoModal();
	}	

	UpdateData(false);					//�������ݵ��ؼ�
}


void Finder::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
	DestroyWindow();
}

