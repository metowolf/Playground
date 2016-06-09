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
#define maxn 30000
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n,m;
int p[maxn+2],r[maxn+2];

int Find(int x){return p[x]==x?x:p[x]=Find(p[x]);}

int main(){
	//freopen("input.txt","r",stdin);
	int T;
	sf("%d",&T);
	while(T--){
		sf("%d%d",&n,&m);
		REP(i,1,n)p[i]=i,r[i]=1;
		int ans=0;
		while(m--){
			int a,b;
			sf("%d%d",&a,&b);
			a=Find(a),b=Find(b);
			if(a!=b){
				p[a]=b;
				r[b]+=r[a];
				ans=max(ans,r[b]);
			}
		}
		pf("%d\n",ans);
	}	
	return 0;
}
