//强制转换 -- 数字→AS码 
#include <iostream>
using namespace std;
int main ()
{
	int a;
	cin >> a;
	cout << char(a) << endl;
	return 0;
} 


//数字 →AS码
#include <iostream>
using namespace std;
int main ()
{
	int a;
	cin >> a;
	char ch;
	ch=a;
	cout << ch << endl;
	return 0;
}


//AS码→数字
#include <iostream>
using namespace std;
int main ()
{
	char ch;
	cin >> ch;
	int n;
	n=ch;
	cout << n << endl;
	return 0;
} 
