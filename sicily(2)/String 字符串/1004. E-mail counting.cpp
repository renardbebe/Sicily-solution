// -- 邮箱地址 
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main ()
{
	string a;
	int n,count;	
	while(cin>>n&&n!=0){
		while(n--){
		cin >> a;	
		int k=0,error=0,sum=0;
		int len=a.length();
		for(int i=0;i<len;i++){
			if(a[i]=='@'){
				k=i;
				break;
			}
		}
		if(k==0||k==len-1) error++;    //第一位或最后一位是 @ 
		string f=a.substr(0,k),b=a.substr(k+1,len-1);
		for(int i=0;i<f.length();i++){
			if((f[i]>='a'&&f[i]<='z')||(f[i]>='A'&&f[i]<='Z')||(f[i]>='0'&&f[i]<='9')) error+=0;       // @ 以前为数字或字母 
			else error++;             
		}
		if((a[0]>='a'&&a[0]<='z')||(a[0]>='A'&&a[0]<='Z')||(a[0]>='0'&&a[0]<='9')) error+=0;           //第一位为数字或字母 
		else error++;
		if((a[len-1]>='a'&&a[len-1]<='z')||(a[len-1]>='A'&&a[len-1]<='Z')||(a[len-1]>='0'&&a[len-1]<='9')) error+=0;      //最后一位为数字或字母
		else error++;
		if((a[k-1]>='a'&&a[k-1]<='z')||(a[k-1]>='A'&&a[k-1]<='Z')||(a[k-1]>='0'&&a[k-1]<='9')) error+=0;     // @ 的前一位为数字或字母 
		else error++;
		if((a[k+1]>='a'&&a[k+1]<='z')||(a[k+1]>='A'&&a[k+1]<='Z')||(a[k+1]>='0'&&a[k+1]<='9')) error+=0;     //  @ 的后一位为数字或字母 
		else error++;
		
		for(int j=0;j<b.length();j++){
			if((b[j]>='a'&&b[j]<='z')||(b[j]>='A'&&b[j]<='Z')||(b[j]>='0'&&b[j]<='9')||b[j]=='.')  error+=0;
			else error++; 
		}
		for(int j=0;j<b.length();j++){
			if(b[j]=='.'){
				if(b[j+1]=='.') error++;         //连续出现 .  
			}
		}
		if(error==0) count ++; 
		}
	cout << count << endl;
	count=0;
	}
} 
