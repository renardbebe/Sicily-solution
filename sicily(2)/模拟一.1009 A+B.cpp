#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main ()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		long long m=0,n=0;
		int flag1=0,flag2=0;
		for(int i=0;i<s1.length();)
		{
			if(s1[0]=='-') 
			{
				flag1 = 1;
				i++;
				s1[0]='0';
			}
			if(s1[i]>='0' && s1[i]<='9')
			{
				m = m*10 + (s1[i] - '0');
				i++;
			}
			else i++;
		}
		for(int i=0;i<s2.length();)
		{
			if(s2[0]=='-') 
			{
				flag2 = 1;
				i++;
				s2[0]='0';
			}
			if(s2[i]>='0' && s2[i]<='9')
			{
				n = n*10 + (s2[i] - '0');
				i++;
			}
			else i++;
		}
		if(flag1) m = 0-m;
		if(flag2) n = 0-n;
		cout << m+n << endl;
	}
}
