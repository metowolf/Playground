#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define maxn 600
using namespace std;

const double PI=acos(-1.0);

struct Point{
	double x,y;
	friend Point operator +(Point a,Point b){
		return (Point){a.x+b.x,a.y+b.y};
	}
	friend Point operator -(Point a,Point b){
		return (Point){a.x-b.x,a.y-b.y};
	}
	Point rotate(double a){
		double tx=x,ty=y;
		return (Point){tx*cos(a)-ty*sin(a),tx*sin(a)+ty*cos(a)};
	}
};

double cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

bool cmp(Point x,Point y){
	return make_pair(x.x,x.y)<make_pair(y.x,y.y);
}

int n;
double sum1,sum2;
vector<Point>P;
Point CH[maxn+2];

void addpoint(double x,double y,double w,double h,double a){
	a=a/180*PI;
	P.push_back((Point){x,y}+((Point){w/2,h/2}).rotate(-a));
	P.push_back((Point){x,y}+((Point){-w/2,h/2}).rotate(-a));
	P.push_back((Point){x,y}+((Point){w/2,-h/2}).rotate(-a));
	P.push_back((Point){x,y}+((Point){-w/2,-h/2}).rotate(-a));
}

int CovexHull(){
	int m=0;
	for(int i=0;i<n;i++){
		while(m>1&&cross(CH[m-1]-CH[m-2],P[i]-CH[m-2])<=0)m--;
		CH[m++]=P[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--){
		while(m>k&&cross(CH[m-1]-CH[m-2],P[i]-CH[m-2])<=0)m--;
		CH[m++]=P[i];
	}
	if(n>1)m--;
	return m;
}	

void Initial(){
	P.clear();
	sum1=sum2=0;
}

int main(){

	//freopen("input.txt","r",stdin);

	int T;
	scanf("%d",&T);
	while(T--){
		Initial();

		scanf("%d",&n);
		REP(i,1,n){
			double x,y,w,h,alpha;
			scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&h,&alpha);
			addpoint(x,y,w,h,alpha);
			sum2+=w*h;
		}
		n*=4;
		sort(P.begin(),P.end(),cmp);
		int m=CovexHull();
		CH[m]=CH[0];
		for(int i=0;i<m;i++){
			sum1+=cross(CH[i],CH[i+1])/2;
		}
		printf("%.1f %%\n",sum2/sum1*100);
	}
	return 0;
}
