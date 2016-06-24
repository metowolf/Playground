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
#define sf   scanf
#define pf   printf
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 1000000
using namespace std;

int A[maxn+2];
bool vis[maxn+2];

int f(int x){
	if(vis[x])return A[x];
	vis[x]=1;
	if(!x)return A[x]=1;
	return A[x]=(f(floor(x-sqrt(x)))+f(floor(log(x)))+f(floor(x*sin(x)*sin(x))))%1000000;
}

int main(){
	int n;
	while(~sf("%d",&n),~n)pf("%d\n",f(n));
	return 0;
}
