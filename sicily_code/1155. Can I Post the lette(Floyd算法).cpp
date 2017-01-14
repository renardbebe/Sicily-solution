#include <bits/stdc++.h>
using namespace std;

int road[201][201];
int n, m;
/*
利用弗洛伊德算法来解这道题,如果两个城市可以连通，
则其距离为0
*/
inline void floyd() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (road[j][k] > (road[j][i] + road[i][k])) {
					road[j][k] = road[j][i] + road[i][k];
				}
			}
		}
	}
}

int main() {
	while (cin >> n && n) {
		if (!n) return 0;
		for (int i = 0; i < 201; i++) {
			for (int j = 0; j < 201; j++) {
				road[i][j] = 100;
			}
			road[i][i] = 0;
		}
		
		cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			road[a][b] = road[b][a] = 0;
		}
		floyd();
		if (road[0][n - 1] == 0) {
			printf("I can post the letter\n");
		}
		else {
			printf("I can't post the letter\n");
		}
	}
}
