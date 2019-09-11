#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int countIsland(int n,int m,int a[][10],int i,int j)
{
    if(i < 0 || j < 0 || i >= n || j >= m)
        return 0;
    if(!a[i][j])
        return 0;
    int count = 1;
	 a[i][j]--;
    count += countIsland(n,m,a, i + 1, j);
    count += countIsland(n,m,a, i - 1, j);
    count += countIsland(n,m,a, i, j + 1);
    count += countIsland(n,m,a, i, j - 1);
    count += countIsland(n,m,a, i + 1, j + 1);
    count += countIsland(n,m,a, i - 1, j - 1);
    count += countIsland(n,m,a, i - 1, j + 1);
    count += countIsland(n,m,a, i + 1, j - 1);
    
    return count;
    
}

int findIsland(int n,int m,int a[][10])
{
    int maxc = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            maxc = max(maxc,countIsland(n,m,a,i,j));
    
    return maxc;
}

int main(){
    int n; 
    scanf("%d",&n);
    int m; 
    scanf("%d",&m);
    int grid[n][m];
    for(int grid_i = 0; grid_i < n; grid_i++){
       for(int grid_j = 0; grid_j < m; grid_j++){
          
          scanf("%d",&grid[grid_i][grid_j]);
       }
    }
    
    printf("%d",findIsland(n,m,grid));
    return 0;
}

