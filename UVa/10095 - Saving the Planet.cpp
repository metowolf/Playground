#include<bits/stdc++.h>
#define maxn 10000
#define eps 1e-12
using namespace std;

struct Point{
	double x,y,z;
	friend Point operator +(Point a,Point b){
		return (Point){a.x+b.x,a.y+b.y,a.z+b.z};
	}
	friend Point operator *(Point a,double b){
		return (Point){a.x*b,a.y*b,a.z*b};
	}
	friend Point operator -(Point a,Point b){
		return a+(b*(-1.));
	}
}P[maxn+2];

double length(Point a){
	return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

int main(){
	int n;
	while(~scanf("%d",&n),n){
		for(int i=1;i<=n;i++)scanf("%lf%lf%lf",&P[i].x,&P[i].y,&P[i].z);
		Point o=(Point){0,0,0};
		double r,cel=1000,step=0.99;
		while(cel>eps){
			int idx=0;r=0;
			for(int i=1;i<=n;i++)if(length(P[i]-o)>r){
				r=length(P[i]-o),idx=i;
			}
			o=o+(P[idx]-o)*(cel/1000);
			cel*=step;
		}
		printf("%.4f %.4f %.4f %.4f\n",r,o.x,o.y,o.z);
	}
	return 0;
}

