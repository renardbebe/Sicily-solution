// -- 输出 输入的一组数中的最大值 
// -- 且当 N=0 时无输出 
#include <iostream>
using namespace std;
int main ()
{
	int N,a,max=0;
	while(cin >> N&&N!=0){
	for(int i=0;i<N;i++){
		cin >> a;
		if (i == 0)  
                max = a;  // 考虑输入负数的情况 
        else  
                max = max > a? max : a;  
	}
	cout << max << endl; 
}
    return 0;
}
