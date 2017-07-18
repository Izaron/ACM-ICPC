import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {

    FastScanner in;
    PrintWriter out;

    static final String FILE = "video";

    int n, m;
    int ms[][];

    int getMs(int a, int b) {
        if (a >= n)
            a %= n;
        if (b >= m)
            b %= m;
        while (a < 0)
            a += n;
        while (b < 0)
            b += m;

        return ms[a][b];
    }

    int getRealA(int a) {
        if (a >= n)
            a %= n;
        while (a < 0)
            a += n;
        return a;
    }

    int getRealB(int b) {
        if (b >= m)
            b %= m;
        while (b < 0)
            b += m;
        return b;
    }

    void solve() {
        n = in.nextInt();
        m = in.nextInt();
        ms = new int[n][m];
        int fail[][] = new int[n][m];
        int zakA[] = new int[n];
        int zakB[] = new int[m];
        int alls[][] = new int[n][m];

        for (int i = 0; i < n; i++) {
            String s = in.next();
            for (int z = 0; z < m; z++) {
                ms[i][z] = s.charAt(z) - '0';
            }
        }

        int all = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            for (int z = 0; z < m; z++) {
                int a1 = i, a2 = getRealA(i + 1);
                int b1 = z, b2 = getRealB(z + 1);

                if (getMs(a1, b1) == getMs(a1, b2) && getMs(a1, b1) == getMs(a2, b1) &&
                        getMs(a1, b1) == getMs(a2, b2)) {
                    all++;
                    fail[a2][b1]++;
                    fail[a1][b2]++;
                    fail[a2][b2]++;
                    zakA[a1]++;
                    zakB[b1]++;
                    alls[a1][b1]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int z = 0; z < m; z++) {
                int zaka = getRealA(i + n - 1);
                int zakb = getRealB(z + m - 1);
                ans = max(ans, all - zakA[zaka] - zakB[zakb] + alls[zaka][zakb]);
            }
        }

        out.print(ans);
    }

    void run() {
        if (FILE.isEmpty()) {
            in = new FastScanner(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        } else {
            try {
                in = new FastScanner(new FileReader(FILE + ".in"));
                out = new PrintWriter(new FileWriter(FILE + ".out"));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {
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

        public FastScanner(Reader reader) {
            br = new BufferedReader(reader);
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
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

    class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
        A a;
        B b;

        public Pair(A a, B b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair<?, ?> pair = (Pair<?, ?>) o;

            if (a != null ? !a.equals(pair.a) : pair.a != null) return false;
            return b != null ? b.equals(pair.b) : pair.b == null;

        }

        @Override
        public int compareTo(Pair<A, B> o) {
            int cmp = a.compareTo(o.a);
            if (cmp == 0)
                return b.compareTo(o.b);
            return cmp;
        }
    }
}