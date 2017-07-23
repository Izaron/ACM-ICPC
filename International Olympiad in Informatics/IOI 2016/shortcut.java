import static java.lang.Math.*;

public class shortcut {

    int n;
    int[] l;
    int[] d;
    int c;
    long[] sum;

    long length(int a, int b) {
        if (a == b)
            return 0;
        if (a > b)
            return length(b, a);
        if (a == 0)
            return sum[b - 1];
        else
            return sum[b - 1] - sum[a - 1];
    }

    long getMaximal(int a, int b) {
        long maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long cur = length(i, j);
                cur = min(cur, length(i, a) + c + length(b, j));
                cur = min(cur, length(i, b) + c + length(a, j));
                maxi = max(maxi, cur + d[i] + d[j]);
            }
        }
        return maxi;
    }

    public long find_shortcut(int n, int[] l, int[] d, int c) {
        this.n = n;
        this.l = l;
        this.d = d;
        this.c = c;

        sum = new long[n - 1];
        sum[0] = l[0];
        for (int i = 1; i < sum.length; i++)
            sum[i] = l[i] + sum[i - 1];

        long ans = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = min(ans, getMaximal(i, j));
            }
        }

        return ans;
    }
}
