// The solution of the problem was written by Izaron
// Date: 00:11:14   22 Aug 2016
// Execution time: 0.14

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    String[] turn = new String[3];

    int readMask() {
        String s = in.next() + in.next() + in.next() + in.next();
        int mask = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'B')
                //mask |= (1 << (s.length() - 1 - i));
                mask |= (1 << i);
        }
        return mask;
    }

    void readTurn() {
        for (int i = 0; i < 3; i++)
            turn[i] = in.next();
    }

    int getPos(int a, int b) {
        return a * 4 + b;
    }

    boolean isCorrectPos(int a, int b) {
        return min(a, b) >= 0 && max(a, b) < 4;
    }

    int calcXor(int a, int b) {
        int xor = 0;
        for (int i = a - 1, c1 = 0; i <= a + 1; i++, c1++) {
            for (int z = b - 1, c2 = 0; z <= b + 1; z++, c2++) {
                if (!isCorrectPos(i, z))
                    continue;
                if (turn[c1].charAt(c2) == '0')
                    continue;
                xor |= (1 << getPos(i, z));
            }
        }
        return xor;
    }

    void print(int a, int b) {
        out.println("TURN:");
        for (int i = 0; i < 4; i++) {
            for (int z = 0; z < 4; z++) {
                int pos = i * 4 + z;
                if ((a & (1 << pos)) != 0)
                    out.print('B');
                else
                    out.print('W');
            }
            out.print(' ');
            for (int z = 0; z < 4; z++) {
                int pos = i * 4 + z;
                if ((b & (1 << pos)) != 0)
                    out.print('B');
                else
                    out.print('W');
            }
            out.println();
        }
        out.println();
    }

    public void solve() {
        Queue<Integer> maskQueue = new ArrayDeque<>();
        Queue<Integer> lenQueue = new ArrayDeque<>();
        boolean[] used = new boolean[(1 << 16)];
        int mask = readMask();
        readTurn();
        int[] xors = new int[16];
        for (int i = 0; i < 16; i++)
            xors[i] = calcXor(i / 4, i % 4);

        used[mask] = true;
        maskQueue.add(mask);
        lenQueue.add(0);

        while (!maskQueue.isEmpty()) {
            int msk = maskQueue.remove();
            int len = lenQueue.remove();
            int bits = Integer.bitCount(msk);
            if (bits == 0 || bits == 16) {
                out.print(len);
                return;
            }
            for (int i = 0; i < 16; i++) {
                int nmask = msk ^ xors[i];
                if (used[nmask])
                    continue;
                used[nmask] = true;
                maskQueue.add(nmask);
                lenQueue.add(len + 1);
                //print(msk, nmask);
                //out.flush();
            }
        }

        out.print("Impossible");
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