// The solution of the problem was written by Izaron
// Date: 20:37:38   23 Aug 2016
// Execution time: 0.296

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int m, n, k;
    List<Integer>[] as;
    List<Integer>[] bs;
    TreeSet<PairInt>[] aSegments;
    TreeSet<PairInt>[] bSegments;

    boolean isCorrectA(int a, int b) {
        if (a - 1 >= 0) {
            PairInt pair = aSegments[a - 1].lower(new PairInt(b, Integer.MAX_VALUE));
            if (pair != null) {
                if (pair.b >= b)
                    return false;
            }
        }

        if (a + 1 < aSegments.length) {
            PairInt pair = aSegments[a + 1].lower(new PairInt(b, Integer.MAX_VALUE));
            if (pair != null) {
                if (pair.b >= b)
                    return false;
            }
        }

        return true;
    }

    public void solve() {
        m = in.nextInt();
        n = in.nextInt();
        k = in.nextInt();
        as = new ArrayList[m];
        for (int i = 0; i < m; i++)
            as[i] = new ArrayList<>();
        bs = new ArrayList[n];
        for (int i = 0; i < n; i++)
            bs[i] = new ArrayList<>();
        aSegments = new TreeSet[m];
        for (int i = 0; i < m; i++)
            aSegments[i] = new TreeSet<>();
        bSegments = new TreeSet[n];
        for (int i = 0; i < n; i++)
            bSegments[i] = new TreeSet<>();

        for (int i = 0; i < k; i++) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            as[a].add(b);
            bs[b].add(a);
        }

        for (int i = 0; i < m; i++) {
            int cur = 0;
            as[i].add(n);
            Collections.sort(as[i]);
            for (Integer it : as[i]) {
                if (it - cur > 0)
                    aSegments[i].add(new PairInt(cur, it - 1));
                cur = it + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            int cur = 0;
            bs[i].add(m);
            Collections.sort(bs[i]);
            for (Integer it : bs[i]) {
                if (it - cur > 0)
                    bSegments[i].add(new PairInt(cur, it - 1));
                cur = it + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (PairInt pair : aSegments[i]) {
                if (pair.b > pair.a) {
                    ans++;
                } else if (isCorrectA(i, pair.a)) {
                    ans++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (PairInt pair : bSegments[i]) {
                if (pair.b > pair.a) {
                    ans++;
                }
            }
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