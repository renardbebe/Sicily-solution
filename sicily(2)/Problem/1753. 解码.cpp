#include <bits/stdc++.h>
using namespace std;

bool ischar(char ch) {
	if(ch >= '0' && ch <= '9') return false;
	else return true;
}

int main () {
	string s;
	while(cin >> s && s != "XXX") {
		int len = s.length();
		string t = "";
		for(int i = 0; i < len; i++) {
			if(ischar(s[i])) {
				t += s[i];
				if(i == len-1) continue;
				else if(ischar(s[i+1])) continue;
				else {
					int h = 0, j;
					for(j = i+1; !ischar(s[j]); j++) {
						h = h * 10 + s[j] - '0';
					}
					j--;
					for(int k = 1; k <= h-1; k++) t += s[i];
					i += (j-i);
				}
			}
		}
		cout << t << endl;
	}
}