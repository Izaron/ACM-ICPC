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
    
    HashMap<Pair, Long> mp = new HashMap<Pair, Long>();
    
    long find(long n, long k) {
        Pair p = new Pair(n, k);
        
        if(mp.containsKey(p)) {
            return mp.get(p);
        }
        
        if(k == 1) {
            mp.put(p, (n + 1) / 2);
            return (n + 1) / 2;
        }
        
        long best = n;
        for(long a = 1; a <= n; a++) {
            if(n % a != 0) continue;
            long aa = (a + 1) / 2;
            best = Math.min(best, find(n / a, k - 1) * aa);
        }
        
        mp.put(p, best);
        return best;
    }
    
    public void solve(InputReader in, PrintWriter out) {
        long n = in.nextLong(), k = in.nextLong();
        out.print(find(n, k));
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