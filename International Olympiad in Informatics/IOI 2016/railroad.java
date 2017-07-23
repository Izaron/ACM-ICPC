import java.util.Arrays;

import static java.lang.Math.*;

public class railroad {

    int n;
    int[] s;
    int[] t;
    long[][] ank;

    long diff(long a, long b) {
        return max(0, a - b);
    }

    long dp(int mask, int last) {
        if (Integer.bitCount(mask) == n)
            return 0;
        if (ank[mask][last] != -1)
            return ank[mask][last];
        long cur = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0)
                continue;
            cur = min(cur, diff(t[last], s[i]) + dp(mask | (1 << i), i));
        }
        ank[mask][last] = cur;
        return cur;
    }

    long plan_roller_coaster(int[] s, int[] t) {
        n = s.length;
        this.s = s;
        this.t = t;
        ank = new long[1 << n][n];
        for (int i = 0; i < (1 << n); i++)
            Arrays.fill(ank[i], -1);
        long cur = Long.MAX_VALUE;
        for (int i = 0; i < n; i++)
            cur = min(cur, dp(1 << i, i));
        return cur;
    }
}
