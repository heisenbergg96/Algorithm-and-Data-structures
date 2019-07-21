#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int x;
	int y;
	int dist;
}Node;

Node createNode(int a,int b,int d)
{
	Node n;
	n.x = a;
	n.y = b;
	n.dist = d;
	
	return n;
}

typedef struct queue
{
	int r,f;
	Node a[100];
}Queue;

Queue create()
{
	Queue q;
	int i;
	q.r = -1;
	q.f = 0;
	
	return q;
}


void Enqueue(Node temp,Queue *q)
{
	q->a[++q->r] = temp;	
}

void Dequeue(Queue *q)
{
	q->a[q->f++];
}

Node getFront(Queue *q)
{
	return q->a[q->f];	
}

int isEmpty(Queue q)
{
	return q.f > q.r;
}

int isSafe(int x,int y,int n)
{
	if (x >= 0 && x <= n-1 && y >= 0 && y <= n-1)
		return 1;
	return 0;
}

int BFS(int n,int a,int b)
{
	int dx[] = {-a, -b, b, a, -a, -b, b, a};
	int dy[] = {-b, -a, -a, -b, b, a, a, b};
	
	Queue q = create();
	
	Enqueue(createNode(0,0,0),&q);
	int x=0,y=0;
	Node t;
	
	int visited[100][100];
	
	for(int i=0;i<=6;i++)
		for(int j=0;j<=6;j++)
			visited[i][j] = 0;
	visited[0][0] = 1;
	
	while(!isEmpty(q))
	{
		t = getFront(&q);
		Dequeue(&q);
		visited[t.x][t.y] = 1;
		
		if((t.x == n-1) && (t.y == n-1))
			return t.dist;
		
		for(int i=0;i<8;i++)
		{
			x = t.x + dx[i];
			y = t.y + dy[i];

			if(isSafe(x,y,n) && !visited[x][y])
				Enqueue(createNode(x,y,(t.dist)+1),&q);
		}		
	}
	
	return -1;
}


int main()
{
	int n;
	scanf("%d",&n);
	
	int moves[100][100];
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
			printf("%d ",BFS(n,i,j));
		printf("\n");
	}
		
	
	return 0;
	
}
