#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include     <list>
#include      <map>
#include      <set>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC  optimize("O2")
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 100
using namespace std;

struct edge{int from,to,dis;};

int n,m,S,lim;
vector<edge>E;
vector<int>G[maxn+2];
bool done[maxn+2];
int d[maxn+2];

struct node{
	int x;
	friend bool operator <(node a,node b){
		return d[a.x]>d[b.x];
	}
};

void addedge(int from,int to,int dis){
	E.push_back((edge){from,to,dis});
	G[from].push_back(E.size()-1);
}

int main(){

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&S,&lim,&m);
		// Initial
		E.clear();
		REP(i,1,n)G[i].clear();
		while(m--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			addedge(b,a,c);
		}
		// Dijkstra
		REP(i,1,n)d[i]=INF,done[i]=0;
		priority_queue<node>Q;
		Q.push((node){S});
		d[S]=0;
		while(!Q.empty()){
			node t=Q.top();
			Q.pop();
			if(done[t.x])continue;
			done[t.x]=1;
			for(int i:G[t.x]){
				edge &e=E[i];
				if(d[e.to]>d[e.from]+e.dis){
					d[e.to]=d[e.from]+e.dis;
					Q.push((node){e.to});
				}
			}
		}
		
		int ans=0;
		REP(i,1,n)ans+=d[i]<=lim;
		printf("%d\n",ans);
		if(T)putchar('\n');
	}
	return 0;
}
