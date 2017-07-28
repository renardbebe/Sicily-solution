#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005
int a[SIZE];
int pre[SIZE];
int n;

bool equal(int a[]) {
	for(int i = 1; i < n; i++) 
		if(a[i] != a[0]) return false;
	return true;
}

int main () {
	while(cin >> n && n) {
		int time = 0, num = 0;
		memset(a,0,sizeof(a));
		memset(pre,0,sizeof(pre));
		for(int i = 0; i < n; i++) cin >> a[i];
		int i = 0;
		while(1) {
			if(equal(a)) break;
			else {
				time++;
				for(int i = 0; i < n; i++) {
					a[i] /= 2;
					pre[i] = a[i];
				}
				for(int i = 0; i < n; i++) {
					if(i > 0) a[i] += pre[i-1];
					else a[0] += pre[n-1];
				}
				for(int i = 0; i < n; i++) {
					if(a[i] % 2) a[i] += 1;
				}
			}
		}
		num = a[0];
		cout << time << " " << num << endl;
	}
}
