import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "game";

    long n, k, ans = 0;
    TreeSet<Long> unique = new TreeSet<>();
    TreeMap<Long, Integer> uniqueIndex = new TreeMap<>();
    TreeSet<Long> nonUnique = new TreeSet<>();
    TreeMap<Long, Integer> nonUniqueIndex = new TreeMap<>();
    TreeSet<Long> triples = new TreeSet<>();

    public void solve() {
        n = in.nextLong();
        k = in.nextLong();

        for (int i = 0; i < n; i++) {
            long it = in.nextLong();
            if (unique.contains(it)) {
                if (nonUnique.contains(it))
                    triples.add(it);
                else
                    nonUnique.add(it);
            } else
                unique.add(it);
        }

        int curr = 1;
        for (Long it : unique)
            uniqueIndex.put(it, curr++);
        curr = 1;
        for (Long it : nonUnique)
            nonUniqueIndex.put(it, curr++);

        for (Long it : unique) {
            long a = it;
            long numHigher = uniqueIndex.get(unique.lower(a * k + 1));
            long numLower = uniqueIndex.get(a);
            long cnt = numHigher - numLower;
            ans += cnt * (cnt - 1) / 2 * 6;
        }

        if (nonUnique.size() != 0) {
            for (Long it : unique) {
                long a = it;

                long numHigher = 0;
                if (a * k >= nonUnique.first())
                    numHigher = nonUniqueIndex.get(nonUnique.lower(a * k + 1));

                long numLower = 0;
                if (a >= nonUnique.first())
                    numLower = nonUniqueIndex.get(nonUnique.lower(a + 1));

                long cnt = numHigher - numLower;

                ans += cnt * 3;
            }

            for (Long it : nonUnique) {
                long a = it;

                long numHigher = 0;
                if (a * k >= unique.first())
                    numHigher = uniqueIndex.get(unique.lower(a * k + 1));

                long numLower = 0;
                if (a >= unique.first())
                    numLower = uniqueIndex.get(unique.lower(a + 1));

                long cnt = numHigher - numLower;

                ans += cnt * 3;
            }
        }

        ans += triples.size();

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