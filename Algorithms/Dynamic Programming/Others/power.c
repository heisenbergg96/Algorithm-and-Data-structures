#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int findcount(int sum,int expo,int num)
{
    int value = sum-pow(num,expo);
    
    if(value < 0) return 0;
    if(value == 0) return 1;

    return findcount(value,expo,num+1) + findcount(sum,expo,num+1);
}

int main() {
    
    int x,n;
    scanf("%d%d",&x,&n);
    printf("%d",findcount(x,n,1));
    
    return 0;
}

