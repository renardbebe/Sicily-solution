#include <bits/stdc++.h>
using namespace std;

class Student{
public:
	string name;
	int final_grade;
	int class_grade;
	char leader;
	char west;
	int number_of_paper;
	int money;
};

int main () {
	int n;
	cin>>n;
	int sum = 0;
	Student a[n];
	for(int i = 0; i < n; i++) {
		a[i].money = 0;
		cin >> a[i].name >> a[i].final_grade >> a[i].class_grade >> a[i].leader >> a[i].west >> a[i].number_of_paper;
		if( (a[i].final_grade > 80) && (a[i].number_of_paper >= 1) ) a[i].money += 8000;
		if( (a[i].final_grade > 85) && (a[i].class_grade > 80) ) a[i].money += 4000;
		if( (a[i].final_grade > 90) ) a[i].money += 2000;
		if( (a[i].final_grade > 85) && (a[i].west == 'Y') ) a[i].money += 1000;
		if( (a[i].class_grade > 80) && (a[i].leader == 'Y') ) a[i].money += 850;
		sum += a[i].money;
	}
	int maxn = -1, pos = -1;
	for(int i = n-1; i > 0; i--) {
		if(a[i].money >= maxn) {
			pos = i;
			maxn = a[i].money;
		}
	}
	cout << a[pos].name << endl << a[pos].money << endl;
	cout << sum << endl;
}
