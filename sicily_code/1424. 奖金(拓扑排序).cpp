//拓扑排序，若a员工工资比b员工多，那么从b->a建立有向边  
#include <bits/stdc++.h>
using namespace std;

int indeg[10005];
vector<int>adj[10005];
queue<int> q;

int main () {
	int n, m;
	scanf("%d%d", &n, &m);
	int reward = n * 100, cnt = 0;
	for(int k = 0; k < m; k++) {
		int a, b;
		scanf("%d%d", &a, &b);
		indeg[a]++;
		adj[b].push_back(a);
	}
	int level = 0;
	while(1) {
		for(int i = 1; i <= n; i++) {
			if(indeg[i] == 0) {
				indeg[i] = -1;
				q.push(i);
			}
		}
		if(q.empty()) break;
		else {
			while(!q.empty()) {
				for(int i = 0; i < adj[q.front()].size(); i++) {
					indeg[adj[q.front()][i]]--;	
				}
				cnt++;
				reward += level;
				q.pop();
			}
		}
		level++;
	}
	if(cnt == n) printf("%d\n", reward);
	else printf("Poor Xed\n");
}
