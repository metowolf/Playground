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
#define maxn 1000
using namespace std;

int DP[maxn+2][maxn+2][10+2];
int doop[maxn+2][maxn+2][10+2];

int main(){
	int n,m,l;
	string s,t;
	sf("%d%d%d",&n,&m,&l);
	cin>>s>>t;
	REP(k,1,l){
		REP(i,1,n)REP(j,1,m)if(s[i-1]==t[j-1]){
			if(!DP[i-1][j-1][k])DP[i][j][k]=doop[i-1][j-1][k-1]+1;
			else DP[i][j][k]=max(doop[i-1][j-1][k-1],DP[i-1][j-1][k])+1;
		}
		REP(i,1,n)REP(j,1,m){
			doop[i][j][k]=max(max(doop[i-1][j][k],doop[i][j-1][k]),DP[i][j][k]);
		}
	}
	pf("%d",doop[n][m][l]);
	return 0;
}
