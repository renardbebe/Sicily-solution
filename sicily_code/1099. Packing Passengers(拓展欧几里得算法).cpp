#include <bits/stdc++.h>
using namespace std;

/*
����˼·��

���������ſ���ת�������Է�������ģ�͡�

������ A * x + B * y = n�� x��y��ʹ Cost = CostA * x + CostB * y �ﵽ��С��

1.�����ж�A��B�Ƿ�Ϊ0��

  ���AΪ0��B��Ϊ0����ôyΪn/B��

  ���BΪ0��A��Ϊ0����ôxΪn/B��

  ���A,BͬʱΪ0�����޽�

  ���A��B����Ϊ0���������һ�����㡣

2.ͨ����ʽ�������Եõ� Cost = K * x + b.

  ���KΪ����x��0��ʼ�������õ� yΪ������

  ���KΪ����x��upper(n/A)��ʼ�ݼ����õ� yΪ������

3.����Kʱ������ K = CostA - CostB * A / B��

*/

int main () {
	long long n, cnt = 1;
	while(cin >> n && n) {
		long long left = 0;                                     // ���� �ж��Ƿ������� 
		long long costA, A, costB, B, x = 0, y = 0;
		cin >> costA >> A >> costB >> B;
		if(A == 0 && B) {
			left = n%B;
			x = 0;
			y = n/B;
		}
		else if(A && B == 0) {
			left = n%A;
			y = 0;
			x = n/A;
		}
		else if(A == 0 && B == 0) left = 1;
		else {
			long long k = costA * B - costB * A;                                // �ó������о��ȶ�ʧ �������⸡���� 
			long long upper = (long long)floor((double)(n/A));
			if(k > 0) {
				for(x = 0; x <= upper; x++) {
					y = (n - A*x) / B;
					left = (n - A*x) % B;
					if(!left) break;
				}
			}
			else {
				for(x = upper; x >= 0; x--) {
					y = (n - A*x) / B;
					left = (n - A*x) % B;
					if(!left) break;
				}
			}
		}
		cout << "Data set " << cnt++ << ": ";
		if(!left) cout << x << " aircraft A, " << y << " aircraft B\n";        // �������н�!! 
		else cout << "cannot be flown\n";
	}
	return 0;
}
