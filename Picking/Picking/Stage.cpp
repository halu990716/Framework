#include "Stage.h"
#include "Tile.h"
#include "Bitmap.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	ImageList["Tile"] = (new Bitmap)->LoadBmp(L"../Resource/Tile.bmp");

	int mine = 100;

	for (int y = 0; y < COUNT_Y; ++y)
	{
		for (int x = 0; x < COUNT_X; ++x)
		{
			Object* tile = new Tile;
			tile->Start();

			int random = rand() % 100;

			if (mine)
			{
				--mine;
				tile->SetOption(8);
			}


			tile->SetPosition(
				Vector3(
					(x * SCALE_X) + (SCALE_X * 0.5f),
					(y * SCALE_Y) + (SCALE_Y * 0.5f)));


			TileList.push_back(tile);
		}
	}

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 100 > GetTickCount64())
		{
			int temp, dest;

			temp = rand() % TileList.size();
			dest = rand() % TileList.size();

			if (temp == dest)
				continue;

			int pTile = TileList[temp]->GetOption();
			TileList[temp]->SetOption(TileList[dest]->GetOption());
			TileList[dest]->SetOption(pTile);
		}
		else
			break;
	}

	// ** ��� Ÿ���� Ȯ��.
	// ** �ֺ� Ÿ���߿� ���ڰ� � �ִ��� Ȯ�� �� Ÿ���� ����

	list<Vector3>MinePositionList;

	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		if ((*iter)->GetOption() == 8)
		{
			Vector3 minePosition = (*iter)->GetPosition();
			MinePositionList.push_back(minePosition);
		}
	}

	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		int nMine = 0;
		int tileSize = 32;

		if ((*iter)->GetOption() != 8)
		{
			for (list<Vector3>::iterator iter1 = MinePositionList.begin(); iter1 != MinePositionList.end(); ++iter1)
			{
				Vector3 position = (*iter)->GetPosition();

				if (position.x - tileSize == (*iter1).x && position.y - tileSize == (*iter1).y)
					nMine++;
				if (position.x == (*iter1).x && position.y - tileSize == (*iter1).y)
					nMine++;
				if (position.x + tileSize == (*iter1).x && position.y - tileSize == (*iter1).y)
					nMine++;
				if (position.x - tileSize == (*iter1).x && position.y == (*iter1).y)
					nMine++;
				if (position.x + tileSize == (*iter1).x && position.y == (*iter1).y)
					nMine++;
				if (position.x - tileSize == (*iter1).x && position.y + tileSize == (*iter1).y)
					nMine++;
				if (position.x == (*iter1).x && position.y + tileSize == (*iter1).y)
					nMine++;
				if (position.x + tileSize == (*iter1).x && position.y + tileSize == (*iter1).y)
					nMine++;
			}
			(*iter)->SetOption(nMine);
		}
	}
	
	/*
	int index = 0;

	if (index < (MAX - 5) &&
		0 <= index &&
		CheckTileList(index + COUNT_X))
		index += COUNT_X;
	*/

	Object::SetImageList(&ImageList);
}



void Stage::Update()
{
	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		int z = (*iter)->Update();
		if ( z == 1)
		{
			// ���ӿ���
		}
	}
}

void Stage::Render(HDC hdc)
{
	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		(*iter)->Render(hdc);
	}
}

void Stage::Destroy()
{
	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	TileList.clear();
}
