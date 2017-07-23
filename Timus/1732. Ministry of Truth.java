import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    class KmpMatcher {
        String s;
        int cur = 0;

        int[] prefixFunction(String s) {
            int[] p = new int[s.length()];
            int k = 0;
            for (int i = 1; i < s.length(); i++) {
                while (k > 0 && s.charAt(k) != s.charAt(i))
                    k = p[k - 1];
                if (s.charAt(k) == s.charAt(i))
                    ++k;
                p[i] = k;
            }
            return p;
        }

        int kmpMatcher(String pattern) {
            int m = pattern.length();
            if (m == 0)
                return 0;
            int[] p = prefixFunction(pattern);
            for (int i = cur, k = 0; i < s.length(); i++, cur++) {
                while (k > 0 && pattern.charAt(k) != s.charAt(i))
                    k = p[k - 1];
                if (pattern.charAt(k) == s.charAt(i))
                    ++k;
                if (k == m) {
                    cur += 2;
                    return i + 1 - m;
                }
            }
            return -1;
        }

        void rebuild(String s) {
            this.s = s;
            cur = 0;
        }
    }

    ArrayList<String> parse(String s) {
        int index = 0;
        ArrayList<String> list = new ArrayList<>();
        while (index < s.length()) {
            StringBuffer buffer = new StringBuffer();
            if (s.charAt(index) == ' ') {
                while (index < s.length() && s.charAt(index) == ' ')
                    buffer.append(s.charAt(index++));
            } else {
                while (index < s.length() && s.charAt(index) != ' ')
                    buffer.append(s.charAt(index++));
            }
            list.add(buffer.toString());
        }
        return list;
    }

    boolean isBad(String s) {
        return s.charAt(0) == ' ';
    }

    public void solve() {
        String a = in.nextLine();
        String b = in.nextLine();

        List<String> listA = parse(a);
        List<String> listB = parse(b);
        List<StringBuffer> listAns = new ArrayList<>();
        for (String s : listA)
            listAns.add(new StringBuffer(s));
        int kz = 0;
        int cur = 0;
        KmpMatcher matcher = new KmpMatcher();
        matcher.rebuild(listA.get(0));

        for (int i = 0; i < listB.size(); i++) {
            String word = listB.get(i);
            if (isBad(word))
                continue;
            while (true) {
                while (cur < listA.size() && isBad(listA.get(cur))) {
                    cur++;
                    matcher.rebuild(listA.get(cur));
                }
                if (cur >= listA.size()) {
                    out.print("I HAVE FAILED!!!");
                    return;
                }
                int index = matcher.kmpMatcher(word);
                if (index == -1) {
                    for (; kz < listAns.get(cur).length(); kz++)
                        listAns.get(cur).setCharAt(kz, '_');
                    kz = 0;
                    cur++;
                    if (cur >= listA.size()) {
                        out.print("I HAVE FAILED!!!");
                        return;
                    }
                    matcher.rebuild(listA.get(cur));
                } else {
                    for (; kz < index; kz++)
                        listAns.get(cur).setCharAt(kz, '_');
                    kz = matcher.cur - 1;
                    break;
                }
            }
        }

        for (; kz < listAns.get(cur).length(); kz++)
            listAns.get(cur).setCharAt(kz, '_');
        cur++;
        while (cur < listAns.size()) {
            if (isBad(listA.get(cur))) {
                cur++;
                continue;
            }
            for (int i = 0; i < listAns.get(cur).length(); i++)
                listAns.get(cur).setCharAt(i, '_');
            cur++;
        }

        for (StringBuffer buffer : listAns)
            out.print(buffer.toString());
        //out.print("YES");
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