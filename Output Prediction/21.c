#include<stdio.h>

int main()
{
    int i;
    char c;
    for(i=1; i<=5; i++)
    {
        scanf("%c",&c); /* given input is 'b' */
        ungetc(c,stdout);
        printf("%c",c);
        ungetc(c,stdin);
    }
    return 0;
}
	
