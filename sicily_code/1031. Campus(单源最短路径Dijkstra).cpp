#include <bits/stdc++.h>
using namespace std;
#define maxn 201
const int INF = 0xFFFFFF;

int len[maxn][maxn];       // 记录两点间距离 
int dis[maxn];             // 记录各点到某点的距离 
bool flag[maxn];           // 判断该点是否被使用过 
int n, road;

int dijkstra(int a, int b) {
	memset(flag,0,sizeof(flag));
	memset(dis,0,sizeof(dis));
	for(int i = 0; i < n; i++) {
		if(i == a) dis[i] = 0;
		else dis[i] = INF;
	}
	
	for(int i = 0; i < n; i++) {               // 选 n条路 
		int minn = INF, x = a;
		for(int j = 0; j < n; j++) {           // 找到离 a最近的点 
			if(!flag[j] && dis[j] < minn) {
				minn = dis[j];
				x = j;
			}	
		}
		flag[x] = 1;
		for(int j = 0; j < n; j++) {           // 更新每条路径 
			dis[j] = (dis[j] > (dis[x] + len[x][j]) ) ? (dis[x] + len[x][j]) : dis[j];
		}
	}
	if(flag[b]) return dis[b];
	else return -1;
}

int main () {
	int Case;
	cin >> Case;
	while(Case--) {
		cin >> road;
		string start, end, s, e;
		int d;
		map<string,int> mp;        // 路名对应路的编号
		for(int i = 0; i < maxn; i++) {
			for(int j = 0; j < maxn; j++) {
				if(i == j) len[i][j] = 0;
				else len[i][j] = INF;	
			}
		}
		n = 0;
		for(int i = 0; i < road; i++) {
			cin >> start >> end >> d;
			if(!mp.count(start)) mp[start] = n++;    // 设置编号 
			if(!mp.count(end)) mp[end] = n++;
			len[mp[start]][mp[end]] = len[mp[end]][mp[start]] = d;
		}
		cin >> s >> e;
		if(s == e) cout << 0 << endl;       // 起终点重合 
		else if(!mp.count(s) || !mp.count(e)) cout << -1 << endl;
		else cout << dijkstra(mp[s],mp[e]) << endl;
	}
} 
