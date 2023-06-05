#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <string>
#include <Windows.h>
#include <math.h>

using namespace std;

// ** �̹���
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

// ** Ÿ�� ����, ���� ũ��
#define SCALE_X 32.0f
#define SCALE_Y 32.0f

// ** Ÿ�� ����, ���� �ִ� ����
#define COUNT_X (WIDTH/SCALE_X)
#define COUNT_Y (HEIGHT/SCALE_Y)

// ** Ÿ�� �ִ� ����
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