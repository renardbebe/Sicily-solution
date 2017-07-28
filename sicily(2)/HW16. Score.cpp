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
	bool operator < (const Student b) const {             // 重载<运算符 按score实现从小到大排序 
		return score < b.score;
	}
	string name;
	int score;
};

int main ()
{
	vector<Student> vc;          // 定义一个以Student类对象为元素的vector 
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
		vc.push_back(stu);       // 将stu加入vector中 
	}
	sort(vc.begin(),vc.end());   // 调用库函数进行排序 
	
	while(m--)
	{
		int num;
		cin>>num;
		cout << vc[num-1].name << " " << vc[num-1].score << endl;
	}
}
