#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct Key
{
	char kword;
	int rank;
};
bool cmp(Key key1, Key key2){
	return key1.kword < key2.kword;
}
int main(){
	string keyword;	
	while(cin>>keyword && keyword!="THEEND"){
		vector<Key> vkey;
		string text;
		char message[11][11];
		cin >> text;
		int col = keyword.length();
		int len = text.length();
		int row = len/col;

		for(int i=0; i<col; i++){
			Key temp;
			temp.kword = keyword[i];
			temp.rank = i;
			vkey.push_back(temp);
		}

		sort(vkey.begin(), vkey.end(), cmp);
		vector<Key>::iterator it;

		int j = 0;
		for(it = vkey.begin(), j=0; it!= vkey.end(); it++, j++){
			for(int i=0; i<row; i++)
				message[i][it->rank] = text[j*row + i];
		}
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				cout<<message[i][j];
			}
		}
		cout << endl;
	}
}

/*
BATBOY
EYDEMBLRTHANMEKTETOEEOTH
HUMDING
EIAAHEBXOIFWEHRXONNAALRSUMNREDEXCTLFTVEXPEDARTAXNAARYIEX
THEEND
*/
