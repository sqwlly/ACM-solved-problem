import java.util.Scanner;
import java.util.Comparator;
import java.math.BigInteger;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int k = 0; k < T; ++k) {
            int n = in.nextInt();
            int a[] = new int[n + 1];
            int max1[] = new int[n + 1];
            for (int i = 1; i <= n; ++i) {
                a[i] = in.nextInt();
            }
            max1[1] = a[1];
            for (int i = 2; i <= n; ++i) {
                max1[i] = Math.max(a[i], max1[i - 1]);
            }
            BigInteger ans = new BigInteger("0");
            for (int i = 2; i <= n; ++i) {
                String t = Integer.valueOf(max1[i - 1]) + Integer.valueOf(a[i]).toString();
                BigInteger t1 = new BigInteger(t);
                if (ans.compareTo(t1) < 0) {
                    ans = t1;
                }
            }
            System.out.println("Case #" + (k + 1) + ": " + ans);
        }
        in.close();
    }
}

