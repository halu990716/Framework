#pragma once
#include "Include.h"

class Scene;
class ScenManager
{
private:
	static ScenManager* Instance;
public:
	static ScenManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ScenManager;
		return Instance;
	}
private:
	Scene* SceneState;
public:
	void SetScene(SCENEID _State);
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
private:
	ScenManager();
public:
	~ScenManager();
};

