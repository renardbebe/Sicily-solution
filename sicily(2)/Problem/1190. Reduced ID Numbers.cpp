#include <bits/stdc++.h>
using namespace std;
#define SIZE 305
#define MaxSin 99999

int a[SIZE];
map<int,int> mp;

int main () {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		memset(a,0,sizeof(a));
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int m = 1; m <= MaxSin; m++) {
			bool find = true;
			mp.clear();
			for(int i = 0; i < n; i++) {
				if(mp[a[i]%m]) {
					find = false;
					break;
				}
				else mp[a[i]%m] = 1;
			}
			if(find) {
				cout << m << endl;
				break;
			}
		}
	}
}