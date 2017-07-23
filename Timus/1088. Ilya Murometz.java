// The solution of the problem was written by Izaron
// Date: 23:28:30   21 Aug 2016
// Execution time: 0.124

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
        int D = in.nextInt();
        int E = in.nextInt();
        int F = in.nextInt();
        int Dp = in.nextInt() - 1;
        int Ep = in.nextInt() - 1;
        int H = in.nextInt();

        int a = 0, b = (1 << F) - 1;
        ArrayList<PairInt> list1 = new ArrayList<>();
        list1.add(new PairInt(a, b));
        while (a != b) {
            if (Ep <= (a + b) / 2) {
                b = (a + b) / 2;
            } else {
                a = (a + b) / 2 + 1;
            }
            list1.add(new PairInt(a, b));
        }
        TreeSet<PairInt> set = new TreeSet<>();
        for (int i = list1.size() - 1 - E; i >= 0; i--)
            set.add(list1.get(i));

        a = 0; b = (1 << F) - 1;
        ArrayList<PairInt> list2 = new ArrayList<>();
        list2.add(new PairInt(a, b));
        while (a != b) {
            if (Dp <= (a + b) / 2) {
                b = (a + b) / 2;
            } else {
                a = (a + b) / 2 + 1;
            }
            list2.add(new PairInt(a, b));
        }
        int timer = 0;
        PairInt lel = null;
        for (int i = list2.size() - 1 - D; i >= 0; i--) {
            if (set.contains(list2.get(i))) {
                timer = (list2.size() - 1 - D) - i;
                lel = list2.get(i);
                break;
            }
        }

        for (int i = list1.size() - 1 - E; i >= 0; i--) {
            if (list1.get(i).equals(lel)) {
                break;
            }
            timer++;
        }

        //out.println(timer);
        if (timer <= H)
            out.print("YES");
        else
            out.print("NO");
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