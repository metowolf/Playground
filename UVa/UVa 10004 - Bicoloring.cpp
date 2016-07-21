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

int n,m,a,b;
bool vis[maxn+2];
int color[maxn+2];
vector<int>G[maxn+2];

void Init(){
	FOR(i,0,n){
		G[i].clear(),color[i]=-1;
	}
}

bool BFS(int x){
	queue<int>Q;
	color[x]=0;
	Q.push(x);
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int to:G[x]){
			if(~color[to]){
				if(color[to]==color[x])return 0;
			}
			else{
				color[to]=color[x]^1;
				Q.push(to);
			}
		}
	}
	return 1;
}

int main(){

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	while(~scanf("%d",&n),n){
		Init();
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		bool flag=1;
		FOR(i,0,n)if(color[i]==-1)if(!BFS(i)){flag=0;break;}
		printf(flag?"BICOLORABLE.\n":"NOT BICOLORABLE.\n");
	}	
	return 0;
}
