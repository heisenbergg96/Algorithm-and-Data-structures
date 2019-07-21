import java.util.*;

class LongestCommonSubsequence {


	public static void main(String args[]) {
		
		String str1 = "ABCsdssd";
		String str2 = "FRTsdsdsd";
		
		System.out.println(findSubsequence(str1, str2));
	}
	
	public static int findSubsequence(String str1, String str2) {
		
		int array[][] = new int[str1.length()][str2.length()];
		
		for(int i=0;i<str1.length();i++) {
			for(int j=0;j<str2.length();j++) {
				
				if(str1.charAt(i) == str2.charAt(j)) {
					
					if(i == 0 || j == 0) {
						array[i][j] = 1;
					} else {
					
						array[i][j] = array[i-1][j-1] + 1;
					}
				} else {
					if(i != 0 && j != 0) {
						array[i][j] = Math.max(array[i-1][j], array[i][j-1]);
					} else {
						// do nothing ante...shata
					}
					
				}
			}
		}
		
		return array[str1.length()-1][str2.length()-1];
	}
}
