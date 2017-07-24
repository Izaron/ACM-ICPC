// The solution of the problem was written by Izaron
// Date: 20:46:57   6 May 2015
// Execution time: 0.109

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.util.Scanner;
public class T1228 {

        public static void main(String[] args)
        {
            Scanner in = new Scanner(System.in);
            int n = in.nextInt();
            int k = in.nextInt();
            int[] a = new int[n+1];
            for (int i = 1; i <=n; i++)
            {
                a[i] = in.nextInt();
            }
            k -=1;
            int t=1;
            while (k!=0)
            {
                System.out.print((k/a[t])+" ");
                k = k%a[t];
                t++;
            }
        }
}