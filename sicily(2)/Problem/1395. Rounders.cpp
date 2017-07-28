#include <bits/stdc++.h>
using namespace std;

int to_num (string s, int len) {
	int h = 0;
	for(int i = 0; i < len; i++) h = h*10 + (s[i] - '0');
	return h;
}

int main () {
	int n;
	cin >> n;
	while(n--) {
		string s, ans = "";
		cin >> s;
		int len = s.length();
		if(to_num(s,len) < 10) cout << s << endl;
		else {
			int input = 0;
			for(int i = len-1; i >= 1; i--) {
				if(s[i] == '9') {
					ans = '0' + ans;
					input = 1;
				}
				else {
					if(input) s[i] = s[i] + 1;
					if(s[i] >= '5') {
						ans = '0' + ans;
						input = 1;
					}
					else {
						ans = '0' + ans;
						input = 0;
					}	
				}
			}
			if(input) {
				if(s[0] == '9') ans = "10" + ans;
				else ans = (char)(s[0] + 1) + ans;
			}
			else ans = (char)(s[0]) + ans;
			cout << ans << endl;
		}
	}
	return 0;
}
