#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int couple[200001];

int main ()
{
	int n;
	while(cin>>n && n != 0)
	{
		stack<int>s;	
		int m = n;
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			couple[a] = b;
			couple[b] = a;	
		}
		
		for(int i = 1; i <= 2*n; i++)
		{
			if(s.empty()) s.push(i);
			else
			{
				if(couple[i] == s.top()) s.pop();
				else s.push(i);
			}
		}
		if(s.empty()) cout << "Yes\n";
		else cout << "No\n";
	}
}
