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
#define maxn 50
using namespace std;

const double PI=acos(-1.0);

int main(){
	double D,V;
	while(sf("%lf%lf",&D,&V),D||V){
		double L=0,R=D;
		while(L+EPS<R){
			double mid=(L+R)/2;
			double t=D*PI*(D/2)*(D/2);
			t-=2*PI*(D-mid)/2/3*((D/2)*(D/2)+(mid/2)*(mid/2)+(D/2)*(mid/2));
			t-=mid*PI*(mid/2)*(mid/2);
			if(t<V)R=mid;
			else L=mid;
		}
		pf("%.3lf\n",L);
	}
	return 0;
}
