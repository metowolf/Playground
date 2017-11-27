import java.util.Scanner;
import java.math.*;
import java.text.*;
public class Main
{
    public static BigDecimal dfs(BigDecimal a,BigDecimal b){
        BigDecimal c=a.setScale(0,BigDecimal.ROUND_DOWN);
        a=a.subtract(c);b=b.subtract(c);
        if(b.compareTo(BigDecimal.ONE)>=1)return BigDecimal.ONE;
        b=BigDecimal.ONE.divide(b,1000,BigDecimal.ROUND_HALF_UP);
        if(BigDecimal.ZERO.compareTo(a.setScale(1000,BigDecimal.ROUND_HALF_UP))==0){
            return b.setScale(0,BigDecimal.ROUND_UP);
        }
        a=BigDecimal.ONE.divide(a,1000,BigDecimal.ROUND_HALF_UP);
        BigDecimal ans=dfs(b,a);
        b=b.multiply(ans);
        return b.setScale(0,BigDecimal.ROUND_UP);
    }

    public static void main(String args[]){
        Scanner cin=new Scanner(System.in);
        int T;
        T=cin.nextInt();
        while(T-->0){
            BigDecimal a,b;
            a=cin.nextBigDecimal();
            b=cin.nextBigDecimal();
            BigDecimal ans=dfs(a,b);
            ans=ans.setScale(0,BigDecimal.ROUND_DOWN);
            BigDecimal R=ans.multiply(b),L=ans.multiply(a);
            if(R.compareTo(R.setScale(0,BigDecimal.ROUND_DOWN))==0&&R.subtract(L).compareTo(BigDecimal.ONE)<0)
                ans=ans.add(BigDecimal.ONE);
            System.out.println(ans.setScale(0,BigDecimal.ROUND_DOWN).toString());
        }
    }
}
