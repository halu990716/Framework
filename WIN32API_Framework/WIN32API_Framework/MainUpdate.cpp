#include "MainUpdate.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
}

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	StartX = 100;
	StartY = 100;

	EndX = 200;
	EndY = 200;
}	

void MainUpdate::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		StartY --;

		EndY --;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		StartY ++;

		EndY ++;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		StartX --;

		EndX --;

	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		StartX ++;

		EndX ++;
	}
	
	if (GetAsyncKeyState(VK_SPACE))
	{
		StartBulletX = StartX + 45;
		StartBulletY = StartY + 45;

		EndBulletX = StartX + 55;
		EndBulletY = StartY + 55;
	}

	StartBulletX += 100;
	EndBulletX += 100;

	Rectangle(m_hdc, StartBulletX, StartBulletY, EndBulletX, EndBulletY);
}

void MainUpdate::Render()
{
	/*
	Rectangle(m_hdc,
		0, 0,
		1280, 720);
		*/
	Rectangle(m_hdc, StartX, StartY, EndX, EndY);
}

void MainUpdate::Destroy()
{
}