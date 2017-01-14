#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	while(cin >> n && n) {
		char s[n+1][6];
		char permutation[125][6];
		char init[6] = "ABCDE";
		int cnt = 0;
		
		do {
			strcpy(permutation[cnt++], init);              // 按字典序保存全排列 
		}while (next_permutation(init, init+5));
		
		for(int i = 0; i < n; i++) {
			cin >> s[i];
		}		
		int min_dis = 999999;
		char min_string[6] = "ABCDE";
		
		for(int i = 0; i < 120; i++) {                     // 遍历字符串的全排列 
			int sum = 0; 
			for(int j = 0; j < n; j++) {                   // 遍历输入的字符串
				for(int m = 0; m < 5; m++) {               // 遍历某个全排列字符串的每一位字符 
					for(int n = m+1; n < 5; n++) {         // 遍历某个全排列字符串的每一位字符的后一位 
						if (strchr(s[j], permutation[i][m]) > strchr(s[j], permutation[i][n])) sum++;
					}
				}
			}
			if(sum < min_dis) {
				min_dis = sum;
				strcpy(min_string, permutation[i]);
			}
		}
		cout << min_string << " is the median ranking with value " << min_dis << ".\n";
	}
}

/*
	strchr() 用来查找某字符在字符串中首次出现的位置，其原型为：
    char* strchr (const char *str, int c);
    
    【参数】str 为要查找的字符串，c 为要查找的字符.
    【返回值】如果找到指定的字符则返回该字符所在地址，否则返回 NULL.
	strchr() 将会找出 str 字符串中第一次出现的字符 c 的地址，然后将该地址返回。
	
*/ 
