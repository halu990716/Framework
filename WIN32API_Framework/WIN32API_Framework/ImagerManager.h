#pragma once
#include "Include.h"
class Bitmap;
class ImagerManager
{
public:
	Single(ImagerManager)
public:
	// ������ �̹���
	map<string, Bitmap*> m_mapImageList;
public:
	// ����� �� �ְ� �Լ� ����
	map < string, Bitmap*>* GetImageList() { return &m_mapImageList; }
private:
	ImagerManager();
public:
	~ImagerManager();
};

