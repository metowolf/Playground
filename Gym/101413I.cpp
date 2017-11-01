#include<bits/stdc++.h>
using namespace std;

struct Point{double x,y;};

int n,m;
vector<Point>V1,V2;

Point input(){
	int x,y;
	scanf("%d%d",&x,&y);
	return (Point){x*1.,y*1.};
}

double calcminx(vector<Point> &V){
	double ans=200;
	for(Point t:V)ans=min(ans,t.x);
	return ans;
}

double calcmaxx(vector<Point> &V){
	double ans=-200;
	for(Point t:V)ans=max(ans,t.x);
	return ans;
}

double S_L(Point s,Point t,double x){
	if(x<min(s.x,t.x)||x>max(s.x,t.x))return -200;
	return s.y+(t.y-s.y)/(t.x-s.x)*(x-s.x);
}

double calc(double x,vector<Point> &V){
	double L=200,R=-200;
	int len=V.size();
	for(int i=0;i<len;i++){
		double t=S_L(V[i],V[(i+1)%len],x);
		if(t<=-101)continue;
		if(t<L)L=t;
		if(t>R)R=t;
	}
	return max(R-L,0.);
}

double f(double x){
	double t1=calc(x,V1);
	double t2=calc(x,V2);
	return t1*t2;
}

double simpson(double L,double R,int nn){
	const double h=(R-L)/nn;
	double ans=f(L)+f(R);
	for(int i=1;i<nn;i+=2)ans+=4*f(L+i*h);
	for(int i=2;i<nn;i+=2)ans+=2*f(L+i*h);
	return ans*h/3;
}

double asr(double L,double R,double eps,double A){
	double mid=L+(R-L)/2;
	double Ls=simpson(L,mid,2),Rs=simpson(mid,R,2);
	if(fabs(Ls+Rs-A)<=15*eps)return Ls+Rs+(Ls+Rs-A)/15.0;
	return asr(L,mid,eps/2,Ls)+asr(mid,R,eps/2,Rs);
}

double asr(double L,double R,double eps){
	return asr(L,R,eps,simpson(L,R,2));
}

int main(){
	freopen("I.in","r",stdin);
	int n,m;
	while(~scanf("%d%d",&n,&m),n||m){
		V1.clear();
		V2.clear();
		for(int i=1;i<=n;i++)V1.push_back(input());
		for(int i=1;i<=m;i++)V2.push_back(input());

		double L=calcminx(V1),R=calcmaxx(V1);
		L=max(L,calcminx(V2)),R=min(R,calcmaxx(V2));

		double ans=asr(L,R,1e-8);
		/*
		double ans=0,eps=max(0.0001,(R-L)/10000);
		for(double LL=L;LL+eps<=R;LL+=eps)
			ans+=simpson(LL,LL+eps);
		*/
		printf("%.10f\n",ans);
	}
	return 0;
}

