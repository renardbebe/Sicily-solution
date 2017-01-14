#include <bits/stdc++.h>
using namespace std;

int main () {
	string s1, s2;
	cin >> s1 >> s2;
	int n = 0;
	/* 单节点的前序遍历的左相邻顶点和后序遍历的右相邻顶点相同 */
	for(int i = 1; i < s1.length(); i++) {
		for(int j = 0; j < s2.length()-1; j++) {
			if(s1[i] == s2[j] && s1[i-1] == s2[j+1]) n++;
		}
	}
	cout << (int)(pow(2,n));
}
