import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {

    public static final String FILE = "data";

    FastScanner in;
    PrintWriter out;
    PrintWriter cerr;

    int n, m;
    ArrayList<Integer> neig[];
    TreeSet<Integer> bad[];
    boolean[] used;
    int[] tin;
    int[] fup;
    int timer;

    void dfs(int v, int p) {
        used[v] = true;
        tin[v] = timer;
        fup[v] = timer++;
        for (int i = 0; i < neig[v].size(); i++) {
            int to = neig[v].get(i);
            if (to == p)
                continue;
            if (used[to])
                fup[v] = min(fup[v], tin[to]);
            else {
                dfs(to, v);
                fup[v] = min(fup[v], fup[to]);
                if (fup[to] > tin[v]) {
                    bad[to].add(v);
                    bad[v].add(to);
                }
            }
        }
    }

    int cutCount;
    long count;

    void dfsCut(int v) {
        used[v] = true;
        count++;
        for (Integer to : neig[v]) {
            if (bad[v].contains(to)) {
                cutCount++;
                continue;
            } else if (used[to]) {
                continue;
            } else {
                dfsCut(to);
            }
        }
    }

    void solve() {
        n = in.nextInt();
        m = in.nextInt();

        neig = new ArrayList[n];
        for (int i = 0; i < n; i++)
            neig[i] = new ArrayList<Integer>();

        bad = new TreeSet[n];
        for (int i = 0; i < n; i++)
            bad[i] = new TreeSet<Integer>();

        used = new boolean[n];
        tin = new int[n];
        fup = new int[n];

        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            neig[a].add(b);
            neig[b].add(a);
        }

        dfs(0, 0);

        Arrays.fill(used, false);

        long cnt = 0, ans = 1;
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            cutCount = 0;
            count = 0;
            dfsCut(i);
            if (cutCount <= 1) {
                cnt++;
                ans *= count;
                ans %= (long)(1e9 + 7);
            }
        }

        out.println(cnt + " " + ans);
    }

    void run() {
        cerr = new PrintWriter(System.err);
        if (FILE.isEmpty()) {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);
        } else {
            try {
                in = new FastScanner(new FileInputStream(FILE + ".in"));
                out = new PrintWriter(FILE + ".out");
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
        solve();
        out.close();
        cerr.close();
    }

    public static void main(String[] args) {
        (new Main()).run();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String next() {
            while (st == null || !st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}