#pragma once

#include"Include.h"

class MainUpdate
{
private:
	HDC m_hdc;

	int StartX, StartY;
	int EndX, EndY;
	int StartBulletX, StartBulletY;
	int EndBulletX, EndBulletY;
public:
	void Start();
	void Update();
	void Render();
	void Destroy();
public:
	MainUpdate();
	~MainUpdate();
};

