#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

double X,Y,S,ans;

double f(double x){
	return min(Y,S/x);
}

double simpson(double L,double R,int n){
	const double h=(R-L)/n;
	double ans=f(L)+f(R);
	for(int i=1;i<n;i+=2)ans+=4*f(L+i*h);
	for(int i=2;i<n;i+=2)ans+=2*f(L+i*h);
	return ans*h/3;
}

double asr(double L,double R,double eps,double A){
	double mid=L+(R-L)/2;
	double Ls=simpson(L,mid,2),Rs=simpson(mid,R,2);
	if(fabs(Ls+Rs-A)<=15*eps)return Ls+Rs+(Ls+Rs-A)/15.0;
	return asr(L,mid,eps/2,Ls)+asr(mid,R,eps/2,Rs);
}

double asr(double L,double R,double eps){
	return asr(L,R,eps,simpson(L,R,2));
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf",&X,&Y,&S);
		if(S==0)ans=100;
		else if(S>X*Y)ans=0;
		else ans=100-(asr(0,X,1e-7))*100/(X*Y);
		printf("%.6lf%%\n",ans);
	}
	return 0;
}
