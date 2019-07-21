#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char stack[100000];
int top =-1;

int alternatingCharacters(char* s){
   
    int count = 0;
    for(int i=0;i<strlen(s);i++)
    {
        if(top == -1) 
            stack[++top] = s[i];
        else
        {
            if(stack[top] == s[i]) 
            {
                count++;
                
            }
            else
                stack[++top] = s[i];
        }
    }
    
    return count;
}

int main() {
    int q; 
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result = alternatingCharacters(s);
        printf("%d\n", result);
    }
    return 0;
}

