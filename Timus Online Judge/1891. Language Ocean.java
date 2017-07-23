// The solution of the problem was written by Izaron
// Date: 22:39:27   18 May 2016
// Execution time: 0.124

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

import java.io.*;
import java.util.*;

import static java.lang.Math.*;


public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    class Function {
        String name;
        ArrayList<String> args;
        String type;

        public Function() {
            name = "";
            args = new ArrayList<>();
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public ArrayList<String> getArgs() {
            return args;
        }

        public void setArgs(ArrayList<String> args) {
            this.args = args;
        }

        public String getType() {
            return type;
        }

        public void setType(String type) {
            this.type = type;
        }
    }

    ArrayList<Function> functions;
    TreeSet<String> variableSet;
    TreeMap<String, String> variableMap;
    ArrayList<String> variableList;
    int n, m;

    void parseFunction() {
        Function function = new Function();
        String s = in.nextLine();

        // parse name
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                function.setName(buffer.toString());
                s = s.substring(i);
            } else {
                buffer.append(s.charAt(i));
            }
        }

        // parse args
        ArrayList<String> args = new ArrayList<>();
        buffer = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                if (buffer.length() > 0) {
                    args.add(buffer.toString());
                    buffer = new StringBuffer();
                }
            } else if (s.charAt(i) == ')') {
                if (buffer.length() > 0) {
                    args.add(buffer.toString());
                }
                s = s.substring(i + 4);
                break;
            } else if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                buffer.append(s.charAt(i));
            }
        }
        function.setArgs(args);

        // parse type
        function.setType(s);

        // add in list
        functions.add(function);
    }

    boolean equalFunction(Function function, String name, ArrayList<String> args) {
        if (!function.getName().equals(name))
            return false;
        ArrayList<String> types = function.getArgs();
        if (types.size() != args.size())
            return false;
        for (int i = 0; i < types.size(); i++) {
            String type = types.get(i);
            if (!variableMap.get(args.get(i)).equals(type))
                return false;
        }
        return true;
    }

    boolean parseExpression(int line) {
        String s = in.nextLine();
        StringBuffer buffer;
        String initType;
        String varName;
        String function;

        // parse init type
        buffer = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                s = s.substring(i + 1);
                break;
            } else {
                buffer.append(s.charAt(i));
            }
        }
        initType = buffer.toString();

        // parse var name
        buffer = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                s = s.substring(i + 3);
                break;
            } else {
                buffer.append(s.charAt(i));
            }
        }
        varName = buffer.toString();

        if (variableSet.contains(varName)) {
            out.println("Error on line " + line + ": Double declaration");
            return false;
        }

        // parse function
        buffer = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                s = s.substring(i);
                break;
            } else {
                buffer.append(s.charAt(i));
            }
        }
        function = buffer.toString();

        // parse args
        ArrayList<String> args = new ArrayList<>();
        buffer = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                if (buffer.length() > 0) {
                    args.add(buffer.toString());
                    buffer = new StringBuffer();
                }
            } else if (s.charAt(i) == ')') {
                if (buffer.length() > 0) {
                    args.add(buffer.toString());
                }
                break;
            } else if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                buffer.append(s.charAt(i));
            }
        }

        for (String var : args) {
            if (!variableSet.contains(var)) {
                out.println("Error on line " + line + ": Unknown variable");
                return false;
            }
        }

        // find function
        Function func = null;
        for (Function function1 : functions) {
            if (equalFunction(function1, function, args)) {
                func = function1;
                break;
            }
        }

        if (func == null) {
            out.println("Error on line " + line + ": No such function");
            return false;
        }

        if (!initType.equals("auto") && !initType.equals(func.getType())) {
            out.println("Error on line " + line + ": Invalid initialization");
            return false;
        }

        if (initType.equals("auto"))
            variableList.add(varName);

        initType = func.getType();

        variableSet.add(varName);
        variableMap.put(varName, initType);

        return true;
    }

    public void solve() {
        functions = new ArrayList<>();
        variableSet = new TreeSet<>();
        variableMap = new TreeMap<>();
        variableList = new ArrayList<>();
        n = in.nextInt();
        for (int i = 0; i < n; i++)
            parseFunction();
        m = in.nextInt();

        for (int i = 0; i < m; i++) {
            if (!parseExpression(i + 1))
                return;
        }

        for (String str : variableList) {
            out.println(str + " : " + variableMap.get(str));
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