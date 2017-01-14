// dfs 回溯 

#include <bits/stdc++.h>
using namespace std;

int number, ans;
int a[6];

void dfs(int n) {
	for(int i = 0; i < n; i++) {
		if(a[i] > ans && a[i] <= number) ans = a[i];
	}
	if(ans == number || n == 1) return ;
	else {
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				int x = a[i], y = a[j];
				a[j] = a[n-1];  // 否则dfs(n-1)时永远无法取得最后一位 a[n-1]的值 
				
				a[i] = x+y;
				dfs(n-1);
				a[i] = x-y;
				dfs(n-1);
				a[i] = y-x;  //遗漏情况 
				dfs(n-1);
				a[i] = x*y;
				dfs(n-1);
				if(x && y%x == 0) {
					a[i] = y/x;
					dfs(n-1);
				}
				else if(y && x%y == 0) {
					a[i] = x/y;
					dfs(n-1);
				}
				a[i] = x;
				a[j] = y;
			}
		}
	}
}

int main () {
	int t;
	scanf("%d", &t);
	while(t--) {
		for(int i = 0; i < 5; i++) scanf("%d", &a[i]);
		scanf("%d",&number);
		ans = -999;
		dfs(5);
		printf("%d\n", ans);
	}
}
