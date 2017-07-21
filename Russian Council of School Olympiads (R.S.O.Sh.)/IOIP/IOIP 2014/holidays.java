import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "holidays";

    int n;
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int ansFirst[][] = new int[7][12];
    int ansLast[][] = new int[7][12];
    int currWeekDay;
    int currMonthDay;
    int currMonth;

    int getDay(String name) {
        switch (name) {
            case "monday":
                return 0;
            case "tuesday":
                return 1;
            case "wednesday":
                return 2;
            case "thursday":
                return 3;
            case "friday":
                return 4;
            case "saturday":
                return 5;
            case "sunday":
                return 6;
            default:
                throw new RuntimeException();
        }
    }

    int getMonth(String name) {
        switch (name) {
            case "january":
                return 0;
            case "february":
                return 1;
            case "march":
                return 2;
            case "april":
                return 3;
            case "may":
                return 4;
            case "june":
                return 5;
            case "july":
                return 6;
            case "august":
                return 7;
            case "september":
                return 8;
            case "october":
                return 9;
            case "november":
                return 10;
            case "december":
                return 11;
            default:
                throw new RuntimeException();
        }
    }

    void work() {
        while (true) {
            if (currMonth >= days.length)
                return;
            ansFirst[currWeekDay][currMonth] = min(ansFirst[currWeekDay][currMonth], currMonthDay + 1);
            ansLast[currWeekDay][currMonth] = max(ansLast[currWeekDay][currMonth], currMonthDay + 1);

            currWeekDay++;
            currWeekDay %= 7;

            currMonthDay++;
            if (currMonthDay >= days[currMonth]) {
                currMonthDay = 0;
                currMonth++;
            }
        }
    }

    public void solve() {
        n = in.nextInt();
        currWeekDay = getDay(in.next());
        currMonthDay = 0;
        currMonth = 0;

        if (in.next().equals("yes"))
            days[1]++;

        for (int i = 0; i < 7; i++) {
            for (int z = 0; z < 12; z++) {
                ansFirst[i][z] = Integer.MAX_VALUE;
                ansLast[i][z] = Integer.MIN_VALUE;
            }
        }

        work();

        for (int i = 0; i < n; i++) {
            boolean first = in.next().equals("first");
            int day = getDay(in.next());
            in.next();
            int month = getMonth(in.next());
            out.println(first ? ansFirst[day][month] : ansLast[day][month]);
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

[close]
