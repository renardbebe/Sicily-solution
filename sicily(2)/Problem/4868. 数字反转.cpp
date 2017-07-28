#include <bits/stdc++.h>
using namespace std;

int main () {
	string s;
	while(cin >> s) {
		int len = s.length();
		if(s[0] == '-') {
			cout << "-";
			bool flag = true;
			for(int i = len-1; i >= 1; i--) {
				if(s[i] == '0' && flag) {
					continue;
				}
				else {
					flag = false;
					cout << s[i];
				}
			}
		}
		else {
			bool flag = true;
			for(int i = len-1; i >= 0; i--) {
				if(s[i] == '0' && flag) {
					continue;
				}
				else {
					flag = false;
					cout << s[i];
				}
			}
		}
		cout << endl;
	}
}