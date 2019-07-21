#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
	if(a > b)
		return a;

	return b;
}

/*int dpapproach(int w[],int v[],int n,int limit,int length,int dp[][10])
{
	if(n == length || limit == 0)
		return 0;
	
	if(limit < w[n])
		return find_max_value(w,v,n+1,limit,length,dp);
	
	if()
		
}*/

int find_max_value(int w[],int v[],int n,int limit,int length)
{
	if(n == length || limit == 0)
		return 0;
	
	if(limit < w[n])
		return find_max_value(w,v,n+1,limit,length);
	
	return max(v[n]+find_max_value(w,v,n+1,limit-w[n],length),find_max_value(w,v,n+1,limit,length));
}

int main()
{
	int w[10],v[10],weight_limit,n,dp[10][10];
	
	printf("Enter number of items : ");
		scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dp[i][j] = -1;
	
	printf("Enter the values and corresponding weight\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
		scanf("%d",&w[i]);
	}

	printf("Enter the weight limit: ");
		scanf("%d",&weight_limit);
	
	printf("max value is :%d", find_max_value(w,v,0,weight_limit,n,dp));

	return 0;

}
