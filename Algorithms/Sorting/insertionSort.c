#include<stdio.h>
#include<stdlib.h>

void swap(int a[],int i,int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void InsertionSort(int a[],int n)
{
	int i,key,count=0;

	for(int j=1;j<=n;j++)
	{
		i = j-1;
		key = a[j];

		while(a[i] > key && i>=0)
		{
			a[i+1] = a[i];
			i--;
			count++;
		}
		a[i+1] = key;
	}
	printf("\n%d \n", count);

}

int main(int argc,char *argv[])
{
	int n,A[100];

	if(argc!=2)
	{
		printf("Correct format is $ ./a.out NoOfElements\n");
		exit(0);
	}

	n = atoi(argv[1]);

	printf("Before sort : ");
	for(int i=0;i<n;i++)
	{
		A[i] = rand()%100;
		printf("%d ",A[i]);
	}

	InsertionSort(A,n-1);

	printf("\nAfter sort : ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);

	return 0;

}