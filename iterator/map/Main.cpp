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

	Score() : Kor(0), Eng(0), Math(0) {}

	Score(int _kor,	int _eng,	int _math)
		: Kor(_kor), Eng(_eng), Math(_math) {}

};


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

	map<string, list<Score>> StudentList;

	string key = "홍";
	Score score = Score(10, 20, 30);
	score.name = "길동";



	//StudentList[key, score.name].push_back(score);

	for (int i = 0; i <= 1; ++i)
	{
		map<string, list<Score>>::iterator iter = StudentList.find(key);

		if (iter == StudentList.end())
		{
			list<Score> tempList;

			tempList.push_back(score);

			StudentList.insert(make_pair(key, tempList));
		}
		else
		{
			iter->second.push_back(score);
		}
	}
	for (int i = 0; i <= 1; ++i)
	{
		map<string, list<Score>>::iterator iter = StudentList.find(key);

		if (iter == StudentList.end())
			return 1;
		else
			cout << &iter->second << endl;
	}
	
	return 0;
}