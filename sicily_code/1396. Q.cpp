#include <bits/stdc++.h>
using namespace std;
string a[25];
string b[25];

int main () {
	int t;
	cin >> t;
	while(t--) {
		int m, n, x, y;
		cin >> m >> n;
		for(int i = 0; i < m; i++) {
			cin >> a[i];
			b[i] = "";
		}
		while(n--) {
			cin >> x >> y;
			b[y-1] = a[x-1];
			a[x-1] = "";
		}
		for(int i = 0, j = 0; i < m; i++) {
			if(b[i] == "") {
				while(a[j] == "") j++;
				b[i] = a[j++];
			}
		}
		for(int i = 0; i < m; i++) {
			if(!i) cout << b[i];
			else cout << " " << b[i];
		}
		cout << endl;
	}
}
