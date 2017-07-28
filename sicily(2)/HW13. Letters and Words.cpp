#include <iostream>
#include <sstream>
#include <cstring>
#include <cstring>
#include <cstdio>

using namespace std;

int main ()
{
	int character;                          // 用于判断到达文件尾 -> -1 
	int letter = 0, word = 0;
	string str;                             // 使用字符串存储输入内容 
	while( (character = cin.get()) != EOF)
	{
		if(character != 10) letter++;       // 判断是否为换行符 
		str += char(character);
	}
	istringstream ss(str);
	string s;
	while(ss >> s)
	{
		if(ss.good() || ss.fail())          // 判断是否为一个子字符串(word) 
		{
			word++;
		}
	}
	
	cout << "Letters: " << letter << endl;
	cout << "Words: " << word << endl;
}
