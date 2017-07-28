#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int &n)
{
	int flag=0;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) flag++;
	}
	if(flag) return 0;
	else return 1;
}
void get(int **list, int n)
{
    if(n == 1)
    {
        list[0] = new int[5];
        list[0][0] = 4;
        list[0][1] = 2;
        list[0][2] = 3;
        list[0][3] = 5;
        list[0][4] = 7;
    }
    else
    {
        int i, j;
        int a[4] = {1,3,7,9};
        int v;
        n--;
        list[n] = new int[17];
        list[n][0] = 0;
        for(i = 1; i <= list[n-1][0]; i ++)
        {
            for(j = 0; j < 4; j ++)
            {
                v = list[n-1][i] * 10 + a[j];
                if(isPrime(v))
                    list[n][++list[n][0]] = v;
            }
        }
    }
}
int main()
{
    int **list, i, n;
    list = new int *[8];
    for(i = 1; i < 9; i ++)
        get(list, i);
    while(cin >> n)
    {
    	n --;
    	for(i = 1; i <= list[n][0]; i ++)
        	cout << list[n][i] <<endl;
    }
}
