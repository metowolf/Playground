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
#define maxn 20000
using namespace std;

int A[maxn+2];

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		int n,ans=0;
		sf("%d",&n);
		REP(i,1,n)sf("%d",A+i);
		sort(A+1,A+n+1);
		for(int i=n-2;i>=1;i-=3)ans+=A[i];
		pf("%d\n",ans);
	}
	return 0;
}
