// The solution of the problem was written by Izaron
// Date: 19:32:36   21 Aug 2016
// Execution time: 0.514

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    class Lca {
        int[] depth;
        int[] dfs_order;
        int cnt;
        int[] first;
        int[] minPos;
        int n;

        void dfs(List<Integer>[] tree, int u, int d) {
            depth[u] = d;
            dfs_order[cnt++] = u;
            for (int v : tree[u])
                if (depth[v] == -1) {
                    dfs(tree, v, d + 1);
                    dfs_order[cnt++] = u;
                }
        }

        void buildTree(int node, int left, int right) {
            if (left == right) {
                minPos[node] = dfs_order[left];
                return;
            }
            int mid = (left + right) >> 1;
            buildTree(2 * node + 1, left, mid);
            buildTree(2 * node + 2, mid + 1, right);
            minPos[node] = depth[minPos[2 * node + 1]] < depth[minPos[2 * node + 2]] ? minPos[2 * node + 1] : minPos[2 * node + 2];
        }

        public Lca(List<Integer>[] tree, int root) {
            int nodes = tree.length;
            depth = new int[nodes];
            Arrays.fill(depth, -1);

            n = 2 * nodes - 1;
            dfs_order = new int[n];
            cnt = 0;
            dfs(tree, root, 0);

            minPos = new int[4 * n];
            buildTree(0, 0, n - 1);

            first = new int[nodes];
            Arrays.fill(first, -1);
            for (int i = 0; i < dfs_order.length; i++)
                if (first[dfs_order[i]] == -1)
                    first[dfs_order[i]] = i;
        }

        public int lca(int a, int b) {
            return minPos(Math.min(first[a], first[b]), Math.max(first[a], first[b]), 0, 0, n - 1);
        }

        int minPos(int a, int b, int node, int left, int right) {
            if (a == left && right == b)
                return minPos[node];
            int mid = (left + right) >> 1;
            if (a <= mid && b > mid) {
                int p1 = minPos(a, Math.min(b, mid), 2 * node + 1, left, mid);
                int p2 = minPos(Math.max(a, mid + 1), b, 2 * node + 2, mid + 1, right);
                return depth[p1] < depth[p2] ? p1 : p2;
            } else if (a <= mid) {
                return minPos(a, Math.min(b, mid), 2 * node + 1, left, mid);
            } else if (b > mid) {
                return minPos(Math.max(a, mid + 1), b, 2 * node + 2, mid + 1, right);
            } else {
                throw new RuntimeException();
            }
        }
    }

    Map<Integer, Integer> map;
    int n;

    int get(int v) {
        if (v == -1)
            return -1;
        if (!map.containsKey(v))
            map.put(v, map.size());
        return map.get(v);
    }

    public void solve() {
        map = new TreeMap<>();
        n = in.nextInt();
        List<Integer>[] tree = new List[n];
        for (int i = 0; i < n; i++)
            tree[i] = new ArrayList<>();
        int root = -1;
        for (int i = 0; i < n; i++) {
            int a = get(in.nextInt()), b = get(in.nextInt());
            if (b == -1) {
                root = a;
            } else {
                tree[a].add(b);
                tree[b].add(a);
            }
        }

        Lca lca = new Lca(tree, root);
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int a = get(in.nextInt()), b = get(in.nextInt());
            int parent = lca.lca(a, b);
            if (a == parent)
                out.println(1);
            else if (b == parent)
                out.println(2);
            else
                out.println(0);
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