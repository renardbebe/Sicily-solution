#include <bits/stdc++.h>
using namespace std;
int a[30];

bool isprime(int num) {
	if(num <= 1) return false;
	for(int i = 2; i <= sqrt(num); i++) {
		if(num%i == 0) return false;
	}
	return true;
}

int main () {
	string s;
	while(cin >> s) {
		int maxn = -1, minn = 999999;
		memset(a,0,sizeof(a));
		for(int i = 0; i < s.length(); i++) {
			a[s[i] - 'a']++;
		}
		for(int i = 0; i < 26; i++) {
			if(!a[i]) continue;
			maxn = max(a[i], maxn);
			minn = min(a[i], minn);
		}
		if(isprime(maxn-minn)) {
			cout << "Lucky Word" << endl;
			cout << maxn - minn << endl;
		}
		else {
			cout << "No Answer" << endl;
			cout << 0 << endl;
		}
	}
}