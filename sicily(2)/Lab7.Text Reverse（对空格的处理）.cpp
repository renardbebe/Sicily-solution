// -- Text Reverse
/*
测试样例： Input  :olleh !dlrow
           Output :hello world!
*/ 
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main ()
{
	int n,k,len=0;
	cin>>n;
	getchar(); //读入n后面的换行符，抛弃掉
	
	int cnt = 1;
	while(cnt<=n) {
		string s;
		getline(cin, s, '\n'); //读入一行（以换行符'\n'结束的）字符串，存到s中，'\n'不会被存储而是被抛弃掉
		for(int i=0;i<s.length();i++){
			if(s[i]!=' '){
				k=i;
				len++;
			}
			else{	
				for(int j=k;j>=k-len+1;j--) cout << s[j];
			    cout << " ";
			    len=0;
			}
			if(i==s.length()-1){
				for(int j=k;j>=k-len+1;j--) cout << s[j];
				len=0; 
			}
		}
		cout << endl;
		cnt = cnt + 1;
	}
}
