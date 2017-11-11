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
#define maxn 20
using namespace std;

int A[maxn+2];

int main(){
	int n,_=0;
	while(~sf("%d",&n)){
		long long ans=0;
		REP(i,1,n)sf("%d",A+i);
		REP(L,1,n)REP(R,L,n){
			long long t=1;
			REP(i,L,R)t*=A[i];
			if(t>ans)ans=t;
		}
		pf("Case #%d: The maximum product is %lld.\n\n",++_,ans);
	}
	return 0;
}
