import java.util.Scanner;
import java.math.*;
import java.text.*;
public class Main
{
	public static void main(String args[]){
		Scanner cin=new Scanner(System.in);
		int T;
		T=cin.nextInt();
		while(T-->0){
			BigInteger ans=BigInteger.ZERO;
			for(int i=1;i<=4;i++){
				BigInteger t=cin.nextBigInteger();
				ans=ans.add(t);
			}
			System.out.println(ans);
		}
	}
}
