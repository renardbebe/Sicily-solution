// -- 科学计数法转换为一般数字表示 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
int main ()
{
	string a;
	while (cin >>a){
		cout << fixed << setprecision(10);
		int k,len=a.length();
		for(int i=0;i<len;){
			if(a[i]!='e')  i++;
			else {
				k=i;
				break;
			}
		}
		string m=a.substr(0,k),n=a.substr(k+1,len-k-1);
		double x,y;
		stringstream o(m);
		o>>x;
		stringstream p(n);
		p>>y;                  /* stringstream函数用法：
		                          stringstream 流a(初始变量b)  流a >>变量c
								  即把变量b 转型给变量 c
		                       */    
		cout << x*pow(10,y)<<endl;
	}
} 
