#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define maxn 100000
using namespace std;

struct Point{
	double x,y;
	friend Point operator -(Point a,Point b){
		return (Point){a.x-b.x,a.y-b.y};
	}
	friend bool operator <(Point a,Point b){
		return make_pair(a.x,a.y)<make_pair(b.x,b.y);
	}
};

double cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

int n;
Point P[maxn+2],CH[maxn+2];

int CovexHull(){
	int m=0;
	for(int i=1;i<=n;i++){
		while(m>1&&cross(CH[m]-CH[m-1],P[i]-CH[m-1])<0)m--;
		CH[++m]=P[i];
	}
	int k=m;
	for(int i=n-1;i>=1;i--){
		while(m>k&&cross(CH[m]-CH[m-1],P[i]-CH[m-1])<0)m--;
		CH[++m]=P[i];
	}
	return m-(n>1);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		REP(i,1,n)scanf("%lf%lf %*c",&P[i].x,&P[i].y);
		sort(P+1,P+n+1);
		int m=CovexHull();
		printf("%d\n",m);
		REP(i,1,m)printf("%.0f %.0f\n",CH[i].x,CH[i].y);
	}
	return 0;
}
