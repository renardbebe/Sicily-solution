// 1003
/*
	�㷨�� 
	һ�ο��Խ����������֣��������ÿ�����������ֲ���ͬ
	��ô����ͬ��������಻�ܳ���������һ�� 
*/ 
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int a[101];
int main ()
{
    int n,len=1,max=1;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)  
            cin >> a[i];
        sort(a,a+n);
        int k=1;
        for(int i=k;i<=n-1;i++)
        {
            if(a[i]==a[i+1]) len++;
            else
            {
                k=i+1;
                len=1;
            } 
            if(len>max) max=len;
        }
        //cout << max << endl;
        if(n%2==0)
        {
            if(max>n/2) cout << "NO\n";
            else cout << "YES\n";
        }
        else
        {
            if(max>(n+1)/2) cout << "NO\n";
            else cout << "YES\n";
        }
        max=0;
    }
}                                 
