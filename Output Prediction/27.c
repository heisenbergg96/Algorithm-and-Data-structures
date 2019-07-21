#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("vik\n");
	fork();
	printf("vik2\n");
	fork();
	printf("vik3\n");

	return 0;
}
