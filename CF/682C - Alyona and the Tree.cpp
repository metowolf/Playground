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
#pragma GCC optimize("O2")
#define sf   scanf
#define pf   printf
#define inf  (~0U>>2)
#define eps  (1e-8)
#define maxn 100000
using namespace std;

int n,ans=0;
long long A[maxn+2];
vector<pair<int,long long> >G[maxn+2];

void DFS(int x,long long p){
	if(x)if(p>A[x])return;
	++ans;
	for(auto t:G[x])DFS(t.first,max(p+t.second,0LL));
}

int main(){
	sf("%d",&n);
	FOR(i,0,n)sf("%I64d",A+i);
	FOR(i,1,n){
		int a,b;
		sf("%d%d",&a,&b);
		G[a-1].push_back({i,b});
	}
	DFS(0,0);
	pf("%d",n-ans);
	return 0;
}

