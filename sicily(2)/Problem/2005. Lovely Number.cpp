#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, number, ans;
	while(cin >> n) {
		cin >> number;
		ans = number;
		for(int i = 1; i < n; i++) {
			cin >> number;
			ans ^= number;
		}
		cout << ans << endl;
	}
}