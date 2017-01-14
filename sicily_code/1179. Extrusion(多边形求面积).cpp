#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

// S = (x2*y1-y2*x1+x3*y2-y3*x2+ бн+x1*yn-y1*xn)/2

int main () {
	int N;
	while(cin >> N && N >= 3) {
		double area = 0.0, a, b, x, y, x1, y1;
		cin >> x1 >> y1;
		a = x1;
		b = y1;
		for(int i = 2; i <= N; i++) {
			cin >> x >> y;
			area += x*b - y*a;
			a = x;
			b = y; 
		}
		area += x1*y - y1*x;
		double cube;
    	cin >> cube;
    	cout << "BAR LENGTH: " << fixed << setprecision(2) << cube*2/area << endl;
	}
	return 0;
}
