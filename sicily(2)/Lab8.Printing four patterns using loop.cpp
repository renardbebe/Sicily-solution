// -- Lab8.Printing four patterns using loop
/*
Pattern 1
  1
  1  2
  1  2  3
  1  2  3  4
  1  2  3  4  5
  1  2  3  4  5  6

Pattern 2
  1  2  3  4  5  6
  1  2  3  4  5
  1  2  3  4
  1  2  3
  1  2
  1

Pattern 3
                 1
              1  2
           1  2  3
        1  2  3  4
     1  2  3  4  5
  1  2  3  4  5  6

Pattern 4
  1  2  3  4  5  6
     1  2  3  4  5
        1  2  3  4
           1  2  3
              1  2
                 1
                */
#include <iostream>
using namespace std;
int main ()
{
	int n,p;
	while(cin>>n)
	{
		if(n==1)
		{
			for(int i=1;i<=6;i++)
			{
				cout << " ";
				for(int j=1;j<=i;j++)
				{
					if(j==i) cout << " " << j;
					else cout << " " << j << " ";
				}
				cout << endl;
			}
		}
		if(n==2)
		{	
			for(int i=6;i>=1;i--)
			{
				cout << " ";
				for(int j=1;j<=i;j++)
				{
					if(j==i) cout << " " << j;
					else cout << " " << j << " ";
				}
				cout << endl;
			}
		}
		if(n==3)
		{
			for(int i=1;i<=6;i++)
			{
				cout << " ";
				for(int k=6-i;k>0;k--){
					cout << "   ";
				}
				for(int j=1;j<=i;j++)
				{
					if(j==i) cout << " " << j;
					else cout << " " << j << " ";
				}
				cout << endl;
			}
		}
		if(n==4)
		{	
			for(int i=6;i>=1;i--)
			{
				cout << " ";
				for(int k=6-i;k>0;k--){
					cout << "   ";
				}
				for(int j=1;j<=i;j++)
				{
					if(j==i) cout << " " << j;
					else cout << " " << j << " ";
				}
				cout << endl;
			}
		}
	}
}
