#include "Bitmap.h"

Bitmap::Bitmap() : m_hdc(NULL), m_MemDC(NULL), m_bitmap(NULL), m_Oldbitmap(NULL)
{								 
}

Bitmap::~Bitmap()
{
	Release();
}

Bitmap* Bitmap::LoadBmp(LPCWSTR _FileName)
{
	// 
	m_hdc = GetDC(g_hWnd);
	m_MemDC = CreateCompatibleDC(m_hdc);

	// 비트맵 기본 옵션값
	m_bitmap = (HBITMAP)LoadImage(NULL, _FileName, IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	// 비트맵을 복사
	m_Oldbitmap = (HBITMAP)SelectObject(m_MemDC, m_bitmap);

	// 기존에 있던 DC는 삭제
	ReleaseDC(g_hWnd, m_hdc);

	return this;
}

void Bitmap::Release()
{
	// 기존의 비트맵으로 원상복구
	SelectObject(m_MemDC, m_Oldbitmap);

	DeleteObject(m_bitmap);
	DeleteDC(m_MemDC);
}
