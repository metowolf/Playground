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
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC  optimize("O2")
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 100
using namespace std;

int n,m;
int c[maxn+2],top;
int V[maxn+2];
vector<int>G[maxn+2];

bool dfs(int x){
	c[x]=-1;
	FOR(i,0,G[x].size()){
		int to=G[x][i];
		if(c[to]<0)return 0;
		else if(!c[to]&&!dfs(to))return 0;
	}
	c[x]=1;
	V[--top]=x;
	return 1;
}

bool topo(){
	top=n;
	CLR(c,0);
	REP(i,1,n)if(!c[i])if(!dfs(i))return 0;
	return 1;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while(~scanf("%d%d",&n,&m),n||m){
		REP(i,1,n)G[i].clear(),V[i]=0;
		REP(i,1,m){
			int a,b;
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
		}
		topo();		
		FOR(i,0,n)printf("%d%c",V[i],i+1==n?'\n':' ');
	}
	return 0;
}
