#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
//#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 50
using namespace std;

double f(double a,double b,double c,double d){
	return fabs(a*d-b*c);
}

double x[4],y[4];

int main(){
    int T;
    sf("%d",&T);
    while(T--){
    	REP(i,1,3)sf("%lf%lf",x+i,y+i);
    	double ans=f(x[1]-x[3],y[1]-y[3],x[2]-x[3],y[2]-y[3])/2;
		pf("%.0lf\n",ans/7);
	}
	return 0;
}
