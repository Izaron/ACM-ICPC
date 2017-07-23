import java.io.*;
import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.CollationElementIterator;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    class State {
        State next;
        State back;
        int program;

        public State() {
            program = 0;
            next = null;
            back = null;
        }
    }

    public void solve() {
        int n = in.nextInt(), m = in.nextInt();

        ArrayList<State> list = new ArrayList<>();
        list.add(new State());

        for (int i = 0; i < n; i++) {
            String com = in.next();
            int index = in.nextInt() - 1;
            State clone = list.get(index);

            if (com.equals("learn")) {
                int prog = in.nextInt();
                State nclone = new State();
                State nnext = new State();

                nclone.program = clone.program;
                nclone.next = nnext;
                nclone.back = clone.back;

                nnext.program = prog;
                nnext.next = null;
                nnext.back = nclone;

                list.set(index, nnext);
            } else if (com.equals("rollback")) {
                State nclone = new State();
                State nback = new State();

                nclone.program = clone.program;
                nclone.next = clone.next;
                //nclone.back = nback;

                nback.program = clone.back.program;
                nback.next = nclone;
                nback.back = clone.back.back;

                nclone.back = nback;

                list.set(index, nback);
            } else if (com.equals("relearn")) {
                State nclone = new State();
                State nnext = new State();

                nclone.program = clone.program;
                //nclone.next = clone.next;
                nclone.back = clone.back;

                nnext.program = clone.next.program;
                nnext.next = clone.next.next;
                nnext.back = nclone;

                nclone.next = clone.next;

                list.set(index, nnext);
            } else if (com.endsWith("clone")) {
                State nclone = new State();
                nclone.program = clone.program;
                nclone.back = clone.back;
                nclone.next = clone.next;

                list.add(nclone);
            } else if (com.equals("check")) {
                if (clone.program == 0)
                    out.println("basic");
                else
                    out.println(clone.program);
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