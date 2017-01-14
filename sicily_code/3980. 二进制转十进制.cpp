#include <bits/stdc++.h>
using namespace std;

int main () {
	int t, ans;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		ans = 0;
		int len = s.length();
		for(int i = len-1; i >= 0; i--) {
			int j = len-i-1;
			ans += (s[i] - '0') * (int)(pow(2,j));
		}
		cout << ans << endl;
	}
}
