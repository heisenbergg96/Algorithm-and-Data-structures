import java.util.*;

class Solution
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		char c[10] = new char[10];
		binaryString(c,n);
	}
	
	public static void binaryString(char c[],int n)
	{
		if(n<1)
			System.out.println(c);
		else
			{
				c[n-1] = '0';
				binaryString(c,n-1);
				c[n-1] = '1';
				binaryString(c,n-1);
			}
	}
}
