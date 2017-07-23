import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    public void solve() {
        int n = in.nextInt();
        int ans = 0;
        for (Integer it : readIntList(n)) {
            ans += (it - 1) / 2;
        }
        if (ans % 2 == 1)
            out.print("Daenerys");
        else
            out.print("Stannis");
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
