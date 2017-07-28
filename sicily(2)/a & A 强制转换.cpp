//强制转换 -- 大小写
#include <iostream>
using namespace std;
int main ()
{
	char a;
	cin >> a;
	cout << char(a+'A'-'a') << endl;
	return 0;
}
