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
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 105
using namespace std;

int n,m;
long long t;

int main(){

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	while(~scanf("%d",&n),n){
		long long ans=0;
		multiset<long long>S;
		while(n--){
			scanf("%d",&m);
			while(m--)scanf("%lld",&t),S.insert(t);
			int L=*(S.begin());
			int R=*(S.rbegin());
			ans+=(R-L);
			multiset<long long>::iterator it;
			it=S.begin();S.erase(it);
			it=S.end();S.erase(--it);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
