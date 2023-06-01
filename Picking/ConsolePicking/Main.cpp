#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>

using namespace std;

// ** Ÿ�� ����, ���� �ִ� ����
#define COUNT_X 5
#define COUNT_Y 5

// ** Ÿ�� �ִ� ����
const int MAX = COUNT_X * COUNT_Y;

// ** Ÿ�� ũ��
const Vector3 scale(6, 3);

//#define BLACK					0
//#define DARKBLUE			1
//#define DARKGREEN		2
//#define DARKSKYBLUE	3
//#define DARKRED			4
//#define DARKPURPLE		5
//#define DARKYELLOW		6
//#define GRAY					7
//#define DARKGRAY			8
//#define BLUE					9
//#define GREEN					10
//#define SKYBLUE				11
//#define RED						12
//#define PURPLE				13
//#define YELLOW				14
//#define WHITE					15

// ** ��
enum COLOR
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKSKYBLUE,
	DARKRED,
	DARKPURPLE,
	DARKYELLOW,
	GRAY,
	DARKGRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
};

// ** ���� ����
void SetCorsorPosition(const float& _x, const float& _y);
void SetColor(int color);
void Text(const float& _x, const float& _y, const string& _str, int _color);
bool CheckTileList(int _index);

// ** ���� Ǯ� ����
typedef struct tagVector3
{
	float x, y;

	tagVector3() : x(0.0f), y(0.0f) {}
	tagVector3(float _x, float _y) : x(_x), y(_y) {}

}Vector3;

typedef struct tagTile
{
	Vector3 position[4];
	string tile[4];
	int option;
	int value;
	int color;
	bool check;

	void Render()
	{
		switch (option)
		{
		case 0:
			color = 15;
			break;

		case 1:
			color = 12;
			break;
		}

		for (int i = 0; i < 3; i++)
			Text(position[i].x, position[i].y, tile[i], color);

	}

	tagTile() : option(0), value(0), color(0), check(false) {}

}Tile;

typedef struct tagInfo
{
	Vector3 position;
	string tile;
	int option;

	tagInfo() : option(0) {}

}Info;

list<Tile*>BlackTileList;

int main(void)
{
	// ** Ÿ�� ��ġ ����
	vector<Tile*> TileList;

	int x = 0;
	int y = 0;

	for (int i = 0; i < COUNT_Y * COUNT_X; i++)
	{
		Tile* tile = new Tile;

		tile->tile[0] = "������";
		tile->position[0] = Vector3(x * scale.x, y * scale.y);
		
		tile->tile[1] = "��  ��";
		tile->position[1] = Vector3(x * scale.x, y * scale.y + 1);
		
		tile->tile[2] = "������";
		tile->position[2] = Vector3(x * scale.x, y * scale.y + 2);

		//char* buffer = new char[4];

		//_itoa(tile->value, buffer, 10);

		//tile->position[3] = Vector3(x * scale.x + 2, y * scale.y +1);

		//Text(position)

		tile->option = 0;
		tile->color = 15;
		tile->value = i + 1;
		tile->check = true;

		x++;

		if (x == COUNT_X)
		{
			x = 0;
			y++;
		}

		TileList.push_back(tile);
	}

	srand(unsigned int(GetTickCount64()));

	for (int i = 0; i < COUNT_Y * COUNT_X; i++)
	{
		int random1 = rand() % 25;
		int random2 = rand() % 25;

		if (random1 == random2)
			continue;
		else
		{
			int value = TileList[random1]->value;
			TileList[random1]->value = TileList[random2]->value;
			TileList[random2]->value = value;
		}
	}

	for (int i = 0; i < COUNT_Y * COUNT_X; i++)
	{
		char* buffer = new char[4];

		_itoa(TileList[i]->value, buffer, 10);

		TileList[i]->position[3] = Vector3(TileList[i]->position[1].x + 2, TileList[i]->position[1].y);
		TileList[i]->tile[3] = string(buffer);
	}

	Vector3 position;
	position.x = 3;
	position.y = 2;


	// ** Target
	Info Cursur;
	Cursur.position = Vector3(15.0f, 8.0f);
	Cursur.option = 0;

	/*

	for (int i = 0; i < 3; ++i)
	{
		int random = rand() % 25;

		TileList[random]->option = 1;

		BlackTileList.push_back(TileList[random]);
	}
	*/

	// ** Ŀ���� ��ġ�� ������ �ε���
	int X = int(Cursur.position.x / scale.x);
	int Y = int(Cursur.position.y / scale.y);

	int index = Y * COUNT_Y + X;

	ULONGLONG time = GetTickCount64();

	while (true)
	{
		SetColor(7);

		if (time + 50 < GetTickCount64())
		{
			time = GetTickCount64();

			// ** ȭ�� û��
			system("cls");

			if (GetAsyncKeyState(VK_RETURN))
				index = 0;

			if (GetAsyncKeyState(VK_UP))
			{
				if(index < MAX &&
					5 <= index &&
					CheckTileList(index - COUNT_X))
				index -= COUNT_X;
			}

			if (GetAsyncKeyState(VK_DOWN))
			{
				if (index < (MAX - 5) &&
					0 <= index &&
					CheckTileList(index + COUNT_X))
					index += COUNT_X;
			}

			if (GetAsyncKeyState(VK_RIGHT))
			{
				if (index % 5 - 4 != 0 &&
					CheckTileList(index + 1))
					index += 1;
			}

			if (GetAsyncKeyState(VK_LEFT))
			{
				if (index % 5 != 0 &&
					CheckTileList(index - 1))
					index -= 1;
			}

			if (GetAsyncKeyState(VK_SPACE))
			{
				Text(57, 14, "Input!", 10);
				TileList[index]->option = !TileList[index]->option;
			}

			// ** ���
			for (int i = 0; i < TileList.size(); i++)
			{
				if (index == i)
				{
					Text(TileList[index]->position[0].x,
						TileList[index]->position[0].y,
						TileList[index]->tile[0],
						2);

					Text(TileList[index]->position[1].x,
						TileList[index]->position[1].y,
						TileList[index]->tile[1],
						2);
					
					Text(TileList[index]->position[2].x,
						TileList[index]->position[2].y,
						TileList[index]->tile[2],
						2);

					/*Text(TileList[index]->position[3].x,
						TileList[index]->position[3].y,
						TileList[index]->tile[3],
						15);*/
				}
				else
					TileList[i]->Render();

				Text(TileList[i]->position[3].x,
					TileList[i]->position[3].y,
					TileList[i]->tile[3],
					15);
				/*
				else
				{
					if (TileList[i]->option == 1)
						TileList[i]->Render(0);
					else
						TileList[i]->Render(15);
				}
				*/
			}


			// ** CPU�� ������ ���� �ʴ� ����.
			Sleep(50);
		}
	}
	return 0;
}

void SetCorsorPosition(const float& _x, const float& _y)
{
	COORD pos = { (SHORT)_x,(SHORT) _y };

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(const int _color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), _color);
}

void Text(const float& _x, const float& _y, const string& _str, int _color)
{
	SetColor(_color);
	SetCorsorPosition(_x, _y);
	cout << _str << endl;
}

bool CheckTileList(int _index)
{
	for (list<Tile*>::iterator iter = BlackTileList.begin(); iter != BlackTileList.end(); iter++)
	{
		if ((*iter)->value == _index)
			return false;
	}
	return true;
}