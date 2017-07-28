#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1000];
int temp[1000];
int main ()
{
	int n;
	while(cin>>n&&n!=0)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		a[n+1]=a[1];
		a[0]=a[n];
		
		int count = 0;
		while(1)
		{
			int flag = 0;
			for(int i=1;i<=n;i++)
			{
				if(i==n) a[i+1]=a[1];
				if(a[i]!=a[i+1]) 
				{
					flag++;
					break;
				}
			}

			if(flag==0)	break;
			else
			{
				count++;
				memset(temp,0,sizeof(temp));
				for(int i=1;i<=n;i++)
				{
					if(a[i]%2==0) 
					{
						a[i]/=2;
						temp[i]=a[i];
					}
				}
				temp[0]=temp[n];
				for(int i=1;i<=n;i++)
				{
					a[i]+=temp[i-1];
				}
				for(int i=1;i<=n;i++)
				{
					if(a[i]%2!=0) a[i]++; 
				}
			}	
		}
		cout << count << " " << a[1] << endl;
	}
}
