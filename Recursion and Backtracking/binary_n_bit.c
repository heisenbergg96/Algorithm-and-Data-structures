// Print all strings of 'n' bits. Assuming str[0...n-1] is an array of size n.

#include<stdio.h>

char str[10];

void Binary(int n)
{
	if(n<1)
		printf("%s",str);
	else
		{
			str[n-1] = 0;
			Binary(n-1);
			str[n-1] = 1;
			Binary(n-1);
		}	
}
int main()
{
	int n = 5;
	str[n] = '\0';
	Binary(n);

	return 0;
}


