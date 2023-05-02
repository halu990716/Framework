#pragma once
#include "GameObject.h"

class  Bullet : public GameObject
{
public:
	void Start();
	void Update();
	void Render(HDC hdc);
	void Destroy();
public:
	Bullet();
	~Bullet();

};
