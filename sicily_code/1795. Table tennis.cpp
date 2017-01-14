#include <bits/stdc++.h>
using namespace std;

int main () {
	int T;
	cin >> T;
	while(T--) {
		int N, points = 0;
		cin >> N;
		for(int k = 0; k < N; k++) {
			int x, y;
			cin >> x >> y;
			if((x - 30)*(x - 30) + (y - 30) * (y - 30) < 20 * 20) points += 1;
			else if((x - 100)*(x - 100) + (y - 30)*(y - 30) < 10 * 10) points += 2;
			else if((x - 170)*(x - 170) + (y - 30)*(y - 30) < 5 * 5) points += 3;
		}
		cout << points << endl;
	}
}
