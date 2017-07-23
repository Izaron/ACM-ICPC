// The solution of the problem was written by Izaron
// Date: 23:37:22   26 May 2016
// Execution time: 0.124

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int n, k, p;
    long ms[];

    long getOne() {
        long ans = 0;
        Arrays.fill(ms, 0);
        int cnt[] = new int[n + 1];
        int curr = 2;

        for (int i = 0; i < n - k; i++) {
            ms[i] = 1;
            ans += 1;
            cnt[1]++;
        }

        for (int i = n - k; i < n; i++) {
            int viewed = i;
            int light = cnt[curr - 1];
            if (100 * light < p * viewed) {
                cnt[curr] += cnt[curr - 1];
                curr++;
            }
            ms[i] = curr;
            ans += curr;
            cnt[curr]++;
        }

        return ans;
    }

    long getTwo() {
        long ans = 1;
        ms[0] = 1;

        int cnt[] = new int[n + 1];
        cnt[1] = 1;
        int curr = 2;

        for (int i = 1; i <= k; i++) {
            int viewed = i;
            int light = cnt[curr - 1];
            if (100 * light < p * viewed) {
                cnt[curr] += cnt[curr - 1];
                curr++;
            }
            ms[i] = curr;
            ans += curr;
            cnt[curr]++;
        }

        for (int i = k + 1; i < n; i++) {
            ms[i] = 1;
            ans += ms[i];
        }

        return ans;
    }

    public void solve() {
        n = in.nextInt();
        k = in.nextInt();
        p = in.nextInt();
        ms = new long[n];

        long a = getOne(), b = getTwo();
        if (a < b) {
            b = a;
            getOne();
        }

        out.println(b);
        for (int i = 0; i < n; i++)
            out.print(ms[i] + " ");
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