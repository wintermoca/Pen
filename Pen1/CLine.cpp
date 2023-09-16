#include "pch.h"
#include "CLine.h"

IMPLEMENT_SERIAL(CLine, CObject, 1)

void CLine::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_From << m_To << m_Size << m_Col;
	}
	else
	{	// loading code
		ar >> m_From >> m_To >> m_Size >> m_Col;
	}
}
// 객체의 데이터를 파일에 저장하거나 파일에서 읽어올 때 사용됩니다. 
// 직렬화를 통해 데이터를 영구적으로 저장하고 나중에 응용 프로그램에서 사용할 수 있도록 합니다.