#pragma once
#include "Include.h"

class Bitmap;
class Object
{
protected:
	static map<string, Bitmap*>* ImageList;
public:
	static void SetImageList(map<string, Bitmap*>* _ImageList) { ImageList = _ImageList; }

protected:
	int Option;
	int Index;
	Transform transform;
public:
	virtual void Start() PURE;
	virtual int Update() PURE;
	virtual void Render(HDC hdc) PURE;
	virtual void Destroy() PURE;
public:
	Transform GetTransform()const { return transform; }

	Vector3 GetPosition()const { return transform.position; }
	void SetPosition(const Vector3& _position) { transform.position = _position; }

	int GetOption()const { return Option; }
	void SetOption(const int& _Option) { Option = _Option; }

	int GetIndex() const { return Index; }
	void SetIndex(const int& _Index) { Index = _Index; }
public:
	Object();
	virtual ~Object();
};

