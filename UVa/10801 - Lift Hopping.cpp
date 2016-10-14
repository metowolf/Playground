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
#define maxn 5
using namespace std;

int n,k;
int A[maxn+2];
vector<int>V[maxn+2];
int edge[100+2][100+2];
int d[100+2];
bool done[100+2];

void addedge(int from,int to,int dis){
	//printf("%d %d %d\n",from,to,dis);
	edge[from][to]=min(edge[from][to],dis);
	edge[to][from]=min(edge[to][from],dis);
}

struct node{
	int x;
	friend bool operator <(node a,node b){
		return d[a.x]>d[b.x];
	}
};

void dijkstra(){
	FOR(i,0,100){
		d[i]=INF;
		done[i]=0;
	}
	priority_queue<node>Q;
	Q.push((node){0});
	d[0]=0;
	while(!Q.empty()){
		node t=Q.top();Q.pop();
		if(t.x==k)return;
		if(done[t.x])continue;
		done[t.x]=1;
		for(int to=0;to<100;to++)if(edge[t.x][to]!=INF){
			if(d[to]>d[t.x]+edge[t.x][to]){
				d[to]=d[t.x]+edge[t.x][to];
				Q.push((node){to});
			}
		}
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while(~scanf("%d%d",&n,&k)){
		REP(i,1,n)V[i].clear();
		FOR(i,0,100)FOR(j,0,100)edge[i][j]=edge[j][i]=INF;
		REP(i,1,n)scanf("%d",A+i);
		REP(i,1,n){
			int t;
			do{
				scanf("%d",&t);
				V[i].push_back(t);
			}while(getchar()!='\n');
		}
		
		REP(k,1,n)FOR(i,0,V[k].size())FOR(j,i,V[k].size()){
			addedge(V[k][i],V[k][j],abs(V[k][i]-V[k][j])*A[k]+60);
		}
		dijkstra();
		if(k==0)printf("0\n");
		else printf(d[k]==INF?"IMPOSSIBLE\n":"%d\n",d[k]-60);
	}
	return 0;
}
