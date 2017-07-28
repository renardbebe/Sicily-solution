// 1004 -- T-primes 
/*
	除了1和它本身之外，只有一个质因数
	算法：
	X的平方根为素数 --→X为 T-prime
*/ 
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int main ()
{
	int n,num=0;
	while(cin>>n)
	{
		while(n--)
		{
			long long x;
			cin >> x; 
			double b = sqrt(1.0*x);
			int c = sqrt(1.0*x);
			if(b==c&&x!=1)
			{
				int cnt = 0;
				for(long long i=2;i<=sqrt(c);i++)
				{
					if(c%i==0) cnt++; 
				}	 
				if(cnt==0) num ++;
				//cout << cnt << endl;
	    	}
	    	if(x==1) num+=0;
		}
		cout << num << endl;
		num=0;
	}
}
