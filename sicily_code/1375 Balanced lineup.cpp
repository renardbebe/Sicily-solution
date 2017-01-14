#include <bits/stdc++.h>
using namespace std;
#define Size 50001

struct Cow {
	int breed;
	int x;
};

Cow a[Size];
int sum_[Size];

bool cmp(Cow m, Cow p) {
	return m.x < p.x;
}

int main () {
	int n, value;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &value, &a[i].x);
		if(value) a[i].breed = value;
		else a[i].breed = -1;
	}
	sort(a,a+n,cmp);
	
	int maxn = 0;
	for(int i = 0; i < n; i++) {
		int cnt = 1;
		sum_[i] = a[i].breed;
		for(int j = i+1; j < n; j++) {
			sum_[i] += a[j].breed;
			if(!sum_[i]) {
				int sub = a[j].x - a[i].x;
				if(sub > maxn) maxn = sub;
			}
		}
	}
	printf("%d\n", maxn);
}
