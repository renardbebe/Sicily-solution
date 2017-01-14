#include <bits/stdc++.h>
using namespace std;

/*
解题思路：

根据题意大概可以转化成线性方程求解的模型。

求满足 A * x + B * y = n的 x、y，使 Cost = CostA * x + CostB * y 达到最小。

1.首先判断A，B是否为0。

  如果A为0，B不为0，那么y为n/B；

  如果B为0，A不为0，那么x为n/B；

  如果A,B同时为0，则无解

  如果A，B都不为0，则进行下一步计算。

2.通过等式代换可以得到 Cost = K * x + b.

  如果K为正，x从0开始递增，得到 y为整数。

  如果K为负，x从upper(n/A)开始递减，得到 y为整数。

3.计算K时，理论 K = CostA - CostB * A / B。

*/

int main () {
	long long n, cnt = 1;
	while(cin >> n && n) {
		long long left = 0;                                     // 余数 判断是否能整除 
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
			long long k = costA * B - costB * A;                                // 用除法会有精度丢失 尽量避免浮点数 
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
		if(!left) cout << x << " aircraft A, " << y << " aircraft B\n";        // 整除才有解!! 
		else cout << "cannot be flown\n";
	}
	return 0;
}
