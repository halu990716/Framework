#pragma once

#include"Include.h"
//x
// �������� �Լ��� 1���� ������ �߻�Ŭ����
class GameObject
{
protected:
	Tranform transform;
	float Speed;
public:
	// virtual = 0 (PURE) ���� �����Լ�

	virtual void Start()PURE;
	virtual void Start(Vector3 _position)PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	Tranform GetTransform() { return transform; }
	//void SetTransform(Tranform _transform) { transform = _transform; }

	Vector3 GetPosition() { return transform.position; }
	void SetPosition(Vector3 _position) 
	{ transform.position = _position; }

public:
	GameObject();
	virtual ~GameObject();
};

