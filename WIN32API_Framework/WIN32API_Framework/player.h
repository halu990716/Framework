#pragma once
#include "GameObject.h"

class  Player : public GameObject
{
public:
	// override �θ�Ŭ������ ���������Լ��� ������
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	//�ζ��� = ����� �ٷ� ����                                  // �⺻ ��������� (this)
	virtual GameObject* Clone()override { return new Player(*this); }
public:
	template <typename T>
	GameObject* CreateBullet();
public:
	Player();
	Player(Transform _transform) : GameObject(_transform) {}
	virtual ~Player();
};
