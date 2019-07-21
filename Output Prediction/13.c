	
#include<stdio.h>
int main()
{
    extern int i;
    i = 20;
    printf("%d\n",sizeof(i));
    return 0;
}
