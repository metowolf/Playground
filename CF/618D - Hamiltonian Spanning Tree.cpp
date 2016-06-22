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
#define maxn 200000
using namespace std;

int tree=0;
vector<int>G[maxn+2];

int DFS(int x,int f){
	int out=2;
	FOR(i,0,G[x].size()){
		int t=G[x][i];
		if(t==f)continue;
		if(DFS(t,x)&&out)++tree,--out;
	}
	return out;
}

int main(){
	int n;
	long long x,y;
	sf("%d%lld%lld",&n,&x,&y);
	FOR(i,1,n){
		int a,b;
		sf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if(x<=y)DFS(1,-1);
	else REP(i,1,n)if(G[i].size()==n-1){++tree;break;}
	pf("%lld",x*tree+y*(n-tree-1));
	return 0;
}
