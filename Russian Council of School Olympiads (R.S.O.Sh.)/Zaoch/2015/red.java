import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int n, m, d, q;

    ArrayList<Pair<Integer, Integer>> defolt[];
    TreeSet<Pair<Integer, Integer>> list[];
    ArrayList<Pair<Pair<Integer, Integer>, Integer>> dek;
    ArrayList<Pair<Integer, Integer>> erased;


    void addNext(int curr) {
        int temp = dek.get(curr).a.a;
        int to = dek.get(curr).a.b;
        int time = dek.get(curr).b;

        erased.clear();

        Pair<Integer, Integer> pair = new Pair<>(temp - d, -1);
        while (true) {
            pair = list[to].higher(pair);
            if (pair == null)
                break;
            if (abs(pair.a - temp) > d)
                break;
            dek.add(new Pair<>(pair, time + 1));
            erased.add(pair);
        }

        for (Pair<Integer, Integer> p : erased)
            list[to].remove(p);
    }

    int work(int a, int b) {
        for (int i = 0; i < n; i++) {
            list[i].clear();
            for (int z = 0; z < defolt[i].size(); z++)
                list[i].add(defolt[i].get(z));
        }
        dek.clear();

        for (Pair<Integer, Integer> pair : list[a])
            dek.add(new Pair<>(pair, 1));
        list[a].clear();

        int curr = 0;
        while (true) {
            if (curr >= dek.size())
                return -1;
            if (dek.get(curr).a.b == b)
                return dek.get(curr).b;
            addNext(curr);
            curr++;
        }
    }

    public void solve() {
        n = in.nextInt();
        m = in.nextInt();
        d = in.nextInt();
        defolt = new ArrayList[n];
        list = new TreeSet[n];
        dek = new ArrayList<>();
        erased = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            defolt[i] = new ArrayList<>();
            list[i] = new TreeSet<>();
        }

        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1, t = in.nextInt();
            defolt[a].add(new Pair<>(t, b));
            defolt[b].add(new Pair<>(t, a));
        }

        q = in.nextInt();
        for (int i = 0; i < q; i++)
            out.println(work(in.nextInt() - 1, in.nextInt() - 1));
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