#pragma once

#include"Include.h"

// �������� �Լ��� 1���� ������ �߻�Ŭ����
class GameObject
{
protected:
	Tranform transform;
	int Speed;
public:
	// virtual = 0 ���� �����Լ�

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Destroy() = 0;
public:
	GameObject();
	~GameObject();
};

