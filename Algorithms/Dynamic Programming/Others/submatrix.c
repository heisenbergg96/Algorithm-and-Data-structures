#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(int x, int y)
{
	return (x > y)? x:y;
}

int min(int x,int y)
{
	return (x < y)? x:y;
}

int FindSubarray(int a[][10],int n)
{
	int dp[10][10],result = INT_MIN;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 1;

			if(a[i-1][j] == a[i][j] && a[i][j-1] == a[i][j] && a[i-1][j-1] == a[i][j])
				dp[i][j] = min(min(dp[i][j-1],dp[j-1][i]),dp[i-1][j-1])+1;
			else
				dp[i][j] = 1;

			result = max(result,dp[i][j]);
		}

		return result;
}

int main(int argc, char *argv[])
{
	int n,a[10][10];

	printf("Enter the size of the matrix: ");
		scanf("%d",&n);

	printf("Enter the elements of the matrix: ");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	printf("size of largest sub array containing same elements is: %d",FindSubarray(a,n));

	return 0;
}
