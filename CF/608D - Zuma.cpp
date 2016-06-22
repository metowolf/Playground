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
#pragma GCC optimize("O2")
#define sf   scanf
#define pf   printf
#define inf  (~0U>>2)
#define eps  (1e-8)
#define maxn 500
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n;
int A[maxn+2];
int DP[maxn+2][maxn+2];

int DFS(int L,int R){
	if(DP[L][R])return DP[L][R];
	if(L>=R)return DP[L][R]=1;
	
	int ans=R-L+1;
	if(A[L]==A[R])ans=min(ans,DFS(L+1,R-1));
	FOR(i,L,R)ans=min(ans,DFS(L,i)+DFS(i+1,R));
	return DP[L][R]=ans;
}

int main(){
	//freopen("input.txt","r",stdin);
	sf("%d",&n);
	REP(i,1,n)sf("%d",A+i);
	pf("%d",DFS(1,n));
	return 0;
}
