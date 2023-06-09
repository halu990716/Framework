#include "MainUpdate.h"
#include "Stage.h"


MainUpdate::MainUpdate() : m_hdc(NULL), stage(nullptr)
{
}

MainUpdate::~MainUpdate()
{
	Destroy();
}

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	srand((unsigned int)GetTickCount64());

	stage = new Stage;
	stage->Start();
}

void MainUpdate::Update()
{
	stage->Update();
}

void MainUpdate::Render()
{
	//Rectangle(m_hdc, 0, 0, 1920, 1080);
	stage->Render(m_hdc);
}

void MainUpdate::Destroy()
{
	delete stage;
	stage = nullptr;
}
