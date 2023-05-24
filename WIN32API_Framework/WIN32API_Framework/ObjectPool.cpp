#include "ObjectPool.h"
#include "GameObject.h"

ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}


void ObjectPool::ReturnObject(GameObject* _Object)
{
	// ** �Ķ���Ͱ� ����Ű���ִ� Ű ���� ���� map�� ���ԵǾ��ִ��� Ȯ��.
	map<string, list<GameObject*>>::iterator iter = PoolList.find(_Object->GetKey());

	// ** ���� Ű�� ���ٸ�....
	if (iter == PoolList.end())
	{
		// ** map�� ���Խ�ų list�� ��������...
		list<GameObject*> tempList;

		// ** ����Ʈ�� ������Ʈ�� �߰�.
		tempList.push_back(_Object);

		// ** ������Ʈ�� �߰��� ����Ʈ�� map�� �߰�.
		PoolList.insert(make_pair(_Object->GetKey(), tempList));
	}
	// ** �̹� Ű�� ���� �Ѵٸ�....
	else
		// ** �ش� ����Ʈ�� ������Ʈ�� �߰�.
		iter->second.push_back(_Object);
}

