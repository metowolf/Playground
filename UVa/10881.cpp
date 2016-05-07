#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define CLR(c,x) memset(c,x,sizeof(c))
#define ESP 1e-8
#define sf scanf
#define pf printf
#define INF ~0U>>1
#define maxn 10000
using namespace std;

struct Ants{
	int x,op,id;
	friend bool operator <(Ants a,Ants b){return a.x<b.x;}
};
int L,T,n;
int order[maxn+2];
vector<Ants>ant,after;

void solve(){
	sf("%d%d%d",&L,&T,&n);
	int t,d;char op;
	FOR(i,0,n){
		scanf("%d %c",&t,&op);
		d=(op=='L')?-1:1;
		ant.push_back((Ants){t,d,i});
		after.push_back((Ants){t+d*T,d,0});
	}
	
	sort(ant.begin(),ant.end());
	FOR(i,0,n)order[ant[i].id]=i;
	
	sort(after.begin(),after.end());
	FOR(i,0,n-1)if(after[i].x==after[i+1].x)after[i].op=after[i+1].op=0;
	
	FOR(i,0,n){
		Ants &e=after[order[i]];
		if(e.x<0||e.x>L)pf("Fell off\n");
		else{
			pf("%d ",e.x);
			if(e.op==0)pf("Turning\n");else if(e.op==-1)pf("L\n");else pf("R\n");
		}
	}
	pf("\n");
}

void init(){
	ant.clear();
	after.clear();
	CLR(order,0);
}

int main(){
	int T;
	while(~sf("%d",&T)){
		REP(kase,1,T){
			init();
			pf("Case #%d:\n",kase);
			solve();
		}
	}
	return 0;
}
