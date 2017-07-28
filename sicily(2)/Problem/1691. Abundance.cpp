#include <bits/stdc++.h>
using namespace std;

int main () {
	int t, x, y, cnt, maxn;
	cin >> t;
	while(t--) {
		cin >> x >> y;
		maxn = -1;
		bool flag = false;
		for(int digit = x; digit <= y; digit++) {
			int sum = 0;
			for(int i = 1; i <= digit; i++) {
				if(digit % i == 0) sum += i;
			}
			cnt = sum - 2*digit;
			if(cnt > 0) {
				flag = true;
				if(cnt > maxn) maxn = cnt;	
			}
		}	
		if(flag) cout << maxn << endl;
		else cout << -1 << endl;
	}
}
