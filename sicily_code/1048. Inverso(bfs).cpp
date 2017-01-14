#include <bits/stdc++.h>
using namespace std;

struct Map {
	char mp[3][3];
	string ans;
};
Map Mp;

bool check(Map m) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(m.mp[i][j] != 'w') return false;
		}
	}
	return true;
}

void transfer(Map &m, int num) {
	switch(num) {
		case 1 : {
			(m.mp[0][0] == 'w') ? m.mp[0][0] = 'b' : m.mp[0][0] = 'w';  // 1
			(m.mp[0][1] == 'w') ? m.mp[0][1] = 'b' : m.mp[0][1] = 'w';  // 2
			(m.mp[1][0] == 'w') ? m.mp[1][0] = 'b' : m.mp[1][0] = 'w';  // 4
			(m.mp[1][1] == 'w') ? m.mp[1][1] = 'b' : m.mp[1][1] = 'w';  // 5
			break;
		}
		case 2 : {
			(m.mp[0][0] == 'w') ? m.mp[0][0] = 'b' : m.mp[0][0] = 'w';  // 1
			(m.mp[0][1] == 'w') ? m.mp[0][1] = 'b' : m.mp[0][1] = 'w';  // 2
			(m.mp[0][2] == 'w') ? m.mp[0][2] = 'b' : m.mp[0][2] = 'w';  // 3
			(m.mp[1][0] == 'w') ? m.mp[1][0] = 'b' : m.mp[1][0] = 'w';  // 4
			(m.mp[1][1] == 'w') ? m.mp[1][1] = 'b' : m.mp[1][1] = 'w';  // 5
			(m.mp[1][2] == 'w') ? m.mp[1][2] = 'b' : m.mp[1][2] = 'w';  // 6
			break;
		}
		case 3 : {
			(m.mp[0][1] == 'w') ? m.mp[0][1] = 'b' : m.mp[0][1] = 'w';  // 2
			(m.mp[0][2] == 'w') ? m.mp[0][2] = 'b' : m.mp[0][2] = 'w';  // 3
			(m.mp[1][1] == 'w') ? m.mp[1][1] = 'b' : m.mp[1][1] = 'w';  // 5
			(m.mp[1][2] == 'w') ? m.mp[1][2] = 'b' : m.mp[1][2] = 'w';  // 6
			break;
		}
		case 4 : {
			(m.mp[0][0] == 'w') ? m.mp[0][0] = 'b' : m.mp[0][0] = 'w';  // 1
			(m.mp[0][1] == 'w') ? m.mp[0][1] = 'b' : m.mp[0][1] = 'w';  // 2
			(m.mp[1][0] == 'w') ? m.mp[1][0] = 'b' : m.mp[1][0] = 'w';  // 4
			(m.mp[1][1] == 'w') ? m.mp[1][1] = 'b' : m.mp[1][1] = 'w';  // 5
			(m.mp[2][0] == 'w') ? m.mp[2][0] = 'b' : m.mp[2][0] = 'w';  // 7
			(m.mp[2][1] == 'w') ? m.mp[2][1] = 'b' : m.mp[2][1] = 'w';  // 8
			break;
		}
		case 5 : {
			(m.mp[0][0] == 'w') ? m.mp[0][0] = 'b' : m.mp[0][0] = 'w';  // 1
			(m.mp[0][1] == 'w') ? m.mp[0][1] = 'b' : m.mp[0][1] = 'w';  // 2
			(m.mp[0][2] == 'w') ? m.mp[0][2] = 'b' : m.mp[0][2] = 'w';  // 3
			(m.mp[1][0] == 'w') ? m.mp[1][0] = 'b' : m.mp[1][0] = 'w';  // 4
			(m.mp[1][1] == 'w') ? m.mp[1][1] = 'b' : m.mp[1][1] = 'w';  // 5
			(m.mp[1][2] == 'w') ? m.mp[1][2] = 'b' : m.mp[1][2] = 'w';  // 6
			(m.mp[2][0] == 'w') ? m.mp[2][0] = 'b' : m.mp[2][0] = 'w';  // 7
			(m.mp[2][1] == 'w') ? m.mp[2][1] = 'b' : m.mp[2][1] = 'w';  // 8
			(m.mp[2][2] == 'w') ? m.mp[2][2] = 'b' : m.mp[2][2] = 'w';  // 9
			break;
		}
		case 6 : {
			(m.mp[0][1] == 'w') ? m.mp[0][1] = 'b' : m.mp[0][1] = 'w';  // 2
			(m.mp[0][2] == 'w') ? m.mp[0][2] = 'b' : m.mp[0][2] = 'w';  // 3
			(m.mp[1][1] == 'w') ? m.mp[1][1] = 'b' : m.mp[1][1] = 'w';  // 5
			(m.mp[1][2] == 'w') ? m.mp[1][2] = 'b' : m.mp[1][2] = 'w';  // 6
			(m.mp[2][1] == 'w') ? m.mp[2][1] = 'b' : m.mp[2][1] = 'w';  // 8
			(m.mp[2][2] == 'w') ? m.mp[2][2] = 'b' : m.mp[2][2] = 'w';  // 9
			break;
		}
		case 7 : {
			(m.mp[1][0] == 'w') ? m.mp[1][0] = 'b' : m.mp[1][0] = 'w';  // 4
			(m.mp[1][1] == 'w') ? m.mp[1][1] = 'b' : m.mp[1][1] = 'w';  // 5
			(m.mp[2][0] == 'w') ? m.mp[2][0] = 'b' : m.mp[2][0] = 'w';  // 7
			(m.mp[2][1] == 'w') ? m.mp[2][1] = 'b' : m.mp[2][1] = 'w';  // 8
			break;
		}
		case 8 : {
			(m.mp[1][0] == 'w') ? m.mp[1][0] = 'b' : m.mp[1][0] = 'w';  // 4
			(m.mp[1][1] == 'w') ? m.mp[1][1] = 'b' : m.mp[1][1] = 'w';  // 5
			(m.mp[1][2] == 'w') ? m.mp[1][2] = 'b' : m.mp[1][2] = 'w';  // 6
			(m.mp[2][0] == 'w') ? m.mp[2][0] = 'b' : m.mp[2][0] = 'w';  // 7
			(m.mp[2][1] == 'w') ? m.mp[2][1] = 'b' : m.mp[2][1] = 'w';  // 8
			(m.mp[2][2] == 'w') ? m.mp[2][2] = 'b' : m.mp[2][2] = 'w';  // 9
			break;
		}
		case 9 : {
			(m.mp[1][1] == 'w') ? m.mp[1][1] = 'b' : m.mp[1][1] = 'w';  // 5
			(m.mp[1][2] == 'w') ? m.mp[1][2] = 'b' : m.mp[1][2] = 'w';  // 6
			(m.mp[2][1] == 'w') ? m.mp[2][1] = 'b' : m.mp[2][1] = 'w';  // 8
			(m.mp[2][2] == 'w') ? m.mp[2][2] = 'b' : m.mp[2][2] = 'w';  // 9
			break;
		}
	}
}

string bfs(string s) {
	int k = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			Mp.mp[i][j] = s[k++];
		}
	}

	queue<Map> q;
	q.push(Mp);
	while(!q.empty()) {
		Map top = q.front();
		for(int i = 1; i <= 9; i++) {
			Map p = top;
			transfer(p,i);
			p.ans += (char)(i + '0');
			if(check(p)) {
				return p.ans;
			}
			q.push(p);
		}
		q.pop();
	}
}

int main () {
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		cout << bfs(s) << endl;
	}
}
