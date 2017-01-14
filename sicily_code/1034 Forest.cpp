#include <bits/stdc++.h>
using namespace std;
#define SIZE 105

int indeg[SIZE];
int a[SIZE];
int b[SIZE];
int w[SIZE];
bool war[SIZE][SIZE];   // 用于沃舍尔 判断是否有回路 
bool adj[SIZE][SIZE];   // 用于dfs 
bool used[SIZE];        // 判断某点是否被使用 
bool flag;              // 判断森林是否合法 
int depth, width;
int n, m;               // n -> nodes , m -> edges

void init () {
	flag = true;
	for(int i = 0; i < SIZE; i++) {
		indeg[i] = 0;
		a[i] = 0;
		b[i] = 0;
		w[i] = 0;
		used[i] = false;
	}
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++) {
			war[i][j] = false;
			adj[i][j] = false;
		}
	depth = 0;
	width = 0;
}

void dfs (int j, int d) {
	if(d > depth) depth = d;
	w[d]++;
	if(w[d] > width) width = w[d];
	for(int i = 1; i <= n; i++) {
		if(adj[j][i]) dfs(i, d+1);
	}
} 

int main () {
	while(cin >> n >> m && n) {
		init();
		for(int i = 0; i < m; i++) {
			cin >> a[i] >> b[i];
			if(a[i] == b[i]) flag = false;  // self-loop
			indeg[b[i]]++;
			war[a[i]][b[i]] = true;
			adj[a[i]][b[i]] = true;
		}
		for(int k = 1; k <= n; k++)  // Warshall Algorithm
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					if(war[i][k] && war[k][j]) war[i][j] = true;
		for(int i = 0; i < m; i++) {
			if(war[i][i] == true) {
				flag = false;
				break;
			}
		}
		for(int i = 1; i <= n; i++) {  // check the indegree
			if(indeg[i] > 1) {
				flag = false;
				break;
			}
		}
		if(flag) {
			for(int i = 1; i <= n; i++) {  // find the root
				if(indeg[i] == 0) dfs(i, 0);
			}
		}
		
		if(flag) cout << depth << " " << width << endl;
		else cout << "INVALID\n";
	}
}
