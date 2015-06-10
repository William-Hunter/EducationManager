// Room.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "Room.h"
#include "afxdialogex.h"
#include "Input.h"

// Room �Ի���

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


// Room ��Ϣ�������

BOOL Room::OnInitDialog()
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
			MessageBox(_T("�ɹ��������ݿ⽨������"));
		}
		else{
			MessageBox(_T("û�м�������"));
		}
	}
	else{
		MessageBox(_T("���ݿ�����ʧ��"));
	}
	Contect();

	return TRUE;  
}

void Room::Contect()
{
	UpdateData();																		//�ӿؼ��������ݵ�����

	int index = 0;																		//����һ���б�ؼ���������Ǳ���
	//�Ӽ�¼���������ݵ����ر���
	Record->MoveFirst();															//ȷ����¼��ָ���һ����¼
	for (index = 0; !(Record->IsEOF()); index++){							//����ѭ����  ����¼�������ݵ�ʱ��isEOF����Ϊ0��������ǰ����ϣ����Ա�֤ѭ��
		Record->GetFieldValue((short)0, RoomID);							//�Ӽ�¼����ȡ���ݵ�����
		Record->GetFieldValue((short)1, NumberOfSeat);
		Record->GetFieldValue((short)2, NumberOfComputer);
		Record->GetFieldValue((short)3, NumberOfWhitebash);
		Record->GetFieldValue((short)4, NumberOfProject);
		//������
		LV_ITEM lvitem;																// �����еı���
		index = List.GetItemCount();												//��ȡ��ǰ����
		lvitem.iItem = index;
		lvitem.mask = LVFIF_TEXT;
		lvitem.iSubItem = 0;
		lvitem.pszText = (char *)(LPCTSTR)RoomID;
		//����һ��
		List.InsertItem(&lvitem);													//����һ�У�
		List.SetItemText(index, 0, RoomID);									//���������ĸ����ϣ��������
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
		Record->MoveNext();														//��¼���ƶ�����һ��
	}

	UpdateData(false);																//�������ݵ��ؼ�
}


void Room::OnBnClickedButtoninsert()
{
	UpdateData();

	ExChange::Clean();
	Input dialog;
	dialog.DoModal();
	if(ExChange::FLAG==TRUE){													//����û��������
		Record->MoveLast();													   	//�ö�̬��¼��ָ������һ����¼
		Record->AddNew();															//���һ���µļ�¼
		Record->m_RoomID = ExChange::ID;									//Ϊ�¼�¼�ı�����ֵ
		Record->m_NumberOfComputer = ExChange::computer;		
		Record->m_NumberOfSeat = ExChange::seat;
		Record->m_NumberOfWhitebash = ExChange::borad;
		Record->m_NumberOfProject = ExChange::project;
		Record->Update();														   //ˢ�¼�¼
		Record->Requery();		
		List.DeleteAllItems();		      											//ɾ���б�ؼ��ڵ�������
		Contect();							     										//���°����ݴӱ��õ��б�
		ExChange::Clean();															//�������ݽ�������
	}
	
	UpdateData(false);
}

long Room::TakeLine()
{
	long Row=-1;																		//����RowΪ-1���������û�δѡ���κ���ʱ���������
	POSITION pos = List.GetFirstSelectedItemPosition();					
	while (pos){
		Row = List.GetNextSelectedItem(pos);								//��ȡ��ǰ��������е���һ��
	}
	Row++;
	return Row;
}

void Room::OnBnClickedButtonchange()
{
	UpdateData();

	Input dialog;
	dialog.DoModal();																//�������봰��
	if(ExChange::FLAG==TRUE){													//����û������������
		Record->SetAbsolutePosition(TakeLine());							//��ȡ�û��������һ�ж�Ӧ�ļ�¼����
		Record->Edit();																//�Դ��н��б༭
		Record->m_RoomID = ExChange::ID;		    						//Ϊ�˼�¼�ı�����ֵ
		Record->m_NumberOfComputer = ExChange::computer;		
		Record->m_NumberOfSeat = ExChange::seat;
		Record->m_NumberOfWhitebash = ExChange::borad;
		Record->m_NumberOfProject = ExChange::project;
		Record->Update();															//��������
		Record->Requery();
		List.DeleteAllItems();														//ɾ��������
		Contect();							     										//���°����ݴӱ��õ��б�
		ExChange::Clean();
	}

	UpdateData(false);
}


void Room::OnBnClickedButtondelete()
{
	UpdateData();

	Record->SetAbsolutePosition(TakeLine());								//��ȡ�û�������к�
	Record->Delete();																//ɾ����¼  
	Record->Requery();			
	List.DeleteAllItems();															//ɾ��������
	Contect();							     											//������ȡ����

	UpdateData(false);
}


void Room::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	UpdateData();

	Record->SetAbsolutePosition(TakeLine());								//��ȡ�û�������к�

	//�����е����ݸ��Ƶ���̬����
	ExChange::Set(Record->m_RoomID,Record->m_NumberOfComputer,Record->m_NumberOfSeat,Record->m_NumberOfWhitebash,Record->m_NumberOfProject);

	*pResult = 0;
	UpdateData(false);																//����
}


void Room::OnBnClickedCancel()
{
	Record->Close();																	//�رռ�¼��
	DB.Close();																			//�ر����ݿ�����
	CDialogEx::OnCancel();															//�뿪����
	DestroyWindow();																//���ٴ���
}






