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
#define INF (~0U>>2)
using namespace std;

const double EPS=1e-15;
const double PI=acos(-1.0);

double area(double a,double b,double c){
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(){
    int T;
	sf("%d",&T);
	while(T--){
		double r,m[4],n[4];
		sf("%lf",&r);
		REP(i,1,3)sf("%lf%lf",m+i,n+i);
		n[2]*=(n[1]/m[2]);m[2]=n[1];
		n[3]*=(n[2]/m[3]);m[3]=n[2];
		double L=0,R=INF,ans;
		while(L+EPS<R){
			double mid=(L+R)/2;
			double l[4],C=0;
			REP(i,1,3)l[i]=mid*(n[i]+m[i]),C+=l[i];
			ans=area(l[1],l[2],l[3]);
			if(ans>C*r/2)R=mid;
			else L=mid;
		}
		pf("%.4lf\n",ans);
	}	 
	return 0;
}


