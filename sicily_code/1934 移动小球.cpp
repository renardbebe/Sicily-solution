#include <bits/stdc++.h>
#include <list>
using namespace std;

int prev[500005];
int next[500005];    // 用数组模拟双向链表  

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;              // 1<n<=500000 , 0<m<100000
		memset(prev,0,sizeof(prev));
		memset(next,0,sizeof(next));
		for(int i = 1; i <= n; ++i) {
			prev[i] = i-1;
			next[i] = i+1;
		}
		
		while(m--) {
			int command, x, y;
			cin >> command >> x >> y;
			if(command == 1) {           // 改变相对位置 
				next[prev[x]] = next[x];
				prev[next[x]] = prev[x];
				next[prev[y]] = x;
				prev[x] = prev[y];
				next[x] = y;
				prev[y] = x;
			}
			else if(command == 2) {
				next[prev[x]] = next[x];
				prev[next[x]] = prev[x];
				prev[next[y]] = x;
				next[x] = next[y];
				next[y] = x;
				prev[x] = y;
			}	
		}
    	int number = next[0];
    	for(int i = 0; i < n; ++i) {
      		cout << number << ' ';
      		number = next[number];
    	}
		cout << endl;
	}
}
