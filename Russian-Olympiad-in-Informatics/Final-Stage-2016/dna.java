import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {

    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    int n;
    int queryMs[][];

    int query(int a, int b) {
        out.println("? " + (a + 1) + " " + (b + 1));
        out.flush();
        return in.nextInt();
    }

    int get(int a, int b) {
        return queryMs[a][b];
    }

    void calcAll() {
        for (int i = 0; i < n; i++) {
            for (int z = i; z < n; z++) {
                if (i == z) {
                    queryMs[i][z] = 1;
                } else {
                    queryMs[i][z] = query(i, z);
                }
            }
        }
    }

    void solve2() {
        calcAll();
        int ms[] = new int[n];
        ms[0] = 1;
        TreeSet<Integer> set = new TreeSet<>();
        set.add(1);
        int maxi = 1;
        for (int i = 1; i < n; i++) {
            int curr = get(0, i);
            if (i == 1) {
                if (curr == 2) {
                    ms[i] = 2;
                    maxi = 2;
                    set.add(2);
                } else {
                    ms[i] = 1;
                }
                continue;
            }
            if (curr > maxi) {
                maxi = curr;
                ms[i] = curr;
                set.add(curr);
            } else {
                if (get(i - 1, i) == 1) {
                    ms[i] = ms[i - 1];
                } else {
                    for (int z = 1; z < i; z++) {
                        int nv = get(z, i);
                        if (nv == curr && get(z, i - 1) == curr - 1) {
                            ms[i] = ms[z - 1];
                            break;
                        } else {
                            curr = nv;
                        }
                    }
                }
            }
        }

        out.println("Ready!");
        out.flush();
        out.println(set.size());
        out.flush();
        for (int i = 0; i < n; i++)
            out.print(ms[i] + " ");
        out.flush();
    }

    boolean can(ArrayList<Pair<Integer, Integer>> list, int v, int index) {
        int to = list.get(v).a;
        int qr = query(to, index);
        return (qr < v + 2);
    }

    int findZ(ArrayList<Pair<Integer, Integer>> list, int index) {
        int a = 0, b = list.size() - 1;
        while (a != b) {
            int la = a, lb = b;
            int mid = (a + b) / 2;

            if (can(list, mid, index))
                b = mid;
            else
                a = mid;

            if (la == a && lb == b) {
                if (can(list, a, index))
                    b = a;
                else
                    a = b;
            }
        }
        return a;
    }

    void solve3() {
        int ms[] = new int[n];
        ms[0] = 1;
        TreeSet<Integer> set = new TreeSet<>();
        set.add(1);
        int maxi = 1;
        int lastAdded[] = new int[n + 1];
        boolean used[] = new boolean[n + 1];

        used[ms[0]] = true;
        lastAdded[ms[0]] = 0;

        for (int i = 1; i < n; i++) {
            int curr = query(0, i);
            if (i == 1) {
                if (curr == 2) {
                    ms[i] = 2;
                    maxi = 2;
                    set.add(2);
                } else {
                    ms[i] = 1;
                }
            } else if (curr > maxi) {
                maxi = curr;
                ms[i] = curr;
                set.add(curr);
            } else {
                if (get(i - 1, i) == 1) {
                    ms[i] = ms[i - 1];
                } else {

                    ArrayList<Pair<Integer, Integer>> list = new ArrayList<>();
                    int cnt = 0;
                    for (int z = 1; z < lastAdded.length; z++) {
                        if (!used[z])
                            continue;
                        list.add(new Pair<>(lastAdded[z], z));
                    }

                    Collections.sort(list, Comparator.reverseOrder());

                    int kz = 1;

                    ms[i] = ms[list.get(findZ(list, i)).a];
                }
            }

            lastAdded[ms[i]] = i;
            used[ms[i]] = true;
        }

        out.println("Ready!");
        out.flush();
        out.println(set.size());
        out.flush();
        for (int i = 0; i < n; i++)
            out.print(ms[i] + " ");
        out.flush();
    }

    void solve() {
        n = in.nextInt();
        queryMs = new int[n][n];
        if (n <= 300) {
            solve2();
        } else {
            solve3();
        }
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