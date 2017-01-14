#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main ()
{
	string s,ss;
	while(getline(cin,s,'\n'))
	{
		ss.clear();
		bool flag = true;
		for(int i = 0; i < s.length(); i++)
		{
			int h = 0;
			if(s[i] >= '0' && s[i] <= '9')
			{
				while(s[i] >= '0' && s[i] <= '9')
				{
					h = h*10 + s[i] - '0';
					i++;
					if(h > 50)
					{
						flag = false;
						break;
					}
				}
				while(h--)
				{
					ss += s[i];
					if(ss.length() > 50)
					{
						flag = false;
						break;
					}
				}	
			}
			else ss += s[i];
			if(flag == false) break;
		}
		if(ss.length() <= 50) cout << ss << endl;
		else cout << "TOO LONG\n";
	}
}
