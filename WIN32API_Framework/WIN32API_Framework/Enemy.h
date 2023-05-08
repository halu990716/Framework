#pragma once
#include "GameObject.h"

class  Enemy : public GameObject
{
public:
	// override (virtual)이 아니더라도
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Enemy();
	virtual ~Enemy();
};
