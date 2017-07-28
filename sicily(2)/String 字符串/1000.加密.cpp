#include <iostream>
#include <string>
using namespace std;
int main ()
{
	int n,i;
	cin >> n;
	while(n--){
		cin >> i;
		string a;
		cin >> a;
		for(int k=0;k<i-1;k++)
		{
			cout << a[k];
		}
		for(int j=i-1;j<a.length()-1;j++)     // Èôj<a.length() Ôòa[j+1]»áÒç³ö 
		{
			a[j]=a[j+1];
			cout << a[j];
		}
	cout << endl;
	}
}
