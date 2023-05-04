#include "MainUpdate.h"
#include "ScenManager.h"

MainUpdate::MainUpdate() : m_hdc(NULL)
{
}

MainUpdate::~MainUpdate()
{
	Destroy();
}

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	SceneManager
}	

void MainUpdate::Update()
{	

}

void MainUpdate::Render()
{
	Rectangle(m_hdc, -1, -1, WIDTH, HEIGHT);
}

void MainUpdate::Destroy()
{
	
}