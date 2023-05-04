#include "ScenManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

ScenManager* ScenManager::Instance = nullptr;


ScenManager::ScenManager() : SceneState(nullptr)
{

}

ScenManager::~ScenManager()
{

}

void ScenManager::SetScene(SCENEID _State)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_State)
	{
	case LOGO:
		SceneState = new Logo;
		break;

	case MENU:
		SceneState = new Menu;
		break;

	case STAGE:
		SceneState = new Stage;
		break;
	}
	SceneState->Start();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Update()
{
	SceneState->Update();
}