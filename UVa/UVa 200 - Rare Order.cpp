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
#define maxn 26
using namespace std;

int n;
int du[maxn+2];
bool app[maxn+2];
vector<int>G[maxn+2];
vector<string>V;

void addedge(string a,string b){
	FOR(i,0,min(a.size(),b.size())){
		if(a[i]!=b[i]){
			G[a[i]-'A'].push_back(b[i]-'A');
			du[b[i]-'A']++;
			return;
		}
	}
}

int main(){
	//freopen("input.txt","rt",stdin);
	string s;
	while(cin>>s){
		FOR(i,0,26)G[i].clear(),app[i]=du[i]=0;
		n=0;
		V.clear();
		
		if(s[0]!='#')V.push_back(s);
		while(cin>>s,s[0]!='#'){
			V.push_back(s);
			FOR(i,0,s.size())app[s[i]-'A']=1;
		}
		FOR(i,0,26)n+=app[i];
		FOR(i,0,V.size())FOR(j,i+1,V.size())addedge(V[i],V[j]);
		REP(i,1,n){
			int pos=0;
			while(!app[pos]||du[pos])pos++;
			putchar('A'+pos);
			du[pos]=-1;
			for(int t:G[pos])--du[t];
		}
		putchar('\n');
	}
	return 0;
}
		
