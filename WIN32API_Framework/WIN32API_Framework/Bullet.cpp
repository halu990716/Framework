#include "Bullet.h"
#include "ObjectPool.h"
#include "NormalBullet.h"

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

	float distance = sqrt((transform.position.x * transform.position.x) +
		(transform.position.y * transform.position.y));

	Key = "Bullet";

	return this;
}

int Bullet::Update()
{
	if (pBridge)
		pBridge->Update(transform);

	if (transform.position.x > WIDTH)
	{
		Destroy();
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

