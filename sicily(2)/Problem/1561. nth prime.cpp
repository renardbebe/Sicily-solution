#include <iostream>
#include <cmath> 
using namespace std;
int a[10001];

bool isprime(int i)
{
	int flag = 0;
	for(int k=2;k<=sqrt(i);k++)
	{
		if(i%k==0)
		{
			flag++;
			break;
		}
	}
	if(flag) return false;
	else return true;
}

int main ()
{
	int p = 0;
	for(int i=2;i<=104730;i++)
	{
		if(isprime(i)) a[p++]=i;
	}
	int n;
	cin>>n;
	cout << a[n-1] << endl;
}
