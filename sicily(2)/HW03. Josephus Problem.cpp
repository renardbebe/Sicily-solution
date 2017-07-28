#include <iostream>
#include <queue>

using namespace std;

class Josephus
{
public:
	Josephus(int n, int s, int m);
	void circle();
private:
	int n;
	int s;
	int m;
};

Josephus::Josephus(int n, int s, int m)
{
	Josephus::n = n;
	Josephus::s = s;
	Josephus::m = m;
}

void Josephus::circle()
{
	queue<int>q;
	for(int i = 1; i <= n; i++)
	{
		q.push(i); 
	}
	for(int i = 1; i < s; i++)
	{
		q.push(i);
		q.pop();
	}
	
	while(!q.empty())
	{
		for(int i = 1; i <= m; i++)
		{
			if(i == m)
			{
				cout << q.front() << endl;
				q.pop();
				break;
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
	}
}

int main ()
{
	int n,s,m;
	cin>>n>>s>>m;
	Josephus myJosephus(n,s,m);
	myJosephus.circle();
	return 0;
}
