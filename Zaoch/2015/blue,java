import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }
}

class PairFull<U extends Comparable<U>, V extends Comparable<V>> implements Comparable<PairFull<U, V>> {
    public U first;
    public V second;

    public PairFull(U u, V v) {
        this.first = u;
        this.second = v;
    }
        
    public int hashCode() {
        return (first == null ? 0 : first.hashCode() * 31) + (second == null ? 0 : second.hashCode());
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        PairFull<U, V> p = (PairFull<U, V>) o;
        return (first == null ? p.first == null : first.equals(p.first)) && (second == null ? p.second == null : second.equals(p.second));
    }

    public int compareTo(PairFull<U, V> b) {
        int cmpU = first.compareTo(b.first);
        return cmpU != 0 ? cmpU : second.compareTo(b.second);
    }
}

class Pair extends PairFull<Long, Long> {
    public Pair(Long u, Long v) {
        super(u, v);
    }
}

class Task {
    
    public int GCD(int a, int b) {
        if (b==0)
            return a;
        return GCD(b, a % b);
    }
    
    public void solve(InputReader in, PrintWriter out) {
        int l = in.nextInt();
        String s = in.next();
        int n = s.length();
        
        if(s.indexOf("c") == -1) {
            // a & b only
            // one word
            for(int len = 1; len <= s.length(); len++) {
                if(s.length() % len != 0)
                    continue;
                if(len > l)
                    break;
                boolean can = true;
                for(int z = 0; z < s.length(); z++) {
                    if(s.charAt(z) != s.charAt(z % len)) {
                        can = false;
                        break;
                    }
                }
                if(can) {
                    out.println(1);
                    for(int z = 0; z < len; z++) {
                        out.print(s.charAt(z));
                    }
                    return;
                }
            }
            out.print("2\na\nb");
            
            return;
        }
        
        // 1 word is s
        if(l >= s.length()) {
            out.print("1\n");
            out.print(s);
            return;
        }
        
        // 1 word
        for(int len = 1; len <= s.length(); len++) {
            if(s.length() % len != 0)
                    continue;
            if(len > l)
                break;
            boolean can = true;
            for(int z = 0; z < s.length(); z++) {
                if(s.charAt(z) != s.charAt(z % len)) {
                    can = false;
                    break;
                }
            }
            if(can) {
                out.println(1);
                for(int z = 0; z < len; z++) {
                    out.print(s.charAt(z));
                }
                return;
            }
        }
        
        // 2 words
        for(int a = 0; a < l; a++) {
            String as = s.substring(0, a + 1);
            int aza = 0;
            while(true) {
                if(s.indexOf(as, aza) == aza) {
                    aza += as.length();
                } else {
                    break;
                }
            }
            
            for(int b = 0; b < l; b++) {
                if(aza + b > n)
                    continue;
                if(n % GCD(a + 1, b + 1) != 0)
                    continue;
               
                String bs = s.substring(aza, aza + b + 1);
                
                if(as.startsWith(bs) || bs.startsWith(as))
                    continue;
                
                int start = 0;
                while(true) {
                    if(start == s.length()) {
                        out.print("2\n");
                        out.println(as);
                        out.println(bs);
                        return;
                    }
                    if(s.indexOf(as, start) == start) {
                        start = start + as.length();
                    } else if(s.indexOf(bs, start) == start) {
                        start = start + bs.length();
                    } else {
                        break;
                    }
                }
            }
        }
        
        
        out.print("3\na\nb\nc");
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
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
    
    public double nextFloat() {
        return Float.parseFloat(next());
    }

}