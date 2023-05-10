#include <iostream>

using namespace std;

// 1. �Լ� ���.
// 2. Ŭ���� ���ص�.

//  for(�ʱ⹮, ���ǹ�, ������)

// ** �ʱ⹮ : in i = 0;
// ** ���ǹ� : i < 10;
// ** ������ : ++i

// while == for

// if != switch

// ��Ÿ�� ���� ���� �����ϴ°� �ʱ�ȭ
// ����ƽ ���� �۷ι� ��Ÿ������ ����

// return 0 = ��������

// return !0 = �ٸ� ���̽�

// return -1 = ����


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
			cout << "Bullet age ���� " << i << "���� �۽��ϴ�." << endl;
	}

	int value = 10;

		if (player->Update(value))
		{
			cout << "player age ���� : " << value << "���� �۽��ϴ�." << endl;
			//break;
		}
	*/

	return 0;
}