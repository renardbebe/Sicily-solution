#include <iostream>
using namespace std;
int main ()
{
	int max,min,a[5];
	for(int i=0;i<=4;i++)
	cin >> a[i];
	max=a[0];
	min=a[0];
	for(int j=0;j<=4;j++)
	{
		if(a[j]>max)
		{
			max=a[j];	
		}
		if(a[j]<min)
		{
			min=a[j];
		}
	}
	cout << max << " " << min << endl;
	return 0;
}
