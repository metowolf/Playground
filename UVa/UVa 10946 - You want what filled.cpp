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

typedef pair<char,int> PII;

int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
int n,m;
char A[maxn+2][maxn+2];
vector<PII>V;

int DFS(int x,int y,char c){
	int ans=1;
	A[x][y]='.';
	FOR(i,0,4)if(A[x+dx[i]][y+dy[i]]==c)ans+=DFS(x+dx[i],y+dy[i],c);
	return ans;
}

bool cmp(PII a,PII b){
	if(a.second!=b.second)return a.second>b.second;
	return a.first<b.first;
}

int main(){
	//freopen("input.txt","r",stdin);
	int _=0;
	while(~scanf("%d%d",&n,&m),n||m){
		V.clear();
		REP(i,1,n)REP(j,1,m)scanf(" %c",&A[i][j]);
		REP(i,1,n)REP(j,1,m)if(A[i][j]!='.'){
			char c=A[i][j];
			V.push_back(PII(c,DFS(i,j,c)));
		}
		sort(V.begin(),V.end(),cmp);
		printf("Problem %d:\n",++_);
		FOR(i,0,V.size()){
			printf("%c %d\n",V[i].first,V[i].second);
		}
		
	}
	return 0;
}
