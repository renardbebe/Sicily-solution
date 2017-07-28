#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, ways;
	while(cin >> n) {
		if(n == -1) return 0;		
		if(n%2 == 1) ways = 0;
		else if(n == 0) ways = 1;            // n = 0时，输出 1 !!
		else {
			int re[35];
			int unre[35];
			memset(re,0,sizeof(re));
			memset(unre,0,sizeof(unre));
			re[2] = 3;
			unre[2] = 1;
			for(int i = 4; i <= 30; i += 2) {
				re[i] = re[i-2]*3 + unre[i-2]*2;
				unre[i] = unre[i-2] + re[i-2];
			}
			ways = re[n];
		}
		cout << ways << endl;
	}
}

/*  方法二： 递推公式  f(n)= 4 * f(n-2) -f(n-4)  */ 
