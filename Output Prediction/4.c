#include<stdio.h>
#define FUN(i, j) i##j

int main()
{
    int va1=10;
    int va12=20;
    printf("%d\n", FUN(va1, 2));
    return 0;
}
