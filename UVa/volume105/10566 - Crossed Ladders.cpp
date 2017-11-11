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
#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 50
#define INF (~0U>>2)
using namespace std;

const double EPS=1e-12;
const double PI=acos(-1.0);

int main(){
	double x,y,c;
	while(~sf("%lf%lf%lf",&x,&y,&c)){
		double L=0,R=min(x,y);
		while(L+EPS<R){
			double mid=(L+R)/2;
			double X=sqrt(x*x-mid*mid),Y=sqrt(y*y-mid*mid);
			double C=Y*(X/(X+Y));
			if(C<c)R=mid;
			else L=mid;
		}
		pf("%.3f\n",L);	
	}
	return 0;
}
