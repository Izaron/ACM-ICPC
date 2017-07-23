import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    class SuffixArray {
        CharSequence S;
        int n;
        int sa[];
        int rank[];
        int lcp[];

        SuffixArray(CharSequence S) {
            this.S = S;
            n = S.length();
            buildArray();
            buildRank();
            buildLcp();
        }

        void buildArray() {
            sa = IntStream.range(0, n).mapToObj(i -> n - 1 - i).sorted((a, b) ->
                Character.compare(S.charAt(a), S.charAt(b))).mapToInt(Integer::intValue).toArray();
            int classes[] = S.chars().toArray();

            for (int len = 1; len < n; len *= 2) {
                int c[] = classes.clone();
                for (int i = 0; i < n; i++) {
                    if (i > 0 && c[sa[i]] == c[sa[i - 1]] && sa[i - 1] + len < n && c[sa[i] + len / 2] == c[sa[i - 1] + len / 2]) {
                        classes[sa[i]] = classes[sa[i - 1]];
                    } else {
                        classes[sa[i]] = i;
                    }
                }

                int s[] = sa.clone();
                int cnt[] = IntStream.range(0, n).toArray();
                for (int i = 0; i < n; i++) {
                    int s1 = s[i] - len;
                    if (s1 >= 0)
                        sa[cnt[classes[s1]]++] = s1;
                }
            }
        }

        void buildRank() {
            rank = new int[n];
            for (int i = 0; i < n; i++)
                rank[sa[i]] = i;
        }

        void buildLcp() {
            lcp = new int[n - 1];
            int h = 0;
            for (int i = 0; i < n; i++) {
                if (rank[i] < n - 1) {
                    int j = sa[rank[i] + 1];
                    while (max(i, j) + h < n && S.charAt(i + h) == S.charAt(j + h))
                        h++;
                    lcp[rank[i]] = h;
                    if (h > 0)
                        h--;
                }
            }
        }
    }

    public void solve() {
        String s = in.next();
        int n = s.length();
        SuffixArray suffixArray = new SuffixArray(s);
        long ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += n - suffixArray.sa[i];
            if (i < s.length() - 1)
                ans -= suffixArray.lcp[i];
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