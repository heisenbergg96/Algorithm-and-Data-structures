#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int min(int x,int y,int z)
{
	if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;

}
int minCost(int a[][10],int m,int n)
{
	if(m<0 || n<0)
		return INT_MAX;
	
	if(m == 0 && n == 0)
		return a[m][n];

	return a[m][n]+min(minCost(a,m-1,n-1),minCost(a,m-1,n),minCost(a,m,n-1));
}

int main(int argc,char *argv[])
{
	int n,m,a[10][10];

	printf("Enter number of rows and column in the cost matrix:\n");
	printf("%s","rows = " );
		scanf("%d",&m);
	printf("%s","column = " );
		scanf("%d",&n);

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j] = rand()%100;
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	printf("\nminimum cost to traverse from  start to end is : %d",minCost(a,m-1,n-1));

	return 0;
}
