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
#define inf  (~0ULL>>2)
#define eps  (1e-8)
#define maxn 50
using namespace std;
typedef long long LL;

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}

int main(){
	LL n,a,b,p,q;
	cin>>n>>a>>b>>p>>q;
	cout<<(n/a)*p+(n/b)*q-min(p,q)*(n/lcm(a,b));
	return 0;
}

