// -- Lab8.Printing numbers in a pyramid pattern
/*
n=5:
         		  	    1
                   1    2    1
              1    2    4    2    1
         1    2    4    8    4    2    1
    1    2    4    8   16    8    4    2    1
*/
#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			for(int k=n-i;k>0;k--)
			{
				cout << "     ";
			}
			for(int j=1;j<=i;j++)
			{
				int p=pow(2,j-1);
				if(p>0&&p<10)
				cout << "    " << p;
				else if(p>=10&&p<100)
				cout << "   " << p;
				else if(p>=100&&p<1000)
				cout << "  " << p;
			}
			for(int j=i-1;j>=1;j--)
			{
				int p=pow(2,j-1);
				if(p>0&&p<10)
				cout << "    " << p;
				else if(p>=10&&p<100)
				cout << "   " << p;
				else if(p>=100&&p<1000)
				cout << "  " << p;
			}
			cout << endl;
		}
	}
}
