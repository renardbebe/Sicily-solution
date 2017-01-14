#include <bits/stdc++.h>
using namespace std;
#define SIZE 102

int mp[SIZE][SIZE][SIZE];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int up, down;

bool in(int x, int y, int z) {
	if(x >= down && x <= up && y >= down && y <= up && z >= down && z <= up) return true;
	else return false;
}
/*
void dfs(int x, int y, int z) {
	mp[x][y][z] = 1;
	
	for(int i = 0; i < 6; i++) {
		int tmp_x = x + dx[i];
		int tmp_y = y + dy[i];
		int tmp_z = z + dz[i];
		if(in(tmp_x,tmp_y,tmp_z) && !mp[tmp_x][tmp_y][tmp_z]) dfs(tmp_x,tmp_y,tmp_z);
	}
}*/

struct Node {
	int x;
	int y;
	int z;
	Node(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
	} 
};

void bfs(int x, int y, int z) {
	queue<Node> q;
	Node node(x, y, z);
	q.push(node);
	mp[x][y][z] = 1;
	while(!q.empty()) {
		Node top = q.front();
		for(int i = 0; i < 6; i++) {
			int tmp_x = top.x + dx[i];
			int tmp_y = top.y + dy[i];
			int tmp_z = top.z + dz[i];
			if(in(tmp_x,tmp_y,tmp_z) && !mp[tmp_x][tmp_y][tmp_z]) {
				Node tmp(tmp_x,tmp_y,tmp_z);
				q.push(tmp);
				mp[tmp_x][tmp_y][tmp_z] = 1;
			}
		}
		q.pop();
	}
}

int main () {
	int t;
	cin >> t;
	while(t--) {
		int m, x, y, z;
		cin >> m;
		for(int i = 0; i < SIZE; i++)
			for(int j = 0; j < SIZE; j++)
				for(int k = 0; k < SIZE; k++)
					mp[i][j][k] = 0;
		up = 101;
		down = 0;
		for(int i = 0; i < m; i++) {
			cin >> x >> y >> z;
			mp[x][y][z] = 1;
		}
		int cnt = 0;
		for(int i = down; i <= up; i++) {
			for(int j = down; j <= up; j++) {
				for(int k = down; k <= up; k++) {
					if(!mp[i][j][k]) {
						bfs(i, j, k);
						cnt++;
					}
				}
			}
		}
		cout << cnt-1 << endl;
	}
}

/*
	dfs 会炸？
	
	dfs 有栈使用上限 大概调用35w次后就会炸 
	
	一般在两种情况均可时，dfs过不了可以试bfs (但可能炸空间) 
*/
