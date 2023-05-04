#include "Menu.h"
#include "ScenManager.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Start()
{
}

int Menu::Update()
{
	if (GetAsyncKeyState('S'))
	{
		SceneManager::
	}

	return 0;
}

void Menu::Render(HDC hdc)
{
	Ellipse(hdc, 500, 500, 600, 600)
}

void Menu::Destroy()
{
}

