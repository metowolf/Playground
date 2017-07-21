#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);
const int maxn=1e5;
const double inf=1e30;
const double eps=1e-9;

struct Point{double x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
Point operator *(Point a,double b){return (Point){a.x*b,a.y*b};}
double operator *(Point a,Point b){return a.x*b.x+a.y*b.y;}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
bool operator <(Point a,Point b){return make_pair(a.x,a.y)<make_pair(b.x,b.y);}

int n;
Point P[maxn+10];
double minx,maxx;
double maxans;
Point ansL,ansR;

vector<Point>lower,upper;

Point Line_cross_Line(Point p,Point q,Point s,Point t){
	double s1=cross(p-s,t-s);
	double s2=cross(q-s,t-s);
	return ((q*s1)-(p*s2))*(1/(s1-s2));
}

double area(double L,double R){
	Point a,b,c,d;
	int p,q;

	p=lower_bound(lower.begin(),lower.end(),(Point){L,inf})-lower.begin();
	q=lower_bound(upper.begin(),upper.end(),(Point){L,inf})-upper.begin();
	a=Line_cross_Line(lower[p-1],lower[p],(Point){L,-1},(Point){L,1});	
	b=Line_cross_Line(upper[q-1],upper[q],(Point){L,-1},(Point){L,1});

	p=lower_bound(lower.begin(),lower.end(),(Point){R,inf})-lower.begin();
	q=lower_bound(upper.begin(),upper.end(),(Point){R,inf})-upper.begin();
	c=Line_cross_Line(lower[p-1],lower[p],(Point){R,-1},(Point){R,1});	
	d=Line_cross_Line(upper[q-1],upper[q],(Point){R,-1},(Point){R,1});
	
	double tans=(R-L)*(min(b.y,d.y)-max(a.y,c.y));
	if(tans>maxans){
		maxans=tans;
		ansL=(Point){L,max(a.y,c.y)};
		ansR=(Point){R,min(b.y,d.y)};
	}
	//printf("[debug]%lf %lf %lf\n",L,R,ans);
	return tans;
}

double search(double L){
	double ans;
	double lx=L,rx=maxx;
	for(int it=1;it<=100;it++){
		double mid1=lx+(rx-lx)/3;
		double mid2=(mid1+rx)/2;
		double ans1=area(L,mid1);
		double ans2=area(L,mid2);
		if(ans1<ans2)lx=mid1;
		else rx=mid2;
		ans=ans1;
	}
	return ans;
}

int main(){

	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);

	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);
		
		minx=inf,maxx=-inf;
		maxans=0;
		for(int i=0;i<n;i++){
			if(P[i].x<minx)minx=P[i].x;
			if(P[i].x>maxx)maxx=P[i].x;
		}
		
		int ld,rd;
		Point Pl=(Point){minx,-inf},Pr=(Point){maxx,inf};
		for(int i=0;i<n;i++){
			if(fabs(P[i].x-minx)<eps)if(Pl<P[i])Pl=P[i],ld=i;
			if(fabs(P[i].x-maxx)<eps)if(P[i]<Pr)Pr=P[i],rd=i;
		}

		lower.clear();
		upper.clear();
		for(int i=rd;;i=(i+1)%n){
			lower.push_back(P[i]);
			if(i==ld)break;
		}
		reverse(lower.begin(),lower.end());
		for(int i=ld;;i=(i+1)%n){
			upper.push_back(P[i]);
			if(i==rd)break;
		}
		
		double ans=0;
		double lx=minx,rx=maxx;
		for(int it=1;it<=100;it++){
			double mid1=lx+(rx-lx)/3;
			double mid2=(mid1+rx)/2;
			double ans1=search(mid1);
			double ans2=search(mid2);
			if(ans1<ans2)lx=mid1;
			else rx=mid2;
			ans=ans1;
		}
		//printf("%lf\n",ans);
		printf("%lf %lf %lf %lf\n",ansL.x,ansL.y,ansR.x,ansR.y);
	}
	return 0;
}
