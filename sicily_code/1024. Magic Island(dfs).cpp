#include <bits/stdc++.h>
using namespace std;
#define maxn 10005

int n, k, max_len;

struct Edge{
	int end;
	int distance;
	Edge(int b, int c) {
		end = b;
		distance = c;
	}
};

vector<Edge> road[maxn];
bool use[maxn];

void init() {
	for(int i = 0; i < maxn; i++) {
		road[i].clear();
	}
	for(int i = 0; i < maxn; i++) use[i] = false;
	max_len = 0;
}

void dfs(int i, int dis) {
	if(dis > max_len) max_len = dis;
	
	use[i] = true;
	for(int j = 0; j < road[i].size(); j++) {
		if(!use[road[i][j].end]) {
			dfs(road[i][j].end, dis + road[i][j].distance);
		}
	}
}

int main () {
	int x, y, d;
	while(cin >> n >> k) {
		init();
		for(int i = 1; i <= n-1; i++) {
			cin >> x >> y >> d;
			Edge e1(y,d);
			Edge e2(x,d);
			road[x].push_back(e1);
			road[y].push_back(e2);
		}
		dfs(k, 0);
		cout << max_len << endl;
	} 
} 
