#include<bits/stdc++.h>
#define maxn 1000
using namespace std;

const double PI=acos(-1.0);
int n;
double L;
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
}P[maxn+2],CH[maxn+2];

double cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

int CovexHull(){
	sort(P+1,P+n+1);
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
		scanf("%d%lf",&n,&L);
		for(int i=1;i<=n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);
		int m=CovexHull();
		double ans=0;
		CH[0]=CH[m];
		for(int i=1;i<=m;i++)ans+=(CH[i]-CH[i-1]).length();
		ans+=2*L*PI;
		printf("%.0f\n",ans);
		if(T)puts("");
	}
	return 0;
}
