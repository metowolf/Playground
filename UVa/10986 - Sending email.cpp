#include<bits/stdc++.h>
#define maxn 20000
#define maxm 100000
using namespace std;

const int INF=~0U>>2;

struct edge{
	int from,to,dis;
}E[maxm+2];

int n,m,S,T;
int head[maxn+2],nxt[maxm+2],cnt=0;

inline void addedge(int from,int to,int dis){
	E[cnt]=(edge){from,to,dis};
	nxt[cnt]=head[from],head[from]=cnt++;
}

int dis[maxn+2];
bool vis[maxn+2];

/*void SPFA(){
	queue<int>Q;
	for(int i=0;i<n;i++)dis[i]=INF,vis[i]=0;
	dis[S]=0,vis[S]=1;
	Q.push(S);
	while(!Q.empty()){
		int t=Q.front();Q.pop();
		vis[t]=0;
		for(int i=head[t];~i;i=nxt[i]){
			edge &e=E[i];
			if(dis[e.from]+e.dis<dis[e.to]){
				dis[e.to]=dis[e.from]+e.dis;
				if(!vis[e.to]){
					vis[e.to]=1;
					Q.push(e.to);
				}
			}
		}
	}
}*/

typedef pair<int,int> PII;
void dijkstra(){
	for(int i=0;i<n;i++)dis[i]=INF,vis[i]=0;
	dis[S]=0;
	priority_queue<PII,vector<PII>,greater<PII>>Q;
	Q.push(PII(dis[S],S));
	while(!Q.empty()){
		PII t=Q.top();Q.pop();
		if(vis[t.second])continue;
		vis[t.second]=1;
		for(int i=head[t.second];~i;i=nxt[i]){
			edge &e=E[i];
			if(dis[e.to]>dis[e.from]+e.dis){
				dis[e.to]=dis[e.from]+e.dis;
				Q.push(PII(dis[e.to],e.to));
			}
		}
	}
}
		

int main(){
	int Kase,_=0;
	scanf("%d",&Kase);
	while(Kase--){
		scanf("%d%d%d%d",&n,&m,&S,&T);
		for(int i=0;i<n;i++)head[i]=-1;
		cnt=0;
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c);
			addedge(b,a,c);
		}
		//SPFA();
		dijkstra();
		printf("Case #%d: ",++_);
		if(dis[T]!=INF)printf("%d\n",dis[T]);
		else printf("unreachable\n");
	}
	return 0;
}
