#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
string factors[100];
vector<string> result;
int sum;
int cnt;
bool location[10];
bool digit[10];

int to_number(string s) {
	int ans = 0;
	for(int i = 0; i < s.size(); i++) {
		ans = ans*10 + s[i] - '0';
	}
	return ans;
}
  
void init() {  
	cnt = 0;  
	factors[0] = "";  
	for(int c = 0; c < s.size(); c++) {  
		if(s[c] == ' ') factors[++cnt] = "";
		else factors[cnt] += s[c]; 
	}  
	cnt++;
	for(int c = 1; c < cnt-1; c++) reverse(factors[c].begin(), factors[c].end());  
	memset(location, false, sizeof(location));
	memset(digit, false, sizeof(digit));
	if(!result.empty()) result.clear();
	sum = to_number(factors[cnt-1]);
}  
  
void check() {  
	for(int c = 0; c < 11; c++) {  
		int num[10] = {0,};      
		for(int d = 1; d < cnt-1; d++) {  
			if(c < factors[d].size()) {  
				if(num[factors[d][c] - '0'] == 1) return;  
				else num[factors[d][c] - '0'] = 1;   
			}
		}  
	}  
       
	int temp = 0;  
	for(int d = 1; d < cnt-1; d++) {
		string str = factors[d];
		reverse(str.begin(),str.end());
		temp += to_number(str); 
		 
	}  

	if(temp == sum) {  
		string ss = factors[0];  
		for(int c = 1; c < cnt-1; c++) {  
			ss += " ";  
	        bool pre = false;  
	        string sss = factors[c];  
	        reverse(sss.begin(), sss.end());  
	        for(int d = 0; sss[d] != '\0'; d++) {  
				if(sss[d] > '0') {  
					ss += sss[d];
					pre = true;  
				}
				else if(pre) ss += sss[d];
	        }  
	        if(pre == false) ss += '0';
		}
		result.push_back(ss);  
	}  
}
  
string insert(string ss, int loc, int dig) {  
	char a = dig + '0';  
	string temp = "";  
	if(loc == 0) {  
		temp += a;  
		temp += ss;  
	}
	else {  
		int c;  
		for(c = 0; c < loc && ss[c] != '\0'; c++) temp += ss[c];  
		temp += a;  
		for(; ss[c] != '\0'; c++) temp += ss[c];  
	}  
	return temp;  
}  
  
void dfs(int num) {
	if(num == cnt-1) check();
	else {
		string temp = factors[num];
		for(int c = 0; c <= temp.size(); c++) {
			if(location[c] == true) continue;
			location[c] = true;
			for(int d = 0; d <= 9; d++) {
				if(digit[d] == true) continue;
				digit[d] = true;
				factors[num] = insert(temp, c, d);
				dfs(num+1);
				digit[d] = false;
        	}
			location[c] = false;
		}
		factors[num] = temp;
	}
}
  
void print() {  
	if(result.empty()) cout << factors[0] << " 0" << endl;
	else {  
		sort(result.begin(), result.end());
		for(int c = 0; c < result.size(); c++) cout << result[c] << endl;
	}
}

int main() {
	while(getline(cin, s)) {
		if(s == "0") return 0;
		init();
		dfs(1);
		print();
	}
}
