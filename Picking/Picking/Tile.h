#pragma once
#include "Object.h"

class Tile : public Object
{
private:
	int check;

	int CountX;
	int CountY;
	int EndFrame;

	HDC m_hdc, hdcTile;
	HBITMAP m_bitmap, m_Oldbitmap;
public:
	virtual Object* Start() override;
	virtual void Update(int _x, int _y) override;
	virtual void Render(HDC hdc,int _x, int _y) override;
	virtual void Destroy() override;
public:
	Tile();
	virtual ~Tile();
};



