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
#define maxn 100000
using namespace std;

int n,W;
int A[maxn+2];

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		sf("%d%d",&n,&W);
		REP(i,1,n)sf("%d",A+i);
		sort(A+1,A+n+1);
		int ans=0;
		while(ans<n&&A[ans+1]<=W)W-=A[++ans];
		pf("%d\n",ans);
	}
	return 0;
}
