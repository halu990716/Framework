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

	// ����� �̹�������Ʈ ����
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
	BitBlt((*m_mapImageList)["Buffer"]->GetMemDC(),			// ������ ���� �׸���?!
		0, 0, WIDTH, HEIGHT,			// ������ ���� ���������κ��� ���κб���
		(*m_mapImageList)["BackGround"]->GetMemDC(), // ������ �̹���
		0, 0,					// �������� ����ش�
		SRCCOPY);			// �ҽ� ������ ��� ������ �����Ѵ�.

	if (m_pPlayer)
		m_pPlayer->Render(
			(*m_mapImageList)["Buffer"]->GetMemDC());

	GetSingle(ObjectManager)->Render((*m_mapImageList)["Buffer"]->GetMemDC());

	BitBlt(hdc,			// ������ ���� �׸���?!
		0, 0, WIDTH, HEIGHT,			// ������ ���� ���������κ��� ���κб���
		(*m_mapImageList)["Buffer"]->GetMemDC(), // ������ �̹���
		0, 0,					// �������� ����ش�
		SRCCOPY);			// �ҽ� ������ ��� ������ �����Ѵ�.



#ifdef DEBUG
	list<GameObject*>* enemyList = GetSingle(ObjectManager)->GetObjectList("Enemy");
	list<GameObject*>* nomalList = GetSingle(ObjectManager)->GetObjectList("NormalBullet");
	list<GameObject*>* guideList = GetSingle(ObjectManager)->GetObjectList("GuideBullet");

	if (enemyList != nullptr && !enemyList->empty())
	{
		// ** Buffer ����
		// ** �迭�� ���̴� �߿����� ����. (����ϸ� ��)
		char* enemyBuffer = new char[128];

		// ** ������ ���ڿ��� ��ȯ. 10������ ��ȯ��
		_itoa((int)enemyList->size(), enemyBuffer,10);

		// ** ���ڿ� �����͸� string ���� ��ȯ.
		string str(enemyBuffer);

		// ** ���ڿ� ������ �迭 ����.
		delete[] enemyBuffer;
		enemyBuffer = nullptr;

		// ** �����ڵ����·� ����
		wchar_t* t = new wchar_t[(int)str.size()];

		// ** ���ڿ� ����.
		mbstowcs(t, str.c_str(), (int)str.size());

		// ** ���
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

