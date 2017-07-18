import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "alarm";

    int n;
    boolean can[][];
    int power[];
    int biggest[];
    ArrayList<PairInt> neig[];
    ArrayList<Integer> component[];
    int root;
    boolean used[];

    void dfsComponent(int v) {
        if (used[v])
            return;
        used[v] = true;

        for (Integer it : component[v]) {
            dfsComponent(it);
        }
    }

    void dfs(int v, int d) {
        if (d < 0)
            return;
        can[root][v] = true;
        d = max(d, power[v]);
        if (biggest[v] >= d)
            return;
        biggest[v] = d;

        for (PairInt pair : neig[v]) {
            dfs(pair.a, d - pair.b);
        }
    }

    public void solve() {
        n = in.nextInt();
        can = new boolean[n][n];
        power = new int[n];
        biggest = new int[n];
        neig = new ArrayList[n];
        component = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            neig[i] = new ArrayList<>();
            component[i] = new ArrayList<>();
        }
        used = new boolean[n];

        for (int i = 0; i < n; i++)
            power[i] = in.nextInt();

        for (int i = 0; i < n - 1; i++) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1, len = in.nextInt();
            neig[a].add(new PairInt(b, len));
            neig[b].add(new PairInt(a, len));
        }

        for (int i = 0; i < n; i++) {
            Arrays.fill(biggest, 0);
            root = i;
            dfs(root, 0);
        }

        for (int i = 0; i < n; i++) {
            boolean weak = false;
            for (int z = 0; z < n; z++) {
                if (i == z)
                    continue;
                if (can[z][i] && !can[i][z]) {
                    weak = true;
                    break;
                }
            }

            if (weak)
                continue;

            for (int z = 0; z < n; z++) {
                if (z == i)
                    continue;
                if (can[z][i] && can[i][z]) {
                    component[i].add(z);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;

            boolean weak = false;
            for (int z = 0; z < n; z++) {
                if (can[z][i] && !can[i][z]) {
                    weak = true;
                    break;
                }
            }

            if (weak)
                continue;

            ans++;
            dfsComponent(i);
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