#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int count = 0;
    char* S = (char *)malloc(10240 * sizeof(char));
    scanf("%s",S);
    
    for(int i=0;i<strlen(S)-2;i+=3)
    {
        if(S[i]!='S' || S[i+1]!='O' || S[i+2]!='S')
            count++;           
    }
    
    printf("%d",count);
    return 0;
}

