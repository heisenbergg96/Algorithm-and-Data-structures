#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int countisland(int a[][10],int n,int m,int i,int j)
{
    if(a[i][j] == 0 || i<0 || j<0 || i>=n || j>=m)
        return 0;
    int count = 1;
    a[i][j] = 0;
    count+=countisland(a,n,m,i+1,j);
    count+=countisland(a,n,m,i-1,j);
    count+=countisland(a,n,m,i,j+1);
    count+=countisland(a,n,m,i,j-1);
    count+=countisland(a,n,m,i-1,j-1);
    count+=countisland(a,n,m,i-1,j+1);
    count+=countisland(a,n,m,i+1,j+1);
    count+=countisland(a,n,m,i+1,j-1);

   return count;
}

int solveit(int a[][10],int n,int m)
{
    int maxc = -1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            maxc = max(maxc,countisland(a,n,m,i,j));
    
    return maxc;
}

int main() {

    int m,n;
    scanf("%d",&n);
    scanf("%d",&m);
    int a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    printf("%d",solveit(a,n,m));
    return 0;
}

