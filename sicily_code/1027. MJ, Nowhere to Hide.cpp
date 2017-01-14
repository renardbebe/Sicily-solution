#include <bits/stdc++.h>
using namespace std;

struct Person {
	string ID;
	string IP;
};

struct People {
	string ID;
	string small_ID;
	string IP;
};

void Swap(string& s1, string& s2) {
	string tmp;
	tmp = s2;
	s2 = s1;
	s1 = tmp;
}

int main () {
	int n;
	while(cin >> n) {
		if(!n) return 0;
		Person a[25];
		People b[25];
		for(int i = 0; i < n; i++) {
			cin >> a[i].ID >> a[i].IP;
		}
		int k = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i < j && a[i].IP != "" && a[i].IP == a[j].IP) {
					b[k].ID = a[i].ID;
					b[k].small_ID = a[j].ID;
					b[k++].IP = a[i].IP;
					a[i].IP = "";
					a[j].IP = "";
				}
			}
		}
		for(int i = 0 ; i < k ; i++) {
			for(int j = k-1 ; j > i ; j--) {
				if(b[j].ID < b[j-1].ID) {
					Swap(b[j].ID,b[j-1].ID);
					Swap(b[j].IP,b[j-1].IP);
					Swap(b[j].small_ID,b[j-1].small_ID);
				}
			}
		}
		for(int i = 0; i < k; i++) {
			cout << b[i].small_ID << " is the MaJia of " << b[i].ID << endl;
		}
		cout << endl;
	}
}
