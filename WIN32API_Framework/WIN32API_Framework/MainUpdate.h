#pragma once

#include"Include.h"
#include"GameObject.h"
#include"player.h"
#include"Bullet.h"

class MainUpdate
{
private:
	HDC m_hdc;

	RECT rcPoint;
	Player* m_pPlayer;
	Bullet* m_pBullet;

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

