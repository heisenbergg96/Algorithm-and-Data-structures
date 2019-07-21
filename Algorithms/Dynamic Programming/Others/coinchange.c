#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long getWays(long int* S,long n,long m){
    if (n == 0)
        return 1;
     
    
    if (n < 0)
        return 0;
 
    
    if (m <=0 && n >= 1)
        return 0;
 
   
    return getWays( S, n, m-1 ) + getWays( S, n-S[m-1], m);
}

int main() {
    int n; 
    int m; 
    scanf("%d %d", &n, &m);
    long *c = malloc(sizeof(long) * m);
    for(int c_i = 0; c_i < m; c_i++){
       scanf("%ld",&c[c_i]);
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(c,n,m);
    printf("%ld",ways);
    return 0;
}

