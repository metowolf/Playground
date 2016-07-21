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

int n,m;
char name[maxn+2][22];
int d[maxn+2][maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int _=0;
	while(~scanf("%d%d",&n,&m),n){
		REP(i,1,n)REP(j,1,n)d[i][j]=i!=j?INF:0;
		getchar();
		REP(i,1,n)gets(name[i]);
		while(m--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			d[a][b]=c;
			d[b][a]=c;
		}
		REP(k,1,n)REP(i,1,n)REP(j,1,n){
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
		int ans=~0U>>1;int id=0;
		REP(i,1,n){
			int t=0;
			REP(j,1,n)t+=d[i][j];
			if(t<ans)ans=t,id=i;
		}
		printf("Case #%d : %s\n",++_,name[id]);		
	}
	return 0;
}
