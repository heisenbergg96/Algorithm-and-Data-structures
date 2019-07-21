import java.util.Scanner;

class BinaryString
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int len = sc.nextInt();
		
		StringBuffer s = new StringBuffer(20);
		Binary(s,len);
	}

	public static void Binary(StringBuffer s,int n)
	{
		if(n<1)
			System.out.println(s);
		else
			{
				s[n-1] = 0;
				Binary(s,n-1);
				s[n-1] = 1;
				Binary(s,n-1);
			}
	}
}
