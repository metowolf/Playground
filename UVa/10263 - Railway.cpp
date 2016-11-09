#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const double eps=1e-10;

int dcmp(double x){return (x>eps)-(x<-eps);}

struct Point{double x,y;};

Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
Point operator *(Point a,double b){return (Point){a.x*b,a.y*b};}

double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
double length(Point a,Point b){return sqrt(dot(a-b,a-b));}

Point PointProjLine(Point p,Point s,Point t){
	double r=dot(t-s,p-s)/dot(t-s,t-s);
	return s+((t-s)*r);
}

double Point2Line(Point p,Point s,Point t){
	if(dcmp(dot(p-s,t-s))<0)return length(p,s);
	if(dcmp(dot(p-t,s-t))<0)return length(p,t);
	return fabs(cross(s-p,t-p)/length(s,t));
}

bool PointOnSeg(Point p,Point s,Point t){
	return dcmp(cross(p-s,t-s))==0&&dcmp(dot(p-s,p-t))<=0;
}

Point P[100+2],M,ans;

int main(){
	while(~scanf("%lf%lf",&M.x,&M.y)){
		int n;
		scanf("%d",&n);
		for(int i=0;i<=n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);

		double mindist=length(M,P[0]);
		ans=P[0];
		
		for(int i=0;i<n;i++){
			Point t=PointProjLine(M,P[i],P[i+1]);
			if(PointOnSeg(t,P[i],P[i+1])){
				double temp=length(M,t);
				if(mindist>temp)mindist=temp,ans=t;
			}
			double temp=length(M,P[i+1]);
			if(mindist>temp)mindist=temp,ans=P[i+1];
		}
		printf("%.4lf\n%.4lf\n",ans.x,ans.y);
	}
	return 0;
}
