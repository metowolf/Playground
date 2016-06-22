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
#define REP(i,a,b)  for(int i=a;i<=b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a,b)  for(int i=a;i!=b;++i)
#define CLR(c,x)    memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf   scanf
#define pf   printf
#define inf  (~0U>>2)
#define eps  (1e-8)
#define maxn 1000
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n,s;
int cnt[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	sf("%d%d",&n,&s);
	REP(i,1,n){
		int a,b;
		sf("%d%d",&a,&b);
		cnt[a]=max(cnt[a],b);
	}
	int ans=0;
	uREP(i,s,0){
		ans=max(ans,cnt[i]);
		ans++;
	}
	pf("%d",ans-1); 
	return 0;
}
