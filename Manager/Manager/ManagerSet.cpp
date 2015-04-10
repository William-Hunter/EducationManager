
// ManagerSet.cpp : CManagerSet 类的实现
//

#include "stdafx.h"
#include "Manager.h"
#include "ManagerSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CManagerSet 实现

// 代码生成在 2015年4月10日, 10:28

IMPLEMENT_DYNAMIC(CManagerSet, CRecordset)

CManagerSet::CManagerSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_DetailOfBuilding7RoomID = 0;
	m_DetailOfBuilding7NumberOfSeat = 0;
	m_DetailOfBuilding7NumberOfComputer = 0;
	m_DetailOfBuilding7NumberOfWhitebash = 0;
	m_DetailOfBuilding7NumberOfProject = 0;
	
	m_DetailOfComputer7203ComputerID = L"";
	m_DetailOfComputer7203SoftwareName = L"";
	m_DetailOfComputer7203DamageStatus = FALSE;
	m_DetailOfComputer7203DamageRemark = L"";
	m_DetailOfComputer7203FixLog = L"";
	m_DetailOfComputer7203BlongOfRoomID = 0;
	m_nFields = 16;
	m_nDefaultType = dynaset;
}
#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CManagerSet::GetDefaultConnect()
{
	return _T("DSN=manager;DBQ=DATABASE\\BuildingManager.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CManagerSet::GetDefaultSQL()
{
	return _T("[DetailOfBuilding7],[DetailOfComputer7203]");
}

void CManagerSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[DetailOfBuilding7].[RoomID]"), m_DetailOfBuilding7RoomID);
	RFX_Long(pFX, _T("[DetailOfBuilding7].[NumberOfSeat]"), m_DetailOfBuilding7NumberOfSeat);
	RFX_Long(pFX, _T("[DetailOfBuilding7].[NumberOfComputer]"), m_DetailOfBuilding7NumberOfComputer);
	RFX_Long(pFX, _T("[DetailOfBuilding7].[NumberOfWhitebash]"), m_DetailOfBuilding7NumberOfWhitebash);
	RFX_Long(pFX, _T("[DetailOfBuilding7].[NumberOfProject]"), m_DetailOfBuilding7NumberOfProject);
	
	RFX_Text(pFX, _T("[DetailOfComputer7203].[ComputerID]"), m_DetailOfComputer7203ComputerID);
	RFX_Text(pFX, _T("[DetailOfComputer7203].[SoftwareName]"), m_DetailOfComputer7203SoftwareName);
	RFX_Bool(pFX, _T("[DetailOfComputer7203].[DamageStatus]"), m_DetailOfComputer7203DamageStatus);
	RFX_Text(pFX, _T("[DetailOfComputer7203].[DamageRemark]"), m_DetailOfComputer7203DamageRemark);
	RFX_Text(pFX, _T("[DetailOfComputer7203].[FixLog]"), m_DetailOfComputer7203FixLog);
	RFX_Long(pFX, _T("[DetailOfComputer7203].[BlongOfRoomID]"), m_DetailOfComputer7203BlongOfRoomID);

}
/////////////////////////////////////////////////////////////////////////////
// CManagerSet 诊断

#ifdef _DEBUG
void CManagerSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CManagerSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

