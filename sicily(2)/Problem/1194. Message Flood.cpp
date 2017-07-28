#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;

int main () {
	int n, m;
	string s;
	while(cin >> n >> m && n) {
		mp.clear();
		for(int i = 0; i < n; i++) {
			cin >> s;
			for(int j = 0; j < s.length(); j++) s[j] = tolower(s[j]);
			mp[s] = 1; 
		}
		for(int i = 0; i < m; i++) {
			cin >> s;
			for(int j = 0; j < s.length(); j++) s[j] = tolower(s[j]);
			if(mp[s] == 1) mp[s] = 2;
		}
		int cnt = 0;
		for(map<string,int>::iterator it = mp.begin(); it != mp.end(); it++) {
			if(it->second == 1) cnt++;
		}
		cout << cnt << endl;
	}
}
