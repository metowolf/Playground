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
#define eps 1e-8
using namespace std;

const double R=6371009;
const double PI=acos(-1.0);

struct point{double x,y,z;}P[2];
double sqr(double x){return x*x;}
double dis(point a,point b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z));}
double angle(double a,double b,double c){return acos((a*a+b*b-c*c)/(2*a*b));}

int main(){
    int T;
    sf("%d",&T);
    while(T--){
    	double a,b,c,d;
    	sf("%lf%lf%lf%lf",&b,&a,&d,&c);
    	P[0]=(point){R*cos(a/180*PI)*cos(b/180*PI),R*sin(a/180*PI)*cos(b/180*PI),R*sin(b/180*PI)};
    	P[1]=(point){R*cos(c/180*PI)*cos(d/180*PI),R*sin(c/180*PI)*cos(d/180*PI),R*sin(d/180*PI)};
    	P[2]=(point){0,0,0};
    	double ans=R*angle(dis(P[0],P[2]),dis(P[1],P[2]),dis(P[0],P[1]));
    	pf("%.0lf\n",ans-dis(P[0],P[1])+eps);
    }
	return 0;
}
