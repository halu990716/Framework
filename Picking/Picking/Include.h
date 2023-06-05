#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <string>
#include <Windows.h>
#include <math.h>

using namespace std;

// ** 이미지
#pragma comment(lib, "msimg32.lib")



#include "Struct.h"
#include "Enum.h"






#define Single(T)											\
public:																\
	static T** GetInstance()					    \
	{																	\
		static T* Instance;								\
		if(Instance == nullptr)							\
			Instance = new T;							\
		return &Instance;								\
	}																	\
	private:														\
		T(const T&) = delete;							\
		T& operator = (const T&) = delete;

#define GetSingle(T) (*T::GetInstance())


#define WIDTH 1280
#define HEIGHT 720

// ** 타일 가로, 세로 크기
#define SCALE_X 32.0f
#define SCALE_Y 32.0f

// ** 타일 가로, 세로 최대 개수
#define COUNT_X (WIDTH/SCALE_X)
#define COUNT_Y (HEIGHT/SCALE_Y)

// ** 타일 최대 개수
const int MAX = int(COUNT_X * COUNT_Y);

template <typename T>
inline void Safe_Release(T& _Object)
{
	if (_Object)
	{
		delete _Object;
		_Object = nullptr;
	}
}

extern HWND g_hWnd;