import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int n;
    int[] c;
    int[][][] calc;
    int[] black;
    int[] white;
    int[] canBlack;
    int[] canWhite;

    int getWhites(int a, int b) {
        int ans = white[min(b, n - 1)];
        if (a > 0)
            ans -= white[a - 1];
        return ans;
    }

    int dp(int v, int k, int e) {
        if (v == n)
            return k == c.length ? 1 : 0;
        if (v > n)
            return 0;
        if (calc[v][k][e] != -1)
            return calc[v][k][e];
        int ans = 0;
        int val;
        if (k < c.length && e != 1 && getWhites(v, v + c[k] - 1) == 0) {
            val = dp(v + c[k], k + 1, 1);
            if (val == 1) {
                ans = 1;
                canBlack[v]++;
                canBlack[min(n, v + c[k])]--;
            }
        }
        if (black[v] == 0) {
            val = dp(v + 1, k, 0);
            if (val == 1) {
                ans = 1;
                canWhite[v] = 1;
            }
        }
        calc[v][k][e] = ans;
        return ans;
    }

    void solve() {
        n = in.nextInt();
        int k = in.nextInt();
        c = new int[k];
        for (int i = 0; i < k; i++)
            c[i] = in.nextInt();
        String s = in.next();
        calc = new int[n][k + 1][2];
        black = new int[n];
        white = new int[n];
        canBlack = new int[n + 1];
        canWhite = new int[n + 1];

        for (int i = 0; i < calc.length; i++) {
            for (int z = 0; z < calc[i].length; z++) {
                for (int q = 0; q < calc[i][z].length; q++) {
                    calc[i][z][q] = -1;
                }
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'X')
                black[i]++;
            else if (s.charAt(i) == '.')
                white[i]++;
        }

        for (int i = 1; i < n; i++)
            white[i] += white[i - 1];

        StringBuffer buffer = new StringBuffer();

        int a = dp(0, 0, 0);
        if (a == 0) {
            out.print("Impossible");
            return;
        }

        for (int i = 1; i < canBlack.length; i++)
            canBlack[i] += canBlack[i - 1];
        for (int i = 0; i < n; i++) {
            if (canBlack[i] > 0 && canWhite[i] > 0)
                buffer.append('?');
            else if (canBlack[i] > 0)
                buffer.append('X');
            else
                buffer.append('.');
        }

        out.print(buffer);
    }

    public void run() {
        if (FILE.equals("")) {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);
        } else {
            try {
                in = new FastScanner(new FileInputStream(FILE +
                        ".in"));
                out = new PrintWriter(new FileOutputStream(FILE +
                        ".out"));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
        solve();
        out.close();
    }

    public static void main(String[] args) {
        (new Main()).run();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
                return null;
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public float nextFloat() {
            return Float.parseFloat(next());
        }
    }

}