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
	TransparentBlt(hdc,				// 복사해 넣을 그림판
		Object->GetPosition().x - Object->GetScale().x * 0.5f,			// 복사할 영역 시작점 X
		Object->GetPosition().y - Object->GetScale().y * 0.5f,			// 복사할 영역 시작점 Y
		Object->GetScale().x,			// 복사할 영역 끝부분 X
		Object->GetScale().y,			// 복사할 영역 끝부분 Y
		(*m_ImageList)[Key]->GetMemDC(),	// 복사할 이미지 (복사대상)
		Object->GetScale().x * frame.CountX,						// 복사할 시작점 X
		Object->GetScale().y * frame.CountY,					   // 복사할 시작점 Y
		Object->GetScale().x,				// 출력할 이미지의 크기 만큼 X
		Object->GetScale().y,				 // 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));				// 해당 색상을 제외
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
