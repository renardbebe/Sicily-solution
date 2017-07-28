#include <cstdio>
long long a[100001];
int main()
{
	int n, m;
	long long add = 0;
	int sign = 1;
	int i,j;
	int x,l,r;
	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		a[i]+=a[i-1];        //求前i项和 
	}
	for(i=0;i<m;i++){
		scanf("%d", &j);
		if(j==1){
			sign *= -1;
			add *= -1;
		}
		else if(j==2){
			scanf("%d", &x);
			add += x;
			}
		else if(j==3){
			scanf("%d%d",&l, &r);
			printf("%lld\n",(a[r]-a[l-1])*sign + add*(r-l+1));   
		}
	}
	return 0;
}
