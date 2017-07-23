// The solution of the problem was written by Izaron
// Date: 14:03:56   20 Aug 2016
// Execution time: 0.109

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int n;
    char[] a;
    char[] b;

    char[] findNextB() {
        char[] bb = b.clone();
        boolean can = false;

        int gran = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == '1' && bb[i] == '1') {
                bb[i] = '0';
                for (int z = gran; z > i - 1; z--)
                    bb[z] = '0';
                gran = i - 1;
            }
        }

        for (int i = gran; i >= 0; i--) {
            if (a[i] == '1')
                continue;
            if (!can) {
                if (bb[i] == '1') {
                    bb[i] = '0';
                } else {
                    bb[i] = '1';
                    can = true;
                }
            }
        }
        if (!can)
            return null;
        return bb;
    }

    char[] findNextA() {
        char[] aa = a.clone();
        boolean can = false;

        for (int i = n - 1; i >= 0; i--) {
            if (!can) {
                if (aa[i] == '1') {
                    aa[i] = '0';
                } else {
                    aa[i] = '1';
                    can = true;
                }
            }
        }
        if (!can)
            return null;
        return aa;
    }

    public void solve() {
        n = in.nextInt();
        a = in.next().toCharArray();
        b = in.next().toCharArray();

        char[] bb = findNextB();
        if (bb != null) {
            for (int i = 0; i < n; i++)
                out.print(a[i]);
            out.println();
            for (int i = 0; i < n; i++)
                out.print(bb[i]);
        } else {
            char[] aa = findNextA();
            if (aa != null) {
                for (int i = 0; i < n; i++)
                    out.print(aa[i]);
                out.println();
                for (int i = 0; i < n; i++)
                    out.print('0');
            } else {
                for (int i = 0; i < n; i++)
                    out.print('0');
                out.println();
                for (int i = 0; i < n; i++)
                    out.print('0');
            }
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