#include <iostream>
#include <map>
#include <list>

using namespace std;

// ** map(트리구조)

typedef struct Score
{
	string name;
	int Kor;
	int Eng;
	int Math;


	// 생성자 
	Score() : name(""),  Kor(0), Eng(0), Math(0) {}

	// 복사 생성자
	// 복사 생성자 사용시 생성자 필수
	Score(string _name) : name(_name),  Kor(0), Eng(0), Math(0) {}

	Score(int _kor,	int _eng,	int _math)
		: name(""), Kor(_kor), Eng(_eng), Math(_math) {}

	Score(string _name, int _kor, int _eng, int _math)
		: name(_name), Kor(_kor), Eng(_eng), Math(_math) {}
};

map<string, list<Score>> StudentList;

Score CreateScore(string _name, int _kor, int _eng, int _math);


bool AddStudent(string _key, Score _score);




int main(void)
{
	/*
	map<string, Score> List;

	string key = "홍";
	Score score = Score(10, 20, 30);

	List.insert(make_pair(key, score));

	score = Score(100, 200, 300);
	score.name = "길동";
	List[key] = score;

	cout << key + List[key].name << endl;
	cout << List[key].Kor << endl;
	cout << List[key].Eng << endl;
	cout << List[key].Math << endl;

	multimap<string, Score> multiList;

	multiList.insert(make_pair(key, score));
	multiList.insert(make_pair(key, score));

	for (multimap<string, Score>::iterator iter = multiList.begin(); iter != multiList.end(); ++iter)
	{
		cout << "[" << iter->first << "]" << endl;
		cout << "국어점수" << " : " << iter->second.Kor << endl;
		cout << "영어점수" << " : " << iter->second.Eng << endl;
		cout << "수학점수" << " : " << iter->second.Math << endl;

	}
	*/


	string key = "홍";
	string name = "길동";

	Score score = CreateScore(name, 10, 20, 30);

	if (!AddStudent(key, score))
	{
		cout << "Log" << endl;
	}
	else
		cout << StudentList[key].front().name << endl;


	for (map<string, list<Score>>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		for (list<Score>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			cout << iter2->name << endl;
			cout << iter2->Kor << endl;
			cout << iter2->Eng << endl;
			cout << iter2->Math << endl << endl;
		}
	}
	/*
	for (map<string, list<Score>>::iterator iter = StudentList.begin();
		iter != StudentList.end();++iter)
	{
		cout << key << GetStudent(key).front().name << endl;
		cout << GetStudent(key).front().Kor << endl;
		cout << GetStudent(key).front().Eng << endl;
		cout << GetStudent(key).front().Math << endl;

		cout << GetStudent(key).size() ;
	}
	*/

	return 0;
}

Score CreateScore(string _name, int _kor, int _eng, int _math)
{
	return Score(_name, _kor, _eng, _math);
}


bool AddStudent(string _key, Score _score)
{
	map<string, list<Score>>::iterator iter = StudentList.find(_key);

	if (iter == StudentList.end())
	{
		list<Score> tempList;
		tempList.push_back(_score);
		StudentList.insert(make_pair(_key, tempList));
	}
	else
	{
		iter->second.push_back(_score);
	}
	return true;
}
