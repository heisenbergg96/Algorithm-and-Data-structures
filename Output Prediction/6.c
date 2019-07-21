#include<stdio.h>
#define MAX(a, b, c) (a>b ? a>c ? a : c: b>c ? b : c)

int main()
{
    int x;
    x = MAX(3+2, 2+7, 3+7);
    printf("%d\n", x);
    return 0;
}
