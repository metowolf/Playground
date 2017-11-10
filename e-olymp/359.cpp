#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;

inline int dcmp(double x){return (x>eps)-(x<-eps);}

struct Point{double x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
double length(Point a){return sqrt(dot(a,a));}
double distPL(Point p,Point a,Point b){
	return fabs(cross(p-a,b-a)/length(a-b));
}

int main(){
	double r;
	Point O,A,B;
	scanf("%lf%lf%lf%lf%lf%lf%lf",&r,&O.x,&O.y,&A.x,&A.y,&B.x,&B.y);
	double dis=distPL(O,A,B);
	if(dcmp(dis-r)>0)printf("-1\n");
	else if(dcmp(dis-r)==0)printf("0\n");
	else{
		printf("%.5f\n",2*sqrt(r*r-dis*dis));
	}
	return 0;
}

