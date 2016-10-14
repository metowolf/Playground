#include<bits/stdc++.h>
#define maxn 200
#define INF ~0U>>2
using namespace std;

struct edge{
	int from,to,cap,flow;
};

struct Dinic{
	int n,s,t;
	vector<edge>E,EE;
	vector<int>G[maxn+2];
	bool vis[maxn+2];
	int d[maxn+2];

	void init(int n){
		this->n=n;
		for(int i=0;i<=n;i++)G[i].clear();
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
		for(int i=0;i<=n;i++)vis[i]=0;
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

	int solve(int nn){
		int ans=INF;
		for(int i=0;i<E.size();i++){
			edge &e=E[i];
			if(e.from==0&&e.to==1&&e.cap>0){
				e.cap=INF;
				break;
			}
		}
		for(int i=1;i<nn;i++){
			EE=E;
			for(int j=0;j<E.size();j++){
				edge &e=E[j];
				if(e.from==i*2&&e.to==i*2+1&&e.cap>0){
					e.cap=INF;
					break;
				}
			}
			ans=min(ans,exec(0,i*2+1));
			E=EE;
		}
		return ans==INF?nn:ans;
	}
}MC;

int main(){

	//freopen("input.txt","r",stdin);

	int n,m;
	while(~scanf("%d%d",&n,&m)){
		MC.init(n*2);
		for(int i=0;i<n;i++){
			MC.addedge(i*2,i*2+1,1);
		}
		for(int i=1;i<=m;i++){
			int a,b;char c;
			while((c=getchar())!='(');
			scanf("%d%*c%d%*c",&a,&b);
			MC.addedge(a*2+1,b*2,INF);
			MC.addedge(b*2+1,a*2,INF);
		}
		printf("%d\n",MC.solve(n));
	}
	return 0;
}
