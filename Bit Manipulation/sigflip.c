#include<stdio.h>

int findsol(int n,int count,int x)
{
	
	for(;n!=0;count++,n>>=1)
	{}
	
	return ((1<<(count))-1)^x;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",findsol(n,0,n));

	return 0;
}
