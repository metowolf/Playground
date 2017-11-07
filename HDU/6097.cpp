#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;

struct Point{double x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
Point operator *(Point a,double b){return (Point){a.x*b,a.y*b};}
Point operator /(Point a,double b){return (Point){a.x/b,a.y/b};}
double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
double length(Point a){return sqrt(dot(a,a));}

double _K;
Point inversionPP(Point p1,Point p){
	Point v=p1-p;
	double len=length(v);
	double k=_K/len;
	v=v/len*k;
	return v+p;
}

double distPL(Point p,Point s,Point t){
	return fabs(cross(p-s,t-s))/length(s-t);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		double r;
		scanf("%lf",&r);
		Point P,Q;
		scanf("%lf%lf",&P.x,&P.y);
		scanf("%lf%lf",&Q.x,&Q.y);

		if(length(P-Q)<=eps){
			printf("%.10f\n",2*(r-length(P)));
			continue;
		}

		_K=r*r;
		Point Po=inversionPP(P,(Point){0,0});
		Point Qo=inversionPP(Q,(Point){0,0});
		double dis=distPL((Point){0,0},Po,Qo);
		if(dis<=r)printf("%.10f\n",length(Po-Qo)/r*length(P));
		else{
			dis-=r;
			double t=length(Po-Qo)/2;
			printf("%.10f\n",2*sqrt(t*t+dis*dis)/r*length(P));
		}
	}
	return 0;
}
