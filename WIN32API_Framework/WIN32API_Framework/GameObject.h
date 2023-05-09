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
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	string GetKey()const { return Key; }

	Tranform GetTransform()const { return transform; }

	Vector3 GetPosition()const { return transform.position; }
	void SetPosition(const Vector3& _position) { transform.position = _position; }

	Vector3 GetScale() { return transform.scale; }
	void SetScale(const Vector3& _scale) { transform.scale = _scale; }
public:
	GameObject();
	virtual ~GameObject();
};

