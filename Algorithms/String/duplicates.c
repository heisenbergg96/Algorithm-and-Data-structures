#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
	char str[100];
	int val,len,checker = 0;

	printf("Enter the string: ");
		scanf("%s",str);

	len = strlen(str);

	for(int i=0;i<len;i++)
	{
		val = str[i] - 'a';
		if((checker&(1<<val)) > 0) {printf("duplicate exits\n");exit(0);}
		checker|=(1<<val);
	}

	printf("duplicate does not exits\n");

	return 0;
}