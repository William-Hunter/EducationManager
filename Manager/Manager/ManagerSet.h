
// ManagerSet.h: CManagerSet 类的接口
//


#pragma once

// 代码生成在 2015年4月10日, 10:28

class CManagerSet : public CRecordset
{
public:
	CManagerSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CManagerSet)

// 字段/参数数据

// 以下字符串类型(如果存在)反映数据库字段(ANSI 数据类型的 CStringA 和 Unicode
// 数据类型的 CStringW)的实际数据类型。
//  这是为防止 ODBC 驱动程序执行可能
// 不必要的转换。如果希望，可以将这些成员更改为
// CString 类型，ODBC 驱动程序将执行所有必要的转换。
// (注意: 必须使用 3.5 版或更高版本的 ODBC 驱动程序
// 以同时支持 Unicode 和这些转换)。

	long	m_DetailOfBuilding7RoomID;	//教室的编号
	long	m_DetailOfBuilding7NumberOfSeat;	//座位的个数
	long	m_DetailOfBuilding7NumberOfComputer;	//计算机的个数
	long	m_DetailOfBuilding7NumberOfWhitebash;	//白板的个数
	long	m_DetailOfBuilding7NumberOfProject;	//投影仪的个数
	
	CStringW	m_DetailOfComputer7203ComputerID;	//计算机的编号，因为有可能会使用字母，所以设为短文本
	CStringW	m_DetailOfComputer7203SoftwareName;	//计算机上安装的软件，因为会有很多软件，所以设为长文本
	BOOL	m_DetailOfComputer7203DamageStatus;	//计算机是否处于损毁状态
	CStringW	m_DetailOfComputer7203DamageRemark;	//损毁原因
	CStringW	m_DetailOfComputer7203FixLog;	//维修记录
	long	m_DetailOfComputer7203BlongOfRoomID;	//所属教室的编号

// 重写
	// 向导生成的虚函数重写
	public:
	virtual CString GetDefaultConnect();	// 默认连接字符串

	virtual CString GetDefaultSQL(); 	// 记录集的默认 SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX 支持

// 实现
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

