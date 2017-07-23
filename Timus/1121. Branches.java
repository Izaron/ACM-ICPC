// The solution of the problem was written by Izaron
// Date: 22:51:36   20 Aug 2016
// Execution time: 0.202

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    public void solve() {
        int h = in.nextInt(), w = in.nextInt();
        int[][] ms = new int[h][w];
        int[][] ans = new int[h][w];
        for (int i = 0; i < h; i++) {
            for (int z = 0; z < w; z++) {
                ms[i][z] = in.nextInt();
            }
        }
        for (int i = 0; i < h; i++) {
            for (int z = 0; z < w; z++) {
                if (ms[i][z] != 0) {
                    ans[i][z] = -1;
                    continue;
                }

                int dist = Integer.MAX_VALUE;

                for (int a = i - 5; a <= i + 5; a++) {
                    for (int b = z - 5; b <= z + 5; b++) {
                        if (a < 0 || b < 0 || a >= h || b >= w)
                            continue;
                        if (ms[a][b] == 0)
                            continue;
                        dist = min(dist, abs(a - i) + abs(b - z));
                    }
                }

                if (dist >= 6)
                    continue;

                for (int a = i - 5; a <= i + 5; a++) {
                    for (int b = z - 5; b <= z + 5; b++) {
                        if (a < 0 || b < 0 || a >= h || b >= w)
                            continue;
                        if (dist == abs(a - i) + abs(b - z)) {
                            ans[i][z] |= ms[a][b];
                        }
                    }
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int z = 0; z < w; z++) {
                out.print(ans[i][z] + " ");
            }
            out.println();
        }
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