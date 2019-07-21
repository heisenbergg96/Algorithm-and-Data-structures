#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int a[],int low,int high,int key)
{
	int mid;
	if(low <= high)
	{
		mid = (low+high)/2;
		if(a[mid] == key)
			return mid;
	}

	if(low > mid)
		return -1;

	if(key > a[mid])
		BinarySearch(a,mid+1,high,key);
	else
		BinarySearch(a,low,mid-1,key);

}

int main(int argc,char *argv[])
{
	int n,a[100],key;

	if(argc!=3)
	{
		printf("The correct format is $ ./a.out NoOfElements key");
		exit(0);
	}

	n = atoi(argv[1]);
	key = atoi(argv[2]);

	for(int i=0;i<n;i++)
		a[i] = i;

	int index = BinarySearch(a,0,n-1,key);

	if(index == -1)
		printf("NOT FOUND!!");
	else
		printf("Found at index : %d",index);

	return 0;
}