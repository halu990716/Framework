#pragma once
#include "Include.h"

class Object
{
protected:
	Transform transform;

	string Key;
public:
	virtual void Start() PURE;
	virtual void Update() PURE;
	virtual void Render(HDC hdc) PURE;
	virtual void Destroy() PURE;
public:
	string GetKey()const { return Key; }

	Transform GetTransform()const { return transform; }

	Vector3 GetPosition()const { return transform.position; }

public:
	Object();
	virtual ~Object();
};

