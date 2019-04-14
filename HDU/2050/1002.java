import java.sql.Timestamp;
import java.util.Scanner;
import java.util.Comparator;
import java.math.BigInteger;
import java.util.Arrays;


public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int i = 0; i < T; ++i) {
            String X = in.next();
            String Y = in.next();
            X = X + " " + Y;
            Timestamp A = Timestamp.valueOf(X);

            Timestamp B = Timestamp.valueOf("2050-01-01 00:00:00");
            System.out.println((B.getTime() - A.getTime()) / 1000 % 100);
        }
        in.close();
    }
}

