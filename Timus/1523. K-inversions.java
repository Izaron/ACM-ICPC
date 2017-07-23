import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    public static final long MOD = (long)1e9;
    int n, k;
    int[] ms;
    SegmentTree[] trees;

    class SegmentTree {
        int n;
        long[] tree;

        SegmentTree(int n) {
            this.n = n;
            tree = new long[4 * n];
        }

        void add(int v, int l, int r, int pos, long val) {
            if (l == r) {
                tree[v] += val;
                tree[v] %= MOD;
            } else {
                if (pos <= (l + r) / 2)
                    add(v * 2, l, (l + r) / 2, pos, val);
                else
                    add(v * 2 + 1, (l + r) / 2 + 1, r, pos, val);
                tree[v] = (tree[v * 2] + tree[v * 2 + 1]) % MOD;
            }
        }

        void add(int pos, long val) {
            add(1, 0, n - 1, pos, val);
        }

        long get(int v, int l, int r, int L, int R) {
            if (r < L || R < l)
                return 0;
            if (l >= L && r <= R)
                return tree[v];
            return (get(v * 2, l, (l + r) / 2, L, R) + get(v * 2 + 1, (l + r) / 2 + 1, r, L, R)) % MOD;
        }

        long get(int l, int r) {
            if (l > r)
                return 0;
            return get(1, 0, n - 1, l, r);
        }
    }

    public void solve() {
        n = in.nextInt();
        k = in.nextInt();
        ms = new int[n];
        for (int i = 0; i < n; i++)
            ms[i] = in.nextInt() - 1;
        trees = new SegmentTree[k];
        for (int i = 0; i < k; i++)
            trees[i] = new SegmentTree(n);

        for (int i = n - 1; i >= 0; i--) {
            for (int ks = 1; ks < k; ks++) {
                long add = trees[ks - 1].get(0, ms[i] - 1);
                trees[ks].add(ms[i], add);
            }
            trees[0].add(ms[i], 1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += trees[k - 1].get(i, i);
            ans %= MOD;
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