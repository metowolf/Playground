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
#define maxn 102
#define sqr(x) ((x)*(x))
using namespace std;

struct Point{double x,y,z,r;};
inline double dis(Point a,Point b){return max(0.0,sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z))-a.r-b.r);}
double A[maxn+2][maxn+2];
Point P[maxn];

int main(){
	//freopen("input.txt","r",stdin);
	int _=0,n;
	while(~sf("%d",&n),~n){
		REP(i,1,n)sf("%lf%lf%lf%lf",&P[i].x,&P[i].y,&P[i].z,&P[i].r);
		sf("%lf%lf%lf",&P[n+1].x,&P[n+1].y,&P[n+1].z);P[n+1].r=0;
		sf("%lf%lf%lf",&P[n+2].x,&P[n+2].y,&P[n+2].z);P[n+2].r=0;
		n+=2;
		REP(i,1,n)REP(j,i,n)A[i][j]=A[j][i]=dis(P[i],P[j]);
		REP(k,1,n)REP(i,1,n)REP(j,1,n)A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
		pf("Cheese %d: Travel time = %.0f sec\n",++_,A[n-1][n]*10);
	}	
	return 0;
}
