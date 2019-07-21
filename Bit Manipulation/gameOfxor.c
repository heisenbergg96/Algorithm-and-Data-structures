#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long int solve(long int n) {
   
   int count = 0;
   while(n!=0)
   {
       if(!(n&1))
           count++;
       n = n>>1;
   }
    return pow(2,count);
}

int main() {
    long int n; 
    scanf("%li", &n);
    long int result = solve(n);
    printf("%ld\n", result);
    return 0;
}
