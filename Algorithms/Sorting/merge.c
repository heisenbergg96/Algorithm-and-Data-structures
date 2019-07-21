#include<stdio.h>
#include<stdlib.h>

void Merge(int a[],int p,int q,int r)
{
	int n1,n2,i=0,j=0,k;
	
	n1 = q-p+1;
	n2 = r-q;
	int L1[n1],L2[n2];

	for(i = 0;i < n1; i++)
		L1[i] = a[p+i];

	for (j = 0; j < n2; j++)
		L2[j] = a[q+j+1];

	
	L1[n1] = L2[n2] = 10000;

	i = j = 0;
	
	for( k = p; k <= r; k++)
		if(L1[i]<=L2[j])
		 	   a[k] = L1[i++];
		else	
			   a[k] = L2[j++];
			   
}

void MergeSort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q = (p+r)/2;
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}

}

int main(int argc,char *argv[])
{
	int n,A[100];

	if(argc!=2)
	{
		printf("The correct format is: $ ./a.out NoOfElements\n");
		exit(0);
	}

	n = atoi(argv[1]);
	
	printf("\nBefore sort : ");
	for(int i=0;i<n;i++)
	{
		A[i] = rand()%100;
		printf("%d ",A[i]);
	}

	MergeSort(A,0,n-1);

	printf("\nAfter sort: ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);

	return 0;
}
