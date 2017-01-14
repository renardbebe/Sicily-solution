#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int a[101];

void select_sort(int a[] , int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		int min = a[i] , pos = i ;
		for(int j = i+1 ; j < size ; j++)
		{
			if(a[j] < min)
			{
				min = a[j] ;
				pos = j ;
				cnt++;
			}
		}
		a[pos] = a[i] ;
		a[i] = min ;
	}
	return ;
}

int main () {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		cnt = 0;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		select_sort(a, n);
		cout << cnt << endl;
	}
}
