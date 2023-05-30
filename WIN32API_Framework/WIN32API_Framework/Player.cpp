#include"Player.h"
#include"Bullet.h"
#include"ObjectManager.h"
#include "InputManager.h"
#include "Prototype.h"
#include "ObjectPool.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"

#include "NormalBullet.h"
#include "GuideBullet.h"
#include "Bitmap.h"

void Player::SetFrame(int _frame, int _locomotion, int _endFrame, float _frameTime)
{
}

void Player::OnAttack()
{
}

void Player::OnMove()
{
}

void Player::OnJump()
{
}

Player::Player()
{

}
Player::~Player()
{

}

GameObject* Player::Start()
{
	Attack = false;
	isJumping = false;
	JumpHeight = 10.0f;
	oldY = 0.0f;
	curentY = 0.0f;

	frame.CountX = 0;
	frame.CountY = 0;
	frame.EndFrame = 7;
	frame.FrameTime = 150;


	transform.position = Vector3(WIDTH * 0.5f, HEIGHT * 0.5f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(679 / 7, 639 / 9, 0.0f);

	Speed = 5.0f;

	Key = "Player";

	Time = GetTickCount64();
	return this;
}
	ULONGLONG Cool = GetTickCount64();
	float HP = 5;

int Player::Update()
{
	list<GameObject*>* enemyList = GetSingle(ObjectManager)->GetObjectList("Enemy");
	DWORD dwKey = GetSingle(InputManager)->GetKey();

	if (Time + frame.FrameTime < GetTickCount64())
	{
		Time = GetTickCount64();
		++frame.CountX;

		if (frame.CountX >= frame.EndFrame)
		{
			frame.CountX = 0;
			//frame.CountY = 0;

			if (Attack)
			{
				Attack = false;
				SetFrame(0, 0, 7, 150);
			}

			if (frame.EndFrame != 7)
				frame.EndFrame = 7;
		}

		//frame.CountX != 0 && dwKey  == 0 && dwKey != KEYID_SPACE
	}

	if (isJumping)
	{
		flightTime += 0.1f;

		transform.position.y += -sinf(90 * PI / )
	}

	if (dwKey & KEYID_LEFT && 20 < transform.position.x && 0 < HP)
	{
		Key = "PlayerFlip";

		transform.position.x -= Speed;

		if (Cool < GetTickCount64() - 300)
			frame.CountY = 1;
	}


	if (dwKey & KEYID_RIGHT && WIDTH - 30 > transform.position.x && 0 < HP)
	{
		Key = "Player";


		transform.position.x += Speed;

		if (Cool < GetTickCount64() - 300)
			frame.CountY = 1;
	}

	if (dwKey & KEYID_UP && 20 < transform.position.y && 0 < HP)
	{
		transform.position.y -= Speed;

		frame.EndFrame = 4;

		if(Cool < GetTickCount64() - 300)
			frame.CountY = 7;
	}

	if (dwKey & KEYID_DOWN && HEIGHT - 100 > transform.position.y && 0 < HP)
	{
		transform.position.y += Speed;

		frame.EndFrame = 4;

		if (Cool < GetTickCount64() - 300)
			frame.CountY = 7;
	}

 	if (dwKey & KEYID_SPACE && Cool < GetTickCount64() - 300 && 0 < HP)
	{
		GetSingle(ObjectManager)->AddObject(CreateBullet<NormalBullet>("NormalBullet"));

 		if (3 < frame.CountX)
			frame.CountX = 0;

		frame.CountY = 4;
		frame.EndFrame = 4;

	}

  	if (dwKey & KEYID_CONTROL)
		GetSingle(ObjectManager)->AddObject(CreateBullet<GuideBullet>("GuideBullet"));

	if (dwKey & KEYID_RETURN && Cool < GetTickCount64() - 1000 && 0 < HP)
	{
		Cool = GetTickCount64();

		frame.CountX = 0;

		frame.CountY = 3;
		frame.EndFrame = 5;
	}

	for (list<GameObject*>::iterator iter = enemyList->begin(); iter != enemyList->end(); ++iter)
		if (CollisionManager::CircleCollision(this, (*iter)) && Cool < GetTickCount64() - 500 && 0 < HP)
		{
			Cool = GetTickCount64();

			if(20 < transform.position.x)
				transform.position.x = transform.position.x - 10;

			frame.CountX = 0;

			frame.CountY = 5;
			frame.EndFrame = 2;

			HP--;
		}

	if (HP <= 0 && Cool < GetTickCount64())
	{
		Cool = 0;

		frame.CountX = 0;

		frame.CountY = 6;
		frame.EndFrame = 5;

	}
	return 0;
}

void Player::Render(HDC hdc)
{
	
	TransparentBlt(hdc,				// 복사해 넣을 그림판
		(int)(transform.position.x - transform.scale.x * 0.5f),			// 복사할 영역 시작점 X
		(int)(transform.position.y - transform.scale.y * 0.5f),			// 복사할 영역 시작점 Y
		(int)transform.scale.x,			// 복사할 영역 끝부분 X
		(int)transform.scale.y,			// 복사할 영역 끝부분 Y
		(*m_ImageList)[Key]->GetMemDC(),	// 복사할 이미지 (복사대상)
		(int)transform.scale.x * frame.CountX,						// 복사할 시작점 X
		(int)transform.scale.y * frame.CountY,					   // 복사할 시작점 Y
		(int)transform.scale.x,				// 출력할 이미지의 크기 만큼 X
		(int)transform.scale.y,				 // 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));				// 해당 색상을 제외

	/*
	Rectangle(hdc,
		int(transform.position.x - transform.scale.x * 0.5f),
		int(transform.position.y - transform.scale.y * 0.5f),
		int(transform.position.x + transform.scale.x * 0.5f),
		int(transform.position.y + transform.scale.y * 0.5f));
	*/

}

void Player::Destroy()
{

}

template <typename T>
GameObject* Player::CreateBullet(string _Key)
{
	GameObject* Obj = GetSingle(ObjectPool)->GetGameObject(_Key);

	if (Obj == nullptr)
	{
		Bridge* pBridge = new T;
		pBridge->Start();
		((BulletBridge*)pBridge)->SetTarget(this);

		GameObject* ProtoObj = GetSingle(Prototype)->GetGameObject(_Key);

		//list<GameObject*>* BulletList = GetSingle(ObjectPool)->GetList();

		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			Object->Start();
			Object->SetPosition(transform.position);
			Object->SetKey(_Key);

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

	Obj->Start();
	Obj->SetPosition(transform.position);
	Obj->SetKey(_Key);

	return Obj;
}