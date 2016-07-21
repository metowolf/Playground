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
#define maxn 105
using namespace std;

int du[maxn+2];
vector<int>G[maxn+2];
string A[maxn+2];
map<string,int>IDX;

void Initial(int N){
	IDX.clear();
	REP(i,1,N)G[i].clear(),du[i]=0;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int N,M,_=0;
	string s1,s2;
	
	while(~scanf("%d",&N)){
		Initial(N);
		REP(i,1,N){
			cin>>s1,A[i]=s1,IDX[s1]=i;
		}
		scanf("%d",&M);
		while(M--){
			cin>>s1>>s2;
			int x=IDX[s1],y=IDX[s2];
			G[x].push_back(y);
			du[y]++;
		}
		printf("Case #%d: Dilbert should drink beverages in this order:",++_);
		REP(i,1,N){
			int pos=1;
			while(du[pos])++pos;
			du[pos]=-1;
			cout<<" "<<A[pos];
			for(int t:G[pos])--du[t];
		}
		printf(".\n\n");
	}
	return 0;
}
