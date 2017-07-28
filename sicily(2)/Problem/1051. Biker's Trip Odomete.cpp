#include <bits/stdc++.h>
using namespace std;

int main () {
	double diameter, revol, time;
	int test = 1;
	while(cin >> diameter >> revol >> time && revol) {
		cout << "Trip #" << test++ << ": ";
		double len = 0.00, speed = 0.00;
		len = (diameter*3.1415927*revol) / (12*5280);
		speed = len / (time/3600);
		cout << fixed << setprecision(2) << len << " " << speed << endl;
	}
}
