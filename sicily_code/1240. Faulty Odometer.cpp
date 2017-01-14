#include <bits/stdc++.h>
using namespace std;

int main () {
	string s, ss;
	while(cin >> s && s != "0") {
		ss = s;
		string nine;
		int ans = 0;
		int len = s.length();
		for(int i = 0; i < len; i++) {
			if(s[i] > '4') ss[i] = (char)(s[i] - 1);
		}
		for(int i = len-1; i >= 0; i--) {
			int j = len - i - 1;
			ans += (ss[i] - '0') * (int)pow(9,j);
		}
		cout << s << ": " << ans << endl;
	} 
}
