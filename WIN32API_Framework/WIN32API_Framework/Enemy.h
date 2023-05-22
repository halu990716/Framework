#pragma once
#include "GameObject.h"

class  Enemy : public GameObject
{
public:
	// override (virtual)이 아니더라도
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	//인라인 = 헤더에 바로 정의                                  // 기본 복사생성자 (this)
	virtual GameObject* Clone()override { return new Enemy(*this); }
public:
	Enemy();
	Enemy(Transform _transform) : GameObject(_transform) {}
	virtual ~Enemy();
};
