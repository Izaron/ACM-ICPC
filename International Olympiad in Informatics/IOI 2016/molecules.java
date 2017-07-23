import java.util.Scanner;
import java.util.stream.IntStream;

public class molecules {

    int[] find_subset(int l, int u, int[] w) {
        int n = w.length;
        int[] sorted = IntStream.range(0, n).mapToObj(i -> i)
                .sorted((a, b) -> Integer.compare(w[a], w[b]))
                .mapToInt(Integer::intValue)
                .toArray();
        int a = 0, b = -1;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += w[sorted[i]];
            while (sum > u)
                sum -= w[sorted[a++]];
            if (sum >= l && sum <= u) {
                b = i;
                break;
            }
        }
        if (b == -1) {
            return new int[0];
        } else {
            int[] ans = new int[b - a + 1];
            int cnt = 0;
            for (int i = a; i <= b; i++) {
                ans[cnt++] = sorted[i];
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), l = in.nextInt(), u = in.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++)
            w[i] = in.nextInt();
        int[] ans = (new molecules()).find_subset(l, u, w);
        System.out.print("[ ");
        for (int i = 0; i < ans.length; i++)
            System.out.print(ans[i] + (i == ans.length - 1 ? " " : ", "));
        System.out.print("]");
    }
}
