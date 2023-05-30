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
	// override �θ�Ŭ������ ���������Լ��� ������
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	//�ζ��� = ����� �ٷ� ����                                  // �⺻ ��������� (this)
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
