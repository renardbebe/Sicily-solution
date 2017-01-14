/* 结论P: S[i],S[j]两个元素不能进入同一个栈 <=> 存在k,满足i<j<k,使得S[k]<S[i]<S[j] */
/* 根据输出的顺序给S的元素编号 转化为二分图染色问题 满足P的两个点之间用一条边连接  */ 

/* 设F[i]为Min{S[i],S[i+1],S[i+2]..S[n-1],S[n]},状态转移方程为F[i]=Min{ S[i] , F[i+1] }.边界为F[N+1]=极大的值 */
/* 判断数对(i,j)是否满足P,只需判断(S[i]<S[j] 并且 F[j+1]<S[i])即可.时间复杂度为O(n^2).                        */

#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
bool Edge[maxn][maxn];           // 两点相连 
int s[maxn], F[maxn], color[maxn];
int n;
bool flag;

void dfs(int x, int c) {         // dfs染色 
	color[x] = c;
	for(int i = 0; i < n; i++) {
		if(Edge[i][x]) {
			if(color[i] == c) {
				flag = false;
			}
			if(!color[i]) dfs(i,3-c);
		}
	}
}

void init() {
	memset(s,0,sizeof(s));
    memset(F,0,sizeof(F));
    memset(color,0,sizeof(color));
    for(int i = 0; i < 1001; i++)
    	for(int j = 0; j < 1001; j++)
    		Edge[i][j] = 0;	
    flag = true;
}

int main () {
    while(cin >> n) {
        stack<int>s1;
        stack<int>s2;
        string str = "";
        init();

        for(int i = 0; i < n; i++) cin >> s[i];
        F[n] = 0x7fffffff;
    	for(int i = n-1; i >= 0; i--) F[i] = min(s[i], F[i+1]);
    	for(int i = 0; i < n-1; i++) {
    		for(int j = i+1; j < n; j++) {
    			if(s[i] < s[j] && F[j+1] < s[i]) Edge[i][j] = Edge[j][i] = 1;
			}
		}
		for(int i = 0; i < n; i++) {
			if(!color[i]) dfs(i,1);	
		}
		int ans = 1;
		for(int i = 0; i < n; i++) {
	        if(color[i] == 1) {  
	           s1.push(s[i]);  
	           str += 'a';  
	        }
			else {  
	           s2.push(s[i]); 
	           str += 'c';
	        }      
	        while ( (!s1.empty() && s1.top() == ans) || (!s2.empty() && s2.top() == ans) ) {  
	            if (!s1.empty() && s1.top() == ans) {  
					s1.pop();
	            	str += 'b';
	            }
				else { 
	            	s2.pop();  
	            	str += 'd'; 
	            }
	            ans++;  
	        }  
	    }
    	
		if(flag) {           
			for(int i = 0; i < str.length(); i++) {                
				if(i) cout << " " << str[i];                
				else cout << str[i];             
			}             
			cout << endl;        
		}
		else cout << 0 << endl;
    }
	return 0;      
}

/*                    Wrong Answer Code                 */
/*                       不能用贪心                     */
/* 没有考虑到有时候能压入栈1的情况下也必须压入栈2的情况 */

