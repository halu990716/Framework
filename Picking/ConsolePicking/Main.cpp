#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>

using namespace std;

// ** Ÿ�� ����, ���� �ִ� ����
#define COUNT_X 9
#define COUNT_Y 9

#define BLACK					0
#define DARKBLUE			1
#define DARKGREEN		2
#define DARKSKYBLUE	3
#define DARKRED			4
#define DARKPURPLE		5
#define DARKYELLOW		6
#define GRAY					7
#define DARKGRAY			8
#define BLUE					9
#define GREEN					10
#define SKYBLUE				11
#define RED						12
#define PURPLE				13
#define YELLOW				14
#define WHITE					15

typedef struct tagVector3
{
	float x, y;

	tagVector3() : x(0.0f), y(0.0f) {}
	tagVector3(float _x, float _y) : x(_x), y(_y) {}

}Vector3;

void SetCorsorPosition(const float& _x, const float& _y);
void SetColor(int color);
void Text(const float& _x, const float& _y, const string& _str);

int main(void)
{
	// ** �÷��̾� ��ġ
	Vector3 playerPosition;
	playerPosition.x = 0;
	playerPosition.y = 0;

	// ** Ÿ�� ��ġ
	Vector3 position;
	position.x = 3;
	position.y = 2;

	// ** Ÿ�� ũ��
	Vector3 scale;
	scale.x = 6;
	scale.y = 3;

	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (time + 50 < GetTickCount64())
		{
			time = GetTickCount64();

			// ** ȭ�� û��
			system("cls");

			for (int y = 0; y < COUNT_Y; ++y)
			{
				for (int x = 0; x < COUNT_X; ++x)
				{
					SetColor(GRAY);

					// ** Ÿ�� ���
					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y,
						"������");

					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 1,
						"��  ��");

					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 2,
						"������");

					// ** index Ȯ��
					int index = y * COUNT_X + x;

					char* buffer = new char[4];
					_itoa(index, buffer, 10);

					SetColor(RED);

					if (playerPosition.y == y && playerPosition.x == x)
						SetColor(GRAY);

					Text(position.x - 1 + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 1,
						string(buffer));

				}
			}
			if (GetAsyncKeyState(VK_UP) && 0 < playerPosition.y)
			{
				playerPosition.y--;
			}

			if (GetAsyncKeyState(VK_DOWN) && playerPosition.y + 1 < COUNT_Y)
			{
				playerPosition.y++;
			}

			if (GetAsyncKeyState(VK_RIGHT) && playerPosition.x + 1 < COUNT_X)
			{
				playerPosition.x++;
			}

			if (GetAsyncKeyState(VK_LEFT) && 0 < playerPosition.x)
			{
				playerPosition.x--;
			}
			// ** CPU�� ������ ���� �ʴ� ����.
			Sleep(50);
		}
	}
	SetColor(GRAY);

	return 0;
}

void SetCorsorPosition(const float& _x, const float& _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(int _color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), _color);
}

void Text(const float& _x, const float& _y, const string& _str)
{
	SetCorsorPosition(_x, _y);
	cout << _str << endl;
}