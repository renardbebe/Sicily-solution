#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
using namespace std;

bool is_hex(string s)
{
	for(int i = 0;i < s.length(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'f' || s[i] >= 'A' && s[i] <= 'F') continue;
		else return false;
	}
	return true;
}

int parseHex(const char * hexString)
{
	string s(hexString);
	if(is_hex(s))
	{
		int n = 0;
		for(int i = 0;i < s.length(); i++)
		{
			if(s[i] >= '0' && s[i] <= '9')
				n = n*16 + s[i] - '0';
			else if(s[i] >= 'a' && s[i] <= 'f')
				n = n*16 + s[i] - 'a' + 10;
			else if(s[i] >= 'A' && s[i] <= 'F')
				n = n*16 + s[i] - 'A' + 10;
		}
		return n;
	}
	else throw runtime_error("Hex number format error");
}

int main()
{
	string s;
	while (cin >> s) {
		try {
			cout << parseHex(s.c_str()) << endl;
		} catch (runtime_error &ex) {
			cout << ex.what() << endl;
		}
	}
	return 0;
}
