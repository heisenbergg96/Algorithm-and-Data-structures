#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include<ctype.h>

int HASH[30];

int main() {
    
    char s[10000];
    getc("%s",s);
    for(int i=0;i<strlen(s);i++)
        if(isalpha(s[i]))
            HASH[tolower(s[i])-'a'] = 1;
    
    
    for(int i=0;i<25;i++)
    	printf("%d ",HASH[i]);
    	
    for(int i=0;i<25;i++)
        if(HASH[i] == 0)
        {
            printf("not pangram");
            exit(0);
        }
    
    printf("pangram");
    return 0;
}

