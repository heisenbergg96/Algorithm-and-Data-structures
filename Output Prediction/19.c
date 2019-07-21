#include<stdio.h>

int main()
{
    char str1[] = "Hello";
    char str2[] = "Hello";
    if(str1 == str2) //here the address of str1 and str2 are compared. The address of both variable is not same. Hence the if condition is failed.
        printf("Equal\n");
    else
        printf("Unequal\n");
    return 0;
}
