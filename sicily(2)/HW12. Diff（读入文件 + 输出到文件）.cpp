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
	
	ifstream fin1(c1);                 // �� File1
	ifstream fin2(c2);                 // �� File2
	ofstream fout;
	fout.open(c3);                     // �� File3
	cnt = 0;
	while(!fin1.eof())
	{
		getline(fin1,s1[cnt]);                         // �� File1���������ж����ַ�������s1
		cnt++; 
	}
	cnt = 0;
	while(!fin2.eof())
	{ 
		getline(fin2,s2[cnt]);                         // �� File2���������ж����ַ�������s2
		cnt++;
	}
	for(int j = 0; j < cnt; j++)
	{
		int pos = -1;                                   // ȷ����ͬ�ַ����ֵ�λ�� 
		bool flag = 1;                                 // �ж������ַ����Ƿ���ͬ
		int len1 = s1[j].length();                     // �ж������Ƿ���ͬ 
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
		fout << flush;                             // ��ջ����� 
	}
	fout.close();                                  // �ر� File3
}
