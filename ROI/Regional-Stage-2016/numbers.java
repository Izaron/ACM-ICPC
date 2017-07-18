import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "numbers";

    int n;
    int msL[];
    int msR[];
    boolean used[][][][];
    int ank[][][][];

    int dp(int v, int symbol, int bigger, int lower) {
        if (v == n)
            return 1;

        if (used[v][symbol][bigger][lower])
            return ank[v][symbol][bigger][lower];
        used[v][symbol][bigger][lower] = true;

        int ans = 0;
        for (int i = symbol; i <= 9; i++) {
            int nl = lower, nb = bigger;
            if (lower == 0 && i > msR[v])
                continue;
            if (bigger == 0 && i < msL[v])
                continue;
            if (i < msR[v])
                nl = 1;
            if (i > msL[v])
                nb = 1;
            ans += dp(v + 1, i, nb, nl);
            ans %= 1_000_000_007;
        }

        ank[v][symbol][bigger][lower] = ans;
        return ans;
    }

    public void solve() {
        String l = in.next(), r = in.next();
        int cst = 105;
        used = new boolean[cst][10][2][2];
        ank = new int[cst][10][2][2];
        while (l.length() < cst)
            l = "0" + l;
        while (r.length() < cst)
            r = "0" + r;
        n = cst;
        msL = new int[n];
        msR = new int[n];
        for (int i = 0; i < l.length(); i++)
            msL[i] = l.charAt(i) - '0';
        for (int i = 0; i < r.length(); i++)
            msR[i] = r.charAt(i) - '0';
        out.print(dp(0, 0, 0, 0));
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
                return "";
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

    class Pair<A extends Comparable<A>, B extends Comparable<B>>
            implements Comparable<Pair<A, B>> {
        public A a;
        public B b;

        public Pair(A a, B b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Pair<A, B> o) {
            if (o == null || o.getClass() != getClass())
                return 1;
            int cmp = a.compareTo(o.a);
            if (cmp == 0)
                return b.compareTo(o.b);
            return cmp;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair<?, ?> pair = (Pair<?, ?>) o;

            if (a != null ? !a.equals(pair.a) : pair.a != null) return
                    false;
            return !(b != null ? !b.equals(pair.b) : pair.b != null);
        }
    }

    class PairInt extends Pair<Integer, Integer> {
        public PairInt(Integer u, Integer v) {
            super(u, v);
        }
    }

    class PairLong extends Pair<Long, Long> {
        public PairLong(Long u, Long v) {
            super(u, v);
        }
    }

}