#pragma once
#include "GameObject.h"

class  Enemy : public GameObject
{
public:
	// override (virtual)�� �ƴϴ���
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	//�ζ��� = ����� �ٷ� ����                                  // �⺻ ��������� (this)
	virtual GameObject* Clone()override { return new Enemy(*this); }
public:
	Enemy();
	Enemy(Transform _transform) : GameObject(_transform) {}
	virtual ~Enemy();
};
