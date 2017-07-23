// The solution of the problem was written by Izaron
// Date: 15:04:41   11 May 2015
// Execution time: 0.14

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.util.Scanner;

public class Sold_Out {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int k = scan.nextInt();

        if(n<3){
            System.out.println(0);
            return;
        }

        System.out.println(Math.max(k - 1, n - k) - 2);
    }
}