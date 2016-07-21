#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include     <list>
#include      <map>
#include      <set>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC  optimize("O2")
#define INF  1e5
#define EPS  1e-8
#define maxn 22
using namespace std;

int main(){

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--){
		int e,f,c;
		scanf("%d%d%d",&e,&f,&c);
		int ans=0;
		e+=f;
		while(e>=c){
			ans+=e/c;
			e=e/c+e%c;
		}
		printf("%d\n",ans);
	}
	return 0;
}
		
