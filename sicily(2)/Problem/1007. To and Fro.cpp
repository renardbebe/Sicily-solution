#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int col;
	while(cin >> col && col != 0)
	{
		string s;
		cin >> s;
		char message[101][21];
		int len = s.length();
		int row = len/col;
		int k = 0;
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				if(!(i%2))
				{
					message[i][j] = s[k];
				}
				else
				{
					message[i][col-j-1] = s[k];
				}
				k++;
			}
		}

		for(int j=0; j<col; j++){
			for(int i=0; i<row; i++){
				cout<<message[i][j];
			}
		}
		cout << endl;
	}
}

