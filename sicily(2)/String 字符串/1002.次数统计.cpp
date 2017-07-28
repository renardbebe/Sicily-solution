#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s,p;
	while(cin >> s >> p ){
		int i=0,count=0;
		int len1=p.length(),len2=s.length();
		while((i + len1) <= len2){
			if( s.substr(i,len1) == p){
				count++;
				i+=len1;
			}
			else i++;  //未检测到重复则后移一位 
		}
		cout << count << endl;
	}
	return 0;
} 
