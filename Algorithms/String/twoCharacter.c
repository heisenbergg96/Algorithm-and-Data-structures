#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int HASH[26];
int TwoCharacter(char s[])
{
    int dp[26][26] = {0},max = INT_MIN,sum = 0,f=0;
    char c[26][26];
    
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            c[i][j] = '#';
    
    for(int i=0;i<strlen(s);i++)
    {
        for(int j=0;j<26;j++)
        {
            if(dp[s[i]-'a'][j]!=-1)
            {
                if(c[s[i]-'a'][j] == s[i])
                    dp[s[i]-'a'][j] = -1;
                else
                     c[s[i]-'a'][j] = s[i];
            }
            
            if(dp[j][s[i]-'a']!=-1)
            {
                if(c[j][s[i]-'a'] == s[i])
                    dp[j][s[i]-'a'] = -1;
                else
                    c[j][s[i]-'a'] = s[i];
            }
        }
      
    }
    
    int o,p;
    for(o=0;o<26;o++)
        for(int p=0;p<26;p++)
            if(dp[o][p]!=-1)
            {
                f = 1;
                sum = HASH[o]+HASH[p];
                if(sum > max)
                    max = sum;
            }
    if(f == 1)
        return max;
    else
        return sum;
}

int main(){
    int len; 
    scanf("%d",&len);
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
        HASH[s[i]-'a']++;
    printf("%d ",TwoCharacter(s));
    return 0;
}
