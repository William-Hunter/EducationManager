
// ClassRoomManagerView.cpp : CClassRoomManagerView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ClassRoomManager.h"
#endif

#include "ClassRoomManagerSet.h"
#include "ClassRoomManagerDoc.h"
#include "ClassRoomManagerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClassRoomManagerView

IMPLEMENT_DYNCREATE(CClassRoomManagerView, CRecordView)

BEGIN_MESSAGE_MAP(CClassRoomManagerView, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CClassRoomManagerView 构造/析构

CClassRoomManagerView::CClassRoomManagerView()
	: CRecordView(CClassRoomManagerView::IDD)
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

CClassRoomManagerView::~CClassRoomManagerView()
{
}

void CClassRoomManagerView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
}

BOOL CClassRoomManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CClassRoomManagerView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ClassRoomManagerSet;
	CRecordView::OnInitialUpdate();

}


// CClassRoomManagerView 打印

BOOL CClassRoomManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CClassRoomManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CClassRoomManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CClassRoomManagerView 诊断

#ifdef _DEBUG
void CClassRoomManagerView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CClassRoomManagerView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CClassRoomManagerDoc* CClassRoomManagerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClassRoomManagerDoc)));
	return (CClassRoomManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CClassRoomManagerView 数据库支持
CRecordset* CClassRoomManagerView::OnGetRecordset()
{
	return m_pSet;
}



// CClassRoomManagerView 消息处理程序
