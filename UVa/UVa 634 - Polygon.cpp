#include<bits/stdc++.h>
#define maxn 1000
#define eps 1e-8
using namespace std;

int dcmp(double x){return (x>eps)-(x<-eps);}

int n;
struct Point{
	double x,y;
	friend Point operator -(Point a,Point b){
		return (Point){a.x-b.x,a.y-b.y};
	}
	friend bool operator <(Point a,Point b){
		return make_pair(a.x,a.y)<make_pair(b.x,b.y);
	}
}P[maxn+2];

double cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

double dot(Point a,Point b){
	return a.x*b.x+a.y*b.y;
}

bool PointOnSeg(Point p,Point s,Point t){
	return dcmp(cross(p-s,t-s))==0&&dcmp(dot(p-s,p-t))<=0;
}

int point_in(Point t){
	int num=0,d1,d2;
	for(int i=1;i<=n;i++){
		if(PointOnSeg(t,P[i-1],P[i]))return 2;
		int k=dcmp(cross(P[i]-P[i-1],t-P[i-1]));
		d1=dcmp(P[i-1].y-t.y);
		d2=dcmp(P[i].y-t.y);
		if(k>0&&d1<=0&&d2>0)num++;
		if(k<0&&d2<=0&&d1>0)num--;
	}
	return num!=0;
}

int main(){
	while(~scanf("%d",&n),n){
		for(int i=1;i<=n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);
		P[0]=P[n];
		Point p;
		scanf("%lf%lf",&p.x,&p.y);
		printf(point_in(p)?"T\n":"F\n");
	}
	return 0;
}
