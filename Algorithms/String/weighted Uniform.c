#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int value[10005];
int HASH[26001];

int main(){
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    int n,k=0; 
    char pre = '#';
    scanf("%d",&n);
    for(int i=0;i<strlen(s);i++)
    {
        if(pre == s[i])
        {
            k++;
            value[k]+=s[i]-'a'+1+value[k-1];
            
        }
        else
        {
            k++;
            value[k] = s[i]-'a'+1;
            pre = s[i];
        }
    }
    for(int i=0;i<=k;i++)
        HASH[value[i]] = 1;
    
    for(int a0 = 0; a0 < n; a0++){
        int x; 
        scanf("%d",&x);
        if(HASH[x] == 1)
            printf("Yes\n");
        else
            printf("No\n");
        
    }
    return 0;
}
