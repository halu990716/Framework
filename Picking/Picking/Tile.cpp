#include "Tile.h"

Tile::Tile() : check(0)
{
}

Tile::~Tile()
{
}

void Tile::Start()
{
	transform.position = Vector3(0, 0);
	transform.scale = Vector3(32, 32);

	check = 0;

	CountX = 0;
	CountY = 0;

	m_hdc = GetDC(g_hWnd);
	hdcTile = CreateCompatibleDC(m_hdc);

	m_bitmap = (HBITMAP)LoadImage(NULL, LPCWSTR(L"../Resource/Tile.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	m_Oldbitmap = (HBITMAP)SelectObject(hdcTile, m_bitmap);
}

void Tile::Update()
{
	POINT ptMouse;

	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd, &ptMouse);

	float fx = ptMouse.x - transform.position.x;
	float fy = transform.position.y - ptMouse.y;

	float sum = transform.scale.x * 0.5f;

	float distanse = sqrt((fx * fx) + (fy * fy));

	if (!check)
	{
		if (transform.position.x - transform.scale.x * 0.5f < ptMouse.x &&
			transform.position.y - transform.scale.y * 0.5f < ptMouse.y &&
			ptMouse.x < transform.position.x + transform.scale.x * 0.5f &&
			ptMouse.y < transform.position.y + transform.scale.y * 0.5f)
		{
			if (GetAsyncKeyState(VK_LBUTTON))
				check = !check;
		}
	}
	/*else
	{
		if (distanse < sum)
			check = !check;
	}*/

	if (GetAsyncKeyState(VK_RETURN))
	{
		check = !check;
		Sleep(100);
	}
}

void Tile::Render(HDC hdc)
{
	/*if (check)
		Rectangle(hdc, 
			transform.position.x - transform.scale.x * 0.5f,
			transform.position.y - transform.scale.y * 0.5f,
			transform.position.x + transform.scale.x * 0.5f,
			transform.position.y + transform.scale.y * 0.5f);
	else
		Ellipse(hdc, 
			transform.position.x - transform.scale.x * 0.5f,
			transform.position.y - transform.scale.y * 0.5f,
			transform.position.x + transform.scale.x * 0.5f,
			transform.position.y + transform.scale.y * 0.5f);*/

	//srand((unsigned int)GetTickCount64());
	for (int x = 0; x < 46; x++)
		for (int y = 0; y < 23; y++)
	float x = transform.scale.x * 0.5f + _x * 32;
	float y = transform.scale.y * 0.5f + _y * 32;


	if (check)
			TransparentBlt(hdc,
				transform.position.x - transform.scale.x * 0.5f,
				transform.position.y - transform.scale.y * 0.5f,  
				transform.scale.x,
				transform.scale.y,
				hdcTile,
				transform.scale.x * CountX + 32,
				transform.scale.y * CountY,
				//transform.scale.x * int(rand() % 4),
				//transform.scale.y * int(rand() % 2),
				transform.scale.x,
				transform.scale.y,
				RGB(255, 0, 255));
	else
		TransparentBlt(hdc,
			transform.position.x - transform.scale.x * 0.5f + x * 32,
			transform.position.y - transform.scale.y * 0.5f + y * 32,
			transform.scale.x,
			transform.scale.y,
			hdcTile,
			transform.scale.x * CountX,
			transform.scale.y * CountY,
			transform.scale.x,
			transform.scale.y,
			RGB(255, 0, 255));
	//Sleep(1000);
}

void Tile::Destroy()
{
}
