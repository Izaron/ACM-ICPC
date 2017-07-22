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
    
    public void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] t = new int[n];
        for(int i = 0; i < n; i++)
            t[i] = in.nextInt();
        int q = in.nextInt();
        
        if(n == 1) {
            for(int i = 0; i < q; i++)
                out.print("1\n");
            return;
        }
        
        int ans = 1;
        for(int i = 1; i < n; i++) {
            if(t[i] != t[i - 1])
                ans++;
        }
        
        for(int i = 0; i < q; i++) {
            int p = in.nextInt(), c = in.nextInt();
            p--;
            
            if(t[p] == c) {
                out.println(ans);
                continue;
            }
            
            // bok sleva
            if(p == 0) {
                if(t[p + 1] == c) {
                    ans--;
                } else if(t[p + 1] == t[p]) {
                    ans++;
                } else {
                    ans = ans;
                }
            }
            
            // bok sprava
            if(p == n - 1) {
                if(t[p - 1] == c) {
                    ans--;
                } else if(t[p - 1] == t[p]) {
                    ans++;
                } else {
                    ans = ans;
                }
            }
            
            // seredina
            if(p > 0 && p < n - 1) {
                if(t[p - 1] == t[p + 1] && t[p - 1] != t[p] &&
                        t[p - 1] == c) {                    // 121 -> 111
                    ans -= 2;
                } else if(t[p - 1] == t[p] && t[p] != t[p + 1] &&
                        t[p + 1] != c) {                    // 221 -> 231
                    ans++;
                } else if(t[p + 1] == t[p] && t[p] != t[p - 1] &&
                        t[p - 1] != c) {                    // 122 -> 132
                    ans++;
                } else if(t[p - 1] == t[p] && t[p] == t[p + 1]) {  // 111 - > 121
                    ans += 2;
                } else if(t[p - 1] != t[p] && t[p] != t[p + 1] &&
                        t[p - 1] != c && t[p + 1] != c) {   // 123 -> 143
                    ans = ans;
                } else if(t[p - 1] != t[p] && t[p] != t[p + 1] &&
                        t[p - 1] != c && t[p + 1] == c) {   // 123 -> 133
                    ans--;
                } else if(t[p - 1] != t[p] && t[p] != t[p + 1] &&
                        t[p - 1] == c && t[p + 1] != c) {   // 123 -> 113
                    ans--;
                } else if(t[p - 1] != t[p] && t[p] == t[p + 1] &&
                        t[p - 1] == c) {                    // 122 -> 112
                    ans = ans;
                } else if(t[p - 1] == t[p] && t[p] != t[p + 1] &&
                        t[p + 1] == c) {                    // 112 -> 122
                    ans = ans;
                }
            }
            
            t[p] = c;
            out.println(ans);
        }
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