import java.util.Scanner;

public class Sold_Out {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int k = scan.nextInt();

        if(n<3){
            System.out.println(0);
            return;
        }

        System.out.println(Math.max(k - 1, n - k) - 2);
    }
}