#include <stdio.h>

int print_sol(int n,int a[])
{
    int dp[n],maxsofar = 1;
    
    for(int i=0;i<n;i++)
        dp[i] = 1;
    
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[j] < a[i])
            {
            		if((dp[j]+1) >= maxsofar)
            		{
                    	maxsofar = dp[j]+1;
                    	dp[i] = maxsofar;
                    }
            }
            
        return maxsofar;
            
}

int main() {
	
	int t,n,a[1001];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    scanf("%d",&n);
	    for(int j=0;j<n;j++)
	        scanf("%d",&a[j]);
	   
	    printf("%d\n",print_sol(n,a));
	}
	
	return 0;
}
