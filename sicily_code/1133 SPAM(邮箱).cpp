#include <bits/stdc++.h>
using namespace std;

int main () {
	string s;
	while(getline(cin,s)) {
		int len = s.length();
		for(int i = 1; i < len-1; i++) {
			if(s[i] == '@') {
				int pos1 = i, pos2 = i;
				if( s[i-1] == '@' || s[i-1] == ' ' || s[i-1] == '.' || s[i+1] == '@' || s[i+1] == ' ' || s[i+1] == '.' ) continue;
				while( (pos1-1) >= 0 && s[pos1-1] != '@' && s[pos1-1] != ' ' && !((pos1-2) >=0 && s[pos1-1] == '.' && s[pos1-2] == '.') ) pos1--;
				if(s[pos1] == '.') pos1++;
				for(int j = pos1; j < i; j++) cout << s[j];
				
				while( (pos2+1) <= len-1 && s[pos2+1] != '@' && s[pos2+1] != ' ' && !((pos2+2) <= len-1 && s[pos2+1] == '.' && s[pos2+2] == '.') ) pos2++;
				if(s[pos2] == '.') pos2--;
				for(int j = i; j <= pos2; j++) cout << s[j];
				cout << endl;
			}
		}
	}
}
