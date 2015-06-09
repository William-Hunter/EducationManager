
// ClassRoomManagerSet.cpp : CClassRoomManagerSet ���ʵ��
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "ClassRoomManagerSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClassRoomManagerSet ʵ��

// ���������� 2015��6�� ���ڶ�, 17:50

IMPLEMENT_DYNAMIC(CClassRoomManagerSet, CRecordset)

CClassRoomManagerSet::CClassRoomManagerSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_RoomID = 0;
	m_NumberOfSeat = 0;
	m_NumberOfComputer = 0;
	m_NumberOfWhitebash = 0;
	m_NumberOfProject = 0;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CClassRoomManagerSet::GetDefaultConnect()
{
	return _T("DSN=BuildingManager;DBQ=C:\\Users\\Administrator\\Documents\\Access\\DataBase\\BuildingManager.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;PWD=admin;UID=admin;");
}

CString CClassRoomManagerSet::GetDefaultSQL()
{
	return _T("[DetailOfRoom]");
}

void CClassRoomManagerSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[RoomID]"), m_RoomID);
	RFX_Long(pFX, _T("[NumberOfSeat]"), m_NumberOfSeat);
	RFX_Long(pFX, _T("[NumberOfComputer]"), m_NumberOfComputer);
	RFX_Long(pFX, _T("[NumberOfWhitebash]"), m_NumberOfWhitebash);
	RFX_Long(pFX, _T("[NumberOfProject]"), m_NumberOfProject);

}
/////////////////////////////////////////////////////////////////////////////
// CClassRoomManagerSet ���

#ifdef _DEBUG
void CClassRoomManagerSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CClassRoomManagerSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

