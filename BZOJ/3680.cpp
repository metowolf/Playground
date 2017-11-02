#include<bits/stdc++.h>
using namespace std;

const int maxn=10000;

struct Point{double x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
Point operator *(Point a,double b){return (Point){a.x*b,a.y*b};}
Point operator /(Point a,double b){return (Point){a.x/b,a.y/b};}
double len(Point a){return sqrt(dot(a,a));}

Point P[maxn+10];
double w[maxn+10];

double Rand(){return rand()%1000/1000.0;}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf%lf",&P[i].x,&P[i].y,w+i);
	Point O=(Point){0,0};
	for(int i=1;i<=n;i++)O=O+P[i];O=O/(double)n;
	double ans=0;
	for(int i=1;i<=n;i++)ans+=len(O-P[i])*w[i];

	double TEMP=1000000,STEP=0.993;
	while(TEMP>0.001){
		Point o;
		o.x=O.x+TEMP*(Rand()*2-1);
		o.y=O.y+TEMP*(Rand()*2-1);
		double tans=0;
		for(int j=1;j<=n;j++)tans+=len(o-P[j])*w[j];
		if(tans<ans)O=o,ans=tans;
		TEMP*=STEP;
	}
	printf("%.3f %.3f\n",O.x,O.y);
	return 0;
}
