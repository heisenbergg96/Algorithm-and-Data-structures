#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include<ctype.h>

int main(){
    int n; 
    scanf("%d",&n);
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);
    int k; 
    scanf("%d",&k);
    return 0;
    for(int i=0;i<strlen(s);i++)
        if(isalpha(s[i])) s[i] = s[i]+k;
    
    printf("%s",s);
    
    return 0;
}

