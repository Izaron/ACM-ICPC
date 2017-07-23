import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int[] suffixArray(String S) {
        int n = S.length();
        int[] sa = IntStream.range(0, n).mapToObj(i -> n - 1 - i).
                sorted((a, b) -> Character.compare(S.charAt(a), S.charAt(b))).mapToInt(Integer::intValue).toArray();
        int[] classes = S.chars().toArray();
        for (int len = 1; len < n; len <<= 1) {
            int[] c = classes.clone();
            for (int i = 0; i < n; i++) {
                if (i > 0 && c[sa[i]] == c[sa[i - 1]] && sa[i - 1] + len < n && c[sa[i] + len / 2] == c[sa[i - 1] + len / 2])
                    classes[sa[i]] = classes[sa[i - 1]];
                else
                    classes[sa[i]] = i;
            }

            int[] s = sa.clone();
            int[] cnt = IntStream.range(0, n).toArray();
            for (int i = 0; i < n; i++) {
                int s1 = s[i] - len;
                if (s1 >= 0)
                    sa[cnt[classes[s1]]++] = s1;
            }
        }
        return sa;
    }

    int[] lcp(int[] sa, String s) {
        int n = sa.length;
        int[] rank = new int[n];
        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;
        int[] lcp = new int[n - 1];
        for (int i = 0, h = 0; i < n; i++) {
            if (rank[i] < n - 1) {
                for (int j = sa[rank[i] + 1]; max(i, j) + h < s.length() && s.charAt(i + h) == s.charAt(j + h); h++)
                    ;
                lcp[rank[i]] = h;
                if (h > 0)
                    h--;
            }
        }
        return lcp;
    }

    long getUniqueSubstringCount(String s) {
        int[] sa = suffixArray(s);
        int[] lcp = lcp(sa, s);
        int n = sa.length;
        long ans = n - sa[0];
        for (int i = 0; i < lcp.length; i++) {
            ans += n - sa[i + 1] - lcp[i];
        }
        return ans;
    }

    public void solve() {
        int k = in.nextInt();
        String s = in.next();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (i + k - 1 < n) {
                String cur = s.substring(i, i + k);
                out.print(getUniqueSubstringCount(cur) + " ");
            } else {
                String cur = s.substring(i) + s.substring(0, k - (n - i));
                out.print(getUniqueSubstringCount(cur) + " ");
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