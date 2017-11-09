#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n),n){
		double Ax,Ay,Bx,By,k1,k2;
		scanf("%lf%lf%lf%lf",&Ax,&Ay,&Bx,&By);
		k1=Ay/Ax,k2=By/Bx;
		
		double s=0,l=0;
		for(int i=1;i<=n;i++){
			double t;
			scanf("%lf",&t);
			s+=t*t;
			l+=t;
		}

		double x1=fabs((k2+1)*l/(k2-k1)),y1=k1*x1;
		double x2=fabs((k1+1)*l/(k2-k1)),y2=k2*x2;
		double area=fabs(x1*y2-x2*y1)/2;
		printf("%.3f\n",area-s/2);
	}
	return 0;
}
