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
#define maxn 200000
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n,m;
char a[maxn+2],b[maxn+2];
int DP[2][maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	sf("%s%s",a,b);
	n=strlen(a);
	m=strlen(b);
	
	long long ans=0;
	FOR(i,0,m){
		DP[0][i]=DP[0][i-1];
		DP[1][i]=DP[1][i-1];
		b[i]=='0'?++DP[0][i]:++DP[1][i];
	}
	FOR(i,0,n)ans+=a[i]=='0'?DP[1][m-n+i]-DP[1][i-1]:DP[0][m-n+i]-DP[0][i-1];
	pf("%I64d",ans);
	return 0;
}
