// Print the path of the knight from [0, 0] to [8,8] if there is any.

// A night is placed at a corner of the chessboard, check if there is a path to reach another point on the chessboard.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int issafe(int x,int y,int a[][8],int n)
{
	return (x>=0 && y>=0 && x<n && y<n && a[x][y] == -1);
}

int findpath(int a[][8],int knightx[],int knighty[],int x,int y,int moves,int n)
{
	if(moves == n*n)
		return 1;

	int nextx,nexty;

	for(int i=0;i<8;i++)
	{
		nextx = x + knightx[i];
		nexty = y + knighty[i];
		if(issafe(nextx,nexty,a,n))
		{
			a[nextx][nexty] = moves;
			if(findpath(a,knightx,knighty,nextx,nexty,moves+1,n))
				return 1;
			else
				a[nextx][nexty] = -1;
		}
	}
	return 0;
}

int printsolution(int n,int a[][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)	
			printf("%2d ",a[i][j]);
		printf("\n");
	}
}

int main()
{
	
	int knightx[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
	int knighty[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	int n;
	scanf("%d",&n);
	int a[n][n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j] = -1;
	a[0][0] = 0;
	
	if(findpath(a,knightx,knighty,0,0,1,n))
	printsolution(n,a);
	else
	printf("NO FUCKING PATH!!");

	return 0;
}
