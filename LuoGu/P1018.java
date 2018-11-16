/*************************************************************************
    > File Name: P1018.java
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月15日 星期四 22时09分15秒
 ************************************************************************/
import java.util.Scanner;
import java.util.Comparator;
import java.math.BigInteger;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        String s = in.next();
        BigInteger dp[][] = new BigInteger[50][50];
        for (int i = 1; i <= k; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                dp[j][i] = BigInteger.ONE;
            }
        }
        for (int i = 1; i <= n; ++i)
            dp[i][0] = new BigInteger(s.substring(0, i));
        for (int i = 1; i <= k; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                for (int p = i; p < j; ++p) {
                    BigInteger t = dp[p][i - 1].multiply(new BigInteger(s.substring(p, j)));
                    if (dp[j][i].compareTo(t) < 0)
                        dp[j][i] = t;
                }
            }
        }
        System.out.println(dp[n][k]);
        in.close();
    }
}

