import java.util.*;

class Main
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		String str;

		str = s.nextLine();
		
		System.out.println(find_palindrome(str));
	}

	static String find_palindrome(String s)
	{
		int a[][] = new int[100][100];
		int m = 0,st=0,end=0;

		//palindromes of length 1
		for(int i=0;i<s.length();i++)
			a[i][i] = 1;

		//palindromes of length 2
		for(int i=0;i<s.length()-1;i++)
			if(s.charAt(i) == s.charAt(i+1))
				a[i][i+1] = 1;

		//palindromes of length >=3
		for(int cur_len=3;cur_len<=s.length();cur_len++)
		{
			for(int i=0;i<s.length()-cur_len;i++)
			{
				int j = i+cur_len-1;
				if(s.charAt(i) == s.charAt(j) && a[i+1][j-1] == 1)
				{
					m = cur_len;
					a[i][j] = 1;
					st = i;
					end = j;
				}
			}
		}
		return s.substring(st,end+1);
	}
}
