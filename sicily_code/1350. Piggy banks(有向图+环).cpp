#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000005
int key_position[SIZE];
int visit[SIZE];

int main () {
	int n;
	while(cin >> n) {
		memset(key_position,0,sizeof(key_position));
		memset(visit,0,sizeof(visit));
		for(int i = 1; i <= n; i++) {
			cin >> key_position[i];
		}
		int min_break = 0, bk = 0;
		for(int i = 1; i <= n; i++) {
			if(!visit[i]) {
				bk++;
				int bank = i;
				while(1) {
					if(visit[bank]) {
						if(visit[bank] == bk) min_break++;  // ˵���л� 
						break;
					}
					else {
						visit[bank] = bk;
						bank = key_position[bank];
					}
				}
			}
		}
		cout << min_break << endl;
	}
}

// ����ת��Ϊ ������ͼ����ͨ���� -> ����洢 
