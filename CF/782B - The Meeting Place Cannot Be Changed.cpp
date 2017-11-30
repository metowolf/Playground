#include<bits/stdc++.h>
using namespace std;

const int maxn=6e4;
const double inf=1e9;
const double eps=1e-12;

int n;
double d[maxn+10],v[maxn+10];

double calc(double x){
	double t=0;
	for(int i=1;i<=n;i++)
		t=max(t,fabs((d[i]-x)/v[i]));
	return t;
}

int main(){
	scanf("%d",&n);
	double L=inf,R=-inf;
	for(int i=1;i<=n;i++)scanf("%lf",d+i),L=min(L,d[i]),R=max(R,d[i]);
	for(int i=1;i<=n;i++)scanf("%lf",v+i);
	for(int __=0;__<100;__++){
		if(L+eps>R)break;
		double mid1=(L+R)/2;
		double mid2=(mid1+R)/2;
		if(calc(mid1)<calc(mid2))R=mid2;
		else L=mid1;
	}
	printf("%.12f\n",calc(L));
	return 0;
}

