#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
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
#define maxn 100
#define sqr(x) ((x)*(x))
#define eps (1e-8)
#define INF (1e9)
using namespace std;

int n;
double r;
struct point{double x,y;}P[maxn+2];
double dis(point a,point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

bool solve(){
	point S=(point){0,0};
	REP(i,1,n)S.x+=P[i].x,S.y+=P[i].y;
	S.x/=n,S.y/=n;
	double T=1000;
	double ans=INF;
	while(T>eps){
		int k=1;
		REP(i,1,n)if(dis(S,P[k])<dis(S,P[i]))k=i;
		ans=min(ans,dis(S,P[k]));
		S.x+=T/1000*(P[k].x-S.x);
		S.y+=T/1000*(P[k].y-S.y);
		T*=0.99;
	}
	return ans<=r+eps;
}

int main(){
	//freopen("input.txt","r",stdin);
	while(~sf("%d",&n),n){
		REP(i,1,n)sf("%lf%lf",&P[i].x,&P[i].y);
		sf("%lf",&r);
		pf(solve()?"The polygon can be packed in the circle.\n":"There is no way of packing that polygon.\n");
	}
	return 0;
}
