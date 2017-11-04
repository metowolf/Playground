#include<bits/stdc++.h>
using namespace std;

const double inf=1e9;
const double eps=1e-9;
const double pi=acos(-1.0);

int dcmp(double x){return (x>eps)-(x<-eps);}
struct Point{double x,y;int id;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y,a.id};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y,a.id};}
double operator *(Point a,Point b){return a.x*b.x+a.y*b.y;}
double operator ^(Point a,Point b){return a.x*b.y-a.y*b.x;}
Point operator /(Point a,double b){return (Point){a.x/b,a.y/b,0};}
double dot(Point a,Point b){return a*b;}
double cross(Point a,Point b){return a^b;}
double length(Point x){return sqrt(x*x);}
double length2(Point x){return x*x;}

struct circle{
	Point c;double r;
	int id;
	Point getp(double ang){
		return (Point){c.x+r*cos(ang),c.y+r*sin(ang),id};
	}
};

Point pnt[100];int num=0;
int ptancircle(Point k,circle a){
	Point u=k-a.c;
	double len=length(u);
	double ang=acos(a.r/len);
	double bas=atan2(u.y,u.x);
	pnt[++num]=a.getp(bas+ang);
	pnt[++num]=a.getp(bas-ang);
	return 2;
}

int getTangents(circle a,circle b){
	int cnt=0;
	if(a.r<b.r)swap(a,b);
	double d2=length2(a.c-b.c);
	double rcha=a.r-b.r;
	double rsum=a.r+b.r;
	if(dcmp(d2-rcha*rcha)<0)return 0;
	double bas=atan2(b.c.y-a.c.y,b.c.x-a.c.x);
	if(dcmp(d2)==0&&dcmp(a.r-b.r)==0)return -1;
	if(dcmp(d2-rcha*rcha)==0){
		pnt[++num]=a.getp(bas);
		pnt[++num]=b.getp(bas);
		cnt++;
		return 1;
	}
	double ang=acos((a.r-b.r)/sqrt(d2));
	pnt[++num]=a.getp(bas+ang);pnt[++num]=a.getp(bas-ang);cnt++;
	pnt[++num]=b.getp(bas+ang);pnt[++num]=b.getp(bas-ang);cnt++;
	if(dcmp(d2-rsum*rsum)==0){
		pnt[++num]=a.getp(bas);pnt[++num]=b.getp(bas+pi);
		cnt++;
	}
	else if(dcmp(d2-rsum*rsum)>0){
		double ang=acos((a.r+b.r)/sqrt(d2));
		pnt[++num]=a.getp(bas+ang);pnt[++num]=a.getp(bas-ang);cnt++;
		pnt[++num]=a.getp(pi+bas+ang);pnt[++num]=b.getp(pi+bas-ang);
		cnt++;
	}
	return cnt;
}

double ptoline(Point p,Point a,Point b){
	if(dcmp(dot(p-a,b-a))<=0)return length(p-a);
	if(dcmp(dot(p-b,a-b))<=0)return length(p-b);
	return fabs(cross(p-a,b-a))/length(a-b);
}

circle C[10];

double D[100][100],DD[100][100];

int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		Point S;S.id=-1;
		scanf("%lf%lf",&S.x,&S.y);
		circle T;T.c.id=-2;
		scanf("%lf%lf%lf",&T.c.x,&T.c.y,&T.r);
		num=0;
		for(int i=1;i<=n;i++)scanf("%lf%lf%lf",&C[i].c.x,&C[i].c.y,&C[i].r),C[i].id=i;

		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)getTangents(C[i],C[j]);

		for(int i=1;i<=n;i++)ptancircle(S,C[i]),ptancircle(T.c,C[i]);

		pnt[++num]=T.c;pnt[++num]=S;

		if(length(S-T.c)<=T.r){
			printf("%.15f\n",0);
			continue;
		}
		
		//for(int i=1;i<=num;i++)printf("(%.3f,%.3f,#%d)\n",pnt[i].x,pnt[i].y,pnt[i].id);

		//init
		for(int i=1;i<=num;i++)for(int j=1;j<=num;j++)D[i][j]=0;
	
		for(int i=1;i<=num;i++)for(int j=i+1;j<=num;j++){
			if(pnt[i].id==pnt[j].id){
				circle o=C[pnt[i].id];
				double ang1=atan2(pnt[i].y-o.c.y,pnt[i].x-o.c.x);
				double ang2=atan2(pnt[j].y-o.c.y,pnt[j].x-o.c.x);
				double dis=o.r*min(fabs(ang1-ang2),2*pi-fabs(ang1-ang2));
				D[i][j]=D[j][i]=dis;
			}
			else{
				bool flag=1;
				for(int ii=1;ii<=n;ii++)if(ptoline(C[ii].c,pnt[i],pnt[j])<C[ii].r)flag=0;
				if(flag)D[i][j]=D[j][i]=length(pnt[i]-pnt[j]);
				else D[i][j]=D[j][i]=inf;
			}
		}

		for(int i=1;i<=num;i++)for(int j=1;j<=num;j++)DD[i][j]=D[i][j];

		for(int k=1;k<=num;k++)
			for(int i=1;i<=num;i++)
				for(int j=1;j<=num;j++)
					D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
		
		/*for(int i=1;i<=num;i++){
			for(int j=1;j<=num;j++)cout<<D[i][j]<<" ";
			cout<<endl;
		}*/

		double ans=D[num][num-1];
		for(int i=1;i<=num;i++)if(length(pnt[i]-T.c)<=T.r)ans=min(ans,D[num][i]);
		
		for(int i=1;i<=num;i++)for(int j=1;j<=num;j++)if(i!=j&&DD[i][j]<inf){
			if(pnt[i].id==pnt[j].id){	
				/*circle o=C[pnt[i].id];
				double ang1=atan2(pnt[i].y-o.c.y,pnt[i].x-o.c.x);
				double ang2=atan2(pnt[j].y-o.c.y,pnt[j].x-o.c.x);
				if(ang1>ang2)swap(ang1,ang2);
				if(ang2-ang1>pi)ang1+=2*pi,swap(ang1,ang2);
				double L=ang1,R=ang2;
				for(int ii=1;ii<=200;ii++){
					double mid=(L+R)/2;
					Point t=o.getp(mid);
					if(length(t-T.c)<T.r)L=mid;
					else R=mid;
				}
				ans=min(ans,D[num][j]+o.r*(L-ang1));
				*/continue;
			}
			if(length(pnt[i]-T.c)<T.r&&length(pnt[j]-T.c)>T.r){
				Point L=pnt[i],R=pnt[j];
				for(int ii=1;ii<=200;ii++){
					Point mid=(L+R)/2;
					if(length(mid-T.c)<=T.r)L=mid;
					else R=mid;
				}
				ans=min(ans,D[num][j]+length(L-pnt[j]));
				//cout<<i<<" "<<j<<" "<<ans<<endl;
			}
		}

		printf("%.15f\n",ans);

	}
	return 0;
}
