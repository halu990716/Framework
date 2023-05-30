#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"
#include "Prototype.h"
#include "CollisionManager.h"
#include "ObjectPool.h"

#include "ImagerManager.h"
#include "Bitmap.h"



Stage::Stage() :m_pPlayer(nullptr), EnemyList(nullptr), BulletList(nullptr)
{

}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	GetSingle(Prototype)->Start();

	{
		GameObject* ProtoObj = GetSingle(Prototype)->GetGameObject("Player");

		if (ProtoObj != nullptr)
		{
			m_pPlayer = ProtoObj->Clone();
			m_pPlayer->Start();
		}
	}

	{
		GameObject* ProtoObj = GetSingle(Prototype)->GetGameObject("Enemy");

		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			GetSingle(ObjectManager)->AddObject(Object->Start());
		}

	}


	EnemyList = GetSingle(ObjectManager)->GetObjectList("Enemy");
	//BulletList = nullptr;

	// 사용할 이미지리스트 생성
	m_mapImageList = GetSingle(ImagerManager)->GetImageList();

	(*m_mapImageList)["BackGround"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/BackGround (1).bmp");
	(*m_mapImageList)["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/Buffer.bmp");
	(*m_mapImageList)["PlayerR"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/Player.bmp");
	(*m_mapImageList)["PlayerL"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/PlayerFlip.bmp");

	GameObject::SetImageList(m_mapImageList);

}

int Stage::Update()
{
    if(m_pPlayer)
		m_pPlayer->Update();

	GetSingle(ObjectManager)->Update();
	/*
	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
		{
			(*iter)->Update();
		}
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			(*iter)->Update();

			if (EnemyList != nullptr && !EnemyList->empty())
			{
				if (CollisionManager::CircleCollision((*iter), (*EnemyList->begin())))
				{
					(*iter)->Destroy();
				}
			}
		};
	}
	else
		BulletList = GetSingle(ObjectManager)->GetObjectList("Bullet");
	*/



	return 0;
}


void Stage::Render(HDC hdc)
{
	BitBlt((*m_mapImageList)["Buffer"]->GetMemDC(),			// 복사해 넣을 그림판?!
		0, 0, WIDTH, HEIGHT,			// 복사할 영역 시작점으로부터 끝부분까지
		(*m_mapImageList)["BackGround"]->GetMemDC(), // 복사할 이미지
		0, 0,					// 스케일을 잡아준다
		SRCCOPY);			// 소스 영역을 대상 영역에 복사한다.

	if (m_pPlayer)
		m_pPlayer->Render(
			(*m_mapImageList)["Buffer"]->GetMemDC());

	GetSingle(ObjectManager)->Render((*m_mapImageList)["Buffer"]->GetMemDC());

	BitBlt(hdc,			// 복사해 넣을 그림판?!
		0, 0, WIDTH, HEIGHT,			// 복사할 영역 시작점으로부터 끝부분까지
		(*m_mapImageList)["Buffer"]->GetMemDC(), // 복사할 이미지
		0, 0,					// 스케일을 잡아준다
		SRCCOPY);			// 소스 영역을 대상 영역에 복사한다.



#ifdef DEBUG
	list<GameObject*>* enemyList = GetSingle(ObjectManager)->GetObjectList("Enemy");
	list<GameObject*>* nomalList = GetSingle(ObjectManager)->GetObjectList("NormalBullet");
	list<GameObject*>* guideList = GetSingle(ObjectManager)->GetObjectList("GuideBullet");

	if (enemyList != nullptr && !enemyList->empty())
	{
		// ** Buffer 생성
		// ** 배열의 길이는 중요하지 않음. (충분하면 됨)
		char* enemyBuffer = new char[128];

		// ** 정수를 문자열로 변환. 10진수로 변환됨
		_itoa((int)enemyList->size(), enemyBuffer,10);

		// ** 문자열 포인터를 string 으로 변환.
		string str(enemyBuffer);

		// ** 문자열 포인터 배열 삭제.
		delete[] enemyBuffer;
		enemyBuffer = nullptr;

		// ** 유니코드형태로 생성
		wchar_t* t = new wchar_t[(int)str.size()];

		// ** 문자열 복사.
		mbstowcs(t, str.c_str(), (int)str.size());

		// ** 출력
		TextOut(hdc, 50, 50, (LPCWSTR)t, (int)str.size());
	}

	if (nomalList != nullptr && !nomalList->empty())
	{
		char* NormarBuffer = new char[128];
		_itoa((int)nomalList->size(), NormarBuffer,10);

		string str(NormarBuffer);

		delete[] NormarBuffer;
		NormarBuffer = nullptr;

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());


		TextOut(hdc, 50, 70, (LPCWSTR)t, str.size());
	}

	if (guideList != nullptr && !guideList->empty())
	{
		char* GuideBuffer = new char[128];
		_itoa((int)guideList->size(), GuideBuffer,10);

		string str(GuideBuffer);

		delete[] GuideBuffer;
		GuideBuffer = nullptr;

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());


		TextOut(hdc, 50, 90, (LPCWSTR)t, (int)str.size());
	}

	list<GameObject*>* NormalBulletList = GetSingle(ObjectManager)->GetObjectList("NormalBullet");
	list<GameObject*>* GuideBulletList = GetSingle(ObjectManager)->GetObjectList("GuideBullet");

	if (NormalBulletList != nullptr && !NormalBulletList->empty())
	{
		char* NormarBuffer = new char[128];
		_itoa((int)NormalBulletList->size(), NormarBuffer, 10);

		string str(NormarBuffer);

		delete[] NormarBuffer;
		NormarBuffer = nullptr;

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());


		TextOut(hdc, 100, 70, (LPCWSTR)t, (int)str.size());
	}

	if (GuideBulletList != nullptr && !GuideBulletList->empty())
	{
		char* GuideBuffer = new char[128];
		_itoa(GuideBulletList->size(), GuideBuffer, 10);

		string str(GuideBuffer);

		delete[] GuideBuffer;
		GuideBuffer = nullptr;

		wchar_t* t = new wchar_t[str.size()];
		mbstowcs(t, str.c_str(), str.size());


		TextOut(hdc, 100, 90, (LPCWSTR)t, str.size());
	}
#else

#endif // DEBUG


	//ObjectManager::GetInstance()->Render(hdc);

	/*
	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
		{
			(*iter)->Render(hdc);
		}
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			(*iter)->Render(hdc);
		}
	}
	*/
	
}

void Stage::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		EnemyList->clear();
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		BulletList->clear();
	}
}

