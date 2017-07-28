#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string a;
	int maxlen=0;
	while(cin>>a){
		int len=a.length();
		for(int i=0;i<len;i++){
			for(int j=0;i-j>=0&&j+i<=len;j++){          //奇数回文串 
				if(a[i-j]!=a[i+j]) break;
				if(2*j+1>maxlen) maxlen=2*j+1;
			}
			for(int j=1;i-j>=0&&j+i-1<=len;j++){          //偶数回文串 
				if(a[i-j]!=a[i+j-1]) break;
				if(2*j>maxlen) maxlen=2*j;
			}
		}
	cout << maxlen << endl;
	maxlen=0;
	}
} 
