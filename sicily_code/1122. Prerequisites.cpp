#include <bits/stdc++.h>
using namespace std;

int main () {
	int k, m, c, r;
	while(cin >> k && k) {
		cin >> m;
		int select[10005];
		memset(select,0,sizeof(select));
		for(int i = 0; i < k; i++) {
			int x;
			cin >> x;
			select[x]++;
		}
		bool flag = true;
		for(int i = 0; i < m; i++) {
			cin >> c >> r;
			int s;
			int cnt = 0;
			
			for(int j = 0; j < c; j++) {
				cin >> s;
				if(select[s]) {
					cnt++;
				}
			}
			if(cnt < r) flag = false;
		}
		if(flag) cout << "yes\n";
		else cout << "no\n";
	}
}
