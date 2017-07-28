// The solution of the problem was written by Izaron
// Date: 00:38:14   26 Jul 2017
// Execution time: 0.124

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    int l, m, k;
    BigInteger num;
    boolean[][] used;
    BigInteger[][] calced;

    // v - out of l, mod - out of m
    BigInteger dp(int v, int mod) {
        if (v == l)
            return (mod == 0 ? BigInteger.ONE : BigInteger.ZERO);
        if (used[v][mod])
            return calced[v][mod];
        used[v][mod] = true;
        BigInteger res = BigInteger.ZERO;
        for (int i = 1; i <= m; i++)
            res = res.add(dp(v + 1, (mod + i) % k));
        calced[v][mod] = res;
        return res;
    }

    void calc() {
        int sum = 0;
        for (int i = 0; i < l; i++) {
            int index = 1;
            for (int r = 1; r < m; r++) {
                BigInteger cur = dp(i + 1, (sum + r) % k);
                if (num.compareTo(cur) >= 0) {
                    num = num.subtract(cur);
                    index = r + 1;
                } else {
                    break;
                }
            }
            System.out.print(index + " ");
            sum += index;
        }
    }

    void solve() {
        Scanner s = new Scanner(System.in);
        l = s.nextInt();
        m = s.nextInt();
        k = s.nextInt();
        num = new BigInteger(s.next());

        used = new boolean[l][k];
        calced = new BigInteger[l][k];
        calc();
        System.out.println();
    }

    public static void main(String[] args) {
        (new Main()).solve();
    }
}
