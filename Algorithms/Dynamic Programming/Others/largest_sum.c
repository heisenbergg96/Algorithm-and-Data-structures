#include<stdio.h>
#include<stdlib.h>

int find_subarray(int n,int a[])
{
	int maxsofar = a[0],current_sum = 0;
	for(int i=0;i<n;i++)
	{
		current_sum+=a[i];
		if(current_sum > maxsofar)
			maxsofar = current_sum;
		else if(current_sum < 0)
			current_sum = 0;
	}
	return maxsofar;
}

int main()
{
	int n,a[100];
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	printf("%d",find_subarray(n,a));

	return 0;
}
