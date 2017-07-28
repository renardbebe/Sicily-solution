#include <bits/stdc++.h>
using namespace std;

int main () {
	int a, b, c;
	cin >> a >> b >> c;
	int tmp = a;
	for(int i = 1; i < b; i++) {
		tmp *= a;
		tmp %= c;
	}
	cout << tmp << endl;
	//system("pause");
}