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
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 100
using namespace std;

int n,m;
int in[maxn+2];
vector<int>G[maxn+2];
vector<int>V;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while(~scanf("%d%d",&n,&m),n){
		// init
		V.clear();
		REP(i,1,n)G[i].clear(),in[i]=0;
		// solve
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
			in[b]++;
		}
		queue<int>Q;
		REP(i,1,n)if(!in[i])Q.push(i);
		while(!Q.empty()){
			int x=Q.front();
			Q.pop();
			V.push_back(x);
			FOR(i,0,G[x].size()){
				int &to=G[x][i];
				if(--in[to]==0)Q.push(to);
			}
		}
		FOR(i,0,V.size())printf("%d%c",V[i],i+1==V.size()?'\n':' ');
	}
	return 0;
}
