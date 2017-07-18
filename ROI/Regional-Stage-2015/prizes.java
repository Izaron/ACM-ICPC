import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "prizes";

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        long ms[] = new long[n];
        long sumLeft[] = new long[n];
        long bestLeft[] = new long[n];
        long sumRight[] = new long[n];
        long bestRight[] = new long[n];
        for (int i = 0; i < n; i++) {
            ms[i] = in.nextInt();
            sumLeft[i] = ms[i];
            sumRight[i] = ms[i];
        }

        bestLeft[0] = ms[0];
        sumLeft[0] = ms[0];
        for (int i = 1; i < n; i++) {
            sumLeft[i] += sumLeft[i - 1];
            if (i - k >= 0)
                sumLeft[i] -= ms[i - k];
            bestLeft[i] = sumLeft[i];
            bestLeft[i] = max(bestLeft[i], bestLeft[i - 1]);
        }

        bestRight[n - 1] = ms[n - 1];
        sumRight[n - 1] = ms[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sumRight[i] += sumRight[i + 1];
            if (i + k < n)
                sumRight[i] -= ms[i + k];
            bestRight[i] = sumRight[i];
            bestRight[i] = max(bestRight[i], bestRight[i + 1]);
        }

        for (int i = 0; i < k - 1; i++) {
            bestLeft[i] = 0;
            bestRight[n - i - 1] = 0;
        }

        long ans = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (i + k - 1 >= n)
                break;
            long curr = 0;
            if (i > 0)
                curr = max(curr, bestLeft[i - 1]);
            if (i + k < n)
                curr = max(curr, bestRight[i + k]);
            ans = min(ans, curr);
        }

        out.print(ans);
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
 
