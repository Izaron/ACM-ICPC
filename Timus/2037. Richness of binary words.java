import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    class Node {
        int length;
        Node suffLink;
        Node next[] = new Node[2];
    }

    Node rootOdd;
    Node rootEven;
    Node last;

    Node findParent(String s, int index, int c) {
        Node ans = last;
        while (true) {
            if (index - ans.length - 1 >= 0 && s.charAt(index - ans.length - 1) == c + 'a')
                return ans;
            ans = ans.suffLink;
        }
    }

    Node findSuffLink(String s, Node node, int index, int c) {
        Node ans = node.suffLink;
        while (true) {
            if (index - ans.length - 1 >= 0 && s.charAt(index - ans.length - 1) == c + 'a')
                return ans.next[c];
            ans = ans.suffLink;
        }
    }

    int add(String s, int index, int c) {
        Node parent = findParent(s, index, c);
        if (parent.next[c] == null) {
            Node node = new Node();
            node.length = parent.length + 2;
            parent.next[c] = node;
            if (parent == rootOdd) {
                node.suffLink = rootEven;
            } else {
                node.suffLink = findSuffLink(s, parent, index, c);
            }
            last = parent.next[c];
            return 1;
        }
        last = parent.next[c];
        return 0;
    }

    void init() {
        rootOdd = new Node();
        rootOdd.length = -1;
        rootOdd.suffLink = rootOdd;

        rootEven = new Node();
        rootEven.length = 0;
        rootEven.suffLink = rootOdd;

        last = rootEven;
    }

    int getPalindromeNumber(String s) {
        init();
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
            ans += add(s, i, s.charAt(i) - 'a');
        return ans;
    }

    String extend(String s, int n) {
        while (s.length() < n)
            s = "0" + s;
        return s;
    }

    public void solve() {
        int n = in.nextInt();
        //if (n > 10)
        //    throw new RuntimeException();
        String[] ans = new String[n];
        int[] code = new int[n];
        String template = "babb";
        for (int i = 1; i <= n; i++) {
            StringBuffer buffer = new StringBuffer();
            String s;
            while (true) {
                for (int z = 0; z < i; z++)
                    buffer.append('a');
                buffer.append(template);
                if (buffer.length() >= n) {
                    s = buffer.toString().substring(0, n);
                    break;
                }
            }
            int num = getPalindromeNumber(s) - 1;
            if (ans[num] == null) {
                ans[num] = s;
                code[num] = i;
            }
        }

        for (int i = 0; i < n; i++) {
            out.print((i + 1) + " : ");
            if (ans[i] == null)
                out.println("NO");
            else
                out.println(ans[i]);
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