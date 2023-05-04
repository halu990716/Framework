#pragma once

#include"Include.h"

// �������� �Լ��� 1���� ������ �߻�Ŭ����
class GameObject
{
protected:
	Tranform transform;
	float Speed;

	string Key;
public:
	// virtual = 0 (PURE) ���� �����Լ�

	virtual GameObject* Start()PURE;
	virtual void Start(Vector3 _position)PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	string GetKey() { return Key; }

	Tranform GetTransform() { return transform; }
	//void SetTransform(Tranform _transform) { transform = _transform; }

	Vector3 GetPosition() { return transform.position; }
	void SetPosition(Vector3 _position) { transform.position = _position; }

	Vector3 GetScale() { return transform.scale; }
	void SetScalen(Vector3 _scale) { transform.scale = _scale; }
public:
	GameObject();
	virtual ~GameObject();
};

