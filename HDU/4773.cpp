#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;
const double pi=acos(-1.0);
const double inf=1e9;
const double _K=1e4;

inline int dcmp(double x){return (x>eps)-(x<-eps);}

struct Point{double x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
Point operator *(Point a,double b){return (Point){a.x*b,a.y*b};}
Point operator /(Point a,double b){return (Point){a.x/b,a.y/b};}
struct Line{Point p,v;};
double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
double length(Point a){return sqrt(dot(a,a));}
Point normal(Point a){return (Point){-a.y,a.x};}

struct Circle{
	Point c;double r;
	Point getP(double ang){
		return (Point){c.x+r*cos(ang),c.y+r*sin(ang)};
	}
};

bool sameSidePL(Point a,Point b,Line l){
	return dcmp(cross(l.p-a,l.v)*cross(l.p-b,l.v))>0;
}

bool pointOnLine(Point a,Line l){
	return !dcmp(cross(a-l.p,l.v));
}

Point inversionPP(Point p1,Point p){
	Point v=p1-p;
	double len=length(v);
	double k=_K/len;
	v=v/len*k;
	return v+p;
}

Point intersectLL(Line la,Line lb){
	double t=cross(lb.v,la.p-lb.p)/cross(la.v,lb.v);
	return la.p+la.v*t;
}

Point outerCenter(Point a,Point b,Point c){
	Line la=(Line){(a+b)/2.0,normal(b-a)};
	Line lb=(Line){(a+c)/2.0,normal(c-a)};
	return intersectLL(la,lb);
}

Circle inversionCC(Circle c,Point p){
	Point p0=c.getP(0);
	Point p1=c.getP(0.5*pi);
	Point p2=c.getP(pi);
	p0=inversionPP(p0,p);
	p1=inversionPP(p1,p);
	p2=inversionPP(p2,p);
	Point ct=outerCenter(p0,p1,p2);
	double radius=length(ct-p0);
	return (Circle){ct,radius};
}

Circle inversionLC(Line &l,Point p){
	Point p1=l.p;
	Point p2=l.p+l.v;
	p1=inversionPP(p1,p);
	p2=inversionPP(p2,p);
	Point ct=outerCenter(p,p1,p2);
	double radius=length(ct-p);
	return (Circle){ct,radius};
}

pair<Point,Point> tangentPointCP(Circle c,Point p){
	double ang=atan2(p.y-c.c.y,p.x-c.c.x);
	double alpha=acos(c.r/length(c.c-p));
	return make_pair(c.getP(ang+alpha),c.getP(ang-alpha));
}

vector<Point> outerTangentPoint(Circle a,Circle b){
	vector<Point>ret;
	Point v=(Point){b.c.x-a.c.x,b.c.y-a.c.y};
	double ang=atan2(v.y,v.x);
	double alpha=acos((a.r-b.r)/length(v));
	ret.push_back(a.getP(ang+alpha));
	ret.push_back(a.getP(ang-alpha));
	ret.push_back(b.getP(ang+alpha));
	ret.push_back(b.getP(ang-alpha));
	return ret;
}

pair<Line,Line> outerTangentLine(Circle a,Circle b){
	vector<Point>t=outerTangentPoint(a,b);
	return make_pair((Line){t[0],t[2]-t[0]},(Line){t[1],t[3]-t[1]});
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		Circle a,b;
		Point p;
		scanf("%lf%lf%lf",&a.c.x,&a.c.y,&a.r);
		scanf("%lf%lf%lf",&b.c.x,&b.c.y,&b.r);
		scanf("%lf%lf",&p.x,&p.y);

		Circle c3=inversionCC(a,p);
		Circle c4=inversionCC(b,p);
		pair<Line,Line> t=outerTangentLine(c3,c4);
		vector<Circle>ans;
		if(!pointOnLine(p,t.first)&&sameSidePL(p,c3.c,t.first)){
			ans.push_back(inversionLC(t.first,p));
		}
		if(!pointOnLine(p,t.second)&&sameSidePL(p,c3.c,t.second)){
			ans.push_back(inversionLC(t.second,p));
		}
		printf("%d\n",(int)ans.size());
		for(int i=0;i<(int)ans.size();i++){
			printf("%.10f %.10f %.10f\n",ans[i].c.x,ans[i].c.y,ans[i].r);
		}
	}
	return 0;
}
