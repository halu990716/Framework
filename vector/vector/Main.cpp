#include <iostream>
#include <vector>

using namespace std;

// vector 사용할 때: 이미 크기가 정해져 있을때 
/*
단점: 추가할 때 새로 배열을 만들어서 추가함 
	삭제할때 삭제는 안하고 예외 처리로 처리함
*/

int* Numbers = nullptr;
int Length = 0;

void push(int n)
{
	if (Numbers == nullptr)
	{
		Numbers = new int;
		*Numbers = n;
		++Length;
		return;
	}
	int* Temp = new int[Length + 1];
	
	for(int i = 0; i < Length; ++i)
	{
		Temp[i] = Numbers[i];
	}

		Temp[Length] = n;
		Numbers = Temp;
		++Length;

}

int main(void)
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	for (int i = 0; i < Length; ++i)
	{
		cout << Numbers[i] << endl;
	}

	vector<int> vecList;

	for (int i = 0; i < 100; ++i)
	{
		vecList.push_back(i * 10 + 10);
		cout << vecList[i] << endl;
		cout << vecList.capacity() << endl << endl;
	}

	return 0;
}