#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	cin >> t;
	while(t--) {
		int maxn = -1, minn = 999999;
		int n, x;
		cin >> n;
		while(n--) {
			cin >> x;
			if(x > maxn) maxn = x;
			if(x < minn) minn = x;
		}
		cout << 2*(maxn - minn) << endl;
	}
}
