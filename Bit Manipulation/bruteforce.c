#include<stdio.h>
#include<time.h>

long int count(long int n)
{
	int count = 0;
	for(long int i=0;i<=n;i++)
		if((i^n) == (i+n))
			count++;
	
	return count;
}

int main()
{
	long int n;

	scanf("%ld",&n);

	float st_time = clock();
	printf("\n%ld",count(n));
	float en_time = clock();
	float diff = (en_time - st_time)/CLOCKS_PER_SEC;

	printf("\n%f",diff);

}
