#include "Bullet.h"
#include"Player.h"

Bullet::Bullet()
{

}
Bullet::~Bullet()
{

}
void Bullet::Start()
{
	transform.position = new Vector3(0, 0, 0.0f);
	transform.rotation = new Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = new Vector3(0, 0, 0.0f);
}
void Bullet::Update()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		transform.position = new Vector3(100.0f, 100.0f, 0.0f);
		transform.rotation = new Vector3(0.0f, 0.0f, 0.0f);
		transform.scale = new Vector3(10.0f, 10.0f, 0.0f);
	}
	transform.position->x += 10.0f;

}
void Bullet::Render(HDC hdc)
{
	Rectangle(hdc,
		int(transform.position->x - transform.scale->x * 0.5f),
		int(transform.position->y - transform.scale->y * 0.5f),
		int(transform.position->x + transform.scale->x * 0.5f),
		int(transform.position->y + transform.scale->y * 0.5f));
}
void Bullet::Destroy()
{

}
