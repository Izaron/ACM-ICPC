import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "search";

    int n, p, k;

    Map<String, Integer> set12;
    Map<String, Integer> set1;
    Map<String, Integer> set2;
    Map<String, Integer> set;
    boolean used[][];

    int parse(String s, boolean saved1, boolean saved2, int a, int b) {
        if (used[a][b])
            return 0;
        used[a][b] = true;

        int ans = 0;

        if (saved1 && saved2) {
            ans += set.getOrDefault(s, 0);
            ans += set1.getOrDefault(s, 0);
            ans += set2.getOrDefault(s, 0);
            ans += set12.getOrDefault(s, 0);
        } else if (saved1) {
            ans += set2.getOrDefault(s, 0);
            ans += set12.getOrDefault(s, 0);
        } else if (saved2) {
            ans += set1.getOrDefault(s, 0);
            ans += set12.getOrDefault(s, 0);
        } else {
            ans += set12.getOrDefault(s, 0);
        }

        if (s.contains("."))
            ans += parse(s.substring(s.indexOf(".") + 1), false, saved2, a + 1, b);
        if (s.contains("/"))
            ans += parse(s.substring(0, s.lastIndexOf("/")), saved1, false, a, b + 1);

        return ans;
    }

    public void solve() {
        set12 = new HashMap<>();
        set1 = new HashMap<>();
        set2 = new HashMap<>();
        set = new HashMap<>();
        used = new boolean[6][6];

        n = in.nextInt();
        p = in.nextInt();

        for (int i = 0; i < n; i++) {
            String template = in.next();
            if (template.startsWith("*.") && template.endsWith("/*")) {
                template = template.substring(2, template.length() - 2);
                set12.put(template, set12.getOrDefault(template, 0) + 1);
            } else if (template.startsWith("*.")) {
                template = template.substring(2);
                set1.put(template, set1.getOrDefault(template, 0) + 1);
            } else if (template.endsWith("/*")) {
                template = template.substring(0, template.length() - 2);
                set2.put(template, set2.getOrDefault(template, 0) + 1);
            } else {
                set.put(template, set.getOrDefault(template, 0) + 1);
            }
        }

        k = in.nextInt();
        for (int i = 0; i < k; i++) {
            for (int z = 0; z < 6; z++) {
                for (int s = 0; s < 6; s++) {
                    used[z][s] = false;
                }
            }
            out.println(parse(in.next(), true, true, 0, 0));
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
