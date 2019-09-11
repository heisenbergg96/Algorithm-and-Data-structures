#include<stdio.h>
#include<stdlib.h>

int isgoodpath(int maze[][10],int n,int x,int y)
{
	if(maze[x][y] == 1 && x<=n-1 && y<=n-1 && x>=0 && y>=0)
		return 1;
	
	return 0;
}


int solvemaze(int maze[][10],int n,int x,int y)
{
	if(x == n-1 && y == n-1)
		return 1;

	if(isgoodpath(maze,n,x+1,y))
		return solvemaze(maze,n,x+1,y);
		
	if(isgoodpath(maze,n,x,y+1))
		return solvemaze(maze,n,x,y+1);
		
	return 0;
	
}

int main()
{
	int n,maze[10][10];
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			maze[i][j] = rand()%2;
			printf("%2d",maze[i][j]);
		}
		
		printf("\n");
	}
		
	if(solvemaze(maze,n,0,0))
		printf("Solution exists\n");
	else
		printf("No solution");
	
	
	return 0;
	
}
