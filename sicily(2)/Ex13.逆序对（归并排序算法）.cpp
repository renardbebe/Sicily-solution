#include <cstdio>

long long length,tomerge[1000100],result[1000100],revnumpair=0;

void mergesort (long long * merge,long long left,long long right,long long * tran) 
{
	if(left < right) 
	{
		long long mid = left+((right-left)>>1);
		mergesort (merge,left,mid,tran);
		mergesort (merge,mid+1,right,tran);
		long long lpos = left, rpos = mid+1, pos = left;
		while (lpos <= mid || rpos <= right) 
		{
			if(rpos > right || (lpos <= mid && merge[lpos] <= merge[rpos])) tran[pos++] = merge[lpos++];
			else tran[pos++] = merge[rpos++], revnumpair += (mid-lpos+1);
		}
		for(pos = left; pos <= right; pos++)
			merge[pos]=tran[pos];
	}
}

int main ()
{
    scanf("%d",&length);
	for(long long i = 0; i < length; i++) 
		scanf("%d",&tomerge[i]);
    mergesort(tomerge,0,length-1,result);
    printf("%lld\n",revnumpair);
    return 0;
}
