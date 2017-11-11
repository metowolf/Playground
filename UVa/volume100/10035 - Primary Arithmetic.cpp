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
	long long n,m;
	while(~sf("%lld%lld",&n,&m),n||m){
		int ans=0;
		for(long long i=10;i<=10000000000;i*=10){
			if(n%i+m%i>=i)ans++;
		}
		pf(ans?"%d carry operation%s.\n":"No carry operation.\n",ans,ans>1?"s":"");
	}
	return 0;
}
