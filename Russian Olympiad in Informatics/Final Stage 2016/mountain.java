import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {

    PrintWriter out;
    FastScanner in;

    String FILE = "mountain";

    int n, q;
    int posX[];
    int posY[];
    double leftMaxK[];
    double rightMaxK[];

    boolean canLeft(int v, int to, double x1, double y1) {
        double x0 = posX[v];
        double y0 = posY[v];
        double d = x1 - x0;
        double k = (y1 - y0) / d;

        if (k == Double.POSITIVE_INFINITY)
            return true;

        for (int i = v + 1; i <= to; i++) {
            double nx = posX[i];
            double nd = nx - x0;
            double ny = y0 + k * nd;

            if (nx == x1) {
                return (y1 >= (double)(posY[i]));
            }

            if (ny < (double)posY[i])
                return false;
        }
        return true;
    }

    boolean canRight(int v, int to, double x1, double y1) {
        double x0 = posX[to];
        double y0 = posY[to];
        double d = x1 - x0;
        double k = (y1 - y0) / d;

        if (k == Double.POSITIVE_INFINITY)
            return true;

        for (int i = to - 1; i >= v; i--) {
            double nx = posX[i];
            double nd = nx - x0;
            double ny = y0 + k * nd;

            if (nx == x1) {
                return (y1 >= (double)(posY[i]));
            }

            if (ny < (double)posY[i])
                return false;
        }
        return true;
    }

    void solveVer() {
        int x = in.nextInt();
        int y = in.nextInt();
        double x1 = x;
        double y1 = y;

        int left = n, right = 0;

        for (; left >= 0; left--) {
            if (posX[left] <= x)
                break;
        }

        for (; right <= n; right++) {
            if (posX[right] >= x)
                break;
        }



        int tarL = left;
        double maxK = Double.POSITIVE_INFINITY;
        for (int i = left; i >= 0; i--) {
            double x0 = posX[i];
            double y0 = posY[i];
            double d = x1 - x0;
            double currK = (y1 - y0) / d;
            if (currK <= maxK) {
                tarL = i;
                maxK = currK;
            } else {
                break;
            }
        }

        int tarR = right;
        maxK = Double.NEGATIVE_INFINITY;
        for (int i = right; i <= n; i++) {
            double x0 = posX[i];
            double y0 = posY[i];
            double d = x0 - x1;
            double currK = (y0 - y1) / d;
            if (currK >= maxK) {
                maxK = currK;
                tarR = i;
            } else {
                break;
            }
        }

        out.print(posX[tarL]);
        out.print(" ");
        out.print(posX[tarR]);
        out.println();
    }

    void solveBrute() {
        for (int i = 0; i < q; i++) {
            solveVer();
        }
    }

    void solveCool() {
        int x = in.nextInt();
        int y = in.nextInt();
        double x1 = x;
        double y1 = y;

        int left = n, right = 0;

        for (; left >= 0; left--) {
            if (posX[left] <= x)
                break;
        }

        for (; right <= n; right++) {
            if (posX[right] >= x)
                break;
        }



        int tarL = left;
        double maxK = Double.POSITIVE_INFINITY;
        for (int i = left; i >= 0; i--) {
            double x0 = posX[i];
            double y0 = posY[i];
            double d = x1 - x0;
            double currK = (y1 - y0) / d;
            if (currK <= maxK) {
                tarL = i;
                maxK = currK;
            } else {
                break;
            }
        }

        int tarR = right;
        maxK = Double.NEGATIVE_INFINITY;
        for (int i = right; i <= n; i++) {
            double x0 = posX[i];
            double y0 = posY[i];
            double d = x0 - x1;
            double currK = (y0 - y1) / d;
            if (currK >= maxK) {
                maxK = currK;
                tarR = i;
            } else {
                break;
            }
        }

        for (int i = 0; i < q; i++) {
            out.print(posX[tarL]);
            out.print(" ");
            out.print(posX[tarR]);
            out.println();
        }
    }

    public void solve() {
        n = in.nextInt();
        q = in.nextInt();

        posX = new int[n + 1];
        posY = new int[n + 1];

        leftMaxK = new double[n + 1];
        rightMaxK = new double[n + 1];

        posX[0] = 0;
        posY[0] = 0;

        for (int i = 1; i <= n; i++) {
            int d = in.nextInt(), k = in.nextInt();
            posX[i] = posX[i - 1] + d;
            posY[i] = posY[i - 1] + k * d;
        }

        if (n <= 3000 && q <= 3000) {
            solveBrute();
        } else {
            solveCool();
        }
    }

    public void run() {
        if (!FILE.isEmpty()) {
            try {
                in = new FastScanner(new FileReader(FILE + ".in"));
                out = new PrintWriter(FILE + ".out");
            } catch (IOException e) {
                e.printStackTrace();
                System.exit(1);
            }
        } else {
            in = new FastScanner(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        }

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer in;

        public FastScanner(Reader reader) {
            br = new BufferedReader(reader);
        }

        public String next() {
            while (in == null || !in.hasMoreTokens()) {
                try {
                    in = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return in.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        new Main().run();
    }

}