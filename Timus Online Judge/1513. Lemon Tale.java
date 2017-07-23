// The solution of the problem was written by Izaron
// Date: 19:39:25   6 May 2015
// Execution time: 0.218

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class JavaAntiCheater {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		BigInteger[] m = new BigInteger[10005];
		m[0] = BigInteger.ONE;
		m[1] = BigInteger.ONE;
		for(int i = 2; i <= n + 1; i++) {
	        m[i] = m[i - 1].multiply(new BigInteger("2"));
	        if(i - k - 2 >= 0) m[i] = m[i].subtract(m[i - k - 2]);
	    }
		System.out.print(m[n + 1]);
	}

}
