#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include     <list>
#include      <map>
#include      <set>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC  optimize("O2")
#define INF  1e5
#define EPS  1e-8
#define maxn 51
#define eps 1e-8
using namespace std;

const double PI=acos(-1.0);

int n;
double A[maxn+2];

double heron(double a,double b,double c){
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		double sum=0;
		
		scanf("%d",&n);
		REP(i,1,n)scanf("%lf",A+i),sum+=A[i];
		REP(i,2,n)if(A[i]>A[1])swap(A[1],A[i]);
		if(A[1]*2>sum){
			printf("0.000\n");
			continue;
		}
		double L=A[1]/2,R=sum;
		while(L+eps<R){
			double mid=(L+R)/2,angle=0;
			REP(i,1,n)angle+=asin(A[i]/2/mid)*2;
			if(angle>2*PI)L=mid;
			else R=mid;
		}
		double ans=0;
		REP(i,1,n)ans+=heron(L,L,A[i]);
		printf("%.3f\n",ans);
	}
	return 0;
}
