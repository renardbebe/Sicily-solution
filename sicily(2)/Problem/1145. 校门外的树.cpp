#include <bits/stdc++.h>
using namespace std;
#define SIZE1 10005
#define SIZE2 105

struct Area
{
	int start;
	int end;
};

Area area[SIZE2];
int tree[SIZE1];

int main () {
	int l, m;
	cin >> l >> m;
	memset(tree,0,sizeof(tree));
	for(int i = 0; i <= l; i++) tree[i] = 1;
	for(int i = 0; i < m; i++) {
		cin >> area[i].start >> area[i].end;
		for(int j = area[i].start; j <= area[i].end; j++) {
			if(tree[j]) tree[j] = 0;
		}
	}
	int cnt = 0;
	for(int i = 0; i <= l; i++) {
		if(tree[i]) cnt++;
	}
	cout << cnt << endl;
	//system("pause");
}