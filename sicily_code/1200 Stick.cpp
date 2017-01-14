#include <bits/stdc++.h>
using namespace std;

int a[101];

int main () {
	int n, x;
	while(cin>>n && n) {
		memset(a,0,sizeof(a));
		for(int k = 0; k < n; k++) {
			cin >> x;
			a[k] = x;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(a[i] == 0) continue;
				else if(a[j] == a[i] && j != i) {
					a[j] = 0;
					a[i] = 0;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			if(a[i]) cout << a[i] << endl;
		}
	}
	//system("pause");
	return 0;
}
