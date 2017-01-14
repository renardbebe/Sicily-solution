#include <bits/stdc++.h>
using namespace std;
#define Size 50001

struct Cow {
	int breed;
	int x;
};

Cow a[Size];
int sum[Size];
int len[Size];

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
	sum[0] = a[0].breed;
	len[sum[1]] = 1;
	for(int i = 1; i < n; i++) {
		sum[i] = sum[i-1] + a[i].breed;
		if(len[sum[i]] > 0) {
			int sub = a[i].x - a[len[sum[i]]+1].x;
			if(sub > maxn) maxn = sub;
		}
		else len[sum[i]] = i;
	}
	
	printf("%d\n", maxn);
}
