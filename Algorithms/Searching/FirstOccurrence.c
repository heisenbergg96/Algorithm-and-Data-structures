#include<stdio.h>
#include<stdlib.h>

int FirstOccurrence(int a[],int low,int high,int key)
{
	int mid;
	if(low <= high)
	{
		mid = (low+high)/2;
		if(mid == 0 || a[mid-1] < key && a[mid] == key )
			return mid;
	}

	if(low > mid)
		return -1;

	if(key > a[mid])
		FirstOccurrence(a,mid+1,high,key);
	else
		FirstOccurrence(a,low,mid-1,key);

}

int main(int argc,char *argv[])
{
	int n,a[100],key;

	if(argc!=2)
	{
		printf("The correct format is $ ./a.out NoOfElements");
		exit(0);
	}

	n = atoi(argv[1]);
	
	printf("Enter the elements in sorted order: ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("Enter the key to be searched: ");
		scanf("%d",&key);

	int index = FirstOccurrence(a,0,n-1,key);

	if(index == -1)
		printf("NOT FOUND!!");
	else
		printf("First occurrence is found at index : %d",index);

	return 0;
}