#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,a[100],checker = 0,count=0;

	printf("Enter number of elements:");
		scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(int i=0;i<n;i++)
		checker|=(1<<a[i]);

	while(checker!=0)
	{
		if(checker&1)
			printf("%d ",count);
		
		count++;
		checker>>=1;
	}

}