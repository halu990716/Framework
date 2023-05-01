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
		StartY -= 1;

		EndY -= 1;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		StartY += 1;

		EndY += 1;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		StartX -= 1;

		EndX -= 1;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		StartX += 1;

		EndX += 1;
	}
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