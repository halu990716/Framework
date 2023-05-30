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

	Key = "PlayerR";

	Time = GetTickCount64();
	return this;
}

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

		transform.position.y += -sinf(90 * PI / 180) * JumpHeight + (flightTime * flightTime * 0.98f);

		if (curentY < transform.position.y)
			SetFrame(frame.CountX, 3, 3, 50);
		else
			SetFrame(frame.CountX, 2, 3, 50);

		curentY = transform.position.y;

		if (oldY < transform.position.y)
		{
			flightTime = 0.0f;
			transform.position.y = oldY;
			isJumping = false;
		}
	}

 	if (dwKey & KEYID_SPACE)
	{
		SetFrame(frame.CountX, 0, 7, 1500 / 7);
		OnAttack();
	}

	if (dwKey & KEYID_CONTROL)
		OnJump();

	if (!Attack)
	{
		if (dwKey & KEYID_UP)
			transform.position.y -= Speed;

		if (dwKey & KEYID_DOWN)
			transform.position.y += Speed;


		if (GetAsyncKeyState('1'))
			Option = 0;

		if (GetAsyncKeyState('2'))
			Option = 1;


		if (dwKey & KEYID_LEFT)
			transform.direction.x = (-1.0f);
		else if (dwKey & KEYID_RIGHT)
			transform.direction.x = 1.0f;
		else
			transform.direction.x = 0.0f;
	}

	if (transform.direction.x)
	{
		SetFrame(frame.CountX, 2, 7, 500 / 7);
		OnMove();
	}
	else if (!isJumping)
		SetFrame(frame.CountX, 0, 7, 1500 / 7);

	if (dwKey & KEYID_RETURN)
	{
		frame.CountX = 0;

		frame.CountY = 3;
		frame.EndFrame = 5;
	}

	for (list<GameObject*>::iterator iter = enemyList->begin(); iter != enemyList->end(); ++iter)
		if (CollisionManager::CircleCollision(this, (*iter)))
		{
			if(20 < transform.position.x)
				transform.position.x = transform.position.x - 10;

			frame.CountX = 0;

			frame.CountY = 5;
			frame.EndFrame = 2;
		}
	return 0;
}

void Player::Render(HDC hdc)
{
	
	TransparentBlt(hdc,				// ������ ���� �׸���
		(int)(transform.position.x - transform.scale.x * 0.5f),			// ������ ���� ������ X
		(int)(transform.position.y - transform.scale.y * 0.5f),			// ������ ���� ������ Y
		(int)transform.scale.x,			// ������ ���� ���κ� X
		(int)transform.scale.y,			// ������ ���� ���κ� Y
		(*m_ImageList)[Key]->GetMemDC(),	// ������ �̹��� (������)
		(int)transform.scale.x * frame.CountX,						// ������ ������ X
		(int)transform.scale.y * frame.CountY,					   // ������ ������ Y
		(int)transform.scale.x,				// ����� �̹����� ũ�� ��ŭ X
		(int)transform.scale.y,				 // ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));				// �ش� ������ ����

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

void Player::SetFrame(int _frame, int _locomotion, int _endFrame, float _frameTime)
{
	frame.CountX = _frame;
	frame.CountY = _locomotion;
	frame.EndFrame = _endFrame;
	frame.FrameTime = _frameTime;
}

void Player::OnAttack()
{
	if (Attack)
		return;

	Attack = true;
	SetFrame(0, 5, 4, 1500 / 4);

	switch (Option)
	{
	case 0:
		GetSingle(ObjectManager)->AddObject(CreateBullet<NormalBullet>("NormalBullet"));
		break;

	case 1:
		GetSingle(ObjectManager)->AddObject(CreateBullet<GuideBullet>("GuideBullet"));
		break;

	}
}

void Player::OnMove()
{
	transform.position += transform.direction * Speed;
	Key = transform.direction.x < 0 ? "PlayerL" : "PlayerR";
}

void Player::OnJump()
{
	if (isJumping)
		return;

	isJumping = true;
	oldY = transform.position.y;
	frame.CountX = 0;
}