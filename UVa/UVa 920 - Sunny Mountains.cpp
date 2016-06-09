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
#define eps 1e-9
using namespace std;

struct point{double x,y;}P[maxn+2];

bool cmp(point a,point b){return a.x>b.x;}

int n;

double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
	//freopen("input.txt","r",stdin);
	int T;
	sf("%d",&T);
	while(T--){
		sf("%d",&n);
		REP(i,1,n)sf("%lf%lf",&P[i].x,&P[i].y);
		sort(P+1,P+n+1,cmp);
		double sum=0;
		int last=1;
		REP(i,2,n){
			if(P[i].y>P[last].y){
				sum+=dist(P[i],P[i-1])*(P[i].y-P[last].y)/(P[i].y-P[i-1].y);
				last=i;
			}
		}
		pf("%.2f\n",sum+eps);
	}
	return 0;
}
