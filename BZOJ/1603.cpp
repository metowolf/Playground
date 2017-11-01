#include<bits/stdc++.h>
using namespace std;

const int maxn=1000;

struct edge{int from,to,dis;};
vector<edge>E;
vector<int>G[maxn+10];
int ans[maxn+10];
bool vis[maxn+10];

void addedge(int from,int to,int dis){
	E.push_back((edge){from,to,dis});
	E.push_back((edge){to,from,dis});
	int s=E.size();
	G[from].push_back(s-2);
	G[to].push_back(s-1);
}

void dfs(int x){
	vis[x]=true;
	for(int i=0;i<G[x].size();i++){
		edge &e=E[G[x][i]];
		if(!vis[e.to]){
			ans[e.to]=ans[e.from]^e.dis;
			dfs(e.to);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
	}
	dfs(1);
	printf("%d\n",ans[n]);
	return 0;
}
