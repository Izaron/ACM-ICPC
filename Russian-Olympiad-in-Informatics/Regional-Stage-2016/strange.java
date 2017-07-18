import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "strange";

    String s;
    int n;
    int alphabet = 26;
    ArrayList<PairLong> list[][];
    int ones[];
    long ans = 0;

    long getOrDefault(long val, TreeMap<Long, Long> map) {
        if (map.containsKey(val))
            return map.get(val);
        return 0;
    }

    long calc(int a, int b) {
        TreeMap<Long, Long> map = new TreeMap<>();
        for (PairLong pair : list[a][b])
            map.put(pair.a, max(getOrDefault(pair.a, map), pair.b));
        map.put(0L, 0L);

        long curr = 0;
        ArrayList<Map.Entry<Long, Long>> lst = new ArrayList<>();
        lst.addAll(map.entrySet());
        Collections.reverse(lst);
        long lastX = n + 10, lastY = 0;
        for (int i = 0; i < lst.size(); i++) {
            long currX = lst.get(i).getKey();
            long currY = lst.get(i).getValue();
            curr += (lastX - currX) * lastY;
            lastX = currX;
            lastY = max(lastY, currY);
        }

        return curr;
    }

    public void solve() {
        s = in.next();
        n = s.length();
        list = new ArrayList[alphabet][alphabet];
        for (int i = 0; i < alphabet; i++) {
            for (int z = 0; z < alphabet; z++) {
                list[i][z] = new ArrayList<>();
            }
        }
        ones = new int[alphabet];

        char curr = s.charAt(0);
        int len = 1;
        ArrayList<Pair<Character, Integer>> chars = new ArrayList<>();
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != curr) {
                chars.add(new Pair<>(curr, len));
                len = 1;
                curr = s.charAt(i);
            } else {
                len++;
            }
        }
        chars.add(new Pair<>(curr, len));

        for (int i = 0; i < chars.size(); i++) {
            int ch = chars.get(i).a - 'a';
            int l = chars.get(i).b;
            ones[ch] = max(ones[ch], l);
        }

        for (int i = 0; i < alphabet; i++)
            ans += ones[i];

        for (int i = 0; i < chars.size() - 1; i++) {
            int ch1 = chars.get(i).a - 'a';
            int ch2 = chars.get(i + 1).a - 'a';
            int l1 = chars.get(i).b;
            int l2 = chars.get(i + 1).b;
            list[ch1][ch2].add(new PairLong((long)l1, (long)l2));
        }

        for (int i = 0; i < alphabet; i++) {
            for (int z = 0; z < alphabet; z++) {
                if (list[i][z].size() == 0)
                    continue;
                ans += calc(i, z);
            }
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
