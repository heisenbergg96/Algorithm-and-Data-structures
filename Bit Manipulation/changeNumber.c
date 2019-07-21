#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m,count = 0;

	printf("\nEnter two numbers:");
		scanf("%d%d",&m,&n);

	int dif = m^n;

	while(dif!=0)
	{
		if(dif&1)
			count++;
		dif>>=1;
	}

	printf("\nNumber of bits to be changed is:%d\n",count);

	return 0;
}