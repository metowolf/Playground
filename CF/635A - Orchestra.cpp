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
#define maxn 10
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n,m,k,x;
int A[maxn+2][maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	sf("%d%d%d%d",&n,&m,&k,&x);
	while(k--){
		int a,b;
		sf("%d%d",&a,&b);A[a][b]=1;
	}
	int ans=0;
	REP(i1,1,n)REP(j1,1,m)REP(i2,i1,n)REP(j2,j1,m){
		int cnt=0;
		REP(i,i1,i2)REP(j,j1,j2)cnt+=A[i][j];
		ans+=(cnt>=x);
	}
	pf("%d",ans);
	return 0;
}
