#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int HASH[100];

char* isValid(char* s,int pre,int k){
    int f=0,i,current;
    for(i=k+1;i<25 && (f<2) ;i++)
    {
        if(HASH[i]!=0)
        {
            current = HASH[i];
            if(current!=pre)
            {
                if(current > pre) HASH[i] = HASH[i] = HASH[i] - 1;
                else HASH[k] = HASH[k] - 1;
                i = k;
                f++;
            } 
            
        }
        
    }
    if(i == 25) return "YES";
    if(f == 2) return "NO";
    else
        return "FALSE";

}
int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
    int result_size,index,pre;
    for(int i=0;i<strlen(s);i++)
        HASH[s[i]-'a']++;
    for(int i=0;i<25;i++)
    	printf("%d ",HASH[i]);
    for(int i=0;i<25;i++)
        if(HASH[i]!=0)
        {            
            pre = HASH[i];
            index = i;
            break;
        }
    char* result = isValid(s,pre,index);
    
    
    printf("%s\n", result);
    return 0;
}
