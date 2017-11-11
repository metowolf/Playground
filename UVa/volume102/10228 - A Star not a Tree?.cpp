#include<bits/stdc++.h>
using namespace std;

const int maxn=100;
const double pi=acos(-1.0);
const double eps=1e-4;

struct Point{double x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
Point operator *(Point a,double b){return (Point){a.x*b,a.y*b};}
double operator *(Point a,Point b){return a.x*b.x+a.y*b.y;}
double operator ^(Point a,Point b){return a.x*b.y-a.y*b.x;}
double len(Point a){return sqrt(a*a);}

int n;
Point P[maxn+10];

double check(Point O){
	double ans=0;
	for(int i=1;i<=n;i++)
		ans+=len(O-P[i]);
	return ans;
}

int main(){
	
	freopen("input.txt","r",stdin);

	srand(time(NULL));

	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			P[i]=(Point){(double)x,(double)y};
		}

		Point O=(Point){0,0};
		for(int i=1;i<=n;i++)O=O+(P[i]*(1./n));
		double ans=check(O);

		double minx=10000,maxx=0;
		double miny=10000,maxy=0;
		for(int i=1;i<=n;i++){
			minx=min(minx,P[i].x);
			maxx=max(maxx,P[i].x);
			miny=min(miny,P[i].y);
			maxy=max(maxy,P[i].y);
		}
		
		double step=min(maxx-minx,maxy-miny);
		while(step>eps){
			int flag=0;
			for(int i=1;i<=10;i++){
				double ang=(rand()%1000+1)/1000.0*10*pi;
				Point tmp=(Point){step*cos(ang),step*sin(ang)};
				tmp=tmp+O;
				double tans=check(tmp);
				if(tans<ans){
					ans=tans;
					O=tmp;
					flag=1;
				}
			}
			if(!flag)step*=0.8;
		}

		printf("%.0f\n",ans);
		if(T)puts("");
	}
	return 0;
}
