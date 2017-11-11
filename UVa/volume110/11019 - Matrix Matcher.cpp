#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x) memset(c,x,sizeof(c))
#define maxn 1000
#define H1 123
#define H2 163
using namespace std;
typedef unsigned long long uLL;

uLL X1[maxn+2],X2[maxn+2];
char A[maxn+2][maxn+2],B[maxn+2][maxn+2];
uLL Hash1[maxn+2][maxn+2],Hash2[maxn+2][maxn+2]; 

void makeHash(char S[][maxn+2],uLL Hash[][maxn+2],int n,int m,int N,int M){
	CLR(Hash,0);
	for(int i=0;i<n;i++){
		for(int j=m-1;j>=0;j--)Hash[i][j]=Hash[i][j+1]*H1+S[i][j]-'a';
		for(int j=0;j<=m-M;j++)Hash[i][j]-=Hash[i][j+M]*X1[M];
	}
	for(int j=0;j<=m-M;j++){
		for(int i=n-1;i>=0;i--)Hash[i][j]+=Hash[i+1][j]*H2;
		for(int i=0;i<=n-N;i++)Hash[i][j]-=Hash[i+N][j]*X2[N];
	}
}
	

int main(){

	//freopen("input.txt","r",stdin);

	X1[0]=X2[0]=1;
	REP(i,1,maxn)X1[i]=X1[i-1]*H1,X2[i]=X2[i-1]*H2;
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,N,M;
		scanf("%d%d",&n,&m);
		FOR(i,0,n)FOR(j,0,m)scanf(" %c",&A[i][j]);
		scanf("%d%d",&N,&M);
		FOR(i,0,N)FOR(j,0,M)scanf(" %c",&B[i][j]);
		
		makeHash(A,Hash1,n,m,N,M);
		makeHash(B,Hash2,N,M,N,M);
		int ans=0;
		REP(i,0,n-N)REP(j,0,m-M)ans+=Hash1[i][j]==Hash2[0][0];
		printf("%d\n",ans);
	}
	return 0;
}
