#pragma once
#include "Include.h"

class Object;
class Tile;
class Stage
{
private:
	Object* object;

	list<Object*>* TileList;
public:
	void Start();
	void Update();
	void Render(HDC hdc);
	void Destroy();
public:
	Stage();
	~Stage();
};


