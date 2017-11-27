#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

const int maxn=15;

int e[maxn+2][maxn+2],dp[maxn+2][maxn+2][1<<12];
int g[1<<12][1<<12];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int N=(1<<n)-1;

	REP(i,1,n)REP(j,1,n)e[i][j]=(i!=j)<<30;
	REP(i,1,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e[a][b]=e[b][a]=min(e[a][b],c);
	}

	REP(i,1,N)for(int j=(i-1)&i;j;j=(j-1)&i)REP(k,1,n)
		if(j&(1<<(k-1))){
			int t=1<<30;
			REP(l,1,n)if((i-j)&(1<<(l-1)))t=min(t,e[k][l]);
			if(t==1<<30){g[i-j][j]=-1;break;}
			g[i-j][j]+=t;
		}

	REP(i,1,n)REP(j,1,n)REP(k,1,N)dp[i][j][k]=1<<30;
	REP(i,1,n)dp[1][i][1<<(i-1)]=0;

	FOR(T,1,n)REP(i,1,n)REP(j,1,N)if(dp[T][i][j]!=1<<30)
		for(int k=N-j;k;k=(k-1)&(N-j))if(g[j][k]>=0)
			dp[T+1][i][j+k]=min(dp[T+1][i][j+k],dp[T][i][j]+g[j][k]*T);

	int ans=1<<30;
	REP(T,1,n)REP(i,1,n)ans=min(ans,dp[T][i][N]);
	printf("%d\n",ans);
	return 0;
}

