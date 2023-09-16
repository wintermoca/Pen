﻿
// Pen1Doc.cpp: CPen1Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Pen1.h"
#endif

#include "Pen1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPen1Doc

IMPLEMENT_DYNCREATE(CPen1Doc, CDocument)

BEGIN_MESSAGE_MAP(CPen1Doc, CDocument)
END_MESSAGE_MAP()


// CPen1Doc 생성/소멸

CPen1Doc::CPen1Doc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CPen1Doc::~CPen1Doc()
{
}

BOOL CPen1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	INT_PTR n = m_oa.GetCount();
	for (INT_PTR i = 0; i < n; i++) {
		delete m_oa[i];
	}
	m_oa.RemoveAll();

	return TRUE;
}// 새 문서를 생성할 때 이전 문서의 데이터를 제거하고 새 문서를 초기화하는 일반적인 패턴을 나타냅니다. 
 //이렇게 하면 이전 문서와 관련된 데이터가 새 문서에 영향을 미치지 않도록 할 수 있습니다.




// CPen1Doc serialization

void CPen1Doc::Serialize(CArchive& ar)
{
	m_oa.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CPen1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CPen1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CPen1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CPen1Doc 진단

#ifdef _DEBUG
void CPen1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPen1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPen1Doc 명령
