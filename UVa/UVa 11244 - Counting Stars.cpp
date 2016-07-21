#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include      <map>
#include      <set>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC  optimize("O2")
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 101
using namespace std;

int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
int n,m,ans;
char A[maxn+2][maxn+2];

int DFS(int x,int y){
	int cnt=1;
	A[x][y]='.';
	FOR(i,0,8)if(A[x+dx[i]][y+dy[i]]=='*')cnt+=DFS(x+dx[i],y+dy[i]);
	return cnt;
}

int main(){
	//freopen("input.txt","r",stdin);
	while(~scanf("%d%d",&n,&m),n||m){
		ans=0;
		REP(i,1,n)REP(j,1,m)scanf(" %c",&A[i][j]);
		REP(i,1,n)REP(j,1,m)if(A[i][j]=='*')ans+=DFS(i,j)==1;
		printf("%d\n",ans);
	}
	return 0;
}
