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

	virtual void Start()=0;
	virtual void Start(Vector3 _position)=0;
	virtual int Update()=0;
	virtual void Render(HDC hdc)=0;
	virtual void Destroy()=0;
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

