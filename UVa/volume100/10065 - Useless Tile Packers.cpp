#include<bits/stdc++.h>
#define maxn 100
using namespace std;

int n;
struct Point{
	double x,y;
	friend Point operator -(Point a,Point b){
		return (Point){a.x-b.x,a.y-b.y};
	}
	friend bool operator <(Point a,Point b){
		return make_pair(a.x,a.y)<make_pair(b.x,b.y);
	}
}P[maxn+2],CH[maxn+2];

double cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

int ConvexHull(){
	sort(P+1,P+n+1);
	int m=0;
	for(int i=1;i<=n;i++){
		while(m>1&&cross(CH[m]-CH[m-1],P[i]-CH[m-1])>0)m--;
		CH[++m]=P[i];
	}
	int k=m;
	for(int i=n-1;i>0;i--){
		while(m>k&&cross(CH[m]-CH[m-1],P[i]-CH[m-1])>0)m--;
		CH[++m]=P[i];
	}
	return m-(n>1);
}

int main(){
	
	//freopen("input.txt","r",stdin);

	int _=0;
	while(~scanf("%d",&n),n){
		for(int i=1;i<=n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);
		double s1=0,s2=0;
		P[0]=P[n];
		for(int i=1;i<=n;i++)s1+=cross(P[i-1],P[i]);
		int m=ConvexHull();
		CH[0]=CH[m];
		for(int i=1;i<=m;i++)s2+=cross(CH[i-1],CH[i]);
		printf("Tile #%d\nWasted Space = %.2f %%\n\n",++_,(1-fabs(s1/s2))*100);
	}
	return 0;
}
