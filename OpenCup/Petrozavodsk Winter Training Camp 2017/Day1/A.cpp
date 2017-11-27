#include<bits/stdc++.h>
using namespace std;

const long double eps=1e-12;

inline int dcmp(long double x){return (x>eps)-(x<-eps);}

long double h,a,b,c,va,vb,vc,ans;

bool gao(long double ang1){
	long double ang2,ang3;
	ang2=ang1*vb/va;
	ang3=ang1*vc/va;
	if(~dcmp(ang2-1)||~dcmp(ang3-1))return 1;
	long double k1,k2,k3;
	k1=a*ang1/sqrtl(1-ang1*ang1);
	k2=b*ang2/sqrtl(1-ang2*ang2);
	k3=c*ang3/sqrtl(1-ang3*ang3);
	ans=k1/ang1/va+k2/ang2/vb+k3/ang3/vc;
	return dcmp(k1+k2+k3-h)>=0;
}

inline long double _read(){
	double x;
	scanf("%lf",&x);
	return (long double)x;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		//scanf("%lf%lf%lf%lf%lf%lf%lf",&h,&a,&b,&c,&va,&vb,&vc);
		h=_read();
		a=_read(),b=_read(),c=_read();
		va=_read(),vb=_read(),vc=_read();
		long double l=0+eps,r=1-eps;
		int lim=200;
		while(lim--){
			if(r-l<eps)break;
			long double mid=(l+r)/2.;
			if(gao(mid))r=mid;else l=mid+eps;
		}
		printf("%.10f\n",(double)(ans+eps));
	}
	return 0;
}
