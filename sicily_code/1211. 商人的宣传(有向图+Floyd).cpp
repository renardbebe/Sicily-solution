#include <bits/stdc++.h>
using namespace std;
#define SIZE 105
int road[SIZE][SIZE];
long long path[SIZE][SIZE];

int main () {
	int n, m, l, x, y, q, a, b;
	while(cin >> n >> m >> l) {
	memset(road,0,sizeof(road));
		while(m--) {
			cin >> x >> y;
			road[x][y] = 1; 
		}
		cin >> q;
		while(q--) {
			cin >> a >> b;
			memset(path,0,sizeof(path));
			path[0][a] = 1;             // 用 0天到 A州只有一条路 
			for(int k = 1; k <= l; k++) {
				for(int i = 1; i <= n; i++) {
					for(int j = 1; j <= n; j++) {
						if(road[i][j]) {
							path[k][j] += path[k-1][i];
						}
					}
				}
			}
			cout << path[l][b] << endl;
		}	
	}
}
