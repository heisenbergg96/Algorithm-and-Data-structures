import java.util.*;

class Fibonacci {
	
	public static void main(String args[]) {
		
		int array[] = new int[1000];
		System.out.println();
	}
	
	public static int fibo(int n, int dp[]) {
		
		if(dp[n] != -1) return dp[n];
		n == 1 ? return 0 : (n == 2) ? return 1: dp[n] = fibo(n-1) + fibo(n-2);
		
		return dp[n];
	}
}
