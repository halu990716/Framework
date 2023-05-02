#pragma once

#include"Include.h"

// 순수가상 함수가 1개라도 있으면 추상클래스
class GameObject
{
protected:
	Tranform transform;
	int Speed;
public:
	// virtual = 0 순수 가상함수

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Destroy() = 0;
public:
	GameObject();
	~GameObject();
};

