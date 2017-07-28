#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main ()
{ 
	string c1,c2,c3; 
	cin>>c1>>c2>>c3;
	string s1[100];
	string s2[100];	
	int cnt;
	
	ifstream fin1(c1);                 // 打开 File1
	ifstream fin2(c2);                 // 打开 File2
	ofstream fout;
	fout.open(c3);                     // 打开 File3
	cnt = 0;
	while(!fin1.eof())
	{
		getline(fin1,s1[cnt]);                         // 将 File1中内容逐行读入字符串数组s1
		cnt++; 
	}
	cnt = 0;
	while(!fin2.eof())
	{ 
		getline(fin2,s2[cnt]);                         // 将 File2中内容逐行读入字符串数组s2
		cnt++;
	}
	for(int j = 0; j < cnt; j++)
	{
		int pos = -1;                                   // 确定不同字符出现的位置 
		bool flag = 1;                                 // 判断两个字符串是否相同
		int len1 = s1[j].length();                     // 判断内容是否相同 
		int len2 = s2[j].length();
		int len = 0;
		if(len1 != len2) flag = 0;
		if(len1 > len2) len = len2;
		else len = len1;
		for(int i = 0; i < len; i++)
		{
			if(s1[j][i] != s2[j][i])
			{
				pos = i;
				flag = 0;
				break;
			}
		}
		if(!flag && pos == -1) pos = len;
		
		if(flag) fout << "Same\n";
		else
		{
			fout << "Different " << pos << endl;
		}
		fout << flush;                             // 清空缓冲区 
	}
	fout.close();                                  // 关闭 File3
}
