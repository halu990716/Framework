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

typedef struct tagNode
{
	tagNode* next;
	int value;
}NODE;

// ** List(효율적인 추가삭제가 가능)
NODE* List = new NODE;
int Length;

void Push(int value);

void insert(int count, int value)
{
	// ** 리스트에 담긴 총 원소의 개수보다 count의 값이 크다면
	// ** 값을 추가할 수 없으므로 종료.
	if (Length < count)
		return;

	// ** 리스트를 들고옴.
	NODE* nextNode = List;

	// ** 카운트의 값만큼 다음 노드로 이동.
	while (0 < count)
	{
		--count;

		// ** 다음노드로 이동
		nextNode = nextNode->next;

	}
	// ** 이동이 끝났다면 새로운 노드를 추가.

	// ** 새로운 노드 생성
	NODE* newNode = new NODE;
	newNode->next = nullptr;
	newNode->value = value;

	// ** 다음 노드를 임시의 저장소에 저장.
	NODE* tempNode = nextNode->next;

	// ** 다음노드를 저장하는 저장소에 새로운 노드를 배치.
	nextNode->next = newNode;

	// ** 새로운 노드가 가르키는 다음노드를 임시공간에 있던 노드로 배치
	newNode->next = tempNode;
}

int main(void)
{
	// ** 첫번째 노드
	// create
	List = new NODE;

	//initialize
	List->next = nullptr;
	List->value = 0.0f;

	//==============================
	// ** 두번째 노드
	Push(10);
	Push(20);
	Push(30);
	Push(40);
	Push(50);
	
	insert(1, 25);


	//==============================


	//==============================


	// ** 두번째 노드를 nextNode에 넘겨준다.
	NODE* nextNode = List->next;

	// ** nextNode가 nullptr이 아니라면 반복.
	while (nextNode != nullptr)
	{
		// ** 출력
		cout << nextNode->value << endl;

		// ** 다음노드로 이동
		nextNode = nextNode->next;
	}








	/*GetSingle(Singleton).SetValue(10);

	cout << GetSingle(Singleton).GetValue() << endl;*/
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

void Push(int value)
{
	// ** 리스트를 가져옴
	NODE* nextNode = List;

	// ** 
	while (nextNode->next != nullptr)
	{

		nextNode = nextNode->next;
	}

	nextNode->next = new NODE;

	nextNode->next->value = value;
	nextNode->next->next = nullptr;

	++Length;
}