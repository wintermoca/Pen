#pragma once
#include <afx.h>
class CLine :
    public CObject
{
    DECLARE_SERIAL(CLine)
    CPoint m_From;
    CPoint m_To;
    int m_Size;
    COLORREF m_Col;
public:
    CLine(){}
    CLine(CPoint From, CPoint To, int Size, COLORREF Col) {
        m_From = From;
        m_To = To;
        m_Size = Size;
        m_Col = Col;
    }
    void Draw(CDC* pDC) {
        CPen pen(PS_SOLID, m_Size, m_Col); //펜의 종류, 크기, 색을 설정
        pDC->SelectObject(&pen);
        pDC->MoveTo(m_From);
        pDC->LineTo(m_To);
    } //펜 객체(pen)의 설정에 따라 선의 스타일 및 색상이 결정됩니다. 
      //MoveTo 함수를 사용하여 시작점을 설정하고, LineTo 함수를 사용하여 선을 그립니다. 
    virtual void Serialize(CArchive& ar);
};

