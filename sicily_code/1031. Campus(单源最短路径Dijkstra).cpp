#include <bits/stdc++.h>
using namespace std;
#define maxn 201
const int INF = 0xFFFFFF;

int len[maxn][maxn];       // ��¼�������� 
int dis[maxn];             // ��¼���㵽ĳ��ľ��� 
bool flag[maxn];           // �жϸõ��Ƿ�ʹ�ù� 
int n, road;

int dijkstra(int a, int b) {
	memset(flag,0,sizeof(flag));
	memset(dis,0,sizeof(dis));
	for(int i = 0; i < n; i++) {
		if(i == a) dis[i] = 0;
		else dis[i] = INF;
	}
	
	for(int i = 0; i < n; i++) {               // ѡ n��· 
		int minn = INF, x = a;
		for(int j = 0; j < n; j++) {           // �ҵ��� a����ĵ� 
			if(!flag[j] && dis[j] < minn) {
				minn = dis[j];
				x = j;
			}	
		}
		flag[x] = 1;
		for(int j = 0; j < n; j++) {           // ����ÿ��·�� 
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
		map<string,int> mp;        // ·����Ӧ·�ı��
		for(int i = 0; i < maxn; i++) {
			for(int j = 0; j < maxn; j++) {
				if(i == j) len[i][j] = 0;
				else len[i][j] = INF;	
			}
		}
		n = 0;
		for(int i = 0; i < road; i++) {
			cin >> start >> end >> d;
			if(!mp.count(start)) mp[start] = n++;    // ���ñ�� 
			if(!mp.count(end)) mp[end] = n++;
			len[mp[start]][mp[end]] = len[mp[end]][mp[start]] = d;
		}
		cin >> s >> e;
		if(s == e) cout << 0 << endl;       // ���յ��غ� 
		else if(!mp.count(s) || !mp.count(e)) cout << -1 << endl;
		else cout << dijkstra(mp[s],mp[e]) << endl;
	}
} 
