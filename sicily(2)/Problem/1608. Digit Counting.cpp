#include <bits/stdc++.h>
using namespace std;

int a[10];

inline string toString(int num) {
	string result = "";
	while(num) {
		result = (char)(num % 10 + '0') + result;
		num /= 10;
	}
	return result;
}

int main () {
	int T, n;
	cin >> T;
	while(T--) {
		cin >> n;
		string s = "";
		memset(a,0,sizeof(a));
		for(int i = 1; i <= n; i++) s += toString(i);
		for(int i = 0; i < s.length(); i++) {
			a[s[i] - '0']++;
		}
		for(int i = 0; i <= 9; i++) {
			if(!i) cout << a[i];
			else cout << " " << a[i];
		}
		cout << endl;
	}
}