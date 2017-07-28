#include <bits/stdc++.h>
using namespace std;
double a[15];
double tx[15];

int main () {
	int n;
	while(cin >> n && n) {
		memset(a,0.0,sizeof(a));
		memset(tx,0.0,sizeof(tx));
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a,a+n);
		for(int i = 0; i < n; i++) tx[i] = (a[0] + a[i])/2;
		double x = tx[n-1];
		double y = 1.0;
        for(int i = 0; i < n-1; i++){
           y += sqrt(4-(tx[i+1] - tx[i]) * (tx[i+1] - tx[i]));
        }
		cout << fixed << setprecision(4) << x << " " << y << endl;
	}
}