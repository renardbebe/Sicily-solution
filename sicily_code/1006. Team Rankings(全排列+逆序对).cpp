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
			strcpy(permutation[cnt++], init);              // ���ֵ��򱣴�ȫ���� 
		}while (next_permutation(init, init+5));
		
		for(int i = 0; i < n; i++) {
			cin >> s[i];
		}		
		int min_dis = 999999;
		char min_string[6] = "ABCDE";
		
		for(int i = 0; i < 120; i++) {                     // �����ַ�����ȫ���� 
			int sum = 0; 
			for(int j = 0; j < n; j++) {                   // ����������ַ���
				for(int m = 0; m < 5; m++) {               // ����ĳ��ȫ�����ַ�����ÿһλ�ַ� 
					for(int n = m+1; n < 5; n++) {         // ����ĳ��ȫ�����ַ�����ÿһλ�ַ��ĺ�һλ 
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
	strchr() ��������ĳ�ַ����ַ������״γ��ֵ�λ�ã���ԭ��Ϊ��
    char* strchr (const char *str, int c);
    
    ��������str ΪҪ���ҵ��ַ�����c ΪҪ���ҵ��ַ�.
    ������ֵ������ҵ�ָ�����ַ��򷵻ظ��ַ����ڵ�ַ�����򷵻� NULL.
	strchr() �����ҳ� str �ַ����е�һ�γ��ֵ��ַ� c �ĵ�ַ��Ȼ�󽫸õ�ַ���ء�
	
*/ 
