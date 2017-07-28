#include <stdio.h>
int a[200000];

void ksort(int l, int h, int a[] ){
    int e = h;
    int p = l;
    int temp;
    if (h < l + 2) return;
    while (l < h) {
        while (++l < e && a[l] <= a[p]);
        while (--h > p && a[h] >= a[p]);
        if (l < h) {
            temp = a[l];
            a[l]=a[h];
            a[h]=temp;
        }
    }
    temp = a[h];
    a[h]=a[p];
    a[p]=temp;
    ksort(p, h, a);
    ksort(l, e, a);
}

int main()
{
    int n;
    while(scanf("%d", &n) && n != 0)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        ksort(0, n, a);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == a[i + 1]) continue;
            else cnt++;
        }
        printf("%d\n", cnt);
    }
}