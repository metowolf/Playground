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

long long reverse(long long x){
	long long t=0;
	while(x)t=t*10+x%10,x/=10;
	return t;
}

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		long long n;
		int cnt=0;
		sf("%lld",&n);
		while(!cnt||n!=reverse(n)){
			n+=reverse(n);
			cnt++;
		}
		pf("%d %lld\n",cnt,n);
	}
	return 0;
}
