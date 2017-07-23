import java.io.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.BiConsumer;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    static class HeavyLight {

        int getNeutralValue() {
            return 0;
        }

        final List<Integer>[] tree;
        final boolean valuesOnVertices; // true - values on vertices, false - values on edges
        final SegmentTree segmentTree;
        final int[] parent;
        final int[] heavy;
        final int[] depth;
        final int[] pathRoot;
        final int[] pos;

        public HeavyLight(List<Integer>[] tree, boolean valuesOnVertices) {
            this.tree = tree;
            this.valuesOnVertices = valuesOnVertices;
            int n = tree.length;
            segmentTree = new SegmentTree(n);

            parent = new int[n];
            heavy = new int[n];
            depth = new int[n];
            pathRoot = new int[n];
            pos = new int[n];

            Arrays.fill(heavy, -1);
            parent[0] = -1;
            depth[0] = 0;
            dfs(0);
            for (int u = 0, p = 0; u < n; u++) {
                if (parent[u] == -1 || heavy[parent[u]] != u) {
                    for (int v = u; v != -1; v = heavy[v]) {
                        pathRoot[v] = u;
                        pos[v] = p++;
                    }
                }
            }
        }

        int dfs(int u) {
            int size = 1;
            int maxSubtree = 0;
            for (int v : tree[u]) {
                if (v != parent[u]) {
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    int subtree = dfs(v);
                    if (maxSubtree < subtree) {
                        maxSubtree = subtree;
                        heavy[u] = v;
                    }
                    size += subtree;
                }
            }
            return size;
        }

        public int query(int u, int v) {
            AtomicInteger res = new AtomicInteger(getNeutralValue()); // just mutable integer
            processPath(u, v, (a, b) -> res.set(segmentTree.queryOperation(res.get(), segmentTree.query(a, b))));
            return res.get();
        }

        public void modify(int u, int v, int delta) {
            processPath(u, v, (a, b) -> segmentTree.modify(a, b, delta));
        }

        void processPath(int u, int v, BiConsumer<Integer, Integer> op) {
            for (; pathRoot[u] != pathRoot[v]; v = parent[pathRoot[v]]) {
                if (depth[pathRoot[u]] > depth[pathRoot[v]]) {
                    int t = u;
                    u = v;
                    v = t;
                }
                op.accept(pos[pathRoot[v]], pos[v]);
            }
            if (!valuesOnVertices && u == v) return;
            op.accept(Math.min(pos[u], pos[v]) + (valuesOnVertices ? 0 : 1), Math.max(pos[u], pos[v]));
        }

        static class SegmentTree {
            int modifyOperation(int x, int y) {
                return x + y;
            }

            int queryOperation(int leftValue, int rightValue) {
                return max(leftValue, rightValue);
            }

            int deltaEffectOnSegment(int delta, int segmentLength) {
                if (delta == getNeutralDelta()) return getNeutralDelta();
                return delta * segmentLength;
            }

            int getNeutralDelta() {
                return 0;
            }

            int getInitValue() {
                return 0;
            }

            // generic code
            int[] value;
            int[] delta; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]

            int joinValueWithDelta(int value, int delta) {
                if (delta == getNeutralDelta()) return value;
                return modifyOperation(value, delta);
            }

            int joinDeltas(int delta1, int delta2) {
                if (delta1 == getNeutralDelta()) return delta2;
                if (delta2 == getNeutralDelta()) return delta1;
                return modifyOperation(delta1, delta2);
            }

            void pushDelta(int i) {
                int d = 0;
                for (; (i >> d) > 0; d++) {
                }
                for (d -= 2; d >= 0; d--) {
                    int x = i >> d;
                    value[x >> 1] = joinNodeValueWithDelta(x >> 1, 1 << (d + 1));
                    delta[x] = joinDeltas(delta[x], delta[x >> 1]);
                    delta[x ^ 1] = joinDeltas(delta[x ^ 1], delta[x >> 1]);
                    delta[x >> 1] = getNeutralDelta();
                }
            }

            public SegmentTree(int n) {
                value = new int[2 * n];
                for (int i = 0; i < n; i++) {
                    value[i + n] = getInitValue();
                }
                for (int i = 2 * n - 1; i > 1; i -= 2) {
                    value[i >> 1] = queryOperation(value[i], value[i ^ 1]);
                }
                delta = new int[2 * n];
                Arrays.fill(delta, getNeutralDelta());
            }

            int joinNodeValueWithDelta(int i, int len) {
                return joinValueWithDelta(value[i], deltaEffectOnSegment(delta[i], len));
            }

            public int query(int from, int to) {
                from += value.length >> 1;
                to += value.length >> 1;
                pushDelta(from);
                pushDelta(to);
                int res = 0;
                boolean found = false;
                for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
                    if ((from & 1) != 0) {
                        res = found ? queryOperation(res, joinNodeValueWithDelta(from, len)) : joinNodeValueWithDelta(from, len);
                        found = true;
                    }
                    if ((to & 1) == 0) {
                        res = found ? queryOperation(res, joinNodeValueWithDelta(to, len)) : joinNodeValueWithDelta(to, len);
                        found = true;
                    }
                }
                if (!found) throw new RuntimeException();
                return res;
            }

            public void modify(int from, int to, int delta) {
                from += value.length >> 1;
                to += value.length >> 1;
                pushDelta(from);
                pushDelta(to);
                int a = from;
                int b = to;
                for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
                    if ((from & 1) != 0) {
                        this.delta[from] = joinDeltas(this.delta[from], delta);
                    }
                    if ((to & 1) == 0) {
                        this.delta[to] = joinDeltas(this.delta[to], delta);
                    }
                }
                for (int i = a, len = 1; i > 1; i >>= 1, len <<= 1) {
                    value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
                }
                for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
                    value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
                }
            }
        }
    }

    public void solve() {
        int n = in.nextInt();
        List<Integer>[] tree = new List[n];
        for (int i = 0; i < n; i++)
            tree[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            tree[a].add(b);
            tree[b].add(a);
        }
        HeavyLight heavyLight = new HeavyLight(tree, true);
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            char c = in.next().charAt(0);
            if (c == 'I') {
                int v = in.nextInt() - 1, plus = in.nextInt();
                heavyLight.modify(v, v, plus);
            } else {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                out.println(heavyLight.query(a, b));
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