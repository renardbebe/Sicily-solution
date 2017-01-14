
/* 二分图最佳匹配算法：Kuhn－Munkras算法

   该算法的时间复杂度为 O（m*m*n)
   
   m、n分别是二分图两个子集的顶点数（m<=n) */
   
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define INF 1e+9
#define clr(x) memset(x,-1,sizeof(int)*MAXN)

int kuhn_munkras(int m, int n, int weight[][MAXN], int match1[], int match2[]) {
    int s[MAXN], t[MAXN], l1[MAXN], l2[MAXN], p, q, i, j, k, ret = 0;
    for(i = 0; i < m; i++) {
    	l1[i] = -(INF);
        for(j = 0; j < n; j++) l1[i] = (weight[i][j] > l1[i]) ? weight[i][j] : l1[i];
        if(l1[i] == -(INF)) return -1;
    }
    for(i = 0; i < n; i++) l2[i] = 0;
    clr(match1);
    clr(match2);
    for(i = 0; i < m; i++) {
    	clr(t);
        for(s[p = q = 0] = i; p <= q && match1[i] < 0; p++)
            for(k = s[p], j = 0; j < n && match1[i] < 0; j++)
                if(l1[k] + l2[j] == weight[k][j] && t[j] < 0) {
                    s[++q] = match2[j], t[j]=k;
                    if(s[q] < 0) {
                    	for(p = j; p >= 0; j = p) match2[j] = k = t[j], p = match1[k], match1[k] = j;
					}
                }
        if(match1[i] < 0) {
            for(i--, p = INF, k = 0; k <= q; k++)
                for(j = 0; j < n; j++)
                    if(t[j] < 0 && l1[s[k]] + l2[j] - weight[s[k]][j] < p) p = l1[s[k]] + l2[j] - weight[s[k]][j];
            for(j = 0; j < n; l2[j] += (t[j] < 0) ? 0 : p, j++);
            for(k = 0; k <= q; l1[s[k++]] -= p);
        }
    }
    for(i = 0; i < m; i++) {
        if(match1[i] < 0) return -1;
        if(weight[i][match1[i]] <= -(INF)) return -1;
        ret += weight[i][match1[i]];
    }
    return ret;
}

int main () {
    int n, weight[MAXN][MAXN], match1[MAXN], match2[MAXN];
    while(cin >> n && n) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> weight[i][j];  // X 到 Y 的映射（权重）, X个工人， Y份工作 
        cout << kuhn_munkras(n,n,weight,match1,match2) << endl;
    }
    return 0;
}
