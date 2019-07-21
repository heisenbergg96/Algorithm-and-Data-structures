#include <stdio.h>

int max(int a,int b)
{
   if (a>b) 
    return a;
    
   return b;
}

int fun(int n,int a[])
{
    int dp[1000];
    dp[0] = a[0];
    dp[1] = max(a[0],a[1]);
    
    for(int i=2;i<n;i++)
        dp[i] = max(dp[i-1],dp[i-2]+a[i]);
    
    return dp[n-1];
}

int main() {
    
	int t,n,a[1100];
	
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    scanf("%d",&n);
	    
	    for(int j=0;j<n;j++)
	        scanf("%d",&a[j]);
	    
	    printf("%d\n",fun(n,a));
	}
	
	return 0;
}
