#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(int a,int b)
{
	if(a > b) 
		return a;
	return b;
}

int rodcutup(int a[],int n)
{
	if(n == 0)
		return 0;

	int q = INT_MIN;

	for(int i=1;i<=n;i++)
		q = max(q,a[i]+rodcutup(a,n-i));

	return q;
}

int main()
{
	int a[100],n;
	scanf("%d",&n);

	for (int i = 1; i <=n; ++i)
	{
		a[i] = rand()%20;
		printf("%d ",a[i]);
	}

	printf("\n%d \n",rodcutup(a,n));

	return 0;
}