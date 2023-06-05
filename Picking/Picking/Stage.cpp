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
	ImageList["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Buffer.bmp");
	ImageList["GameOver"] = (new Bitmap)->LoadBmp(L"../Resource/GameOver.bmp");

	int mine = 150;

	for (int y = 0; y < COUNT_Y; ++y)
	{
		for (int x = 0; x < COUNT_X; ++x)
		{
			Object* tile = new Tile;
			tile->Start();

			tile->SetIndex(y * COUNT_X + x);

			if (mine)
			{
				--mine;
				tile->SetOption(10);
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

	// ** 모든 타일을 확인.
	// ** 주변 타일중에 지뢰가 몇개 있는지 확인 후 타일을 설정

	for (int i = 0; i < TileList.size(); ++i)
	{
		if (TileList[i]->GetOption() == 10)
			continue;

		// ** 12시 방향
		int index = TileList[i]->GetIndex() - COUNT_X;
		int count = 0;

		if (0 <= index && index < MAX &&
			TileList[index]->GetOption() == 10)
			count++;

		// ** 1시 방향
		index = TileList[i]->GetIndex() - COUNT_X + 1;
		if (0 <= index && index < MAX &&
			TileList[i]->GetPosition().x < TileList[index]->GetPosition().x &&
			TileList[index]->GetOption() == 10)
			count++;

		// ** 3시 방향
		index = TileList[i]->GetIndex() + 1;
		if (0 <= index && index < MAX &&
			TileList[i]->GetPosition().x < TileList[index]->GetPosition().x &&
			TileList[index]->GetOption() == 10)
			count++;

		// ** 5시 방향
		index = TileList[i]->GetIndex() + COUNT_X + 1;
		if (0 <= index && index < MAX &&
			TileList[i]->GetPosition().x < TileList[index]->GetPosition().x &&
			TileList[index]->GetOption() == 10)
			count++;

		// ** 6시 방향
		index = TileList[i]->GetIndex() + COUNT_X;
		if (0 <= index && index < MAX &&
			TileList[index]->GetOption() == 10)
			count++;

		// ** 7시 방향
		index = TileList[i]->GetIndex() + COUNT_X - 1;
		if (0 <= index && index < MAX &&
			TileList[index]->GetPosition().x < TileList[i]->GetPosition().x &&
			TileList[index]->GetOption() == 10)
			count++;

		// ** 9시 방향
		index = TileList[i]->GetIndex() - 1;
		if (0 <= index && index < MAX &&
			TileList[index]->GetPosition().x < TileList[i]->GetPosition().x &&
			TileList[index]->GetOption() == 10)
			count++;

		// ** 11시 방향
		index = TileList[i]->GetIndex() - COUNT_X - 1;
		if (0 <= index && index < MAX &&
			TileList[index]->GetPosition().x < TileList[i]->GetPosition().x &&
			TileList[index]->GetOption() == 10)
			count++;

		TileList[i]->SetOption(count + 1);
	}



	//list<Vector3>MinePositionList;

	//for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	//{
	//	if ((*iter)->GetOption() == 10)
	//	{
	//		Vector3 minePosition = (*iter)->GetPosition();
	//		MinePositionList.push_back(minePosition);
	//	}
	//}

	//for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	//{
	//	int nMine = 1;
	//	int tileSize = 32;

	//	if ((*iter)->GetOption() != 10)
	//	{
	//		for (list<Vector3>::iterator iter1 = MinePositionList.begin(); iter1 != MinePositionList.end(); ++iter1)
	//		{
	//			Vector3 position = (*iter)->GetPosition();

	//			if (position.x - tileSize == (*iter1).x && position.y - tileSize == (*iter1).y)
	//				nMine++;
	//			if (position.x == (*iter1).x && position.y - tileSize == (*iter1).y)
	//				nMine++;
	//			if (position.x + tileSize == (*iter1).x && position.y - tileSize == (*iter1).y)
	//				nMine++;
	//			if (position.x - tileSize == (*iter1).x && position.y == (*iter1).y)
	//				nMine++;
	//			if (position.x + tileSize == (*iter1).x && position.y == (*iter1).y)
	//				nMine++;
	//			if (position.x - tileSize == (*iter1).x && position.y + tileSize == (*iter1).y)
	//				nMine++;
	//			if (position.x == (*iter1).x && position.y + tileSize == (*iter1).y)
	//				nMine++;
	//			if (position.x + tileSize == (*iter1).x && position.y + tileSize == (*iter1).y)
	//				nMine++;
	//		}
	//		(*iter)->SetOption(nMine);
	//	}
	//}

	Object::SetImageList(&ImageList);
}



void Stage::Update()
{
	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		int z = (*iter)->Update();
		if ( z == 1)
		{
			// 게임오버
			Result = 1;
		}
	}
}

void Stage::Render(HDC hdc)
{

	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	}

	if (Result == 1)
	{
		TransparentBlt(ImageList["Buffer"]->GetMemDC(),
			0, 0,
			COUNT_X * SCALE_X + 16, COUNT_Y * SCALE_Y + 55,
			ImageList["GameOver"]->GetMemDC(),
			0, 0,
			COUNT_X * SCALE_X + 16, COUNT_Y * SCALE_Y + 55,
			RGB(255, 0, 255));
	}

	BitBlt(hdc,
		0, 0,
		COUNT_X * SCALE_X + 16, COUNT_Y * SCALE_Y + 55,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
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
