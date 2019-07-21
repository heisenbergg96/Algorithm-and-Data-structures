import java.util.*;
import java.lang.*;

class Longsub
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		String s1 = in.nextLine();
		String s2 = in.nextLine();

		System.out.println(Long_subsequence(s1,s2));
	}
	
	public static StringBuffer Long_subsequence(String s1,String s2)
	{
		int dp[][] = new int[s1.length()+1][s2.length()+1];
		int pointer[][] = new int[s1.length()+1][s2.length()+1];

		for(int i=1;i<=s1.length();i++)
			for(int j=1;j<=s2.length();j++)
			{
				if(s1.charAt(i-1) == s2.charAt(j-1))
				{
					dp[i][j] = 1 + dp[i-1][j-1];
					pointer[i][j] = 3;
				}
				else
				{
					if(dp[i-1][j] > dp[i][j-1])
					{	
						dp[i][j] = dp[i-1][j];
						pointer[i][j] = 1;
					}
					else
					{
						dp[i][j] = dp[i][j-1];
						pointer[i][j] = 2;
					}
				}
			}
			StringBuffer sub = new StringBuffer();
			int i = s1.length(),j=s2.length();
			while(i>=1 && j>=1)
			{
				if(pointer[i][j] == 1)
					i--;
				if(pointer[i][j] == 2)
					j--;
				if(pointer[i][j] == 3)
				{
					sub.append(s1.charAt(i-1));
					i--;
					j--;
				}
			}
			return sub.reverse();
	}

}
