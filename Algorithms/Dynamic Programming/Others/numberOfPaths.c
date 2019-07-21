#include <stdio.h>

//int visited[1001][1001];

int fun(int m,int n,int i,int j)
{
    if(i == m-1 && j == n-1)
        return 1;
    if(i<0 || i>=m || j<0 || j>=n)
        return 0;
    return fun(m,n,i+1,j) + fun(m,n,i,j);
}

int main() {
	
	int t,m,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    scanf("%d%d",&m,&n);
	    printf("%d\n",fun(m,n,0,0));
	}
	return 0;
}
