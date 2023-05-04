#pragma once
#include "Scene.h"

class Stage : public Scene
{
private:
	HDC m_hdc;

	GameObject* m_pPlayer;
	GameObject* m_pEnemy;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Stage();
	virtual ~Stage();
};

