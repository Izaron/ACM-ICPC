// The solution of the problem was written by Izaron
// Date: 22:26:12   2 Apr 2015
// Execution time: 0.14

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.


import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		
        int k = in.nextInt();
        
        BigInteger ans = new BigInteger("36");
        for(int i = 1; i < k; i++) {
        	ans = ans.multiply(new BigInteger("55"));
        }
        
		System.out.print(ans);
	}

}