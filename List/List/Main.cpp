#include <iostream>

using namespace std;

// 1. 함수 사용.
// 2. 클래스 이해도.

//  for(초기문, 조건문, 증감문)

// ** 초기문 : in i = 0;
// ** 조건문 : i < 10;
// ** 증감문 : ++i

// while == for

// if != switch

// 런타임 이전 가장 먼저하는게 초기화
// 스태틱 전역 글로벌 런타임이전 생성

// return 0 = 정상종료

// return !0 = 다른 케이스

// return -1 = 오류


#define function(x) (cout << x << endl)

class xObject
{
protected:
	string name;
	int age;
public:
	
};

#define Single(T)											 \
public:																 \
	static T& GetInstance()					     \
	{																	 \
		static T instance;								 \
		return instance;									 \
	}																	 \
	private:														 \
		T(const T&) = delete;							 \
		T& operator = (const T&) = delete;

#define GetSingle(T) (T::GetInstance())

class Singleton
{
	Single(Singleton)
	/*
private:
	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton;

		return Instance;
	}
	*/
private:
	int Value;

public:
	int GetValue() { return Value; }
	void SetValue(int _value) { Value = _value; }
private:
	Singleton() : Value(0) {}
public:
	~Singleton() {}
};

//Singleton* Singleton::Instance = nullptr;

class inputmanager : public Singleton
{

};

class Object
{
protected:
	string name;
	int age;
public:
	virtual void Start(int x) = 0;
	virtual int Update(int x) = 0;
};

class Player : public Object
{
public:
	virtual void Start(int x) override
	{
		age = x;
	}

	virtual int Update(int x) override
	{
		if (age < x)
			return 1;

		return 0;
	}
};

class Bullet : public Object
{
public:
	virtual void Start(int x) override
	{
		age = x;
	}

	virtual int Update(int x) override
	{
		if (age < x)
			return 1;

		return 0;
	}
};

int main(void)
{
	GetSingle(Singleton).SetValue(10);

	cout << GetSingle(Singleton).GetValue() << endl;
	/*
	function(10);
	Object* player = new Player;

	int length = 16;
	Object* bulletList = new Bullet[length];

	for (int i = 0; i < length; ++i)
	{
		bulletList->Start(i);

		if (bulletList[i].Update(i))
			cout << "Bullet age 값이 " << i << "보다 작습니다." << endl;
	}

	int value = 10;

		if (player->Update(value))
		{
			cout << "player age 값이 : " << value << "보다 작습니다." << endl;
			//break;
		}
	*/

	return 0;
}