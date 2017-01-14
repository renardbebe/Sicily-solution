/*
 * Quick Sort
 */ 
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    while(n)
    {
        int a[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a,a+n);
        printf("%d", a[0]);
        for(int i = m; i < n; i += m)
        {
            printf(" %d",a[i]);
        }
        printf("\n");
        scanf("%d%d", &n, &m);
    }
    return 0;
}
