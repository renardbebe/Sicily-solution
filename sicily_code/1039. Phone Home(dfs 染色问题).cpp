#include <bits/stdc++.h>
using namespace std;

struct Tower{
	double x;
	double y;
};

int cnt, n;
Tower a[20];
bool adj[20][20];
int color[20];
bool flag;

void init() {
	for(int i = 0; i < 20; i++) {
		a[i].x = 0;
		a[i].y = 0;
	}
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) 
			adj[i][j] = false;
	}
	for(int i = 0; i < 20; i++) color[i] = 0;
	cnt = 0;
	flag = false;
}

bool check(int i) {
	for(int j = 0; j < n; j++) {
		if( (i != j) && adj[i][j] && (color[i] == color[j])) return false;
	}
	return true;
}

void dfs(int i) {
	if(i > n) {
		flag = true;
		return;
	}
	else {
		for(int k = 1; k <= 5; k++) {        // the max color number is 5
			if(flag) break;
			color[i] = k;
			if(check(i)) {
				if(k > cnt) cnt = k;
				dfs(i+1);
			}
			color[i] = 0;
		}
	}
}

int main () {
	int k = 1;
	while(cin >> n) {
		if(!n) return 0;
		init();
		for(int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if( (a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y) <= 400 ) adj[i][j] = adj[j][i] = true;
			}
		}
		dfs(0);
		cout << "The towers in case " << k++ << " can be covered in " << cnt << " frequencies.\n";
	}
}
