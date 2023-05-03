#pragma once

#include"Include.h"
#include"GameObject.h"
#include"player.h"
#include"Enemy.h"

class MainUpdate
{
private:
	HDC m_hdc;

	RECT rcPoint;
	Player* m_pPlayer;
	Enemy* m_pEnemy;
public:
	void Start();
	void Update();
	void Render();
	void Destroy();
public:
	MainUpdate();
	~MainUpdate();
};

