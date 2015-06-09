
// ClassRoomManagerView.cpp : CClassRoomManagerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CClassRoomManagerView ����/����

CClassRoomManagerView::CClassRoomManagerView()
	: CRecordView(CClassRoomManagerView::IDD)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CClassRoomManagerView::~CClassRoomManagerView()
{
}

void CClassRoomManagerView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
}

BOOL CClassRoomManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CClassRoomManagerView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ClassRoomManagerSet;
	CRecordView::OnInitialUpdate();

}


// CClassRoomManagerView ��ӡ

BOOL CClassRoomManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CClassRoomManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CClassRoomManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CClassRoomManagerView ���

#ifdef _DEBUG
void CClassRoomManagerView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CClassRoomManagerView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CClassRoomManagerDoc* CClassRoomManagerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClassRoomManagerDoc)));
	return (CClassRoomManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CClassRoomManagerView ���ݿ�֧��
CRecordset* CClassRoomManagerView::OnGetRecordset()
{
	return m_pSet;
}



// CClassRoomManagerView ��Ϣ�������
