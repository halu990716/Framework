#pragma once
#include "Include.h"
class Bitmap;
class ImagerManager
{
public:
	Single(ImagerManager)
public:
	// 원본의 이미지
	map<string, Bitmap*> m_mapImageList;
public:
	// 사용할 수 있게 함수 생성
	map < string, Bitmap*>* GetImageList() { return &m_mapImageList; }
private:
	ImagerManager();
public:
	~ImagerManager();
};

