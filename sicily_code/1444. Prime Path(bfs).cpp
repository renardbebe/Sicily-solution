#include <bits/stdc++.h>
using namespace std;

string s1, s2;
queue<string> q;
int step[10000];
bool flag;

bool isPrime(string s) {
	int number = 0;
	for(int i = 0; i < s.length(); i++) number = number * 10 + (s[i] - '0');

	if(number < 2) return false; 
	for(int i = 2; i <= sqrt(number); i++)   
		if(number%i == 0) return false;   
	return true;
}

int toNum(string s) {
	int num = 0;
	for(int i = 0; i < s.length(); i++) num = num*10 + s[i] - '0';
	return num;
}

void init() {
	while(!q.empty()) q.pop();
	memset(step,0,sizeof(step));
	flag = false;
}

int main () {
	int kase;
	cin >> kase;
	while(kase--) {
		cin >> s1 >> s2;
		if(s1 == s2) cout << 0 << endl;
		else {
			init();
			q.push(s1);
			while(!q.empty()) {
				string s = q.front();
				if(s == s2) {
					flag = true;
					break;
				}
				
				q.pop();
				string tmp = s;
				for(int j = '0'; j <= '9'; j++) {
					for(int i = 0; i < 4; i++) {
						if(s[i] != j && !((i == 0) && (j == '0'))) {
							tmp[i] = j;
							if(isPrime(tmp) && !step[toNum(tmp)]) {
								q.push(tmp);
								step[toNum(tmp)] = step[toNum(s)] + 1;
							}
							tmp[i] = s[i]; // »¹Ô­ 
						}
					}
				}
			}
			if(flag) cout << step[toNum(s2)] << endl;
			else cout << "Impossible\n";	
		}	
	}
}
