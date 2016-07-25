#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define maxn 100
using namespace std;

struct Point{
	double x,y;
	friend Point operator -(Point a,Point b){
		return (Point){a.x-b.x,a.y-b.y};
	}
	friend bool operator <(Point a,Point b){
		return make_pair(a.x,a.y)<make_pair(b.x,b.y);
	}
	double length(){
		return sqrt(x*x+y*y);
	}
};

int n;
Point P[maxn+2],CH[maxn+2];

double cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

int CovexHull(){
	int m=0;
	for(int i=1;i<=n;i++){
		while(m>1&&cross(CH[m]-CH[m-1],P[i]-CH[m-1])<=0)m--;
		CH[++m]=P[i];
	}
	int k=m;
	for(int i=n-1;i>=1;i--){
		while(m>k&&cross(CH[m]-CH[m-1],P[i]-CH[m-1])<=0)m--;
		CH[++m]=P[i];
	}
	return m-(n>1);
}

double dia_rotate_calipers(int m){
	double ans=1e9;
	int j=1;
	CH[0]=CH[m];
	REP(i,1,m){
		while(cross(CH[i]-CH[i-1],CH[j%m+1]-CH[i-1])>cross(CH[i]-CH[i-1],CH[j]-CH[i-1]))
			j=j%m+1;
		ans=min(ans,cross(CH[i]-CH[i-1],CH[j]-CH[i-1])/(CH[i]-CH[i-1]).length());
	}
	return ans;
}

int main(){
	int _=0;
	while(~scanf("%d",&n),n){
		REP(i,1,n)scanf("%lf%lf",&P[i].x,&P[i].y);
		sort(P+1,P+n+1);
		int m=CovexHull();
		printf("Case %d: %.2f\n",++_,dia_rotate_calipers(m));
	}
	return 0;
}
