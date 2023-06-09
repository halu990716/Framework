#pragma once
#include "GameObject.h"

class  Player : public GameObject
{
private:
	bool Attack;
	bool isJumping;
	float JumpHeight;
	float flightTime;

	int Direction;

	int Option;
	float oldY;
	float curentY;
public:
	// override 부모클래스의 순수가상함수를 재정의
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	//인라인 = 헤더에 바로 정의                                  // 기본 복사생성자 (this)
	virtual GameObject* Clone()override { return new Player(*this); }
public:
	template <typename T>
	GameObject* CreateBullet(string _Key);
	void SetFrame(int _frame, int _locomotion, int _endFrame, float _frameTime);
	void OnAttack();
	void OnMove();
	void OnJump();
public:
	Player();
	Player(Transform _transform) : GameObject(_transform) {}
	virtual ~Player();
};
