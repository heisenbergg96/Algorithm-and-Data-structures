#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
	char str[100];
	int j,previous = -1;

	printf("Enter the string :\n");
		scanf("%s",str);

	for(int i=0;i<strlen(str);i++)
	{
		j = previous;
		while(j >= 0)
		{
			if(str[i] == str[j]) break;
			else j--;
		}

		if(j == -1)
			str[++previous] = str[i];
	}

	str[++previous] = '\0';
	printf("String after removing duplicates : %s\n",str);

	return 0;
}