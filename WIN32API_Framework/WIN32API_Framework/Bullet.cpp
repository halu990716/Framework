#include "Bullet.h"
#include "ObjectPool.h"
#include "NormalBullet.h"
#include "CollisionManager.h"
#include "ObjectManager.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
	Destroy();
}

GameObject* Bullet::Start()
{
	transform.position = Vector3(0.0f, 0.0f, 0.0f);
	transform.direction = Vector3(1.0f, 0.0f, 0.0f);
	transform.scale = Vector3(30.0f, 30.0f, 0.0f);

	Key = "Bullet";

	return this;
}

int Bullet::Update()
{
	list<GameObject*>* enemyList = GetSingle(ObjectManager)->GetObjectList("Enemy");

	if (pBridge)
		pBridge->Update(transform);

	for (list<GameObject*>::iterator iter = enemyList->begin(); iter != enemyList->end(); ++iter)
		if (CollisionManager::CircleCollision(this, (*iter)) || transform.position.x > WIDTH)
		{
			return 1;
		}


	return 0;
}

void Bullet::Render(HDC hdc)
{
	if (pBridge)
		pBridge->Render(hdc);
}

void Bullet::Destroy()
{
	GetSingle(ObjectPool)->ReturnObject(this);
	transform.scale = Vector3(0.0f, 0.0f, 0.0f);
}

