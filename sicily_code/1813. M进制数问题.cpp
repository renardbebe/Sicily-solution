#include <bits/stdc++.h>
using namespace std;

int trans(string s, int m) {
	int len = s.length(), num = 0;
	for(int i = len - 1, j = 0; i >= 0; i--, j++) {
		if(s[i] >= '0' && s[i] <= '9') num += (s[i] - '0') * pow(m,j);
        else if(s[i] >= 'A' && s[i] <= 'Z') num += (s[i] - 'A' + 10) * pow(m,j);
        else if(s[i] >= 'a' && s[i] <= 'z') num += (s[i] - 'a' + 10) * pow(m,j);
	}	
	return num;
}

string reverse_trans(int number, int m) {
	string str, s = "";
	if(!number) s = "0";
	else {
		while(number) {
			int x = number%m;
			if(x >= 0 && x <= 9) str += (x + '0');
			else str += (char)(x + 'A' - 10);
			number /= m;
		}
		for(int i = str.length() - 1; i >= 0; i--) s += str[i];	
	}
	return s;
}

int main () 
{
	int T, m;
	string A, B;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &m);
		cin >> A >> B;
		int a = trans(A, m), b = trans(B, m);
		string P, Q;
		P = reverse_trans(a/b, m);
		Q = reverse_trans(a%b, m);
		cout << P << endl << Q << endl; 
	}
}
