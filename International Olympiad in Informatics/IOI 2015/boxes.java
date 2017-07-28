import java.util.Scanner;

import static java.lang.Math.*;

public class boxes {
    long getDistance(int L, int p[], int from, int to) {
        long a = p[to] + p[to];
        long b = p[to] + (L - p[to]);
        long c = (L - p[from]) + (L - p[from]);
        long d = (L - p[from]) + p[from];
        return min(min(a, b), min(c, d));
    }

    long delivery(int N, int K, int L, int p[]) {
        long ans[] = new long[N + 1];

        for (int v = N - 1; v > 0; v--) {
            ans[v] = getDistance(L, p, v, min(N, v + K) - 1) + ans[min(N, v + K)];
        }

        long res = Long.MAX_VALUE;
        for (int i = 0; i < min(N, K); i++) {
            res = min(res, getDistance(L, p, 0, i) + ans[i + 1]);
        }

        return res;
    }

    public static void main(String[] args) {
        boxes b = new boxes();

        Scanner in = new Scanner(System.in);

        int n = in.nextInt(), k = in.nextInt(), l = in.nextInt();
        int p[] = new int[n];
        for (int i = 0; i < n; i++)
            p[i] = in.nextInt();

        System.out.println(b.delivery(n, k, l, p));
    }
}
