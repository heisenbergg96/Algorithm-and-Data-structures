#include<stdio.h>
#include<stdlib.h>

void swap(int a[],int index)
{
	int temp;

	temp = a[index];
	a[index] = a[index+1];
	a[index+1] = temp;
}

int main(int argc,char *argv[])
{
	int a[100],n;

	if(argc!=2)
	{
		printf("The format is: $ ./a.out NoOfElements\n");
		exit(0);
	}

	n = atoi(argv[1]);

	printf("Before sorting : ");
	for(int i=0;i<n;i++)
	{
		a[i] = rand()%100;
		printf("%d ",a[i]);
	}

	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1])
				swap(a,j);
		}


	printf("\nAfter sorting : ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);

	return 0;

}