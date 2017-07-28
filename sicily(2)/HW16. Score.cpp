#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Student
{
public:
	bool operator < (const Student b) const {             // ����<����� ��scoreʵ�ִ�С�������� 
		return score < b.score;
	}
	string name;
	int score;
};

int main ()
{
	vector<Student> vc;          // ����һ����Student�����ΪԪ�ص�vector 
	int n,m;
	cin>>n>>m;
	while(n--)
	{
		string s;
		int num;
		cin>>s>>num;
		Student stu;
		stu.name = s;
		stu.score = num;
		vc.push_back(stu);       // ��stu����vector�� 
	}
	sort(vc.begin(),vc.end());   // ���ÿ⺯���������� 
	
	while(m--)
	{
		int num;
		cin>>num;
		cout << vc[num-1].name << " " << vc[num-1].score << endl;
	}
}
