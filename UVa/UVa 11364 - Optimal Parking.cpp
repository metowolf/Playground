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

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		int n,t,L=99,R=1;
		sf("%d",&n);
		REP(i,1,n){
			sf("%d",&t);
			if(t<L)L=t;
			if(t>R)R=t;
		}
		pf("%d\n",2*(R-L));
	}
	return 0;
}
