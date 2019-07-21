#include<stdio.h>

int main()
{
    int i;
    char a[] = "\0";
    if(printf("%s", a))
        printf("The string is not empty\n");
    else
        printf("The string is empty\n");
    return 0;
}
