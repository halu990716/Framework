#pragma once
#include "Include.h"

class GameObject;
class ObjectPool
{
public:
	Single(ObjectPool)
private:
	list<GameObject*> PoolList;
public:
	list<GameObject*>* GetList() { return &PoolList; }
	void ReturnObject(GameObject* _Object);
private:
	ObjectPool();
public:
	~ObjectPool();
};
	
// ������ �ҷ��� ���ʹ̿� �浹�� �Ǿ����� �浹 Ȯ����
// �浹 ������ �ҷ��� ������ �ڽ��� ��Ʈ���� ȣ��
// ���굦ƮǮ -> ���� ������Ʈ �Լ� ȣ��
// ���� ������Ʈ ȣ���� Ǯ����Ʈ�� �߰�