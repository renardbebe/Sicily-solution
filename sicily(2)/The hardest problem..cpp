// -- ��� �����һ�����е����ֵ 
// -- �ҵ� N=0 ʱ����� 
#include <iostream>
using namespace std;
int main ()
{
	int N,a,max=0;
	while(cin >> N&&N!=0){
	for(int i=0;i<N;i++){
		cin >> a;
		if (i == 0)  
                max = a;  // �������븺������� 
        else  
                max = max > a? max : a;  
	}
	cout << max << endl; 
}
    return 0;
}
