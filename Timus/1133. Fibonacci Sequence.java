// The solution of the problem was written by Izaron
// Date: 22:05:44   10 May 2015
// Execution time: 0.14

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class JavaAntiCheater {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		
		int i, j, n;
		BigInteger fi, fj;
		i = in.nextInt();
		fi = in.nextBigInteger();
		j = in.nextInt();
		fj = in.nextBigInteger();
		n = in.nextInt();
		
		if(i > j) {
			int tmp = i;
			i = j;
			j = tmp;
			
			BigInteger tmi = fi;
			fi = fj;
			fj = tmi;
		}
		
		j -= i;
		n -= i;
		i -= i;
		
	    if(i == n) {
	        System.out.print(fi);
	        return;
	    }

	    if(j == n) {
	    	System.out.print(fj);
	        return;
	    }
	    
	    BigInteger[][] m = new BigInteger[3000][];
	    for(int z = 0; z < 3000; z++) {
	    	m[z] = new BigInteger[2];
	    }
	    m[0][0] = BigInteger.ONE;
	    m[0][1] = BigInteger.ZERO;
	    m[1][0] = BigInteger.ZERO;
	    m[1][1] = BigInteger.ONE;
	    
	    for(int z = 2; z <= Math.max(j, n); z++) {
	    	m[z][0] = m[z - 1][0].add(m[z - 2][0]);
	    	m[z][1] = m[z - 1][1].add(m[z - 2][1]);
	    }
	    
	    BigInteger x = fj;
	    x = x.subtract(m[j][0].multiply(fi));
	    x = x.divide(m[j][1]);

	    System.out.print(m[n][0].multiply(fi).add(m[n][1].multiply(x)));
	}

}
