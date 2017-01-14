#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1005;

bool used[SIZE];
int a[SIZE];
int n, m, d; // 1 <= n < m <= 1000, and 2 <= d <= 10
bool flag;

bool isPrime(int number) {
	if(number < 2) return false; 
	for(int i = 2; i*i <= number; i++)   
		if(number%i == 0) return false;   
	return true;
}

bool check(int pos,int value) {
	int sum = value;
	for(int i = pos-1; i >= 0 && i >= (pos-d+1); i--) {
		sum += a[i];
		if(isPrime(sum)) return false;
	}
	return true;
}

void dfs(int pos) {
	if(pos == m-n+1) {
		flag = true;
		return;
	}
	
	for(int i = n; i <= m; i++) {
		if(!used[i] && check(pos, i)) {      // ±ØÐëÏÈÅÐ¶Ï used[i] ·ñÔò TLE 
			a[pos] = i;
			used[i] = true;
			dfs(pos+1);
			if(!flag) used[i] = false;
			else return;
		}
	}
}

int main () {	
	while(cin >> n >> m >> d && n && m && d) {
		memset(used,false,sizeof(used));
		memset(a,0,sizeof(a));
		flag = false;
		dfs(0);
		
		if(!flag) printf("No anti-prime sequence exists.\n");
		else {
			cout << a[0];
			for(int i = 1; i <= (m-n); i++) {
				cout << "," << a[i];
			}
			cout << endl;	
		}
	}
}
