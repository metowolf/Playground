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

const double EPS=1e-14;
const double PI=acos(-1.0);
inline double sqr(double x){return x*x;}

int main(){
	int n;
	double xa,xb,ya,yb;
    while(~sf("%lf%lf%lf%lf%d",&xa,&ya,&xb,&yb,&n),n){
    	double len=sqrt(sqr(xa-xb)+sqr(ya-yb))+EPS;
    	double angle=(2*PI)/n*(n/2);
    	double r=len/2/sin(angle/2);
    	pf("%.6f\n",n*r*r*sin((2*PI/n))/2);
    }
	return 0;
}
