#pragma once
#include "Include.h"

class Object;
class ObjectManager
{
private:
		static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	map<string, list<Object*>>ObjectList;
public:
	void AddObject(Object* _Object);

	list<Object*>* GetObjectList(string key);
	void Update();
	void Render(HDC _hdc);
private:
	ObjectManager();
public:
	~ObjectManager();
};

