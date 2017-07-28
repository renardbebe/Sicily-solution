#include <iostream> 
#include <cstdio> 
using namespace std;   
int n, t; 
int f[1100];  
int main() 
{ 
    scanf("%d", &t); 
    for(int cas = 1; cas <= t; cas++) 
	{ 
        scanf("%d", &n); 
        for (int i = 1;  i <= n; i++)
			f[i]  = 0; 
        for (int i = 1; i <= n; i++) 
		{ 
            for (int j = i; j <= n; j += i) 
			{ 
                f[j] = 1 - f[j]; 
         	} 
	    } 
	    int ans = 0; 
        for (int i = 1; i <= n; i++) 
			ans += f[i]; 
        printf("test case %d:\n", cas); 
        printf("%d\n", ans); 
    }    
}
