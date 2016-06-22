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

const LL MOD=1e9+7;
LL a,b,n,x;

LL MUL(LL a,LL b){a%=MOD,b%=MOD;LL ans=a*b-(LL)((long double)a*b/MOD+eps)*MOD;if(ans<0)ans+=MOD;return ans;}
LL POW(LL a,LL k){LL t=1;while(k){if(k&1LL)t=MUL(t,a);a=MUL(a,a);k>>=1LL;}return t;}

int main(){
	cin>>a>>b>>n>>x;
	return pf("%I64d",a==1LL?(MUL(b,n)+x)%MOD:(MUL(MUL(POW(a,n)-1,POW(a-1,MOD-2)),b)+MUL(POW(a,n),x))%MOD)*0;
}
