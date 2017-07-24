// The solution of the problem was written by Izaron
// Date: 22:36:43   5 Dec 2015
// Execution time: 0.124

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int curr(int a, int b, int c) {
        TreeSet<Integer> set = new TreeSet<>();
        set.add(a - b - c);
        set.add(a - b + c);
        set.add(a - b * c);
        set.add(a + b - c);
        set.add(a + b + c);
        set.add(a + b * c);
        set.add(a * b - c);
        set.add(a * b + c);
        set.add(a * b * c);
        return set.first();
    }

    public void solve() {
        int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
        TreeSet<Integer> set = new TreeSet<>();
        set.add(curr(a, b, c));
        set.add(curr(a, c, b));
        set.add(curr(b, a, c));
        set.add(curr(b, c, a));
        set.add(curr(c, a, b));
        set.add(curr(c, b, a));
        out.print(set.first());
    }

    public void run() {
        if (FILE.equals("")) {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);
        } else {
            try {
                in = new FastScanner(new FileInputStream(FILE + ".in"));
                out = new PrintWriter(new FileOutputStream(FILE + ".out"));
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
    }

    public ArrayList<Integer> readIntList(int n) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(in.nextInt());
        return list;
    }

    public ArrayList<String> readStringList(int n) {
        ArrayList<String> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(in.next());
        return list;
    }

    public abstract class Tuple implements Comparable<Tuple> {
        private Object[] valueArray;
        private List<Object> valueList;

        protected Tuple(Object... values) {
            super();
            this.valueArray = values;
            this.valueList = Arrays.asList(values);
        }

        public Object getValue(int pos) {
            return this.valueArray[pos];
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            Tuple other = (Tuple) obj;
            return valueList.equals(other.valueList);
        }

        public int compareTo(Tuple o) {
            for (int i = 0; i < valueArray.length; i++) {
                Comparable tElement = (Comparable) valueArray[i];
                Comparable oElement = (Comparable) o.valueArray[i];
                int comparison = tElement.compareTo(oElement);
                if (comparison != 0) {
                    return comparison;
                }
            }
            return 0;
        }
    }

    public class Pair<A, B> extends Tuple {
        public A a;
        public B b;

        public Pair() {

        }

        public Pair(A a, B b) {
            super(a, b);
            this.a = a;
            this.b = b;
        }
    }

    public class Triplet<A, B, C> extends Tuple {
        public A a;
        public B b;
        public C c;

        public Triplet(A a, B b, C c) {
            super(a, b, c);
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
}
