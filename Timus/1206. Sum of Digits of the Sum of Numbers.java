
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