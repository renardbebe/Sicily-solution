// -- Text Reverse
/*
���������� Input  :olleh !dlrow
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
	getchar(); //����n����Ļ��з���������
	
	int cnt = 1;
	while(cnt<=n) {
		string s;
		getline(cin, s, '\n'); //����һ�У��Ի��з�'\n'�����ģ��ַ������浽s�У�'\n'���ᱻ�洢���Ǳ�������
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
