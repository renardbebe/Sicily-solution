#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int MOD = 1000000007;
struct matrix
{
    long long a[2][2];
}origin,res;

matrix multiply(matrix x, matrix y)
{
    matrix temp;
    memset(temp.a, 0, sizeof(temp.a));
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                temp.a[i][j] = (temp.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
            }
        }
    }
    return temp;
}
void init()
{
    //origin.a = {1,1, 1,0};
    origin.a[0][0] = origin.a[0][1] = origin.a[1][0] = 1;
    origin.a[1][1] = 0;
    memset(res.a, 0, sizeof(res.a));
    res.a[0][0] = res.a[1][1] = 1;
}
void calc(int n)
{
    while(n)
    {
        if(n&1)
            res = multiply(res, origin);
        n >>= 1;
        origin = multiply(origin, origin);
    }
    //for(int i=0; i<2; i++)
      //  for(int j=0; j<2; j++)
    printf("%lld\n",res.a[0][1] );
}

int main()
{
    int n;
    while(cin >> n)
    {
        init();
        calc(n);
    }
}                                 