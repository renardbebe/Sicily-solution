#include <bits/stdc++.h>
using namespace std;
#define SIZE 3000001

int exist[SIZE];
int ori[SIZE];

int main () {
	int c, n, x;
	while(cin >> c >> n) {
		memset(ori,0,sizeof(ori));
		memset(exist,-1,sizeof(exist));
		int k = 0;
		stack<int> s;
		for(int i = 0; i < n; i++) cin >> ori[i];
		for(int i = n-1; i >= 0; i--) {
			if(exist[ori[i]] == -1) {
				s.push(ori[i]);
				exist[ori[i]] = 1;
			}
		}
		cout << s.size() << endl;
		for(int i = s.size()-1; i >= 0; i--) {
			if(i) cout << s.top() << " ";
			else cout << s.top();
			s.pop();
		}
		cout << endl;
	}
}
