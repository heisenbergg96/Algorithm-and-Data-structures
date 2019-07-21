#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int HASH[100];

int find(char s[],char c1,char c2)
{
    
    int x = 0,f1,f2,count;
    f1 = f2 = count = 0;
    
    while(f1<2 && x<strlen(s) && f2<2)
    {
        if(s[x] == c1)
        {
            f1++;
            f2 = 0;
            count++;
        }
        if(s[x] == c2)
        {
            f2++;
            f1 = 0;
            count++;
        }
        
        x++;
    }
    
    if(x == strlen(s)) return count;
    if(f1 == 2 || f2 == 2) 
        return -1;
    else
        return -1;
}

void TwoCharacter(char s[])
{
    int j,len;
    if(strlen(s) == 1) {printf("0"); exit(0);}
    for(int i=0;i<25;i++)
        if(HASH[i]!=0)
        {
            j = i+1;
            while(j<=25)
            {
            if(HASH[j]!=1 && (abs(HASH[i] - HASH[j]) == 0 || abs(HASH[i] - HASH[j]) == 1))
            {
                len = find(s,'a'+i,'a'+j);
                if(len!=-1) 
                {
                    printf("%d",len);
                    exit(0);
                }
            }
                j++;
            }
        }   

        printf("0"); 
}


int main(){
    int len; 
    scanf("%d",&len);
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
        HASH[s[i]-'a']++;
    TwoCharacter(s);
    return 0;
}
