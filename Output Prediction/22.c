#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    int k;
    p = (int *)malloc(20);
    printf("%ld\n", sizeof(p));
    printf("%ld\n",sizeof(k));
    free(p);
    return 0;
}
