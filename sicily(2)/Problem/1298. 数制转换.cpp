#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	while(cin>>n) {
		string s, ans;
		if(!n) ans = "0";
		while(n) {
			int x = n/3;
			if(n%3 ==0 || n%3 == 1) {
				s += (n%3 + '0');
			} 
			else if(n%3 == -1){
				s += '-';
			}
			else if(n%3 == 2) {
				s += '-';
				x += 1;
			}
			else if(n%3 == -2) {
				s += '1';
				x -= 1;
			}
			n = x;
		}
		for(int i = s.length()-1; i >= 0; i--) {
			ans += s[i];
		}
		cout << ans << endl;
	}
}
