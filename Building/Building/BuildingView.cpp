
// BuildingView.cpp : CBuildingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Building.h"
#endif

#include "BuildingSet.h"
#include "BuildingDoc.h"
#include "BuildingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBuildingView

IMPLEMENT_DYNCREATE(CBuildingView, CRecordView)

BEGIN_MESSAGE_MAP(CBuildingView, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CBuildingView 构造/析构

CBuildingView::CBuildingView()
	: CRecordView(CBuildingView::IDD)
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

CBuildingView::~CBuildingView()
{
}

void CBuildingView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
}

BOOL CBuildingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CBuildingView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_BuildingSet;
	CRecordView::OnInitialUpdate();

}


// CBuildingView 打印

BOOL CBuildingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBuildingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CBuildingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CBuildingView 诊断

#ifdef _DEBUG
void CBuildingView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CBuildingView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CBuildingDoc* CBuildingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBuildingDoc)));
	return (CBuildingDoc*)m_pDocument;
}
#endif //_DEBUG


// CBuildingView 数据库支持
CRecordset* CBuildingView::OnGetRecordset()
{
	return m_pSet;
}



// CBuildingView 消息处理程序
