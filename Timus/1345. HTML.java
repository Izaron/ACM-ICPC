import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static java.lang.Math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    static final String FILE = "";

    static Set<String> keywordSet;
    static String[] keywords = {
            "and", "array", "begin", "case", "class", "const", "div", "do", "else", "end", "for",
            "function", "if", "implementation", "interface", "mod", "not", "of", "or", "procedure",
            "program", "record", "repeat", "shl", "shr", "string", "then", "to", "type", "unit",
            "until", "uses", "var", "with", "while"
    };

    String read() {
        StringBuffer buffer = new StringBuffer();
        while (true) {
            String s = in.nextLine();
            if (s == null)
                break;
            buffer.append(s);
            buffer.append('\n');
        }
        return buffer.toString();
    }

    static void setKeywords() {
        keywordSet = new HashSet<>();
        for (String s : keywords)
            keywordSet.add(s);
    }

    static boolean isKeyword(String s) {
        return keywordSet.contains(s.toLowerCase());
    }

    String createHTML(String s) {
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '{') {
                buffer.append("<span class=comment>");
                for (int z = i; z < s.length(); z++) {
                    buffer.append(s.charAt(z));
                    if (s.charAt(z) == '}') {
                        i = z;
                        break;
                    }
                }
                buffer.append("</span>");
            } else if (i + 1 < s.length() && s.charAt(i) == '/' && s.charAt(i + 1) == '/') {
                buffer.append("<span class=comment>");
                for (int z = i; z < s.length(); z++) {
                    if (s.charAt(z) == '\n') {
                        i = z - 1;
                        break;
                    }
                    buffer.append(s.charAt(z));
                }
                buffer.append("</span>");
            } else if (s.charAt(i) == '\'') {
                buffer.append("<span class=string>");
                buffer.append('\'');
                for (int z = i + 1; z < s.length(); z++) {
                    buffer.append(s.charAt(z));
                    if (s.charAt(z) == '\'') {
                        i = z;
                        break;
                    }
                }
                buffer.append("</span>");
            } else if (i + 1 < s.length() && s.charAt(i) == '#' && Character.isDigit(s.charAt(i + 1))) {
                buffer.append("<span class=string>");
                for (int z = i; z < s.length(); z++) {
                    if (!Character.isDigit(s.charAt(z)) && z != i) {
                        i = z - 1;
                        break;
                    }
                    buffer.append(s.charAt(z));
                }
                buffer.append("</span>");
            } else if (Character.isDigit(s.charAt(i))) {
                buffer.append("<span class=number>");
                boolean can = true;
                for (int z = i; z < s.length(); z++) {
                    if (!Character.isDigit(s.charAt(z))) {
                        if (can && s.charAt(z) == '.' && z + 1 < s.length() && Character.isDigit(s.charAt(z + 1))) {
                            buffer.append(s.charAt(z));
                            can = false;
                            continue;
                        } else {
                            i = z - 1;
                            break;
                        }
                    }
                    buffer.append(s.charAt(z));
                }
                buffer.append("</span>");
            } else if (Character.isLetter(s.charAt(i)) || s.charAt(i) == '_') {
                StringBuffer id = new StringBuffer();
                for (int z = i; z < s.length(); z++) {
                    if (!Character.isDigit(s.charAt(z)) && !Character.isLetter(s.charAt(z)) && s.charAt(z) != '_') {
                        i = z - 1;
                        break;
                    }
                    id.append(s.charAt(z));
                }
                if (isKeyword(id.toString())) {
                    buffer.append("<span class=keyword>");
                    buffer.append(id);
                    buffer.append("</span>");
                } else {
                    buffer.append(id);
                }
            } else {
                buffer.append(s.charAt(i));
            }
        }

        return buffer.toString();
    }

    void crash(List<String> source) {
        for (String s : source)
            if (s.equals("#"))
                throw new RuntimeException();
        /*for (String s : source) {
            for (char c : s.toCharArray())
                if (Character.isDigit(c))
                    throw new RuntimeException();
        }*/
    }

    public void solve() {
        setKeywords();
        String code = read();
        out.print(createHTML(code));
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