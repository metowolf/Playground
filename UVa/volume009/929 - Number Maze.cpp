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
#define maxn 1000
using namespace std;

int n,m;
int A[maxn+2][maxn+2],d[maxn+2][maxn+2];
bool vis[maxn+2][maxn+2];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

struct node{
	int x,y;
	friend bool operator <(node a,node b){
		return d[a.x][a.y]>d[b.x][b.y];
	}
};

int main(){
	
	//freopen("input.txt","r",stdin);
	
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		REP(i,1,n)REP(j,1,m)scanf("%d",&A[i][j]);
		REP(i,1,n)REP(j,1,m)d[i][j]=INF;
		d[1][1]=A[1][1];
		
		priority_queue<node>Q;
		Q.push((node){1,1});
		while(!Q.empty()){
			node t=Q.top();
			Q.pop();
			if(t.x==n&&t.y==m)break;
			FOR(i,0,4){
				int x=t.x+dx[i],y=t.y+dy[i];
				if(x<1||x>n||y<1||y>m)continue;
				if(d[x][y]>d[t.x][t.y]+A[x][y]){
					d[x][y]=d[t.x][t.y]+A[x][y];
					Q.push((node){x,y});
				}
			}
		}
		printf("%d\n",d[n][m]);
	}
	return 0;
}
