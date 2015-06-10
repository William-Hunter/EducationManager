// Display.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "Display.h"
#include "afxdialogex.h"
#include "ExChange.h"


// Display �Ի���

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


// Display ��Ϣ�������


void Display::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


BOOL Display::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//���ڿؼ��ĳ�ʼ��
	List.ModifyStyle(0, LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS);
	List.SetTextColor(RGB(0, 0, 0));
	List.SetBkColor(RGB(255, 255, 255));
	List.InsertColumn(0, _T("���ұ��"), LVCFMT_CENTER, 80, 0);
	List.InsertColumn(1, _T("��λ����"), LVCFMT_CENTER, 140, 0);
	List.InsertColumn(2, _T("���������"), LVCFMT_CENTER, 180, 0);
	List.InsertColumn(3, _T("��ʾ�װ�����"), LVCFMT_CENTER, 180, 0);
	List.InsertColumn(4, _T("ͶӰ������"), LVCFMT_CENTER, 160, 0);
	//�����ݿ�������ӣ����Ҵ򿪱��ǵļ�¼����Ϊ��̬�ģ�
	CString DSNname = _T("DSN=BuildingManager");
	Record = new CClassRoomManagerSet(&DB);
	if (DB.OpenEx(DSNname, 0)){
		if (Record->Open(CRecordset::dynaset, _T("select * from detailofroom"), CRecordset::none)){
			//MessageBox(_T("�ɹ��������ݿ⽨������"));
		}
		else{
			MessageBox(_T("û�м�������"));
		}
	}
	else{
		MessageBox(_T("���ݿ�����ʧ��"));
	}

	int index = 0;																//����һ���б�ؼ���������Ǳ���
	//�Ӽ�¼���������ݵ����ر���
	Record->MoveFirst();													//ȷ����¼��ָ���һ����¼
	for (index = 0; !(Record->IsEOF()); index++){					//����ѭ����  ����¼�������ݵ�ʱ��isEOF����Ϊ0��������ǰ����ϣ����Ա�֤ѭ��
		if(  (Record->m_NumberOfComputer>=ExChange::FindComputer)&&(Record->m_NumberOfSeat>=ExChange::FindSeat)&&(Record->m_NumberOfProject>=ExChange::FindProject)&&(Record->m_NumberOfWhitebash>=ExChange::FindBorad)  ){
			Record->GetFieldValue((short)0, RoomID);					//�Ӽ�¼����ȡ���ݵ�����
			Record->GetFieldValue((short)1, NumberOfSeat);
			Record->GetFieldValue((short)2, NumberOfComputer);
			Record->GetFieldValue((short)3, NumberOfWhitebash);
			Record->GetFieldValue((short)4, NumberOfProject);
			//������
			LV_ITEM lvitem;														// �����еı���
			index = List.GetItemCount();										//��ȡ��ǰ����
			lvitem.iItem = index;
			lvitem.mask = LVFIF_TEXT;
			lvitem.iSubItem = 0;
			lvitem.pszText = (char *)(LPCTSTR)RoomID;
			//����һ��
			List.InsertItem(&lvitem);											//����һ�У�
			List.SetItemText(index, 0, RoomID);							//���������ĸ����ϣ��������
			List.SetItemText(index, 1, NumberOfSeat);
			List.SetItemText(index, 2, NumberOfComputer);
			List.SetItemText(index, 3, NumberOfWhitebash);
			List.SetItemText(index, 4, NumberOfProject);
			//�������ݣ�����ѭ��ʱ������ݻ���ʹ��
			RoomID = "";
			NumberOfSeat = "";
			NumberOfComputer = "";
			NumberOfWhitebash = "";
			NumberOfProject = "";
		}
		Record->MoveNext();												//��¼���ƶ�����һ��
	}
		
	UpdateData(false);		
	return TRUE;  // return TRUE unless you set the focus to a control
}
