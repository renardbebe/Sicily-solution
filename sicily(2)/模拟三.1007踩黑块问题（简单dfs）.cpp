#include <iostream>
using namespace std;
char a[22][22];
int w,h,count=0;

void dfs(int m, int n)  
{  
    if (m>=0 && n>=0 && m<h && n<w && (a[m][n]=='@' || a[m][n]=='.') )  
    {  
        count++;  
        a[m][n]='0';
        dfs(m+1,n);  
        dfs(m-1,n); 
		dfs(m,n+1); 
        dfs(m,n-1);  
    }  
}  

int main ()
{
	while(cin>>w>>h)
	{
		if(w==0&&h==0) return 0;
		else
		{
			count=0;
			int m,n;
			string s;
			for(int i=0;i<h;i++)
			{
				cin>>s;
				for(int j=0;j<w;j++)
				{
					a[i][j]=s[j];
					if(a[i][j]=='@') 
					{
						m=i;
						n=j;
					}
				} 
			}
			dfs(m,n);
			cout << count << endl;
		} 
	}
}
