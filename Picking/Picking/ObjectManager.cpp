#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	if (iter == ObjectList.end())
	{
		list<Object*> tempList;
		tempList.push_back(_Object);
		ObjectList.insert(make_pair(_Object->GetKey(), tempList));
	}
	else
		iter->second.push_back(_Object);
}

list<Object*>* ObjectManager::GetObjectList(string key)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(key);

	if (iter == ObjectList.end())
		return nullptr;
	else
		return &iter->second;
}

void ObjectManager::Update()
{
}

void ObjectManager::Render(HDC _hdc)
{
}
