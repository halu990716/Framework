#include "MainUpdate.h"
#include "Player.h"
#include "Bullet.h"

MainUpdate::MainUpdate() : m_pPlayer(NULL)
{
}

MainUpdate::~MainUpdate()
{
	Destroy();
}

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	m_pPlayer = new Player();
	m_pPlayer->Start();

	m_pBullet = new Bullet();
	m_pBullet->Start();
}	

void MainUpdate::Update()
{
	m_pPlayer->Update();
	m_pBullet->Update();
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, -1, -1, 1920, 1080);
	m_pPlayer->Render(m_hdc);
	m_pBullet->Render(m_hdc);
}

void MainUpdate::Destroy()
{
}