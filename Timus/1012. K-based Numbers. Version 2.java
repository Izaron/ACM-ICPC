import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class JavaAntiCheater {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		
	    int n, k;
	    n = in.nextInt();
	    k = in.nextInt();
	    BigInteger[][] m = new BigInteger[2000][];
	    
	    for(int i = 0; i < 2000; i++) {
	    	m[i] = new BigInteger[20];
	    	for(int z = 0; z < 20; z++) {
	    		m[i][z] = BigInteger.ZERO;
	    	}
	    }
	    
	    m[0][0] = BigInteger.ONE;

	    BigInteger sum = BigInteger.ZERO;

	    for(int i = 1; i <= n; i++) {
	        // 0
	        for(int z = 1; z < k; z++) {
	        	m[i][0] = m[i][0].add(m[i - 1][z]);
	        }

	        // other
	        for(int oth = 1; oth < k; oth++) {
	            for(int z = 0; z < k; z++) {
	            	m[i][oth] = m[i][oth].add(m[i - 1][z]);
	            }
	        }
	    }

	    for(int i = 0; i < k; i++)
	    	sum = sum.add(m[n][i]);

	    System.out.print(sum);
	}

}
