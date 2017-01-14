#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main () 
{
    int n;
    cin>>n;
    for(int k = 1; k <= n; k++)
    {
        int a;
        string s,ss;
        cin>>a>>s;
        ss.clear();
        for(int i = 0; i < a-1; i++)
        {
            ss += s[i];
        }
        for(int i = a; i < s.length(); i++)
        {
            ss += s[i];
        }
        cout << k << " " << ss << endl;
    }
}                                 
