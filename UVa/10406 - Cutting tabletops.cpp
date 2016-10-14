#include<bits/stdc++.h>
#define maxn 1000
using namespace std;

struct Point{
	double x,y;
	friend Point operator -(Point a,Point b){
		return (Point){a.x-b.x,a.y-b.y};
	}
	double length(){
		return sqrt(x*x+y*y);
	}
}P[maxn+2];

double cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

int main(){
	double d;int n;
	while(~scanf("%lf%d",&d,&n),d||n){
		for(int i=1;i<=n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);
		P[0]=P[n],P[n+1]=P[1];
		double S=0,C=0;
		for(int i=1;i<=n;i++){
			S+=cross(P[i],P[i+1])/2.;
			C+=(P[i]-P[i+1]).length();
		}
		S=fabs(S);
		for(int i=1;i<=n;i++){
			double a=(P[i-1]-P[i]).length();
			double b=(P[i+1]-P[i]).length();
			double c=(P[i+1]-P[i-1]).length();
			double alpha=acos((a*a+b*b-c*c)/(2*a*b));
			double w=d/tan(alpha/2);
			C-=2*w;
			S-=w*d;
		}
		S-=C*d;
		printf("%.3f\n",S);
	}
	return 0;
}

