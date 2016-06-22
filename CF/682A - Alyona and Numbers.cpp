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
#define maxn 50
using namespace std;

int n,m;
int a[5],b[5];
long long sum=0;

int main(){
	sf("%d%d",&n,&m);
	REP(i,1,n)a[i%5]++;
	REP(j,1,m)b[j%5]++;
	sum+=(long long)a[0]*b[0];
	REP(i,1,4)sum+=(long long)a[i]*b[5-i];
	pf("%I64d",sum);
	return 0;
}

