#include<bits/stdc++.h>
using namespace std;

const int maxn=1000;
const int MAXB=22;

int n;
int depth[maxn+10],father[maxn+10][MAXB+10];
int dis[maxn+10];
bool visited[maxn+10];

struct edge{int from,to,dis;};
vector<edge>E;
vector<int>G[maxn+10];

void dfs(int x,int d,int dd){
	depth[x]=d;
	dis[x]=dd;
	visited[x]=true;
	for(int i=0;i<G[x].size();i++){
		edge &e=E[G[x][i]];
		if(!visited[e.to]){
			father[e.to][0]=e.from;
			dfs(e.to,d+1,dd+e.dis);
		}
	}
}

void initlca(int n){
	for(int j=1;j<MAXB;j++)
		for(int i=1;i<=n;i++)
			if(~father[i][j-1])
				father[i][j]=father[father[i][j-1]][j-1];
}

int lca(int u,int v){
	if(depth[u]<depth[v])swap(u,v);
	for(int b=MAXB-1;b>=0;b--)
		if(depth[father[u][b]]>=depth[v])
			u=father[u][b];
	if(u==v)return u;
	for(int b=MAXB-1;b>=0;b--)
		if (father[u][b]!=father[v][b])
			u=father[u][b],v=father[v][b];
	return father[u][0];
}

void addedge(int from,int to,int dis){
	E.push_back((edge){from,to,dis});
	E.push_back((edge){to,from,dis});
	int s=E.size();
	G[from].push_back(s-2);
	G[to].push_back(s-1);
}

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
	}
	dfs(1,0,0);
	initlca(n);
	for (int i=1;i<=q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=dis[x]+dis[y]-2*dis[lca(x,y)];
		printf("%d\n",ans); 
	}
	return 0;
}

