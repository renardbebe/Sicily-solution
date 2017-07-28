#include <iostream>
#include <cmath>
#include <cstdio> 
using namespace std;

double f(double a,int i)
{
	double x,y;
	x=a+i;
	x=(0-pow(x,2))/2;
	x=exp(x);
	y=x*1/sqrt(2*acos(-1));
	return y;
}

int main ()
{
	double a,b;
	int n;
	while(cin>>a>>b>>n)
	{
		double s=f(b,0)+f(b,n);
		for(int i=1;i<n;i++)
		{
			if(i%2) s += 4*f(b,i);
			else s += 2*f(b,i);
		}
		s /= 3;
		
		double s1=f(a,0)+f(a,n);
		for(int i=1;i<n;i++)
		{
			if(i%2) s1 += 4*f(a,i);
			else s1 += 2*f(a,i);
		}
		s1 /= 3;
		s=fabs(s-s1);
		printf("%.2f\n",s);
	}
}
