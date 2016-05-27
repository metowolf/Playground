#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
#define maxn 10000
#define eps 1e-10
using namespace std;

int n;
struct line{double a,b,c;}Line[maxn+2];

double f(double x){
	double ans=Line[1].a*x*x+Line[1].b*x+Line[1].c;
	REP(i,2,n)ans=max(ans,Line[i].a*x*x+Line[i].b*x+Line[i].c);
	return ans;
}

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		sf("%d",&n);
		REP(i,1,n)sf("%lf%lf%lf",&Line[i].a,&Line[i].b,&Line[i].c);
		double L=0,R=1000;
		while(L+eps<R){
			double mid1=L+(R-L)/3;
			double mid2=R-(R-L)/3;
			if(f(mid1)<f(mid2))R=mid2;
			else L=mid1;
		}
		pf("%.4f\n",f(L)+eps);
	}
	return 0;
}
