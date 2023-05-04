#pragma once
#include "GameObject.h"
//x
class  Bullet : public GameObject
{
public:
	// override (virtual)�� �ƴϴ���
	virtual GameObject* Start()override;
	virtual void Start(Vector3 _position)override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Bullet();
	virtual ~Bullet();
};
