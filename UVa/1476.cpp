#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
using namespace std;

double 

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		sf("%d%d%d%d",&n,&m,&s,&t);
		REP(i,a,b){
			sf("%d%d%d",&L[i].a,&L[i].b,&L[i].c);
		}
		double L=-10000,R=10000;
		while(L+eps<R){
			double mid1=(L+R)/2-(R-L)/1000;
			double mid2=(L+R)/2+(R-L)/1000;
			if(f(mid1)>f(mid2))L=mid1;
			else R=mid2;
		}
		pf("%lf\n",L);
	}
	return 0;
}