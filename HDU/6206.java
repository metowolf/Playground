import java.util.Scanner;
import java.math.*;

public class Main
{
	private static BigDecimal length(BigDecimal ax,BigDecimal ay,BigDecimal bx,BigDecimal by){
		BigDecimal x=ax.subtract(bx);
		BigDecimal y=ay.subtract(by);
		return (x.multiply(x)).add(y.multiply(y));
	}

	public static void main(String args[]){
		Scanner cin=new Scanner(System.in);
		int T;
		T=cin.nextInt();
		while(T-->0){
			BigDecimal ax,ay,bx,by,cx,cy,dx,dy;
			ax=cin.nextBigDecimal();
			ay=cin.nextBigDecimal();
			bx=cin.nextBigDecimal();
			by=cin.nextBigDecimal();
			cx=cin.nextBigDecimal();
			cy=cin.nextBigDecimal();
			dx=cin.nextBigDecimal();
			dy=cin.nextBigDecimal();
			// work O
			BigDecimal a1,b1,c1,a2,b2,c2,d,ox,oy;
			a1=bx.subtract(ax);
			b1=by.subtract(ay);
			c1=(a1.multiply(a1)).add(b1.multiply(b1)).multiply(BigDecimal.valueOf(0.5));

			a2=cx.subtract(ax);
			b2=cy.subtract(ay);
			c2=(a2.multiply(a2)).add(b2.multiply(b2)).multiply(BigDecimal.valueOf(0.5));
			
			d=(a1.multiply(b2)).subtract(a2.multiply(b1));

			ox=ax.add(((c1.multiply(b2)).subtract(c2.multiply(b1))).divide(d));
			oy=ay.add(((a1.multiply(c2)).subtract(a2.multiply(c1))).divide(d));

			BigDecimal r=length(ox,oy,ax,ay);
			BigDecimal t=length(ox,oy,dx,dy);
			
			if(r.compareTo(t)>=0)System.out.println("Rejected");
			else System.out.println("Accepted");
		}
	}
}
