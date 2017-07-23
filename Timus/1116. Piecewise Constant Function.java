import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int get(int v) {
        return v + 32001;
    }

    int unget(int v) {
        return v - 32001;
    }

    public void solve() {
        int[] ms1 = new int[32000 * 2 + 5];
        int[] ms2 = new int[32000 * 2 + 5];
        int[] ms3 = new int[32000 * 2 + 5];
        Arrays.fill(ms1, Integer.MAX_VALUE);
        Arrays.fill(ms2, Integer.MAX_VALUE);
        Arrays.fill(ms3, Integer.MAX_VALUE);

        int k1 = in.nextInt();
        for (int i = 0; i < k1; i++) {
            int a = get(in.nextInt()), b = get(in.nextInt()), c = in.nextInt();
            for (int z = a; z < b; z++)
                ms1[z] = c;
        }

        int k2 = in.nextInt();
        for (int i = 0; i < k2; i++) {
            int a = get(in.nextInt()), b = get(in.nextInt()), c = in.nextInt();
            for (int z = a; z < b; z++)
                ms2[z] = c;
        }

        for (int i = 0; i < ms3.length; i++) {
            if (ms1[i] != Integer.MAX_VALUE && ms2[i] == Integer.MAX_VALUE)
                ms3[i] = ms1[i];
        }

        int cur = Integer.MAX_VALUE;
        int st = 0;
        List<Integer> starts = new ArrayList<>();
        List<Integer> ends = new ArrayList<>();
        List<Integer> vals = new ArrayList<>();
        for (int i = 0; i < ms3.length; i++) {
            if (ms3[i] != cur) {
                starts.add(st);
                ends.add(i);
                vals.add(cur);
                st = i;
                cur = ms3[i];
            }
        }


        List<Integer> rStarts = new ArrayList<>();
        List<Integer> rEnds = new ArrayList<>();
        List<Integer> rVals = new ArrayList<>();
        for (int i = 0; i < starts.size(); i++) {
            if (vals.get(i) != Integer.MAX_VALUE) {
                rStarts.add(starts.get(i));
                rEnds.add(ends.get(i));
                rVals.add(vals.get(i));
            }
        }

        out.print(rStarts.size() + " ");
        for (int i = 0; i < rStarts.size(); i++)
            out.print(unget(rStarts.get(i)) + " " + unget(rEnds.get(i)) + " " + rVals.get(i) + " ");
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