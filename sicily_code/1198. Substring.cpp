#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm> 
using namespace std;

bool cmp(string a,string b)
{
	return a+b<b+a;
}
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s[n+1];
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		sort(s,s+n,cmp);
		string ss;
		for(int i=0;i<n;i++)
		{
			ss += s[i];
		}
		cout << ss << endl;
	}
} 
