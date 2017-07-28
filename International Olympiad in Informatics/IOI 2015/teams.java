import java.util.*;

public class teams {

    int N;
    int[] A;
    int[] B;
    List<Integer> list;

    public void init(int N, int A[], int B[]){
        this.N = N;
        this.A = A;
        this.B = B;

        list = new ArrayList<>();
        for (int i = 0; i < N; i++)
            list.add(i);

        Collections.sort(list, (a, b) -> Integer.compare(A[a], A[b]) == 0 ?
                Integer.compare(B[a], B[b]) : Integer.compare(A[a], A[b]));
    }

    static int addNumber(int number, TreeMap<Integer, Integer> map) {
        map.put(number, map.getOrDefault(number, 0) + 1);
        return 1;
    }

    static int removeNumber(int number, TreeMap<Integer, Integer> map) {
        if (map.containsKey(number)) {
            map.put(number, map.get(number) - 1);
            if (map.get(number) == 0)
                map.remove(number);
            return 1;
        }
        return 0;
    }

    public int can(int M, int K[]){
        long sum = 0;
        for (int i = 0; i < M; i++)
            sum += K[i];
        if (sum > N)
            return 0;

        int[] k = K.clone();
        Arrays.sort(k);
        int cnt = 0;

        TreeMap<Integer, Integer> map = new TreeMap<>();
        int b = 0;
        for (int i = 0; i < M; i++) {
            while (b < N) {
                int index = list.get(b);
                if (A[index] <= k[i]) {
                    if (B[index] >= k[i]) {
                        cnt += addNumber(B[index], map);
                    }
                    b++;
                } else {
                    break;
                }
            }

            while (true) {
                if (map.size() == 0)
                    break;
                int cur = map.firstKey();
                if (cur >= k[i])
                    break;
                cnt -= removeNumber(cur, map);
            }

            if (cnt < k[i])
                return 0;

            for (int z = 0; z < k[i]; z++) {
                cnt -= removeNumber(map.firstKey(), map);
            }
        }

        return 1;
    }

}
