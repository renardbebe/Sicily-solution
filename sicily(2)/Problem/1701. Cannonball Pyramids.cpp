#include <bits/stdc++.h>
using namespace std;

int sum (int i) {
	int result = 0;
	for(int j = 1; j <= i; j++) result += j;
	return result;
}

int main () {
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		int n;
		cin >> n;
		int ans = 0;
		for(int i = 1; i <= n; i++) ans += sum(i);
		cout << kase << ": " << n << " " << ans << endl;
	}
}