#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int q,x,k=0; 
    scanf("%d",&q);
    char hacker[] = {'h','a','c','k','e','r','r','a','n','k'};
    char str[100],temp;
    for(int a0 = 0; a0 < q; a0++){
        char* s = (char *)malloc(51200000 * sizeof(char));
        scanf("%s",s);
        temp = hacker[0];
        x = 1;
        k = 0;
       for(int i=0;i<strlen(s);i++)
       {
           if(temp == s[i])
           {
               str[k++] = temp;
               temp = hacker[x++];
           }
       }
        
       str[k] = '\0';
          
       if(strcmp(str,"hackerrank") == 0)
           printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

