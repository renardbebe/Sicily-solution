#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	while(n--) {
		string s, ans = "";
		cin >> s;
		if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') {
			ans = s + "cow";
		}
		else {
			for(int i = 1; i < s.length(); i++) ans += s[i];
			ans += s[0];
			ans += "ow";
		}
		cout << ans << endl;
	}
}
