#pragma once
#include "Include.h"

class Bitmap;
class Object;
class Stage
{
private:
	map <string, Bitmap*> ImageList;
	vector<Object*> TileList;
	int Result;
public:
	void Start();
	void Update();
	void Render(HDC hdc);
	void Destroy();
public:
	Stage();
	~Stage();
};


