import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "sequence";

    int n;
    long bs[];
    long sum[] = new long[3];
    ArrayList<Long> list[] = new ArrayList[3];
    TreeSet<PairLong> set[] = new TreeSet[3];  // (val, cnt)
    ArrayList<Long> sumCnt[] = new ArrayList[3];

    long calc(int v, long x) {
        PairLong pair = new PairLong(x, Long.MAX_VALUE);
        if (pair.compareTo(set[v].first()) < 0) {
            return sum[v] - set[v].size() * x;
        } else if (pair.compareTo(set[v].last()) > 0) {
            return set[v].size() * x - sum[v];
        } else {
            long cnt = set[v].lower(pair).b;
            return (x * (cnt + 1) - sumCnt[v].get((int)cnt)) +
                    (sum[v] - sumCnt[v].get((int)cnt) - x * (sumCnt[v].size() - cnt - 1));
        }
    }

    long getAns(long x, long y) {
        return calc(0, x) + calc(1, y) + calc(2, y - x);
    }

    long findY(long x) {
        long a = -3 * 1_000_000_000L, b = 3 * 1_000_000_000L;
        while (abs(a - b) > 10) {
            long l = a + (b - a) / 3;
            long r = b - (b - a) / 3;

            if (getAns(x, l) > getAns(x, r))
                a = l;
            else
                b = r;
        }
        long ans = Long.MAX_VALUE;
        for (long i = a; i <= b; i++)
            ans = min(ans, getAns(x, i));
        return ans;
    }

    long findX() {
        long a = -3 * 1_000_000_000L, b = 3 * 1_000_000_000L;
        while (abs(a - b) > 10) {
            long l = a + (b - a) / 3;
            long r = b - (b - a) / 3;

            if (findY(l) > findY(r))
                a = l;
            else
                b = r;
        }
        long ans = Long.MAX_VALUE;
        for (long i = a; i <= b; i++)
            ans = min(ans, findY(i));
        return ans;
    }

    public void solve() {
        for (int i = 0; i < 3; i++) {
            list[i] = new ArrayList<>();
            set[i] = new TreeSet<>();
            sumCnt[i] = new ArrayList<>();
        }

        n = in.nextInt();
        bs = new long[n];
        for (int i = 0; i < n; i++) {
            bs[i] = in.nextLong();
            if (i % 6 >= 3)
                bs[i] *= -1;
            sum[i % 3] += bs[i];
            list[i % 3].add(bs[i]);
        }

        for (int i = 0; i < 3; i++) {
            Collections.sort(list[i]);
            long sm = 0;
            for (int z = 0; z < list[i].size(); z++) {
                long val = list[i].get(z);
                set[i].add(new PairLong(val, (long)z));
                sm += val;
                sumCnt[i].add(sm);
            }
        }

        out.print(findX());
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