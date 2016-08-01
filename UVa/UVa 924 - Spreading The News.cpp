#include<bits/stdc++.h>
#define maxn 2500
#define INF ~0U>>2
using namespace std;

int n;
int d[maxn+2];
int cnt[maxn+2];
bool vis[maxn+2];
vector<int>G[maxn+2];

void BFS(int S){
	for(int i=0;i<n;i++)d[i]=INF,vis[i]=0;
	d[S]=0;vis[S]=1;
	queue<int>Q;
	Q.push(S);
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int to:G[x]){
			if(!vis[to]&&d[to]>d[x]+1){
				vis[to]=1;
				d[to]=d[x]+1;
				Q.push(to);
			}
		}
	}
}

int main(){
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			G[i].clear();
			int m;
			scanf("%d",&m);
			while(m--){
				int x;
				scanf("%d",&x);
				G[i].push_back(x);
			}
		}
		int T;
		scanf("%d",&T);
		while(T--){
			int x;
			scanf("%d",&x);
			BFS(x);
			for(int i=0;i<n;i++)cnt[i]=0;
			int maxx=0,idx;
			for(int i=0;i<n;i++)if(d[i]!=INF)cnt[d[i]]++;
			for(int i=1;i<n;i++)if(maxx<cnt[i]){
				maxx=cnt[i];
				idx=i;
			}
			if(maxx)printf("%d %d\n",maxx,idx);
			else printf("0\n");
		}
	}
	return 0;
}
