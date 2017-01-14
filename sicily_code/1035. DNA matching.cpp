#include <iostream>
#include <map>

using namespace std;

map<char, char> m;

bool match(string s1, string s2)
{
	if(s1.length() != s2.length())
		return false;
	else {
		for(int i=0; i<s1.length(); i++){
			if(m[s1[i]] != s2[i])
				return false;
		}
	}
	return true;
}

int main()
{
	m['A'] = 'T';	m['T'] = 'A';
	m['C'] = 'G';	m['G'] = 'C';	    // 匹配关系 
	int t;
	cin >> t;
	while(t--){
		int n;
		string s[101];
		bool use[101] = {0};            // 标记单链是否被使用过 
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> s[i];
		}
		int count = 0;
		for(int i=0; i<n; i++){
			if(!use[i]){
				for(int j=i+1; j<n; j++){
					if(!use[j] && match(s[i], s[j]))
					{
						count ++;
						use[i] = use[j] = 1;
						break;
					}		
				}	
			}	
		}
		cout << count << endl;
	}
}

