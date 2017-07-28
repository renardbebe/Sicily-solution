#include <bits/stdc++.h>
using namespace std;
#define SIZE 10001

int a[SIZE],b[SIZE],c[SIZE];

void init()
{
	int i;
	string s1, s2;
	cin >> s1;
	a[0]=s1.length();
	for (i=0;i<a[0];i++)
	  a[i+1]=s1[a[0]-i-1]-'0';
	cin >> s2;
	b[0]=s2.length();
	for (i=0;i<b[0];i++)
	  b[i+1]=s2[b[0]-i-1]-'0';
}

void mul()
{
	int i,j;
	memset(c,0,sizeof(c));
	for (i=1;i<=a[0];i++)
	  for (j=1;j<=b[0];j++)
	    c[i+j-1]+=a[i]*b[j];
	c[0]=a[0]+b[0];
	for (i=1;i<=c[0];i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	while (c[c[0]+1]>0)
	{
		c[0]++;
		c[c[0]+1]+=c[c[0]]/10;
		c[c[0]]%=10;
    }
    while (c[c[0]]==0 && c[0]!=1)
      c[0]--;
}

void print()
{
	int i;
	for (i=c[0];i>=1;i--)
	  printf("%d",c[i]);
	printf("\n");
}

int main()
{
	int T;
	cin >> T;
	while(T--) {
		init();
		mul();
		print();
	}
	return 0;
}
