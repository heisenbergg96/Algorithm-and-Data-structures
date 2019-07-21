#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char Stack[150];
int top = -1;

void super_reduced_string(char* s)
{
    for(int i=0;i<strlen(s);i++)
    {
        if(top == -1) 
        {
            Stack[++top] = s[i];
            
        }
        else
        {
            if(s[i] == Stack[top]) 
                top--;
            else
                Stack[++top] = s[i];
           	
           	printf("%d\n",top);                
        }
    }
    
    if(top == -1) printf("Empty String");
    else
    {
    	Stack[++top] = '\0';
        printf("%s",Stack);      
    }
       
}

int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
    super_reduced_string(s);
    return 0;
}

