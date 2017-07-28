#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a,b;
	int i,k,j;
	while(cin>>a>>i>>b){
		for(int k=a.length()-1;k>=0;k--){
			if(k!=i-1)  cout << a[k];	
			else 
			{
				for(int j=b.length()-1;j>=0;j--){
					cout << b[j];
				}
				cout << a[k];
			} 
		}
		cout << endl;
	}
	return 0;	
}
