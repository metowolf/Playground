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
#define maxn 10000
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int m[128];
char s[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	int T;
	sf("%d",&T);
	while(T--){
		int k;
		FOR(i,0,128)m[i]=0;
		sf("%d",&k);
		while(k--){
			char a;int b;
			sf(" %c %d",&a,&b);
			m[a]=b;
		}
		sf("%d\n",&k);
		double ans=0;
		while(k--){
			gets(s);
			for(int i=0;s[i];i++)ans+=m[s[i]];
		}
		pf("%.2lf$\n",ans/100);
	}
	return 0;
}
