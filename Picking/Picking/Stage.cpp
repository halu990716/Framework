#include "Stage.h"
#include "Tile.h"
#include "ObjectManager.h"

Stage::Stage() : object(nullptr)
{
}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	for (int x = 0; x < 46; x++)
		for (int y = 0; y < 23; y++)
	ObjectManager::GetInstance()->AddObject((new Tile)->Start());
	TileList = ObjectManager::GetInstance()->GetObjectList("Tile");
}

void Stage::Update()
{
	if (TileList != nullptr && !TileList->empty())
	{
		int i = 0, j = 0;
		for (list<Object*>::iterator iter = TileList->begin(); iter != TileList->end(); iter++)
		{
			(*iter)->Update(i, j);
			i++;
			if (46 <= i)
			{
				i = 0;
				j++;
			}
		}
	}
}

void Stage::Render(HDC hdc)
{
	if (TileList != nullptr && !TileList->empty())
	{
		int i = 0, j = 0;
		for (list<Object*>::iterator iter = TileList->begin(); iter != TileList->end(); iter++)
		{
			(*iter)->Render(hdc, i, j);
			i++;
			if (46 <= i)
			{
				i = 0;
				j++;
			}
		}
	}
}

void Stage::Destroy()
{
	if (TileList != nullptr && !TileList->empty())
	{
		for (list<Object*>::iterator iter = TileList->begin(); iter != TileList->end(); iter++)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		TileList->clear();
	}
}
