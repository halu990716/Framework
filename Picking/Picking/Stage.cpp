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
	object = new Tile;
	object->Start();
}

void Stage::Update()
{
	object->Update();

	if (TileList != nullptr && !TileList->empty())
	{
		for (list<Object*>::iterator iter = TileList->begin(); iter != TileList->end(); iter++)
		{
			(*iter)->Update();
		}
	}
	else
		TileList = ObjectManager::GetInstance()->GetObjectList("Tile");
}

void Stage::Render(HDC hdc)
{
	object->Render(hdc);

	if (TileList != nullptr && !TileList->empty())
	{
		for (list<Object*>::iterator iter = TileList->begin(); iter != TileList->end(); iter++)
		{
			(*iter)->Render(hdc);
		}
	}
}

void Stage::Destroy()
{
	delete object;
	object = nullptr;

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
