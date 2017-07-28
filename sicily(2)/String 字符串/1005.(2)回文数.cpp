#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		if(s.length()==1) cout << s << endl;
		else
		{
			while(1)
			{
				int flag = 0;
				int len = s.length();
				if(len%2==0)
				{
					for(int i=0;i<len/2;i++)
					{
						if(s[i]!=s[len-i-1])
						{
							flag++;
							break;
						}	
					}
				}
				else
				{
					for(int i=0;i<(len-1)/2;i++)
					{
						if(s[i]!=s[len-i-1])
						{
							flag++;
							break;
						}
					}
				}
				
				if(flag==0) break;
				else
				{
					string ss,r; 
					for(int i=s.length()-1;i>=0;i--)
					{
						ss += s[i];
					}
					
					int len1 = s.length();
					int len2 = ss.length();
					if(len1 < len2)
					{
						for(int i = 1;i <= len2-len1; i++)
							s = "0" + s;
					}
					else
					{
						for(int i = 1;i <= len1-len2; i++)
							ss = "0" + ss;
					}
					int f = 0;
					int temp;
					for(int i = len1-1;i >= 0; i--)
					{
						temp = s[i] - '0' + ss[i] - '0' + f;
						f = temp / 10;
						temp %= 10;
						r = char(temp + '0') + r;
					}
					if(f != 0)
					{
						r = char(f + '0') + r;
					}
					r.erase(0,r.find_first_not_of('0'));
					s = r;
				}
			}
			cout << s << endl;
		}
	}
}
