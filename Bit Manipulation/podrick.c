#include<stdio.h>

int fun(int n)
{
	int count = 0;

	while(n!=0)
	{
		n = n&(n-1);
		count++;
	}

	return count;
}

int main()
{
	int a,b;
	
	scanf("%d%d",&a,&b);
	printf("%d\n",fun(a^b));

	return 0;
}
