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
//#pragma comment(linker,"/STACK:36777216")
using namespace std;
typedef long long LL;

int main(){
	//freopen("input.txt","r",stdin);
	LL s,x,t;
	sf("%I64d%I64d",&s,&x);
	LL ans=s==x?-2:0,cnt=0;
	t=(s-x)>>1;
	if(s<x||(s-x)&1||x&t){pf("0");return 0;}
	while(x)cnt+=x&1,x>>=1;
	ans+=1LL<<cnt; 
	pf("%I64d",ans);
	return 0;
}
