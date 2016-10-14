#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include     <list>
#include      <map>
#include      <set>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC  optimize("O2")
#define INF  1e5
#define EPS  1e-8
#define maxn 100000
#define eps 1e-8
using namespace std;

struct Point{
	double x,y;
	friend Point operator -(Point a,Point b){
		return (Point){a.x-b.x,a.y-b.y};
	}
	friend bool operator <(Point a,Point b){
		if(a.x==b.x)return a.y<b.y;
		return a.x<b.x;
	}
};

int n,m;
Point P[maxn+2],S;
Point CH[maxn+2];

double cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

int ConvexHull(){
	sort(P+1,P+n+1);
	//REP(i,1,n)printf("%lf %lf\n",P[i].x,P[i].y);
	int t=0;
	REP(i,1,n){
		while(t>1&&cross(CH[t]-CH[t-1],P[i]-CH[t-1])<=0)t--;
		CH[++t]=P[i];
	}
	int k=t;
	for(int i=n-1;i>=1;i--){
		while(t>k&&cross(CH[t]-CH[t-1],P[i]-CH[t-1])<=0)t--;
		CH[++t]=P[i];
	}
	return t-(n>1);
}

int main(){
	
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	while(~scanf("%d",&n)){
		REP(i,1,n)scanf("%lf%lf",&P[i].x,&P[i].y);
		n=ConvexHull();
		REP(i,1,n)P[i]=CH[i];P[0]=P[n];
		//REP(i,1,n)printf("%lf %lf\n",P[i].x,P[i].y);
		
		scanf("%d",&m);
		while(m--){
			scanf("%lf%lf",&S.x,&S.y);
			int cnt1=0,cnt2=0;
			REP(i,1,n){
				//printf("%lf\n",cross(P[i]-P[i-1],S-P[i-1]));
				if(cross(P[i]-P[i-1],S-P[i-1])>-eps)cnt1++;
				if(cross(P[i]-P[i-1],S-P[i-1])<eps)cnt2++;
			}
			//printf("%d %d\n",cnt1,cnt2);
			printf((cnt1==n||cnt2==n)?"inside\n":"outside\n");
		}
	}
	return 0;
}
