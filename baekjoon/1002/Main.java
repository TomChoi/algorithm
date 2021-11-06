import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i = scanner.nextInt();
        ArrayList<Integer> ans = new ArrayList<>();

        while(i-- > 0) {
            Integer res;
            int x1 = scanner.nextInt();
            int y1 = scanner.nextInt();
            int r1 = scanner.nextInt();
            int x2 = scanner.nextInt();
            int y2 = scanner.nextInt();
            int r2 = scanner.nextInt();

            if(x1 == x2 && y1 == y2) {
                res = r1 == r2 ? -1 : 0;
            } else {
                double distance =
                Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
                res = distance == r1 + r2 ? 1 : distance > r1 + r2 ? 0 : 2;
            }
            ans.add(res);
        }

        for(Integer n: ans) {
            System.out.println(n.intValue());
        }
    }
}
