#pragma once
#include "Include.h"

class GameObject;
class ObjectPool
{
public:
	Single(ObjectPool)
private:
	map<string, list<GameObject*>> PoolList;
public:
	list<GameObject*>* GetList(string _key) 
	{
		map<string, list<GameObject*>>::iterator iter = PoolList.find(_key);

		if (iter == PoolList.end())
			return nullptr;
		return &iter->second;
	}

	GameObject* GetGameObject(string _key)
	{
		list<GameObject*>* tempList = GetList(_key);

		if (tempList == nullptr)
			return nullptr;

		GameObject* Obj = tempList->front();
		tempList->pop_front();

		return Obj;
	}

	void ReturnObject(GameObject* _Object);
private:
	ObjectPool();
public:
	~ObjectPool();
};
	
// 생성된 불렛이 에너미와 충돌이 되었을때 충돌 확인후
// 충돌 판정시 불렛이 스스로 자신의 디스트로이 호출
// 오브덱트풀 -> 리턴 오브젝트 함수 호출
// 리턴 오브젝트 호출후 풀리스트에 추가