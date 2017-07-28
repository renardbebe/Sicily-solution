#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int main ()
{
	string s;
	while(cin>>s)
	{
		if(s=="*") return 0;
		else
		{
			int len = s.length();
			if(len<=2)
			{
				cout << s << " is surprising.\n";
			}
			else
			{
				int flag = 1;
				for(int i=0;i<=s.length()-2;i++)
				{
					int dflag = 1;
					map<string,int>mp;
					
					for(int j=0;j<=s.length()-2&&j+i<s.length()-1;j++)
					{
						string ss = "";
						ss += s[j];
						ss += s[i+j+1];
						if(mp[ss])
						{
							dflag = 0;
							break;
						}
						else
						{
							mp[ss] = 1;
						}
					}
					if(dflag==0)
					{
						flag = 0;
						break;
					}
				}
				if(flag) cout << s << " is surprising.\n";
				else cout << s << " is NOT surprising.\n";	
			}	
		}
	} 
} 
