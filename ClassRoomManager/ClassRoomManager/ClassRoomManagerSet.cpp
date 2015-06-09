
// ClassRoomManagerSet.cpp : CClassRoomManagerSet 类的实现
//

#include "stdafx.h"
#include "ClassRoomManager.h"
#include "ClassRoomManagerSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClassRoomManagerSet 实现

// 代码生成在 2015年6月 星期二, 17:50

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[RoomID]"), m_RoomID);
	RFX_Long(pFX, _T("[NumberOfSeat]"), m_NumberOfSeat);
	RFX_Long(pFX, _T("[NumberOfComputer]"), m_NumberOfComputer);
	RFX_Long(pFX, _T("[NumberOfWhitebash]"), m_NumberOfWhitebash);
	RFX_Long(pFX, _T("[NumberOfProject]"), m_NumberOfProject);

}
/////////////////////////////////////////////////////////////////////////////
// CClassRoomManagerSet 诊断

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

