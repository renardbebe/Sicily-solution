#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

int main ()
{
	int n;
	while(cin>>n)
	{
		list<int> my_list;
		while(n--)
		{
			string s;
			cin>>s;
			int x;
			if(s == "push_back")
			{
				cin>>x;
				my_list.push_back(x); 
			}
			else if(s == "push_front")
			{
				cin>>x;
				my_list.push_front(x);
			}
			else if(s == "pop_back")
			{
				my_list.pop_back();
			}
			else if(s == "pop_front")
			{
				my_list.pop_front();
			}
			else if(s == "print")
			{
				cout << "List:\n";
				list<int>::iterator it;
				for(it = my_list.begin(); it != my_list.end(); it++)
					cout << *it << endl;
			}
		}
	}
}
