#include "NormalBullet.h"
#include "Bullet.h"

NormalBullet::NormalBullet()
{
}

NormalBullet::~NormalBullet()
{
}


void NormalBullet::Start()
{
	Speed = 15.0f;
}

void NormalBullet::Update(Transform& transform)
{
	transform.position += transform.direction * Speed;
}

void NormalBullet::Render(HDC hdc)
{
	/*
	TransparentBlt(hdc,				// ������ ���� �׸���
		Object->GetPosition().x - Object->GetScale().x * 0.5f,			// ������ ���� ������ X
		Object->GetPosition().y - Object->GetScale().y * 0.5f,			// ������ ���� ������ Y
		Object->GetScale().x,			// ������ ���� ���κ� X
		Object->GetScale().y,			// ������ ���� ���κ� Y
		(*m_ImageList)[Key]->GetMemDC(),	// ������ �̹��� (������)
		Object->GetScale().x * frame.CountX,						// ������ ������ X
		Object->GetScale().y * frame.CountY,					   // ������ ������ Y
		Object->GetScale().x,				// ����� �̹����� ũ�� ��ŭ X
		Object->GetScale().y,				 // ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));				// �ش� ������ ����
	 */

	Ellipse(hdc,
		int(Object->GetPosition().x - (Object->GetScale().x * 0.5f)),
		int(Object->GetPosition().y - (Object->GetScale().y * 0.5f)),
		int(Object->GetPosition().x + (Object->GetScale().x * 0.5f)),
		int(Object->GetPosition().y + (Object->GetScale().y * 0.5f)));
}

void NormalBullet::Destroy()
{

}
