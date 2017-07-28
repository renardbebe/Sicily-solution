#include <bits/stdc++.h>
using namespace std;
int a[105];
int main () {
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; i++) cin >> a[i];
		set<int> myset(a,a+n);
		cout << myset.size() << endl;
		for(set<int>::iterator it = myset.begin(); it != myset.end(); ++it) {
			if(it == myset.begin()) cout << *it;
			else cout << " " << *it;
		}
		cout << endl;
	}
}