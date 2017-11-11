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
	REP(_,1,T){
		int a,b,ans=0;
		sf("%d%d",&a,&b);
		REP(i,a,b)if(i&1)ans+=i;
		pf("Case %d: %d\n",_,ans);
	}
	return 0;
}
