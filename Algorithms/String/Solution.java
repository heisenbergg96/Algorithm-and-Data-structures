import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        int pre = -1,cur,i;
        String str = "hackerank";
        char [] ch = str.toCharArray();
        for(int a0 = 0; a0 < q; a0++){
            String s = in.next();
           for(i=0;i<ch.length;i++)
           {
               cur = s.indexOf(ch[i],pre+1);
               if(pre+1 > cur)
               {
                   System.out.println("NO");
                   break;
               }
               pre = cur;
   
           }
            if(i == str.length())System.out.println("YES");
            pre = -1;
        }
    }
}

