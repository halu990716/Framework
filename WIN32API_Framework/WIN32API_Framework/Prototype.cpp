#include "Prototype.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

Prototype::Prototype()
{
}

Prototype::~Prototype()
{
}

void Prototype::Start()
{
	Transform transform;

	transform.position = Vector3(0.0f, 0.0f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(0.0f, 0.0f, 0.0f);

	// 리터널 상수 심볼릭 상수
	string key = "Player";
	PrototypeObject.insert(make_pair(key, (new Player(transform))->Start()->SetKey(key)));

	key = "GuideBullet";
	PrototypeObject.insert(make_pair(key, (new Bullet(transform))->Start()->SetKey(key)));

	key = "NormalBullet";
	PrototypeObject.insert(make_pair(key, (new Bullet(transform))->Start()->SetKey(key)));

	key = "Enemy";
	PrototypeObject.insert(make_pair(key, (new Enemy(transform))->Start()->SetKey(key)));

}

GameObject* Prototype::GetGameObject(string _key)
{
	map<string, GameObject*>::iterator iter = PrototypeObject.find(_key);

	if (iter == PrototypeObject.end())
		return nullptr;
	else
		return iter->second;
}
