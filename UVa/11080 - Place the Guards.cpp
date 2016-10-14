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
#define maxn 200
using namespace std;

int n,m,B,W;
int color[maxn+2];
vector<int>G[maxn+2];

bool DFS(int x){
	for(int to:G[x]){
		if(color[to]==color[x])return 0;
		if(color[to]==-1){
			color[to]=color[x]^1;
			if(color[to])B++;else W++;
			if(!DFS(to))return 0;
		}
	}
	return 1;
}

int solve(){
	int ans=0;
	FOR(i,0,n)if(color[i]==-1){
		B=W=0;
		color[i]=0;W++;
		if(DFS(i))ans+=max(1,min(B,W));
		else return -1;
	}
	return ans;
}

void Init(){
	FOR(i,0,n)G[i].clear(),color[i]=-1;
}

int main(){

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		Init();
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		printf("%d\n",solve());
	}
	return 0;
}

