#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 21
using namespace std;

int k,cnt;
bool E[maxn+2][maxn+2];
bool vis[maxn+2];
vector<int>ans;

bool BFS(){
	REP(i,1,maxn)vis[i]=0;
	queue<int>Q;
	Q.push(1);
	vis[1]=1;
	while(!Q.empty()){
		int t=Q.front();Q.pop();
		if(t==k)return 1;
		REP(i,1,maxn)if(!vis[i]&&E[t][i])vis[i]=1,Q.push(i);
	}
	return 0;
}

void DFS(int x){
	if(x==k){
		pf("1");
		ECH(it,ans)pf(" %d",*it);
		pf("\n");
		cnt++;
		return;
	}
	vis[x]=1;
	REP(i,1,maxn)if(!vis[i]&&E[x][i]){
		ans.push_back(i);
		DFS(i);
		ans.pop_back();
	}
	vis[x]=0;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	int _=0;
	while(~sf("%d",&k)){
		CLR(E,0);cnt=0;
		int u,v;
		while(sf("%d%d",&u,&v),u||v)E[u][v]=E[v][u]=1;
		pf("CASE %d:\n",++_);
		if(BFS())CLR(vis,0),DFS(1);
		pf("There are %d routes from the firestation to streetcorner %d.\n",cnt,k);
	}
		
	return 0;
}
