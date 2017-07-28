#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[201][201][201];

int main ()
{
	long long n,m,x,y,z,o,p,q;
	while(scanf("%lld%lld",&n,&m)!=EOF)
	{
		getchar();
		while(n--)
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			a[x][y][z]++;
		}
		while(m--)
		{
			scanf("%lld%lld%lld",&o,&p,&q);
			if(a[o][p][q]) printf("Yes\n");
			else printf("No\n");
		}
	}
} 
