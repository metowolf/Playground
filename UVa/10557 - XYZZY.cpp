#include<bits/stdc++.h>
#define maxn 100
using namespace std;

struct edge{
	int from,to,dis;
};

int n;
vector<int>G[maxn+2];
vector<edge>E;
int d[maxn+2];
bool vis[maxn+2];

void addedge(int from,int to,int dis){
	E.push_back((edge){from,to,dis});
	G[from].push_back(E.size()-1);
}

int spfa(int S,int T){
	for(int i=1;i<=n;i++)d[i]=vis[i]=0;
	d[S]=100,vis[S]=1;
	queue<int>Q;
	Q.push(S);
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();vis[x]=0;
		for(int i:G[x]){
			edge &e=E[i];
			if(d[e.to]>100*n)continue;
			if(d[e.to]<d[e.from]+e.dis){
				d[e.to]=d[e.from]+e.dis;
				if(!vis[e.to]){
					if(e.to==T)return 1;
					vis[e.to]=1;
					Q.push(e.to);
				}
			}
		}
	}
	return d[T];
}

int main(){

	//freopen("input.txt","r",stdin);

	while(~scanf("%d",&n),~n){
		E.clear();
		for(int i=1;i<=n;i++){
			G[i].clear();
			int v,m;
			scanf("%d%d",&v,&m);
			while(m--){
				int j;
				scanf("%d",&j);
				addedge(i,j,v);
			}
		}
		if(n==1||spfa(1,n))printf("winnable\n");
		else printf("hopeless\n");
	}
	return 0;
}

