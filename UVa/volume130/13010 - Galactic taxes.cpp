#include<bits/stdc++.h>
using namespace std;
typedef pair<double,int> PDI;

const int maxn=2048;
const int maxm=131072;
const double eps=1e-7;
const double inf=1e+60;

int n,m;

struct edge{int from,to;double dis;}E[maxm+10];
int head[maxn+10],nxt[maxm+10],cnt;
inline void addedge(int from,int to,double dis){E[cnt]=(edge){from,to,dis};nxt[cnt]=head[from];head[from]=cnt++;}
double dis[maxn+10];bool vis[maxn+10];
double dijkstra(int S,int T){
	for(int i=1;i<=n;i++)dis[i]=inf,vis[i]=0;
	dis[S]=0;
	priority_queue<PDI,vector<PDI>,greater<PDI> >Q;
	Q.push(PDI(dis[S],S));
	while(!Q.empty()){
		PDI t=Q.top();Q.pop();
		if(vis[t.second])continue;
		vis[t.second]=1;
		for(int i=head[t.second];~i;i=nxt[i]){
			edge &e=E[i];
			if(dis[e.to]>dis[e.from]+e.dis){
				dis[e.to]=dis[e.from]+e.dis;
				Q.push(PDI(dis[e.to],e.to));
			}
		}
	}
	return dis[T];
}

int I[maxm+10],J[maxm+10],A[maxm+10],B[maxm+10];

double solve(double t){
	for(int i=1;i<=n;i++)head[i]=-1;
	cnt=0;
	for(int i=1;i<=m;i++){
		double cost=t*A[i]+B[i];
		addedge(I[i],J[i],cost);
		addedge(J[i],I[i],cost);
	}
	return dijkstra(1,n);
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=m;i++)scanf("%d%d%d%d",I+i,J+i,A+i,B+i);
		double L=0,R=24*60;int lim=100;
		double ans=0;
		while(lim--){
			double mid1=(L+R)/2;
			double mid2=(mid1+R)/2;
			double ans1=solve(mid1);
			double ans2=solve(mid2);
			ans=max(ans,max(ans1,ans2));
			if(fabs(ans1-ans2)<eps)break;
			if(ans1>ans2)R=mid2;
			else L=mid1;
		}
		printf("%.5f\n",ans);
	}
	return 0;
}
