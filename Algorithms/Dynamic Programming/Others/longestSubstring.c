#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	
	return b;
}

void LongestSubstring(char s1[],char s2[],int dp[][15])
{
	int ma = -1,index;
		
	for(int i=1;i<=strlen(s1);i++)
		for(int j=1;j<=strlen(s2);j++)
			if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
				if(ma < dp[i][j])
				{
					ma = dp[i][j];
					index = i;
				}
			}

	for(int i=index-ma;i<index;i++)
		printf("%c",s1[i]);
	printf("\n");
}

int main()
{
	char s1[10],s2[10];
	int dp[15][15];
	printf("Enter the first string: ");
		scanf("%s",s1);
	printf("Enter the second string: ");
		scanf("%s",s2);
	
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			dp[i][j] = 0;
	
	LongestSubstring(s1,s2,dp);
	return 0;
}
