#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int y, m, d, c, w;
    int re_d, re_m, re_y;
    int cases;
    int interval;

    int month[13] = {0, 31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};

    cin >> cases;
    while (cases--)
    {
        cin >> m >> d >> y;
        re_d = d;
        re_m = m;
        re_y = y;
        if (m < 3)
        {
            y--;
            m+=12;
        }

        c = y/100;
        y = y % 100;

        w = y + y/4 + c/4 - 2*c + 26*(m+1)/10 + d-1; //蔡勒公式
        w = ( w % 7 + 7 ) % 7; //注意这里不是mod7 ，考虑到负数取模

        interval = 7- w;
        re_d += interval;

        if ( (re_y % 400 == 0) || (re_y % 4 == 0 && re_y % 100 != 0) )
            month[2] = 29;
        else
            month[2] = 28;

        if (re_d > month[re_m])
        {
            re_d = re_d - month[re_m];
            re_m++;
            if (re_m > 12)
            {
                re_m = 1;
                re_y++;
            }
        }
        printf("%.2d %.2d %d\n", re_m, re_d, re_y);
    }
    return 0;
}