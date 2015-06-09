
// ClassRoomManagerSet.h: CClassRoomManagerSet ��Ľӿ�
//


#pragma once

// ���������� 2015��6�� ���ڶ�, 17:50

class CClassRoomManagerSet : public CRecordset
{
public:
	CClassRoomManagerSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CClassRoomManagerSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_RoomID;	//���ҵı��
	long	m_NumberOfSeat;	//��λ�ĸ���
	long	m_NumberOfComputer;	//������ĸ���
	long	m_NumberOfWhitebash;	//�װ�ĸ���
	long	m_NumberOfProject;	//ͶӰ�ǵĸ���

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

