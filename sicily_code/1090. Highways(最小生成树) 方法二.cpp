#include <bits/stdc++.h>
using namespace std;
#define N 505

using namespace std;

struct Edge{
	int a;
	int b;
	int w;
	Edge(int x, int y, int z) {
		a = x;
		b = y;
		w = z;
	}
};

int n, p[N];
vector<Edge> vc;

int cmp(const Edge i,const Edge j)
{
	return i.w < j.w;
}

int find(int x)    // ���鼯�Ѹ��ڵ� 
{
	if(p[x] == x) return x;
	else {
		p[x] = find(p[x]);
		return p[x];
	}
}

int kruskal()
{
    int maxn = 0;
    for(int i = 1; i <= n; i++) p[i] = i;       // ʼ����ָ��,һ��ʼÿ����ĸ��׶����Լ�
    for(int i = 0; i < vc.size(); i++)
    {
        if(find(vc[i].a) != find(vc[i].b)) {
        	if(maxn < vc[i].w) maxn = vc[i].w;
        	p[find(vc[i].a)] = find(vc[i].b);   // �ϲ������� -> �ѽ��"������" 
		}                                       // ��������һ����Ȩֵ��С���� 
    }
    return maxn;
}

int main()
{
    int T;
	cin >> T;
	while(T--) {
		cin >> n;
		vc.clear();
		int a[N][N];
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if(i < j) vc.push_back(Edge(i,j,a[i][j]));
			}
		}
		sort(vc.begin(),vc.end(),cmp);
		int ans = kruskal();
        printf("%d\n",ans);
        if(T) printf("\n");
	} 
}
