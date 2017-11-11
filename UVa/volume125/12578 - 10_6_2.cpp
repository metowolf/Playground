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
	int T;
	sf("%d",&T);
	while(T--){
		double n,m,r;
		sf("%lf",&n);
		m=n/10*6;
		r=n/10*2;
		pf("%.2f %.2f\n",PI*r*r,n*m-PI*r*r);
	}
	return 0;
}
