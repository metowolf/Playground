#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include      <map>
#include      <set>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC  optimize("O2")
#define sf   scanf
#define pf   printf
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 1000
using namespace std;

int n;
double x[maxn+2],y[maxn+2];

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
	while(~sf("%d",&n),n){
		REP(i,1,n)sf("%lf%lf",x+i,y+i);
		double area=0,W=0;
		x[0]=x[n],y[0]=y[n];
		FOR(i,0,n){
			area+=(x[i]*y[i+1]-x[i+1]*y[i])/2.0;
			W+=gcd((int)fabs(x[i+1]-x[i]),(int)fabs(y[i+1]-y[i]));
		}
		pf("%.0f\n",fabs(area)+1-W/2+0.001);
	}
	return 0;
}
