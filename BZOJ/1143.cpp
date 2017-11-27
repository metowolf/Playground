#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int maxn=1000;

int n,m;
int d[maxn+10][maxn+10];
int vis[maxn+10],f[maxn+10],_vis=0;

bool find(int x){
	REP(i,1,n)if(d[x][i]&&vis[i]!=_vis){
		vis[i]=_vis;
		if(!f[i]||find(f[i])){f[i]=x;return 1;}
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	REP(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		d[u][v]=1;
	}
	REP(k,1,n)REP(i,1,n)REP(j,1,n)
		d[i][j]=d[i][j]|(d[i][k]&d[k][j]);
	int ans=0;
	REP(i,1,n){
		_vis++;
		if(find(i))ans++;
	}
	printf("%d",n-ans);
	return 0;
}
