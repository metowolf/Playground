#include<bits/stdc++.h>
#define maxn 300
#define INF ~0U>>2
using namespace std;


struct edge{
	int from,to,cap,flow;
};

struct Dinic{
	int n,s,t;
	vector<edge>E;
	vector<int>G[maxn+2];
	bool vis[maxn+2];
	int d[maxn+2];

	void init(int n){
		this->n=n;
		for(int i=1;i<=n;i++)G[i].clear();
		E.clear();
	}

	void addedge(int from,int to,int cap){
		E.push_back((edge){from,to,cap,0});
		E.push_back((edge){to,from,0,0});
		int s=E.size();
		G[from].push_back(s-2);
		G[to].push_back(s-1);
	}

	bool BFS(){
		for(int i=1;i<=n;i++)vis[i]=0;
		queue<int>Q;
		Q.push(s);
		vis[s]=1;d[s]=0;
		while(!Q.empty()){
			int x=Q.front();Q.pop();
			for(int i:G[x]){
				edge &e=E[i];
				if(!vis[e.to]&&e.cap>e.flow){
					vis[e.to]=1;
					d[e.to]=d[e.from]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}

	int DFS(int x,int a){
		if(x==t||a==0)return a;
		int flow=0,f;
		for(int i:G[x]){
			edge &e=E[i];
			if(d[e.to]==d[e.from]+1&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
				e.flow+=f;
				E[i^1].flow-=f;
				flow+=f;
				a-=f;
				if(!a)break;
			}
		}
		return flow;
	}

	int exec(int s,int t){
		this->s=s,this->t=t;
		int flow=0;
		while(BFS())flow+=DFS(s,INF);
		return flow;
	}
}MC;

int main(){
	int _=0;
	int n,s,t,c;
	while(~scanf("%d",&n),n){
		scanf("%d%d%d",&s,&t,&c);
		MC.init(n);
		for(int i=1;i<=c;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			MC.addedge(a,b,c);
			MC.addedge(b,a,c);
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",++_,MC.exec(s,t));
	}
	return 0;
}
