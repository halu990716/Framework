#include"Player.h"
#include"Bullet.h"
#include"ObjectManager.h"
#include "InputManager.h"
#include "Prototype.h"
#include "ObjectPool.h"
#include "ObjectFactory.h"

#include "NormalBullet.h"
#include "GuideBullet.h"

Player::Player()
{

}
Player::~Player()
{

}
GameObject* Player::Start()
{
	transform.position = Vector3(WIDTH * 0.5f, HEIGHT * 0.5f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(100.0f, 100.0f, 0.0f);

	Speed = 5.0f;

	return this;
}

int Player::Update()
{
	DWORD dwKey = GetSingle(InputManager)->GetKey();

	if (dwKey & KEYID_UP)
	{
		transform.position.y -= Speed;
	}
	if (dwKey & KEYID_DOWN)
	{
		transform.position.y += Speed;
	}
	if (dwKey & KEYID_LEFT)
	{
		transform.position.x -= Speed;
	}
	if (dwKey & KEYID_RIGHT)
	{
		transform.position.x += Speed;
	}

	if (dwKey & KEYID_SPACE)
		GetSingle(ObjectManager)->AddObject(CreateBullet<NormalBullet>());

	if (dwKey & KEYID_CONTROL)
		GetSingle(ObjectManager)->AddObject(CreateBullet<GuideBullet>());

	return 0;
}

void Player::Render(HDC hdc)
{

	Rectangle(hdc, 
		int(transform.position.x - transform.scale.x * 0.5f),
		int(transform.position.y - transform.scale.y * 0.5f),
		int(transform.position.x + transform.scale.x * 0.5f),
		int(transform.position.y + transform.scale.y * 0.5f));

	
}

void Player::Destroy()
{

}

template <typename T>
GameObject* Player::CreateBullet()
{
	Bridge* pBridge = new T;
	pBridge->Start();
	((BulletBridge*)pBridge)->SetTarget(this);

	GameObject* ProtoObj = GetSingle(Prototype)->GetGameObject("Bullet");

	//list<GameObject*>* BulletList = GetSingle(ObjectPool)->GetList();

	if (ProtoObj != nullptr)
	{
		GameObject* Object = ProtoObj->Clone();
		Object->Start();
		Object->SetPosition(transform.position);

		pBridge->SetObject(Object);
		Object->SetBridge(pBridge);

		return Object;
		/*
		if (BulletList->begin() == BulletList->end())
		{
		return ObjectFactory<Bullet>::CreateObject(transform.position);
		}
		else
		{
			list<GameObject*>::iterator iter = BulletList->begin();
			(*iter)->Start();
			(*iter)->SetPosition(transform.position);

			return (*iter);
		}
		*/
	}
	else
		return nullptr;
}