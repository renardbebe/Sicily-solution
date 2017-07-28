#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

int flag;

void to_int(string s)
{
	stringstream ss;
	ss << s;
	int a;
	ss >> a;
	if(!ss.good() && !ss.fail())
	{
		flag++;
		if(a == 0) cout << "Integer: " << 0 << endl;
		else cout << "Integer: 0x" << hex << a << endl;
	}
	return ;
}

void to_double(string s)
{
	stringstream ss;
	ss << s;
	double b;
	ss >> b;
	if(!ss.good() && !ss.fail())
	{
		flag++;
		cout << "Double: "<< fixed << setprecision(6) << b << endl;
	}
	return ;
} 

void to_string(string s)
{
	stringstream ss;
	ss << s;
	string c;
	ss >> c;
	if(!ss.good() && !ss.fail())
	{
		cout << "String: " << c << endl;
	}
	return ;
} 

int main ()
{
	string str;
	while(cin>>str)
	{
		flag = 0;
		if(!flag) to_int(str);
		if(!flag) to_double(str);
		if(!flag) to_string(str);
	}
}

/*
Hello 123
  Welcome 0.01
1+1 = 2
0
1e-2
*/
