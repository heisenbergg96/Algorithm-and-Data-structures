import java.util.*;

class Node
{
	int x;
	int y;
	int dist;

	Node(int x,int y,int dist)
	{
		this.x = x;
		this.y = y;
		this.dist = dist;
	}
}

class Solution
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
        int[][] moves = new int[n+1][n+1];
        
        for(int i=1;i<n;i++)
            for(int j=1;j<n;j++)
                    if(i<=j) 
                        moves[i][j] = minimumstep(n,i,j);
                    else
                        moves[i][j] = moves[j][i];
        
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<n;j++)
				System.out.print(moves[i][j]+" ");
			System.out.println();
		}
	}

	static int minimumstep(int n,int a,int b)
	{
		int dx[] = {-a, -b, b, a, -a, -b, b, a};
		int dy[] = {-b, -a, -a, -b, b, a, a, b};

		Queue<Node> q = new LinkedList<>();
		q.add(new Node(0,0,0));
		int x=0,y=0;
		Node t;
		boolean visited[][] = new boolean[n+1][n+1];
		
		visited[0][0] = true;
		
		while(!q.isEmpty())
		{
			t = q.remove();
			visited[t.x][t.y] = true;

			if(t.x == n-1 && t.y == n-1)
				return t.dist;
			for(int i=0;i<8;i++)
			{
				x = t.x + dx[i];
				y = t.y + dy[i];

				if(isSafe(x,y,n) && !visited[x][y])
					q.add(new Node(x,y,t.dist+1));
			}
			
		}
		return -1;
	}

	static boolean isSafe(int x,int y,int n)
	{
		if (x >= 0 && x <= n-1 && y >= 0 && y <= n-1)
			return true;
		return false;
	}
}
