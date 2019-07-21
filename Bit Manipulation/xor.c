#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,res=1;

	printf("\nEnter two numbers:");
		scanf("%d",&n);

	for(int i=2;i<=n;i++)
		res = res^i;

	printf("\nres=:%d\n",res);

	return 0;
}