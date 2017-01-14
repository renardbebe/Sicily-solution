#include <bits/stdc++.h>
using namespace std;

#define SIZE 205

bool adj[SIZE][SIZE];
bool used[SIZE];
int n;

void init() {
	for(int i = 0; i < SIZE; i++) used[i] = false;
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			adj[i][j] = false;
		}
	}
}

void dfs(int k) {
	used[k] = true;
	for(int i = 0; i < n; i++) {
		if(i != k && adj[i][k] && !used[i]) dfs(i);
	}
}

bool check(int x) {
	if(used[x]) return true;
	else return false;
}

int main () {
	while(cin >> n && n) {
		init();
		int m;
		cin >> m;
		while(m--) {
			int x, y;
			cin >> x >> y;
			adj[x][y] = adj[y][x] = true;
		}
		dfs(0);
		if(check(n-1)) cout << "I can post the letter\n";
		else cout << "I can't post the letter\n";	
	}
	return 0;
}
