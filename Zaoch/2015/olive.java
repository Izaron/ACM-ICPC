import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int n;
    int ms[];
    long higher[][];
    long ans = 0;

    void precalcAns() {
        for (int i = 0; i < n; i++) {
            for (int z = i + 1; z < n; z++) {
                if (ms[z] < ms[i]) {
                    ans++;
                }
            }
        }
    }

    void calc(int v) {
        int curr = 0;
        for (int z = n - 1; z >= 0; z--) {
            if (ms[z] < ms[v]) {
                curr++;
            }
            higher[v][z] = curr;
        }
    }

    long change(int a, int b) {
        long curr = ans;
        curr -= higher[b][b];
        curr += higher[b][a + 1];
        curr -= higher[a][a];
        curr += higher[a][b + 1];
        if (ms[a] > ms[b])
            curr--;
        else
            curr++;
        return curr;
    }

    public void solve() {
        n = in.nextInt();
        ms = new int[n];
        higher = new long[n + 1][n + 1];
        for (int i = 0; i < n; i++)
            ms[i] = in.nextInt();
        precalcAns();
        for (int i = 0; i < n; i++)
            calc(i);
        int l = -1, r = -1;
        long mini = ans;
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                long kz = change(a, b);
                if (kz < mini) {
                    mini = kz;
                    l = a + 1;
                    r = b + 1;
                }
            }
        }
        out.print(l + " " + r);
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