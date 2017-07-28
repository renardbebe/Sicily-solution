#include <bits/stdc++.h>
using namespace std;

int main () {
	string s;
	while(cin >> s && s[0] != '#') {
		int len = s.length();
		int cnt = 0;
		for(int i = 0; i < len-1; i++) {
			if(s[i] == '1') cnt++;
			cout << s[i];
		}
		if(s[len-1] == 'e') {
			if(cnt%2 == 0) cout << 0;
			else cout << 1;
		}
		else if(s[len-1] == 'o') {
			if(cnt%2 == 0) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
}