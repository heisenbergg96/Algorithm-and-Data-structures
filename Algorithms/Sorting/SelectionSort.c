#include<stdio.h>
#include<stdlib.h>

void swap(int a[],int i,int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void SelectionSort(int a[],int n)
{
	int i,small,smallIndex;

	for(int j=0;j<n;j++)
	{
		
		smallIndex = j;

		for(i=j+1;i<=n;i++)
			if(a[i] < a[smallIndex])
				smallIndex = i;	
		
		swap(a,smallIndex,j);
	}
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

	SelectionSort(A,n-1);

	printf("\nAfter sort : ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);

	return 0;

}