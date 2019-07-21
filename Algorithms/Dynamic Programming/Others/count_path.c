#include<stdio.h>
#include<stdio.h>

int count_path(int dp[][10],int n,int m)
{
	for(int i=0;i<n;i++)
		dp[i][0] = 1;
	for(int j=0;j<m;j++)
		dp[0][j] = 1;
		
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			
	return dp[n-1][m-1];
}

int main()
{
	int n,a[10][10] = {0},m;
	
	scanf("%d%d",&n,&m);
	
	printf("%d\n",count_path(a,n,m));
	
	return 0;
	
}
