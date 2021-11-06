import java.util.*;

public class Main {
    static int[][] cache = new int[41][2];

    static void fibonacci(Integer n) {
        if (n == 0) {
            cache[0][0] = 1;
            cache[0][1] = 0;
        } else if (n == 1) {
            cache[1][0] = 0;
            cache[1][1] = 1;
        } else {
            if(cache[n][0] == 0) {
                fibonacci(n-1);
                fibonacci(n-2);
                cache[n][0] = cache[n-1][0] + cache[n-2][0];
                cache[n][1] = cache[n-1][1] + cache[n-2][1];
            }
        }
        return;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();

        while(i-- > 0) {
            int n = sc.nextInt();
            fibonacci(n);
            System.out.println(cache[n][0] + " " + cache[n][1]); 
        }
    }
}
