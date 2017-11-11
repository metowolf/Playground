#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn (100)
#define INF (~0U>>2)
using namespace std;

struct edge{
	int from,to,cap,flow,cost;
};

struct MCMF{
	int n,m,s,t;
	int cnt,cost;
	vector<edge>E;
	vector<int>G[maxn+2];
	bool vis[maxn+2];
	int d[maxn+2];
	int p[maxn+2];
	int a[maxn+2];
	
	void init(int n){
		this->n=n;
		this->cnt=0;
		REP(i,0,n)G[i].clear();
		E.clear();
	}
	
	void addedge(int from,int to,int cap,int cost){
		E.push_back((edge){from,to,cap,0,cost});
		E.push_back((edge){to,from,0,0,-cost});
		int s=E.size();
		G[from].push_back(s-2);
		G[to].push_back(s-1);
	}
	
	bool SPFA(int s,int t,int &cost){
		REP(i,0,n)d[i]=INF;
		CLR(vis,0);
		d[s]=0,vis[s]=1,p[s]=0,a[s]=INF;
		
		queue<int>Q;
		Q.push(s);
		while(!Q.empty()){
			int x=Q.front();Q.pop();
			vis[x]=0;
			FOR(i,0,G[x].size()){
				edge &e=E[G[x][i]];
				edge &ee=E[G[x][i]^1];
				if(e.cap>e.flow&&d[e.to]>d[e.from]+e.cost){
					d[e.to]=d[e.from]+e.cost;
					p[e.to]=G[x][i];
					a[e.to]=min(a[e.from],e.cap-e.flow);
					if(!vis[e.to])vis[e.to]=1,Q.push(e.to);
				}
			}
		}
		if(d[t]==INF)return 0;
		cost+=d[t]*a[t];
		cnt+=a[t];
		int u=t;
		while(u!=s){
			E[p[u]].flow+=a[t];
			E[p[u]^1].flow-=a[t];
			u=E[p[u]].from;
		}
		return 1;
	}
	
	void MinCost(int s,int t){
		int cost=0;
		while(SPFA(s,t,cost));
		this->cost=cost;
	}
};
		
int main(){
	int n,m;
	MCMF D;
    while(~sf("%d",&n),n){
    	D.init(n+1);
		sf("%d",&m);
		while(m--){
			int a,b,c;
			sf("%d%d%d",&a,&b,&c);
			D.addedge(a,b,1,c);
			D.addedge(b,a,1,c);
		}
		D.addedge(0,1,2,0);
		D.addedge(n,n+1,2,0);
		D.MinCost(0,n+1);
		if(D.cnt==2)pf("%d\n",D.cost);
		else pf("Back to jail\n");
	}
	return 0;
}
