import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "melman";

    String s;
    int n, k;
    int zs;
    int z[];
    long hash1[];
    long pPow1[];
    long p1 = 1007;
    long MOD = 1_000_000_009;
    ArrayList<Integer> list = new ArrayList<>();

    void ZFunction() {
        z = new int[n];
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s.charAt(z[i]) == s.charAt(z[i] + i))
                z[i]++;
            if (r < z[i] + i - 1) {
                r = z[i] + i - 1;
                l = i;
            }
        }
    }

    void hashFunction() {
        hash1 = new long[n];
        pPow1 = new long[n];
        pPow1[0] = 1;
        for (int i = 1; i < n; i++)
            pPow1[i] = (pPow1[i - 1] * p1) % MOD;
        for (int i = 0; i < s.length(); i++) {
            hash1[i] = (long) (s.charAt(i)) * pPow1[i];
            hash1[i] %= MOD;
            if (i > 0)
                hash1[i] += hash1[i - 1];
            hash1[i] %= MOD;
        }
    }

    boolean isEquals(int x, int y, int w, int h) {
        if (w < x)
            return isEquals(w, h, x, y);
        if (h >= n)
            return false;
        if (x > y + 1)
            return false;
        if (x == y + 1)
            return true;

        long h1 = hash1[y];
        if (x > 0) h1 -= hash1[x - 1];
        long h2 = hash1[h];
        if (w > 0) h2 -= hash1[w - 1];
        while (h1 < 0)
            h1 += MOD;
        while (h2 < 0)
            h2 += MOD;

        return ((h1 * pPow1[w - x]) % MOD == h2);
    }

    void check(int v) {
        int poh = z[v];
        if (isEquals(0, poh - 1, v, poh - 1 + v)) {
            if (isEquals(poh + 1, poh + k - 1, poh + 1 + v, poh + k - 1 + v)) {
                if (isEquals(poh + k + 1, zs, poh + k + 1 + v, zs + v)) {
                    if (s.charAt(poh) != s.charAt(poh + v)) {
                        if (s.charAt(poh + k) != s.charAt(poh + k + v)) {
                            list.add(v);
                        }
                    }
                }
            }
        }
    }

    public void solve() {
        String oh = in.next(), ah = in.next();
        k = in.nextInt();
        s = ah + "#" + oh;
        zs = ah.length() - 1;
        n = s.length();
        ZFunction();
        hashFunction();

        //out.println(s);
        //for (int i = 0; i < n; i++) {
        //    out.print(z[i]);
        //}
        //out.println();
        //out.flush();

        /*while (true) {
            int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
            out.println(isEquals(a, b, c, d));
            out.flush();
        }*/

        for (int i = ah.length() + 1; i < n; i++)
            check(i);

        out.println(list.size());
        for (Integer it : list)
            out.print((it - ah.length()) + " ");
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