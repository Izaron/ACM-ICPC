// The solution of the problem was written by Izaron
// Date: 23:20:31   27 Jul 2017
// Execution time: 0.187

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {


    void solve() {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        BigDecimal res = BigDecimal.ZERO;
        for (int i = 0; i < n; i++)
            res = res.add(new BigDecimal(scan.next()));

        int cnt = 0;
        while (res.toBigInteger().compareTo(BigInteger.TEN) >= 0) {
            cnt++;
            res = res.divide(BigDecimal.TEN);
        }
        System.out.println(res.toPlainString() + "e" + cnt);
    }

    public static void main(String[] args) {
        (new Main()).solve();
    }
}
