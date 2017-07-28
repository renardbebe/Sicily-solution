//  多个区间的并集 
#include <iostream>
#include <algorithm>
using namespace std;
int a[101],b[101],c[1001];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	} 
	sort(a,a+n);
	sort(b,b+n);
	
	int count = 0;
	c[count] = a[0];
   	c[count+1] = b[0];
	for(int i=0;i<n-1;i++)
	{
	    if((a[i+1]<=b[i]) && (b[i]<b[i+1]))  c[count+1] = b[i+1];
		else if(a[i+1]>b[i])
		{
			count += 2;
			c[count] = a[i+1];
         	c[count+1] = b[i+1];
		}
	}
	for(int i=0;i<=count;i+=2 )
	{
		cout << c[i] << " " << c[i+1] << endl;	
	}	
}
