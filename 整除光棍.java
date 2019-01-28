import java.math.*;
import java.util.Scanner;;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = "1";
        BigInteger bi = new BigInteger(s);
        BigInteger n = sc.nextBigInteger();
        while(bi.remainder(n).equals(BigInteger.ZERO)==false)
        {
            s+="1";
            bi = new BigInteger(s);
        }
        System.out.println(bi.divide(n)+" "+bi.toString().length());
        sc.close();
    }
    //java处理大数还是很棒的。不过，就调俩包差点超时，300多毫秒。
}
