#pragma once

#include"Include.h"
//x
// 순수가상 함수가 1개라도 있으면 추상클래스
class GameObject
{
protected:
	Tranform transform;
	float Speed;
public:
	// virtual = 0 (PURE) 순수 가상함수

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

