import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int a, b;
    int n;
    ArrayList<PairInt> list[];

    public void solve() {
        a = in.nextInt();
        b = in.nextInt();
        n = in.nextInt();
        list = new ArrayList[n];
        for (int i = 0; i < n; i++)
            list[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int l = in.nextInt();
            for (int z = 0; z < l + 1; z++)
                list[i].add(new PairInt(in.nextInt(), in.nextInt()));
        }

        boolean men = false, bol = false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                men = false;
                bol = false;
                for (int aa = 0; aa < list[i].size() - 1; aa++) {
                    for (int bb = 0; bb < list[j].size() - 1; bb++) {
                        if (list[i].get(aa + 1).a <= list[j].get(bb).a) {
                            continue;
                        }
                        if (list[i].get(aa).a >= list[j].get(bb + 1).a) {
                            continue;
                        }

                        int minX = max(list[i].get(aa).a, list[j].get(bb).a);
                        int maxX = min(list[i].get(aa + 1).a, list[j].get(bb + 1).a);

                        double h, l1, l2, aY1, aY2, bY1, bY2;

                        // GET A Y1
                        h = list[i].get(aa + 1).b - list[i].get(aa).b;
                        l1 = list[i].get(aa + 1).a - list[i].get(aa).a;
                        l2 = minX - list[i].get(aa).a;
                        aY1 = h * l2 / l1 + list[i].get(aa).b;

                        // GET A Y2
                        h = list[i].get(aa + 1).b - list[i].get(aa).b;
                        l1 = list[i].get(aa + 1).a - list[i].get(aa).a;
                        l2 = maxX - list[i].get(aa).a;
                        aY2 = h * l2 / l1 + list[i].get(aa).b;

                        // GET B Y1
                        h = list[j].get(bb + 1).b - list[j].get(bb).b;
                        l1 = list[j].get(bb + 1).a - list[j].get(bb).a;
                        l2 = minX - list[j].get(bb).a;
                        bY1 = h * l2 / l1 + list[j].get(bb).b;

                        // GET B Y2
                        h = list[j].get(bb + 1).b - list[j].get(bb).b;
                        l1 = list[j].get(bb + 1).a - list[j].get(bb).a;
                        l2 = maxX - list[j].get(bb).a;
                        bY2 = h * l2 / l1 + list[j].get(bb).b;

                        if (aY1 < bY1 && aY2 <= bY2) {
                            men = true;
                        }
                        if (aY1 <= bY1 && aY2 < bY2) {
                            men = true;
                        }
                        if (aY1 > bY1 && aY2 >= bY2) {
                            bol = true;
                        }
                        if (aY1 >= bY1 && aY2 > bY2) {
                            bol = true;
                        }

                        if (aY1 <= bY1 && aY2 <= bY2) {

                        } else if (aY1 >= bY1 && aY2 >= bY2) {

                        } else {
                            out.println("No");
                            out.print((i + 1) + " " + (j + 1));
                            return;
                        }

                        if (bol && men) {
                            out.println("No");
                            out.print((i + 1) + " " + (j + 1));
                            return;
                        }
                    }
                }
            }
        }

        out.print("Yes");
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