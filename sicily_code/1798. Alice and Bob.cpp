#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	while(cin >> n) {
		if(!n) return 0;
		if(n%2 == 0) cout << "Alice\n";
		else cout << "Bob\n";
	} 
}
