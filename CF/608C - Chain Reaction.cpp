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
#define maxn 1000000
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n;
int minx=inf,maxx=0;
int A[maxn+2],DP[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	sf("%d",&n);
	
	REP(i,1,n){
		int a,b;
		sf("%d%d",&a,&b);
		A[a]=b;
		minx=min(minx,a);
		maxx=max(maxx,a);
	}
	REP(i,minx,maxx){
		if(!A[i]){DP[i]=DP[i-1];continue;}
		if(i-A[i]-1>=0)DP[i]=DP[i-A[i]-1]+1;
		else DP[i]=1;
	}
	int ans=0;
	REP(i,minx,maxx)ans=max(ans,DP[i]);
	pf("%d",n-ans);
	return 0;
}
