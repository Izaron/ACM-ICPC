import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static final String FILE = "building";

    FastScanner in;
    PrintWriter out;
    PrintWriter cerr;

    long n, k, x, y;

    boolean can(long et, long kvar) {
        long osob = et / k;
        long pod = osob * x + (et - osob) * y;
        return pod >= kvar;
    }

    void solve() {
        n = in.nextLong();
        k = in.nextLong();
        x = in.nextLong();
        y = in.nextLong();

        long osob = n / k;
        long pod = osob * x + (n - osob) * y;

        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            long a = in.nextLong();
            a--;
            a %= pod;
            a++;

            long l = 0, r = n;
            while (l != r) {
                long la = l, lb = r;
                long mid = (l + r) / 2;
                if (can(mid, a))
                    r = mid;
                else
                    l = mid;
                if (la == l && lb == r) {
                    if (can(l, a))
                        r = l;
                    else
                        l = r;
                }
            }

            out.println(l);
        }
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