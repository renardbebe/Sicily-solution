#include <iostream>
#include <sstream>
#include <cstring>
#include <cstring>
#include <cstdio>

using namespace std;

int main ()
{
	int character;                          // �����жϵ����ļ�β -> -1 
	int letter = 0, word = 0;
	string str;                             // ʹ���ַ����洢�������� 
	while( (character = cin.get()) != EOF)
	{
		if(character != 10) letter++;       // �ж��Ƿ�Ϊ���з� 
		str += char(character);
	}
	istringstream ss(str);
	string s;
	while(ss >> s)
	{
		if(ss.good() || ss.fail())          // �ж��Ƿ�Ϊһ�����ַ���(word) 
		{
			word++;
		}
	}
	
	cout << "Letters: " << letter << endl;
	cout << "Words: " << word << endl;
}
