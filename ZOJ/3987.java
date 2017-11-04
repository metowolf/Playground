import java.util.*;
import java.math.*;

public class Main {
	static final BigInteger TWO = BigInteger.valueOf(2);
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(), kk;
		BigInteger n, m, ans, two, tmp, tm;
		while((T--) > 0) {
			n = in.nextBigInteger();
			m = in.nextBigInteger();
			ans = BigInteger.ZERO;
			two = BigInteger.valueOf(2);
			kk = n.bitLength();
			two = two.pow(kk);
			//System.out.println(two);
			//System.out.println(two.subtract(BigInteger.ONE));
			for(int i = kk; i >= 0; --i) {
				tmp = m.multiply(two.subtract(BigInteger.ONE));
				if(n.compareTo(tmp) == 1) {
					ans = ans.add(two);
					//n = n.mod(two);
					tm = n.divide(two);
					if(tm.compareTo(m) == 1) tm = m;
					n = n.subtract(tm.multiply(two));
				}
				two = two.divide(TWO);
			}
			System.out.println(ans);
		}
	}
}

