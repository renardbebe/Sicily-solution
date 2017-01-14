#include <bits/stdc++.h>
using namespace std;
int goal[2][4];
int n;

struct Board {
	int tmp[2][4];
	int step;
	string ans;
	Board() {
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 4; j++) {
				tmp[i][j] = 0;
			}
		}
		step = 0;
		ans = "";
	}
};
Board B;

struct Ans {
	int step;
	string s;
};
Ans ans;

bool equal(Board b1, Board b2) {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			if(b1.tmp[i][j] != b2.tmp[i][j]) return false;
		}
	}
	return true;
}

Ans bfs(Board bb) {
	queue<Board> q;
	q.push(bb);
	int step = 0;
	while(!q.empty()) {
		Board b = q.front();
		for(int i = 1; i <= 3; i++) {
			switch (i) {
				case 1 : {  // 上下交换 
					Board b1;
					b1.tmp[0][0] = b.tmp[1][0];b1.tmp[0][1] = b.tmp[1][1];b1.tmp[0][2] = b.tmp[1][2];b1.tmp[0][3] = b.tmp[1][3];
					b1.tmp[1][0] = b.tmp[0][0];b1.tmp[1][1] = b.tmp[0][1];b1.tmp[1][2] = b.tmp[0][2];b1.tmp[1][3] = b.tmp[0][3];
					b1.step = b.step + 1;
					b1.ans = b.ans + 'A';
					q.push(b1);
					if(equal(b1, B)) {
						Ans x;
						x.s = b1.ans;
						x.step = b1.step;
						return x;
					}
					break;
				}
				case 2 : {  // 循环右移 
					Board b2;
					b2.tmp[0][0] = b.tmp[0][3];b2.tmp[0][1] = b.tmp[0][0];b2.tmp[0][2] = b.tmp[0][1];b2.tmp[0][3] = b.tmp[0][2];
					b2.tmp[1][0] = b.tmp[1][3];b2.tmp[1][1] = b.tmp[1][0];b2.tmp[1][2] = b.tmp[1][1];b2.tmp[1][3] = b.tmp[1][2];
					b2.step = b.step + 1;
					b2.ans = b.ans + 'B';
					q.push(b2);
					if(equal(b2, B)) {
						Ans x;
						x.s = b2.ans;
						x.step = b2.step;
						return x;
					}
					break;
				}
				case 3 : {  // 顺时针 
					Board b3;
					b3.tmp[0][1] = b.tmp[1][1];b3.tmp[0][2] = b.tmp[0][1];b3.tmp[1][1] = b.tmp[1][2];b3.tmp[1][2] = b.tmp[0][2];
					b3.tmp[0][0] = b.tmp[0][0];b3.tmp[1][0] = b.tmp[1][0];b3.tmp[0][3] = b.tmp[0][3];b3.tmp[1][3] = b.tmp[1][3];
					b3.step = b.step + 1;
					b3.ans = b.ans + 'C';
					q.push(b3);
					if(equal(b3, B)) {
						Ans x;
						x.s = b3.ans;
						x.step = b3.step;
						return x;
					}
					break;
				}
				default : break;
			}
		}
		q.pop();
	}
}

int main () {
	while(cin >> n && n != -1) {
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 4; j++) {
				cin >> B.tmp[i][j];
			}
		}
		Board b;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 4; j++) {
				if(!i) b.tmp[i][j] = j+1;
				else b.tmp[i][j] = 8-j;
			}
		}
		b.step = 0;
		ans.s = "";
		ans.step = 0;
		ans = bfs(b);
		
		if(ans.step != -1 && ans.step <= n) cout << ans.step << " " << ans.s << endl;
		else cout << -1 << endl;
	}
}
